#include "uls.h"

void mx_full_path(t_data *data, t_const *data_l) {
    while (data_l) {
        if (data->path) {
            char *tmp = mx_strjoin(data->path, "/");

            data_l->ful_n = mx_strjoin(tmp, data_l->name);
            free(tmp);
        }
        else {
            data_l->ful_n = NULL;
        }
        data_l = data_l->next;
    }
}

