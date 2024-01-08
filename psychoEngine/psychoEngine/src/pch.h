#pragma once

#include <windows.h>

#include "../resource.h" // DÁ AO ARQUIVO "WINMAIN" HABILIDADE DE CHAMAR AS STRINGS DO "RESOURCE.H"

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)
