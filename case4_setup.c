#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "md5.h"
#include "sha512.h"
#include "sha3.h"

void md5(unsigned char *input, unsigned int inputlen, unsigned char *output) {
    MD5_CTX md5;

    MD5Init(&md5);         

    MD5Update(&md5,input,inputlen);

    MD5Final(&md5,output);

}

int main() {
    
    int chain_len = 1050000;    //the length of hash chain
    unsigned char seed[] = "admin";    //the seed

    uint8_t sha512_out[512/8];
    uint8_t md5_out[16];
    uint8_t keccak_out[256/8];

    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < round; i++) {
        if (i ==0)
            md5(seed, strlen((char *)seed), md5_out);
        else
            md5(sha512_out, strlen((char *)sha512_out), md5_out);

        sha3_HashBuffer(256, SHA3_FLAGS_KECCAK, md5_out, strlen((char *)md5_out), keccak_out, sizeof(keccak_out));

        SHA512_Simple(keccak_out, sizeof(keccak_out), sha512_out);
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (Case IV): %f seconds.\n", dura);

    return 0;
}