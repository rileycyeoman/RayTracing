#ifndef HITTABLE_H
#define HITTABLE_H

class material;
class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
        bool front_face;
        shared_ptr<material> mat;

        void set_face_normal(const ray& r, const vec3& outward_normal){
            //Sets the normal vecotr for the hit record
            front_face = dot(r.direction(), outward_normal) < 0; //if opposite directions, ray is coming from outside object
            normal = front_face ? outward_normal : -outward_normal; //if 
        }
};

class hittable{
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
      
};

#endif