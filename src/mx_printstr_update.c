#include "uls.h"

void mx_printstr_update(char *str1, char *str2, char *str3, char *str4) {
    if (str1) {
        mx_printstr(str1);
    }
    if (str2) {
        mx_printstr(str2);
    }
    if (str3) {
        mx_printstr(str3);
    }
    if (str4) {
        mx_printstr(str4);
    }
}

