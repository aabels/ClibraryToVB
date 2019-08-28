// dllmain.cpp : Defines the entry point for the DLL application.
#define DllExport   __declspec( dllexport )
#include "pch.h"
#include <stdio.h>


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
extern "C" __declspec(dllexport) int __cdecl CallCByVal(char c, short s, long l, float f, double d, LPCSTR  str);
extern "C" __declspec(dllexport) int __cdecl CallCByRef(char* c, short* s, long* l, float* f, double* d, LPSTR* str);


__declspec(dllexport) int __cdecl CallCByVal(char c,
	short s,
	long l,
	float f,
	double d,
	LPCSTR  str)
{
	char str_m[100];
	sprintf_s(str_m,
		"Char %c, Short 0x%X, Long %ld, \nFloat %f, Double %lf, String \"%s\"",
		c, (int)s, l, f, d, str);
	MessageBoxA(NULL, (const char*)str_m, "Message from C", MB_OK);
	return 0;
}


__declspec(dllexport) int __cdecl CallCByRef(char* c,
	short* s,
	long* l,
	float* f,
	double* d,
	LPSTR* str)
{
	char str_m[100];
	sprintf_s(str_m,
		"Char %c, Short 0x%X, Long %ld, \nFloat %f, Double %lf, String \"%s\"",
		*c, (int)* s, *l, *f, *d, *str);
	MessageBoxA(NULL, (const char*)str_m, "Values from VB", MB_OK);
	*c = *c + 1;
	*s = *s + 1;
	*l = *l + 1;
	*f = *f + 1;
	*d = *d + 1;
	strcpy_s(*str, sizeof str, "String from C");

	return 0;
}
