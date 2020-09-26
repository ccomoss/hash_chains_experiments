#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "sha512.h"

int main() {
    
    int chain_len = 1050000;    //the length of hash chain
    unsigned char seed[] = "admin";    //the seed

    uint8_t sha512_out[512/8];

    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < chain_len; i++) {
        if (i ==0)
            SHA512_Simple(seed, strlen((char*)seed), sha512_out);
        else
            SHA512_Simple(sha512_out, strlen((char*)sha512_out), sha512_out);
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (SHA512): %f seconds.\n", dura);

    return 0;
}