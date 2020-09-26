#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "sha3.h"

int main() {
    
    int chain_len = 1050000;    //the length of hash chain
    unsigned char seed[] = "admin";    //the seed

    uint8_t sha3_out[256/8];

    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < chain_len; i++) {
        if (i ==0)
            sha3_HashBuffer(256, SHA3_FLAGS_KECCAK, seed, strlen((char*)seed), sha3_out, strlen((char*)sha3_out));
        else
            sha3_HashBuffer(256, SHA3_FLAGS_KECCAK, sha3_out, strlen((char*)sha3_out), sha3_out, strlen((char*)sha3_out));
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (KECCAK256): %f seconds.\n", dura);

    return 0;
}