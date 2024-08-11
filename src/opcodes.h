#pragma once

inline constexpr auto OP_DSIZE_FLAG   = 0x0080u;
inline constexpr auto OP_ARGTYPE_MASK = 0x007Fu;

                    // FUNCTION                 ARGUMENT_TYPES_ALLOWED
enum opcode_t {
    OP_ADD = 0,
    OP_AND = 1,
    OP_BF = 2,
    OP_BRA = 3,
    OP_BSL = 4,     // Call library function    LFR
    OP_BSR = 5,     // Branch to subroutine     SFR
    OP_BST = 6,
    OP_BTH = 7,
    OP_DEC = 8,
    OP_DIV = 9,
    OP_DUP = 10,
    OP_EQ  = 11,
    OP_GE  = 12,
    OP_GT  = 13,
    OP_INC = 14,
    OP_KIL = 15,
    OP_LE  = 16,
    OP_LNT = 18,
    OP_LT  = 20,
    OP_MOD = 21,
    OP_MUL = 22,
    OP_NE  = 23,
    OP_NEG = 24,
    OP_NOP = 25,
    OP_NOT = 26,
    OP_OR  = 27,
    OP_POP = 28,
    OP_PSH = 29,
    OP_RET = 30,
    OP_SHL = 31,
    OP_SHR = 32,
    OP_SPA = 33,
    OP_SUB = 34,
    OP_XOR = 35,
    OP_STR_EQ = 37,
    OP_STR_NE = 38,
    OP_ECB = 43,
    OP_ESB = 44,
    OP_ECO = 45,
    OP_SCO = 46,

    OP_MS2 = 55,
};

inline const char * opcode_t_str[] = {
    "OP_ADD",
    "OP_AND",
    "OP_BF",
    "OP_BRA",
    "OP_BSL",
    "OP_BSR",
    "OP_BST",
    "OP_BTH",
    "OP_DEC",
    "OP_DIV",
    "OP_DUP",
    "OP_EQ",
    "OP_GE",
    "OP_GT",
    "OP_INC",
    "OP_KIL",
    "OP_LE",
    "",
    "OP_LNT",
    "",
    "OP_LT",
    "OP_MOD",
    "OP_MUL",
    "OP_NE",
    "OP_NEG",
    "OP_NOP",
    "OP_NOT",
    "OP_OR",
    "OP_POP",
    "OP_PSH",
    "OP_RET",
    "OP_SHL",
    "OP_SHR",
    "OP_SPA",
    "OP_SUB",
    "OP_XOR",
    "OP_STR_EQ",
    "OP_STR_NE",
    "",
    "",
    "",
    "",
    "OP_ECB",
    "OP_ESB",
    "OP_ECO",
    "OP_SCO",
};

enum opcode_arg_t {
    OP_ARG_NULL = 0,
    OP_ARG_NUM = 1,
    OP_ARG_NUMR = 2,
    OP_ARG_STR = 3,
    OP_ARG_WORD = 4,
    OP_ARG_PCR = 5,     // PC-relative address (2 bytes)
    OP_ARG_SPR = 6,     // SP-relative address (2 bytes)
    OP_ARG_POPO = 7,    // stack contents (pop) plus offset (2 bytes)
    OP_ARG_SDR = 8,     // static data member reference (4 bytes)
    OP_ARG_SFR = 9,
    OP_ARG_LFR = 10,    // library function member reference (4 bytes)
    OP_ARG_CLV = 11,    // class value reference (4 bytes)
    OP_ARG_SIG = 15,
    OP_ARG_PSIG = 16,
};

inline const char *opcode_arg_t_str[] = {
    "OP_ARG_NULL",
    "OP_ARG_NUM",
    "OP_ARG_NUMR",
    "OP_ARG_STR",
    "OP_ARG_WORD",
    "OP_ARG_PCR",
    "OP_ARG_SPR",
    "OP_ARG_POPO",
    "OP_ARG_SDR",
    "OP_ARG_SFR",
    "OP_ARG_LFR",
    "OP_ARG_CLV",
    "OP_ARG_SIG",
    "OP_ARG_PSIG",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
    "OP_ARG_UNDEFINED",
};

inline constexpr uint32_t opcode_arg_t_shift[] = {
    0, //OP_ARG_NULL
    2, //OP_ARG_NUM
    2, //OP_ARG_NUMR
    2, //OP_ARG_STR
    1, //OP_ARG_WORD
    1, //OP_ARG_PCR
    1, //OP_ARG_SPR
    1, //OP_ARG_POPO
    2, //OP_ARG_SDR
    2, //OP_ARG_SFR
    2, //OP_ARG_LFR
    2, //OP_ARG_CLV
    2, //OP_ARG_SIG
    2, //OP_ARG_PSIG
    2, //17
};
