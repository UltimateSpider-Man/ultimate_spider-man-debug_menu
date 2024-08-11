
#include "singleton.h"



#include "limited_timer.h"

#include "os_developer_options.h"

#include "game.h"
#include "mstring.h"


#include "log.h"

#include "trace.h"

#include "common.h"

#include <cassert>

struct game;

struct app : singleton {
    struct internal {
        mString field_0;
        int field_10;
        int field_14;
        int field_18;
        int field_1C;
        int field_20;
        float field_24;
        int field_28;

    };

    internal field_4;
    game *m_game;
    limited_timer_base field_34;
    int field_38;

    //0x005D6FC0




    void tick()
    {
        TRACE("tick");

        {

            float v6 = this->field_34.elapsed();
            sp_log("%f", v6);

            auto frame_lock = os_developer_options::instance()->get_int(mString { "FRAME_LOCK" });
            sp_log("frame_lock = %d", frame_lock);


            float time_inc = 0.0f;
            do {
                time_inc = this->field_34.elapsed();
                g_game_ptr()->handle_frame_locking(&time_inc);

                assert(time_inc >= 0 && time_inc < 1e9f);

                const float v4 = 0.066733405f;
                if (time_inc > v4) {
                    time_inc = v4;
                }
            } while (0 /* time_inc < 0.0f */);

            this->field_34.reset();

            void(__fastcall * func)(void*) = (decltype(func))0x005D6FC0;
            func(this);
        }
    }
    
      static inline Var<app*> instance { 0x009685D4 };
};

   inline   void app_patch()
{
    if constexpr (1) {
    }

    {
        auto address = func_address(&app::tick);
        REDIRECT(0x005AD495, address);
    }
}