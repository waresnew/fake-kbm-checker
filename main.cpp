#include <iostream>
#include <windows.h>

HHOOK kbHook{nullptr};
HHOOK mbHook{nullptr};

LRESULT CALLBACK kb_hook(int nCode, WPARAM wParam, LPARAM lParam) {
    if (wParam == WM_KEYDOWN) {
        auto *kbdStruct = (KBDLLHOOKSTRUCT *) lParam;
        //the 4th bit is the injected flag https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-kbdllhookstruct
        std::cout << "KB Injected: " << (kbdStruct->flags >> 4 & 1) << std::endl;
    }
    return CallNextHookEx(kbHook, nCode, wParam, lParam);
}
//filters for lmb and rmb only
LRESULT CALLBACK mouse_hook(int nCode, WPARAM wParam, LPARAM lParam) {
    if (wParam == WM_LBUTTONDOWN || wParam == WM_RBUTTONDOWN) {
        auto *mslStruct = (MSLLHOOKSTRUCT *) lParam;
        //the 1st bit is the injected flag https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-msllhookstruct
        std::cout << "Mouse Injected: " << (mslStruct->flags & 1) << std::endl;
    }
    return CallNextHookEx(mbHook, nCode, wParam, lParam);
}
int main() {
    kbHook = SetWindowsHookEx(WH_KEYBOARD_LL, kb_hook, nullptr, 0);
    mbHook = SetWindowsHookEx(WH_MOUSE_LL, mouse_hook, nullptr, 0);
    while (GetMessage(nullptr, nullptr, 0, 0));
    return 0;
}
