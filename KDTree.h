#pragma once

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

    static KDTree * build(PointList & pointList);

    bool contains(const Point & p);

	Point point;
	const KDTree * left;
	const KDTree * right;
};