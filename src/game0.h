#pragma once

#include "fetext.h"
#include "variable.h"
#include "common.h"
#include "os_developer_options.h"
#include "entity_handle_manager.h"
#include "vector2di.h"
#include "memory.h"
#include "ngl.h"
#include "entity.h"
#include "physical_interface.h"
#include "po.h"
#include "region.h"
#include "terrain.h"
#include "utility.h"
#include "wds.h"
#include "limited_timer.h"













#pragma once

#include "color32.h"
#include "fixedstring.h"
#include "float.hpp"
#include "game_button.h"
#include "limited_timer.h"
#include "mstring.h"
#include "rumble_struct.h"
#include "vector3d.h"




enum class game_state {
    LEGAL = 1,
    WAIT_LINK = 4,
    LOAD_LEVEL = 5,
    RUNNING = 6,
    PAUSED = 7,
};

struct game;

// 0x006063C0
extern void game__setup_input_registrations(game* a1);

// 0x00605950
extern void game__setup_inputs(game* a1);

struct game_process {
    const char* field_0;
    int* field_4;
    int index;
    int num_states;
    int field_10;
    bool field_14;
};

inline Var<game_process> lores_game_process { 0x00922074 };

struct game_settings;
struct message_board;
struct world_dynamics_system;
struct entity_base;
struct localized_string_table;
struct game_process;
struct camera;
struct input_mgr;
struct mic;
struct nglMesh;
struct vector2di;
struct resource_key;
struct level_descriptor_t;

struct game {

        struct level_load_stuff {
        level_descriptor_t* descriptor;
        mString name_mission_table;
        mString field_14;
        vector3d field_24;
        int field_30;
        limited_timer_base field_34;
        bool load_widgets_created;
        bool load_completed;
        bool field_3A;
        bool field_3B;

        void reset_level_load_data();

    };

    struct flag_t {
        bool level_is_loaded;
        bool single_step;
        bool physics_enabled;
        bool field_3;
        bool game_paused;
    };

    char field_0;
    char field_1;
    char field_2;
    mString field_4;
    level_load_stuff level;
    world_dynamics_system* the_world;
    int field_54;
    int field_58;
    entity* field_5C;
    entity_base* current_game_camera;
    mic* field_64;
    message_board* mb;
    std::vector<game_process> process_stack;
    localized_string_table* field_7C;
    game_button field_80;
    nglMesh* field_B4;
    nglMesh* field_B8;
    char field_BC;
    char empty3[3];
    game_settings* gamefile;
    int empty4[30];
    float field_13C;
    float field_140;
    int field_144;
    char field_148;
    char field_149;
    char field_14A;
    float field_14C;
    float field_150;
    int field_154;
    bool field_158;
    bool field_159;
    bool field_15A;
    bool field_15B;
    bool field_15C;
    bool field_15D;
    bool field_15E;
    bool field_15F;
    bool field_160;
    bool field_161;
    bool field_162;
    bool field_163;
    bool field_164;
    bool field_165;
    bool field_166;
    bool field_167;
    flag_t flag;
    bool field_16D;
    bool field_16E;
    bool m_hero_start_enabled;
    bool field_170;
    bool field_171;
    bool m_user_camera_enabled;
    bool field_173;
    vector3d field_174;
    vector3d field_180[10];
    vector3d field_1F8[10];
    int field_270;
    float field_274;
    float field_278;
    int field_27C;
    int field_280;
    float field_284;
    int field_288;
    float field_28C;
    rumble_struct field_290;
    bool field_2B4;
    bool field_2B5;
    int field_2B8;
    int field_2BC;
    limited_timer_base field_2C0;




















    game_settings *get_game_settings() {
        assert(gamefile != nullptr);

        return this->gamefile;
    }

    void enable_user_camera(bool a2) {
        this->field_170 = a2;
    }

    bool is_user_camera_enabled() const {
        return this->field_170;
    }

    void set_camera(int camera_state);

    void enable_physics(bool a2)
    {
        void (__fastcall *func)(void*, int, bool) = (decltype(func)) 0x00515230;
        func(this, 0, a2);
    }

    void message_board_init();

    void enable_marky_cam(bool a2, bool a3, Float a4, Float a5)
    {
        void (__fastcall *func)(void *, void *, bool, bool, Float, Float) = bit_cast<decltype(func)>(0x005241E0);

        func(this, nullptr, a2, a3, a4, a5);
    }

    void push_process(game_process &process) {
        void (__fastcall *sub_570FD0)(void *, int, void *) = (decltype(sub_570FD0)) 0x00570FD0;

        sub_570FD0(&this->process_stack, 0, &process);

        auto &last_proc = this->process_stack.back();
        last_proc.index = 0;
        last_proc.field_10 = 0;
    }

    void push_lores()
    {
        this->push_process(lores_game_process());
    }




        void load_this_level()
    {

        void(__fastcall * func)(void*, void*) = CAST(func, 0x0055C6E0);
        return func(this, nullptr);
    }

    void begin_hires_screenshot(int a2, int a3)
    {
        void (__fastcall *func)(void *, void *, int, int) = (decltype(func)) 0x00548C10;
        func(this, nullptr, a2, a3);
    }

    mString get_hero_info();

    mString get_camera_info();

    mString get_analyzer_info();

    void show_debug_info();

    void frame_advance_level(Float time_inc);

    void handle_frame_locking(float* a1);

    void soft_reset_process();


        void load_new_level(const mString& a1, int a2);

        void load_new_level_internal(const mString& a2);
    };

inline Var<game *> g_game_ptr{0x009682E0};

extern void game_patch();

