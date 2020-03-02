#include "uls.h"

int mx_columns(void) {
    int columns = 0;
    struct ttysize ts;

    ioctl(1, TIOCGSIZE, &ts);
    columns = ts.ts_cols;
    return columns;
}

