#include "wndproc.h"

#include <print>

LONG_PTR wndproc::originalWndProc{ NULL };
bool wndproc::keyState[0xFF];

LRESULT __stdcall wndproc::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    // check which message game window is receiving
    switch(uMsg) {
        case WM_KEYDOWN: {
            keyState[wParam] = true;
            break;
        }
        case WM_KEYUP: {
            keyState[wParam] = false;
            break;
        }
        default: break;
    }

    // call the original wndproc
    return CallWindowProcW(reinterpret_cast<WNDPROC>(originalWndProc), hWnd, uMsg, wParam, lParam);
}