#include "uls.h"

bool mx_last_char(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/' && str[i + 1] == '\0') {
            return 1;
        }
    }
    return 0;
}

