#include "structs.h"

// vector.h
typedef struct {
    float x, y, z;
} vec3_t;

vec3_t vec3_add(vec3_t v1, vec3_t v2) {
    return (vec3_t){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

vec3_t vec3_sub(vec3_t v1, vec3_t v2) {
    return (vec3_t){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

vec3_t vec3_mul(vec3_t v, float t) {
    return (vec3_t){v.x * t, v.y * t, v.z * t};
}

float vec3_dot(vec3_t v1, vec3_t v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vec3_t vec3_normalize(vec3_t v) {
    float len = sqrt(vec3_dot(v, v));
    return vec3_mul(v, 1.0f / len);
}

// ray.h
typedef struct {
    vec3_t origin;
    vec3_t direction;
} ray_t;

ray_t ray_create(vec3_t origin, vec3_t direction) {
    return (ray_t){origin, vec3_normalize(direction)};
}

vec3_t ray_at(ray_t ray, float t) {
    return vec3_add(ray.origin, vec3_mul(ray.direction, t));
}

// sphere.h
bool sphere_intersect(sphere_t sphere, ray_t ray, hit_record_t *rec) {
    vec3_t oc = vec3_sub(ray.origin, sphere.center);
    float a = vec3_dot(ray.direction, ray.direction);
    float b = 2.0f * vec3_dot(oc, ray.direction);
    float c = vec3_dot(oc, oc) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0)
        return false;
        
    float t = (-b - sqrt(discriminant)) / (2.0f * a);
    if (t < 0) {
        t = (-b + sqrt(discriminant)) / (2.0f * a);
        if (t < 0)
            return false;
    }
    
    rec->t = t;
    rec->point = ray_at(ray, t);
    rec->normal = vec3_normalize(vec3_sub(rec->point, sphere.center));
    rec->color = sphere.color;
    return true;
}

// Basic trace function
vec3_t trace_ray(ray_t ray, scene_t scene, int depth) {
    hit_record_t rec;
    bool hit = false;
    float closest = INFINITY;
    
    // Find closest intersection
    for(int i = 0; i < scene.sphere_count; i++) {
        if (sphere_intersect(scene.spheres[i], ray, &rec)) {
            if (rec.t < closest) {
                closest = rec.t;
                hit = true;
            }
        }
    }
    
    if (!hit)
        return (vec3_t){0.2, 0.3, 0.5}; // Sky color
        
    return rec.color;
}


// Basic ray tracer with minimal functions
int main() {
    // Setup scene
    scene_t scene = {
        .spheres = malloc(sizeof(sphere_t)),
        .sphere_count = 1,
        .lights = malloc(sizeof(light_t)),
        .light_count = 1
    };
    
    // Create sphere
    scene.spheres[0] = (sphere_t){
        .center = (vec3_t){0, 0, -5},
        .radius = 1,
        .color = (vec3_t){1, 0, 0},  // Red
        .specular = 50,
        .reflective = 0.3
    };
    
    // Add light
    scene.lights[0] = (light_t){
        .position = (vec3_t){2, 2, 0},
        .color = (vec3_t){1, 1, 1},
        .intensity = 1
    };
    
    // Render loop
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            // Calculate ray direction
            vec3_t direction = calculate_ray_direction(x, y);
            ray_t ray = ray_create((vec3_t){0,0,0}, direction);
            
            // Trace ray and get color
            vec3_t color = trace_ray(ray, scene, 0);
            
            // Write pixel
            put_pixel(x, y, color);
        }
    }
    
    // Cleanup
    free(scene.spheres);
    free(scene.lights);
    return 0;
}