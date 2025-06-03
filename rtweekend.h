#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <memory>

//C++ Std Strings
using std::make_shared;
using std::shared_ptr;

//Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//Utility Functions

inline double degrees_to_radians(double degrees) {
	return degrees * pi / 100.0;
}

inline double random_double() {
	//Returns random real in [0,1)
	return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
	//Returns a random real in [min,max)
	return min + (max - min) * random_double();
}

//Common Headers

#include "color.h"
#include "ray.h"
#include "interval.h"
#include "vec3.h"

#endif // !RTWEEKEND_H
