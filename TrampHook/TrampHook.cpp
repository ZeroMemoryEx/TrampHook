#include "Header.h"

_declspec(naked) void _return()
{
	_asm
	{
		xor eax, eax
		dec eax
		push eax
		call ExitProcess
	}
}

_declspec(naked) void FakeFunction()
{
	__asm
	{
		push ebp
		mov ebp, esp
		push 0
		push Lcp
		push Lxt
		push MB_OK
		call MessageBoxA
		pop ebp
		ret
	}
}

int __stdcall IntereceptCalls(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
	__asm
	{
		push    lpText
		call    printf
		push    lpCaption
		call    printf
		push    dt
		call	printf
		add     esp, 12
	}

	WriteProcessMemory(GetCurrentProcess(), (LPVOID)originalAdd, originalbytes, sizeof(originalbytes), NULL);

	__asm
	{
		push 0
		push Lcp
		push Lxt
		push MB_OK
		call MessageBoxA
	}

	__asm
	{
		push hWnd
		push lpText
		push lpCaption
		push uType
		call MessageBoxA
	}

	WriteProcessMemory(GetCurrentProcess(), originalAdd, patchOpcodes, sizeof(patchOpcodes), NULL);

	return 0;
}

int wmain()
{
	HMODULE library = LoadLibraryA("user32.dll");
	
	originalAdd = GetProcAddress(library, "MessageBoxA");
	if (!originalAdd)
	{
		__asm
		{
			call _return
		}
	}

	ReadProcessMemory(GetCurrentProcess(), originalAdd, originalbytes, 6, &nobytes);
	__asm
	{
		cmp eax, 0 
		je _return		
	}

	vfunc = &IntereceptCalls;
	memcpy_s(patchOpcodes + 2, 4, &vfunc, 4);
	WriteProcessMemory(GetCurrentProcess(), originalAdd, patchOpcodes, sizeof(patchOpcodes), NULL);
	__asm
	{
		cmp eax, 0
		je _return
	}

	MessageBoxA(NULL, "alert 1", "HELLO 1", MB_OK);
	MessageBoxA(NULL, "alert 2", "HELLO 2", MB_OK);
	MessageBoxA(NULL, "alert 3", "HELLO 3", MB_OK);
	__asm
	{
		call __return
	}
}
