#ifndef WNDPROC_H
#define WNDPROC_H

#include <Windows.h>

namespace wndproc {
    extern LONG_PTR originalWndProc;
    extern bool keyState[0xFF]; // ( FF = last key on extended ascii )
    LRESULT __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}

#endif //WNDPROC_H