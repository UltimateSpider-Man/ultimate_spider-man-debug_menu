#pragma once

#include "float.hpp"
#include "mstring.h"
#include "vector2di.h"
#include "keyboard.h"

#include <list>
#include <stack>
#include <string>

struct tokenizer;
struct color32;
struct mString;
struct PanelQuad;
struct ConsoleCommand;
struct ConsoleVariable;

struct Console {
    bool m_visible;
    char oldCurrent[256];
    char current[256];

    std::list<mString> m_log;
    std::list<mString> m_command_log;
    bool field_220;
    float field_224;
    float m_height = 240.0f;
    uint32_t lineNumber;
    uint32_t field_230;
    int field_234;
    int cmdLogNumber;
    std::string field_23C;
    PanelQuad *field_248;
    bool field_24C;
    bool field_24D;
    bool field_24E;
    bool field_24F;

 inline Console();

 inline void* operator new(size_t size);

   inline void operator delete(void* ptr, size_t size);

   inline bool StrnCopy(const char *src, char *dest, int *a3);

   inline void exec_frame_advance(Float a2);

  inline virtual ~Console();

  inline virtual void getMatchingCmds(const char* a2, std::list<mString>& cmds);

  inline virtual void partialCompleteCmd(char* a1, std::list<mString>& list);

 inline virtual void hide();

  inline /*virtual*/ void render();

  inline virtual void exec(const mString& a2);

 inline virtual void addToLog(const char* arg4, ...);

 inline virtual void processCommand(const char* a2, bool is_log);

inline virtual void addToCommandLog(const char* a1);

inline virtual ConsoleCommand* getCommand(const std::string& a1);

inline virtual ConsoleVariable* getVariable(const std::string& a1);

  inline  virtual bool isVisible() const;

inline virtual void show();

 inline /* virtual */ void frame_advance(Float a2);

 inline /* virtual */ void handle_event(KeyEvent a2, Key_Axes a3, void* a4);

 inline /* virtual */ void handle_char(char a2, void*);

inline /* virtual */ void setHeight(Float a2);

 inline /* virtual */ float getHeight();

inline /* virtual */ void setRenderCursor(bool a2);
};

inline void _kbevcb(KeyEvent a1, Key_Axes a2) {};

inline void _kbchcb(char a1) {};

inline char KB_register_event_callback(void (*a1)(KeyEvent, Key_Axes, void*), void* a2) {};

inline void render_console_text(const mString& a1, vector2di a2, const color32& a4) {};

inline  Console *g_console;

extern std::stack<tokenizer *> s_exec_tok_stack;

extern float s_exec_tick;

inline void console_patch()
{};