#include "uls.h"

int mx_print_flag_f(char *str, t_data *data) {
    t_const *cnst = data->cnst;

    if (!str) {
        return 0;
    }
    while (cnst) {
        if (mx_strcmp(cnst->name_c, str) == 0) {
            if (data->flags[20] && cnst->flag_f && *cnst->flag_f == '/') {
                mx_printstr(cnst->flag_f);
                return 1;
            }
            if (data->flags[19] && cnst->flag_f) {
                mx_printstr(cnst->flag_f);
                return 1;
            }
            return 0;
        }
        cnst = cnst->next;
    }
    return 0;
}

