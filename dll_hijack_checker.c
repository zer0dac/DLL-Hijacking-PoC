#include <stdio.h>
#include <windows.h>
__declspec(dllexport) void <DLL_CALLER_FUNCTION_NAME>()
{
printf("<DLL_CALLER_FUNCTION_NAME> function has been hijacked!\n");
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
switch (ul_reason_for_call)
{
case DLL_PROCESS_ATTACH:
{
printf("Hijacked... Oops...\n");
FARPROC p<DLL_CALLER_FUNCTION_NAME> = GetProcAddress(GetModuleHandle("kernel32.dll"),
"<DLL_CALLER_FUNCTION_NAME>");
if (p<DLL_CALLER_FUNCTION_NAME> != NULL)
{
printf("<DLL_CALLER_FUNCTION_NAME> found!\n");
}
else
{
printf("<DLL_CALLER_FUNCTION_NAME> not found in kernel32.dll, hijacking...\n");
<DLL_CALLER_FUNCTION_NAME>();
}
}
break;
case DLL_PROCESS_DETACH:
break;
case DLL_THREAD_ATTACH:
break;
case DLL_THREAD_DETACH:
break;
}
return TRUE;
}
