#ifndef HITTABLE_H
#define HITTABLE_H

class material;

class hit_record {

public:
	point3 p; //The point where the ray hit the object
	vec3 normal; //The surface normal at that point
	shared_ptr<material> mat;
	double t; //The distance along the ray (parameter t)
	bool front_face;

	void set_face_normal(const ray& r, const vec3& outward_normal) {
		//Sets the hit record normal vector
		//NOTE: The parameter 'outward_normal' is assumed to have unit length.

		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

//Interface abstract class
class hittable {

public:
	virtual ~hittable() = default; //A virtual destructor to ensure cleanup happens correctly in subclasses

	virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};


#endif // !HITTABLE_H
