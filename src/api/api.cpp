#include "../../include/hidapi.h"
#include <iostream>
#define MAX_STR 255

void startApi() {
    wchar_t wstr[MAX_STR];
    hid_init();
    auto handle = hid_open(0x1532, 0x0084, nullptr);
    if (!handle) {
        std::cout << "Couldn't open device"<<std::endl;
        hid_exit();
        return;
    }
    hid_get_manufacturer_string(handle, wstr, MAX_STR);
    std::cout << wstr << std::endl;
    hid_close(handle);
    hid_exit();
}