#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>

// n dimensional vector
typedef glm::vec3 Point;

typedef std::vector<Point> PointList;

struct BoundingBox
{
    glm::vec3 origin;
    glm::vec3 dimensions;
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

    BoundingBox box;
};
