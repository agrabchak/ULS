#include "uls.h"

void mx_get_uid(struct stat st, t_const *cnst) {
    struct passwd *pw = getpwuid(st.st_uid);

    if (!pw) {
        cnst->struid = mx_itoa_sp((long long)st.st_uid);
    }
    else {
        cnst->struid = mx_strdup(pw->pw_name);
    }
}

