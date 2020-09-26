#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "md5.h"

void md5(unsigned char *input, unsigned int inputlen, unsigned char *output) {
    MD5_CTX md5;

    MD5Init(&md5);         

    MD5Update(&md5,input,inputlen);

    MD5Final(&md5,output);

}


int main() {
    
    int chain_len = 1050000;    //the length of hash chain
    unsigned char seed[] = "admin";    //the seed
    uint8_t md5_out[16];


    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < chain_len; i++) {
        if (i ==0)
            md5(seed, strlen((char *)seed), md5_out);
        else
            md5(md5_out, strlen((char *)md5_out), md5_out);
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (MD5): %f seconds.\n", dura);

    return 0;
}