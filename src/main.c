#include "uls.h"

int main(int argc, char **argv) {
    t_data *data = malloc(sizeof(t_data));
    t_data *save = data;

    mx_read_flags(argv, argc, data);
    if (!(*data->dir_arr)) {
        mx_one_argument(data);
    }
    else {
        mx_many_argument(data);
    }
    while (data) {
        if (data->errors) {
            return 1;
        }
        data = data->next;
    }
    data = save;
    return 0;
}

