// main.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


// Basic Types
typedef struct {
    float x, y, z;
} vec3_t;       // Standard for 3D vector

typedef struct {
    vec3_t origin;
    vec3_t direction;
} ray_t;        // Ray definition

typedef struct {
    vec3_t position;
    vec3_t color;
    float intensity;
} light_t;      // Light source

typedef struct {
    vec3_t center;
    float radius;
    vec3_t color;
    float specular;
    float reflective;
} sphere_t;     // Basic primitive

typedef struct {
    vec3_t normal;
    vec3_t point;
    float t;
    vec3_t color;
} hit_record_t; // Intersection data

// Scene Management
typedef struct {
    sphere_t *spheres;
    int sphere_count;
    light_t *lights;
    int light_count;
} scene_t;

// Core Functions
vec3_t vec3_add(vec3_t v1, vec3_t v2);
vec3_t vec3_sub(vec3_t v1, vec3_t v2);
vec3_t vec3_mul(vec3_t v, float t);
float vec3_dot(vec3_t v1, vec3_t v2);
vec3_t vec3_normalize(vec3_t v);

ray_t ray_create(vec3_t origin, vec3_t direction);
vec3_t ray_at(ray_t ray, float t);

bool sphere_intersect(sphere_t sphere, ray_t ray, hit_record_t *rec);
vec3_t calculate_normal(hit_record_t hit, ray_t ray);

vec3_t trace_ray(ray_t ray, scene_t scene, int depth);
vec3_t calculate_color(hit_record_t hit, scene_t scene, ray_t ray, int depth);