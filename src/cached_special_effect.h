#pragma once

#include "resource_key.h"
#include "vector3d.h"

struct fx_cache;
struct vector3d;
struct handheld_item;
struct entity_base;
struct entity;

struct generic_mash_header;
struct generic_mash_data_ptrs;

struct cached_special_effect {
    resource_key field_0;
    resource_key field_8;
    vector3d field_10;
    int field_1C;
    int field_20;
    entity *field_28;
    float field_2C;
    fx_cache *field_30;
    int16_t field_34;
    int16_t field_36;
    int field_38;
    bool field_3C;
    bool field_3D;


};

