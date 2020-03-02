#include "uls.h"

bool mx_isspecial(t_const *cnst) {
    if (*cnst->strrwx == 'c' || *cnst->strrwx == 'b') {
        return true;
    }
    return false;
}

