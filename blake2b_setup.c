#include <stdio.h>
#include <string.h>
#include <time.h>
#include "blake2b.h"

int main() {
    
    int chain_len = 1050000;    //the length of hash chain
    unsigned char seed[] = "admin";    //the seed

    uint8_t blake_out[64];

    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < chain_len; i++) {
        if (i ==0)
            blake2b(blake_out, 64, NULL, 0, seed, strlen((char *)seed));
        else
            blake2b(blake_out, 64, NULL, 0, blake_out, strlen((char *)blake_out));
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (blake2b): %f seconds.\n", dura);

    return 0;
}