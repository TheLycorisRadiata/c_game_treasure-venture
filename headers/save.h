#ifndef SAVE_H
#define SAVE_H

#ifndef STANDARD_LIBRARY_STDIO
#define STANDARD_LIBRARY_STDIO
#include <stdio.h>
#endif
#ifndef STANDARD_LIBRARY_STDLIB
#define STANDARD_LIBRARY_STDLIB
#include <stdlib.h>
#endif
#ifndef STANDARD_LIBRARY_STRING
#define STANDARD_LIBRARY_STRING
#include <string.h>
#endif
#ifndef STANDARD_LIBRARY_STDARG
#define STANDARD_LIBRARY_STDARG
#include <stdarg.h>
#endif

#include "game.h"
#include "events.h"

void save_game(FILE* save_file);

#endif

