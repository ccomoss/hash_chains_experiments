#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sha1.h"

int sha1(const char *input, uint8_t output[20], unsigned size)
{
    int i, err;
    SHA1Context sha;

    err = SHA1Reset(&sha);
    err = SHA1Input(&sha,(const unsigned char *) input, size);
    if (err){
        printf("SHA1Input Error %d.\n", err);
        return -1;
    }
    err = SHA1Result(&sha, output);
    if (err){
        printf("SHA1Result Error %d, could not compute message digest.\n",err );
        return -1;
    } 
    return 0;
}


int main() {
    
    int chain_len = 1050000;    //the length of hash chain
    unsigned char seed[] = "admin";    //the seed
    uint8_t sha1_out[20];

    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < chain_len; i++) {
        if (i ==0)
            sha1(seed, sha1_out, strlen((char *)seed));
        else
            sha1(sha1_out, sha1_out, strlen((char *)sha1_out));
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (SHA1): %f seconds.\n", dura);

    return 0;
}