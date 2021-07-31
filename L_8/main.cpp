#include "closest_pair.h"

#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"


#include <math.h>
#include <iostream>

int main(int argc, char** argv) {
    std::vector<Point> points;
    points.push_back(Point(1,2));
    points.push_back(Point(1, 2));
    points.push_back(Point(0, 7));
    points.push_back(Point(7, 9));
    points.push_back(Point(1, 3));

    closest_pair(points);

    //int result = Catch::Session().run(argc, argv);
    //return result;
}