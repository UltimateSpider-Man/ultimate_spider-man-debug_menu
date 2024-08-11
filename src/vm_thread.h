#pragma once

#include "script_library_class.h"
#include "fixed_pool.h"
#include "msimpletemplates_guts.h"
#include "opcodes.h"
#include "vm_stack.h"

#include "variable.h"

#include <vector>

struct mString;
struct script_instance;
struct vm_executable;

struct vm_thread {
    union argument_t {
        vm_num_t val;
        vm_str_t str;
        short word;
        char *sdr;
        script_library_class::function *lfr;
        vm_executable *sfr;
        unsigned binary;
    };

    enum flags_t
    {
        SUSPENDED   = 0x0001,
        SUSPENDABLE = 0x0002,
    };

    simple_list<vm_thread>::vars_t simple_list_vars;
    script_instance *inst;
    const vm_executable *ex;
    vm_thread *field_14;
    int field_18;

private:
    int flags;

public:
    vm_stack dstack;
    const uint16_t *PC;
    const uint16_t *field_1B0;
    float field_1B4;
    std::vector<unsigned short const *> PC_stack;
    std::vector<void *> field_1C8;
    script_library_class::function::entry_t entry;
    void *field_1DC;
    int field_1E0;
    int field_1E4;


    static Var<char[64][256]> string_registers;

    static Var<fixed_pool> pool;

    static inline Var<int> id_counter {0x00965F0C};
};

extern void vm_thread_patch();
