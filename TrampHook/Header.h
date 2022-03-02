#pragma once

#include <Windows.h>
#include <stdio.h>
#include <iostream>
void		*vfunc;
LPVOID		originalAdd;
SIZE_T		nobytes;
unsigned	char originalbytes[6];
unsigned	char patchOpcodes[]		= { 0x48, 0xb8, 0, 0, 0, 0, 0xff, 0xe0 };
const		char* const  dt			= "\n";
const		char* const  Lxt		= "Function Hooked";
const		char* const  Lcp		= "Alert";

_declspec(naked) void __return()
{
	_asm
	{
		push 0
		call ExitProcess
	}
}