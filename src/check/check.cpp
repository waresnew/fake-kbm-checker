#include <windows.h>
#include <iostream>

HHOOK kbHook;
HHOOK mbHook;

LRESULT CALLBACK kbProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (wParam == WM_KEYDOWN) {
        auto *kbdStruct = (KBDLLHOOKSTRUCT *) lParam;
        //the 4th bit is the injected flag https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-kbdllhookstruct
        std::cout << "KB Injected: " << (kbdStruct->flags >> 4 & 1) << std::endl;
    }
    return CallNextHookEx(kbHook, nCode, wParam, lParam);
}

//filters for lmb and rmb only
LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (wParam == WM_LBUTTONDOWN || wParam == WM_RBUTTONDOWN) {
        auto *mslStruct = (MSLLHOOKSTRUCT *) lParam;
        //the 1st bit is the injected flag https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-msllhookstruct
        std::cout << "Mouse Injected: " << (mslStruct->flags & 1) << std::endl;
    }
    return CallNextHookEx(mbHook, nCode, wParam, lParam);
}

void startChecker() {
    kbHook = SetWindowsHookEx(WH_KEYBOARD_LL, kbProc, nullptr, 0);
    mbHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, nullptr, 0);
    while (GetMessage(nullptr, nullptr, 0, 0));
}