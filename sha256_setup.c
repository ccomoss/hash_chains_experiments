#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sha256.h"

int main() {
    
    int chain_len = 1050000;    //the length of hash chain
    unsigned char seed[] = "admin";    //the seed

    uint8_t sha256_out[SHA256_BYTES];

    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < chain_len; i++) {
        if (i ==0)
            sha256(seed, strlen((char *)seed), sha256_out);
        else
            sha256(sha256_out, strlen((char *)sha256_out), sha256_out);
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (SHA256): %f seconds.\n", dura);

    return 0;
}