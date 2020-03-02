#include "uls.h"

void mx_sort_file(char **str, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (mx_strcmp(str[j], str[j + 1]) > 0) {
                char *tmp = str[j];

                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
    }
}

