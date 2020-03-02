#include "uls.h"

static t_data *get_dir(t_data *app, char **argv, int i, int argc) {
    int j = 0;

    while (i < argc) {
        app->dir_arr[j] = mx_strdup(argv[i]);
        j++;
        i++;
    }
    return app;
}

int mx_dir_arr(char **argv, int argc, t_data *app) {
    int len = 0;
    int i = 1;

    while (i < argc) {
        if (argv[i][0] != '-' || mx_strcmp(argv[i], "--") == 0) {
            if (mx_strcmp(argv[i], "--") == 0)
                i++;
            break;
        }
        i++;
    }
    for (int j = i; j < argc; j++)
        len++;
    app->dir_arr = malloc(sizeof(char*) * len + 1);
    for (int k = 0; k <= len; k++)
        (app->dir_arr)[k] = NULL;
    app = get_dir(app, argv, i, argc);
    if (mx_strcmp(argv[i - 1], "--") == 0)
        i--;
    return i;
}

