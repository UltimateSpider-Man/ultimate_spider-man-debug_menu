#pragma once

#include  <cassert>

#include  "log.h"

using vm_num_t = float;
using vm_str_t = const char *;

struct vm_thread;

inline constexpr auto UNINITIALIZED_SCRIPT_PARM = 0x7BAD05CF;

class vm_stack {
    int field_0[96];

public:
    char *buffer;

private:
    char *SP;
    vm_thread *my_thread;

public:
    vm_stack(vm_thread *t);

    int capacity() const {
        return 96 * 4;
    }

    vm_thread * get_thread() {
        return my_thread;
    }

    int size() const {
        return this->SP - this->buffer;
    }

    vm_num_t& top_num() {
        return *(vm_num_t *)(SP - sizeof(vm_num_t));
    }

    vm_str_t& top_str() {
        return *(vm_str_t *)(SP - sizeof(vm_str_t));
    }



void push(const char* a2, int n)
    {
#if enable_trace
        TRACE("vm_stack::push(const char *, int)");
#endif

        sp_log("0x%X 0x%X %d", this->get_SP(), a2, n);

        assert(size() + n <= capacity());

        std::memcpy(this->SP, a2, n);
        this->move_SP(n);

        sp_log("size = %d", this->size());
    }

void move_SP(int n)
    {
#if enable_trace
        TRACE("vm_stack::move_SP");
#endif

        assert(!(n & 3));

        assert(!((unsigned)SP & 3));
        this->SP += n;

        auto my_size = this->size();

        assert(my_size >= 0 && "underflow -> VM stack corruption");
        if (my_size > this->capacity()) {
            auto v2 = this->capacity();
            printf("capacity: %d", v2);
            assert(0 && "overflow -> bad scripter");
        }
    }


    char *get_SP() const {
        return this->SP;
    }

    void set_SP(char *sp) {
        SP = sp;
    }

    void move_SP(int n)
    {
        return ;
    }

    void pop(int n) {
        this->move_SP(-n);
    }

    void * pop_addr()
    {
        this->pop(sizeof(void *));
        return *(void**)SP;
    }

    vm_str_t pop_str()
    {
        this->pop(sizeof(vm_str_t));
        return *(vm_str_t *)SP;
    }

    vm_num_t pop_num();
};
