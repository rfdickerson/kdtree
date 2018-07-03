#include "KDTree.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <memory>

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

	const auto axis = depth % 2;

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



