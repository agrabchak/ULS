#include "uls.h"

static void file(t_const *cnst) {
    if (cnst->strrwx[3] == 's' || cnst->strrwx[6] == 's') {
        cnst->flag_f = "*";
    }
    else if (cnst->strrwx[3] == 'x' || cnst->strrwx[6] == 'x'
             || cnst->strrwx[9] == 'x' || cnst->strrwx[9] == 't') {
        cnst->flag_f = "*";
    }
    else {
        cnst->flag_f = NULL;
    }
}

void mx_get_flag_f(t_const *cnst) {
    while (cnst) {
        if (*cnst->strrwx == 's')
            cnst->flag_f = "=";
        else if (*cnst->strrwx == 'p') {
            cnst->flag_f = "|";
        }
        else if (*cnst->strrwx == 'l') {
            cnst->flag_f = "@";
        }
        else if (*cnst->strrwx == 'b' || *cnst->strrwx == 'c') {
            cnst->flag_f = NULL;
        }
        else if (*cnst->strrwx == '-') {
            file(cnst);
        }
        else if (*cnst->strrwx == 'd') {
            cnst->flag_f = "/";
        }
        cnst = cnst->next;
    }
}

