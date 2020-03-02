#include "uls.h"

void mx_one_argument(t_data *data) {
    if (!mx_read_dir(".", data)) {
        return;
    }
    if (data->flags[4] || data->flags[5] || data->flags[3])
        mx_print_l(data->cnst, data);
    else {
        if (data->flags[8] && !data->flags[14] && data->cnst->next) {
            mx_printstr_update("total ", data->strtotal, "\n", NULL);
        }
        if (data->flags[14]) {
            mx_print_m(data);
            mx_printchar('\n');
        }
        else if (data->flags[24]) {
            mx_print_x(data);
        }
        else {
            mx_print_file(data);
        }
    }
}

