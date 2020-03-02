#include "uls.h"

static void spase(int i) {
    for (int j = 0; j < i; j++) {
        mx_printchar(' ');
    }
}

static void printcolor(char *str, t_const *cnst, t_data *data) {
    while (cnst) {
        if (mx_strcmp(cnst->name_c, str) == 0) {
            if (data->flags[7]) {
                spase(data->max_len_ino - mx_strlen(cnst->strino));
                mx_printstr(cnst->strino);
            }
            if (data->flags[8]) {
                spase(data->max_len_blocks - mx_strlen(cnst->strblocks) + 1);
                mx_printstr_update(cnst->strblocks, " ", NULL, NULL);
            }
            if (cnst->color) {
                mx_printstr(cnst->color);
            }
            mx_printstr(cnst->name);
            return;
        }
        cnst = cnst->next;
    }
}

void mx_print_to_file(char **file, t_data *data) {
    for (int i = 0; i < data->size; i++) {
        if (data->flags[16] && isatty(1)) {
            printcolor(file[i], data->cnst, data);
        }
        if (!data->flags[16] || !isatty(1)) {
            mx_printstr(file[i]);
        }
        if (data->flags[16] && isatty(1)) {
            mx_printstr(MX_NOCOLOR);
        }
        if (data->flags[19] || data->flags[20]) {
            mx_print_flag_f(file[i], data);
        }
        mx_printstr("\n");
    }
}

