#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>

// n dimensional vector
typedef glm::vec3 Point;

typedef std::vector<Point> PointList;


struct Ray
{
    Ray(const glm::vec3 &orig, const glm::vec3 &dir);
    glm::vec3 origin;
    glm::vec3 direction;

    glm::vec3 invdir;
    int sign[3];
};

struct BoundingBox
{
    glm::vec3 bounds[2];

    bool intersect(const Ray &r);

};

/**
KDTree

Partitions space by median
*/
class KDTree {

public:

    static std::unique_ptr<KDTree> build(PointList & pointList);

    bool contains(const Point & p);

	Point point;
	std::unique_ptr<KDTree> left;
	std::unique_ptr<KDTree> right;

    BoundingBox boundingbox;
};
