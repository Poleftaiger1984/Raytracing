#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <vector>

class hittable_list : public hittable {

public:
	std::vector<shared_ptr<hittable>> objects;

	hittable_list() {}
	hittable_list(shared_ptr<hittable> object) {   
		// Consider calling set_num_of_objects() before add() for better performance
		// if you plan to add many objects to the list.
		add(object); 
	} 

	void clear() { objects.clear(); }

	// Reserve space in the internal object list to avoid reallocations.
	// Call this before adding many objects for improved performance.
	void set_num_of_objects(unsigned int size) { objects.reserve(size); }

	void add(shared_ptr<hittable> object) {
		objects.emplace_back(object);
	}

	bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
		hit_record temp_rec;
		bool hit_anything = false;
		auto closest_so_far = ray_t.max;

		for (const auto& object : objects) {
			if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
				hit_anything = true;
				closest_so_far = temp_rec.t;
				rec = temp_rec;
			}
		}

		return hit_anything;
	}
};

#endif // !HITTABLE_LIST_H
