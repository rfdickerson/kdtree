#include "KDTree.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <memory>

Ray::Ray(const glm::vec3 &orig, const glm::vec3 &dir)
: origin(orig), direction(dir)
{
    invdir = 1.0f / dir;
    sign[0] = (invdir.x < 0);
    sign[1] = (invdir.y < 0);
    sign[2] = (invdir.z < 0);
}

bool BoundingBox::intersect(const Ray &r)
{
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

      tmin = (bounds[r.sign[0]].x - r.origin.x) * r.invdir.x;
      tmax = (bounds[1-r.sign[0]].x - r.origin.x) * r.invdir.x;
      tymin = (bounds[r.sign[1]].y - r.origin.y) * r.invdir.y;
      tymax = (bounds[1-r.sign[1]].y - r.origin.y) * r.invdir.y;

      if ((tmin > tymax) || (tymin > tmax))
          return false;
      if (tymin > tmin)
          tmin = tymin;
      if (tymax < tmax)
          tmax = tymax;

      tzmin = (bounds[r.sign[2]].z - r.origin.z) * r.invdir.z;
      tzmax = (bounds[1-r.sign[2]].z - r.origin.z) * r.invdir.z;

      if ((tmin > tzmax) || (tzmin > tmax))
          return false;
      if (tzmin > tmin)
          tmin = tzmin;
      if (tzmax < tmax)
          tmax = tzmax;

      return true;
}

struct Comparator {

	int m_axis;

	Comparator(int axis) : m_axis(axis) {}

	bool operator() (const Point i, const Point j)
	{
		return (i[m_axis] < j[m_axis]);
	}
};

std::unique_ptr<KDTree> kd_tree( 
	const PointList::iterator begin, 
	const PointList::iterator end, 
	const int depth, 
	const size_t numPoints)
{

    const auto axis = depth % 3;

	const Comparator comparator(axis);

	std::sort (begin, end, comparator);

	const auto c = numPoints / 2;

	auto tree = std::make_unique<KDTree>();
	tree->point = *(begin + c);

	if (c > 0) {
		tree->left = kd_tree( begin, begin + c - 1, depth + 1, c );
		tree->right = kd_tree( begin + c + 1, end, depth + 1, c);
	}

	return tree;

}

std::unique_ptr<KDTree> KDTree::build(PointList & pointList)
{
    return kd_tree(pointList.begin(), pointList.end(), 0, pointList.size());
}

bool KDTree::contains(const Point & p)
{
    return false;
}



