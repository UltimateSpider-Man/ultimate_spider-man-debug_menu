#include "mstring.h"
#include "utility.h"

#include "common.h"

#include "os_file.h"

#include <cstdint>
#include <windows.h>

    VALIDATE_OFFSET(os_file, field_1C, 0x1C);

    void os_file_patch()
    {
        {
            auto address = func_address(&os_file::write);
            REDIRECT(0x0052A72B, address);
            REDIRECT(0x0052A74C, address);
            REDIRECT(0x0052A79A, address);
        }

        {
            auto address = func_address(&os_file::read);
            REDIRECT(0x00550E8E, address);
            REDIRECT(0x00598B28, address);
        }

        {
            auto address = func_address(&os_file::open);
            SET_JUMP(0x0059B740, address);
        }
    }
    

   

