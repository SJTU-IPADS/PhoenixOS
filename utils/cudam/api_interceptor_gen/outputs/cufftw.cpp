
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cufft.h>
#include <cufftw.h>

#include "cudam.h"
#include "api_counter.h"

#undef cuserid
char * cuserid(char * __s){
    char * lretval;
    char * (*lcuserid) (char *) = (char * (*)(char *))dlsym(RTLD_NEXT, "cuserid");
    
    /* pre exeuction logics */
    ac.add_counter("cuserid", kApiTypeCuFFT);

    lretval = lcuserid(__s);
    
    /* post exeuction logics */

    return lretval;
}
#define cuserid cuserid

