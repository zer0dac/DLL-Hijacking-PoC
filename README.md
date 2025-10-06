# Disclaimer:
This tool is intended for educational and ethical hacking purposes only. Always obtain permission before testing any system or application. The developers are not responsible for any misuse or damage caused by this tool.



# DLL-Injector-PoC

DLL hijacking and DLL side loading are techniques that rely on how Windows resolves and loads dynamic link libraries. If an application attempts to load a missing or misplaced DLL from a writable location, an attacker can supply a malicious DLL and achieve code execution.

# Usage 

x86_64-w64-mingw32-gcc -I/usr/x86_64-w64-mingw32/include -shared -o <file_name>.dll <file_name>.c

Then move malicious dll to correct path.

# Three DLL PoCs:

<dll_hijack_checker.c> — DLL hijack PoC: loads in place of a missing export and prints a simple message.

<dll_hijack_command_execution> — Creates a user via cmd and assigns local admin privileges when loaded.

<dll_hijack_loader> — Downloads an EXE from <remote_url> and uses PyinMemoryPE to execute it in memory (helper binary performs the in-memory run). (Ref: https://github.com/ELMERIKH/PyinMemoryPE)

