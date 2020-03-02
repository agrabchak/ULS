#include "uls.h"

bool mx_islink(t_const *cnst) {
    if (*cnst->strrwx == 'l') {
        return true;
    }
    return false;
}

