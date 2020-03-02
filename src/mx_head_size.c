#include "uls.h"

void mx_head_size(t_const *cnst, t_data *data) {
    int size = 0;

    while (cnst) {
        size++;
        cnst = cnst->next;
    }
    data->size = size;
}

