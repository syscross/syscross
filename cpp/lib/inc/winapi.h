
#pragma once

#include "prelude.h"

#ifdef _WIN32
int _main();
#endif

struct WindowDesc {
    str title  = "Application";
    i32 width  = 800;
    i32 height = 600;
};

void create_window(WindowDesc desc = {});
