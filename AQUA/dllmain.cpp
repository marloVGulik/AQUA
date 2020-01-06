// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "dllmain.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    Debug debug(0);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        debug.log("Debug enabled, mode 0");
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }


    return TRUE;
}

