
#pragma once

#ifdef _WIN32
int _main();
#define main _main
#endif

void hello();
