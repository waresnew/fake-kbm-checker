#include <iostream>
#include <windows.h>
#include "check/check.h"
#include "api/api.h"


int main(int argc, char *argv[]) {
    std::string paramHelp = "Use '-check' to run the fake input checker. Use '-api' to run the fake input sender.";
    if (argc == 1) {
        std::cout << "Invalid number of arguments. " << paramHelp << std::endl;
        return 0;
    } else if (argc == 2) {
        if (strcmp(argv[1], "-check") == 0) {
            startChecker();
        } else if (strcmp(argv[1], "-api") == 0) {
            startApi();
        } else {
            std::cout << "Invalid argument. " << paramHelp << std::endl;
            return 0;
        }
    }

    return 0;
}
