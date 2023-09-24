#include "../../include/hidapi.h"
#include "api.h"
#include <iostream>

wchar_t wideStr[MAX_STR];
void click() {

}
hid_device *openDevice(const std::string& type) {
    int vid, pid;
    printf("What is your %s's Vendor ID? (eg. 0x1532)\n", type.c_str());
    std::cin >> vid;
    fflush(stdin);
    printf("What is your %s's Product ID? (eg. 0x0084)\n", type.c_str());
    std::cin >> pid;
    fflush(stdin);
    auto handle = hid_open(vid, pid, nullptr);
    if (!handle) {
        std::cout << "Couldn't open device. Double check that the IDs are correct (0xsomething)" << std::endl;
        hid_exit();
        exit(0);
    }
    hid_get_product_string(handle, wideStr, MAX_STR);
    printf("Is this your %s? (Y/N) %ls\n", type.c_str(), wideStr);
    char mouseConfirm;
    std::cin >> mouseConfirm;
    if (mouseConfirm == 'Y') {

    } else {
        std::cout << "Double check that you entered the correct vendor and/or product id." << std::endl;
        exit(0);
    }
    return handle;
}

void startApi() {
    hid_init();
    auto mouse = openDevice("mouse");
    auto kb = openDevice("keyboard");
    hid_close(kb);
    hid_close(mouse);
    hid_exit();
}