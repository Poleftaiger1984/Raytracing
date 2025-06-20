#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

int main() {

	//World
	hittable_list world;
	world.set_num_of_objects(4);

	//Materials
	auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0));
	auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
	auto material_left	= make_shared<dielectric>(1.50);
	auto material_bubble = make_shared<dielectric>(1.0 / 1.50);
	auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

	//Make objects
	world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
	world.add(make_shared<sphere>(point3( 0.0,  0.0,   -1.2), 0.5,   material_center));
	world.add(make_shared<sphere>(point3(-1.0,  0.0,   -1.0), 0.5,   material_left));
	world.add(make_shared<sphere>(point3(-1.0,  0.0,   -1.0), 0.4,   material_bubble));
	world.add(make_shared<sphere>(point3( 1.0,  0.0,   -1.0), 0.5,   material_right));

	camera cam;

	//Camera variables
	cam.aspect_ratio	  = 16.0 / 9.0;
	cam.image_width		  = 1000;
	cam.samples_per_pixel = 100;
	cam.max_depth		  = 50;

	//Camera controls
	cam.vfov	 = 20;
	cam.lookfrom = point3(-2, 2, 1);
	cam.lookat	 = point3(0, 0, -1);
	cam.vup		 = vec3(0, 1, 0);

	cam.render(world);

}