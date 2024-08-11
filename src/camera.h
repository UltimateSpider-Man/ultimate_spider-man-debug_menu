#pragma once

#include "actor.h"

struct vector3d;
struct string_hash;
struct entity;
struct mic;

struct camera : actor {
    mic *field_C0;
    float field_C4;
    float field_C8;

  

};

inline Var<camera*> g_camera_link {0x0095C720};

struct region;

