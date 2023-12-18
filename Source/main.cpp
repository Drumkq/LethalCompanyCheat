#include <Windows.h>
#include "Core/Core.hpp"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
            Core core;
            core.Initialize();
            break;
    }
    return TRUE;
}