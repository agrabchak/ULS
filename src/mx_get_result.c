#include "uls.h"

char **mx_get_result(char **file, t_data *data) {
    char **result = malloc(sizeof(char*) * (data->size_all + 1));
    int line = data->size_all / data->width;
    int counter[2];

    *counter = 0;
    counter[1] = 0;
    for (int i = 0; i <= data->size_all; i++) {
        result[i] = NULL;
    }
    for (int j = 0; j < data->width; j++) {
        *counter = j;
        for (int k = 0; k < line; k++) {
            result[*counter] = file[counter[1]];
            *counter += data->width;
            counter[1]++;
        }
    }
    return result;
}

