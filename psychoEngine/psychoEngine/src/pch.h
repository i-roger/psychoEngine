#pragma once

#include <windows.h>

#include "../resource.h" // D� AO ARQUIVO "WINMAIN" HABILIDADE DE CHAMAR AS STRINGS DO "RESOURCE.H"

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)
