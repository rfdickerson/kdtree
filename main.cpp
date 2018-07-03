#include <iostream>
#include <vector>

#include "KDTree.h"

const static float pointList[7][2] = {
	{3, 4},
	{5, 6},
	{9, 1},
	{1, 6},
	{20, 5},
	{7, 300},
	{9, 8}
};

int main()
{

	auto v = PointList();

	for (int i = 0; i < 7; ++i)
	{
		auto a = { pointList[i][0], pointList[i][1] };
		v.push_back(a);
	}

	auto kdtree = KDTree::build(v);

    Point p = {3.5, 7.6};
    kdtree->contains(p);

	std::cout << "Hello World!" << std::endl;
    std::cout << kdtree->contains(p) << std::endl;
    
	return 0;
}
