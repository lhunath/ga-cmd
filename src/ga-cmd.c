#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "keyhide.h"
#include "cfgfile.h"
#include "verf.h"
#include "codegen.h"
#include "google-authenticator/libpam/google_authenticator_gen.h"

/*-----------------------------------------------------------------*/
int main(int argc, char *const argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: ga-cmd keyfile\n");
        return 1;
    }
    char *key;
    int keyLen;
    if (!(keyLen = load_key(argv[1], &key))) {
        return 1;
    }

    int verf_code = generateCode(key, time(0) / 30);
    fprintf(stderr, "%s: ", argv[1]);
    fflush(stderr);
    fprintf(stdout, "%d", verf_code);
    fflush(stdout);
    fprintf(stderr, "\n");

    return EXIT_SUCCESS;
}
