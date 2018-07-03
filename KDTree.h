#pragma once

#include <memory>
#include <vector>

// n dimensional vector
typedef std::vector<float> Point;

typedef std::vector<Point> PointList;

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
};