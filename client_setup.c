#include <stdio.h>
#include <string.h>
#include <time.h>
#include "md5.h"
#include "sha1.h"
#include "sha256.h"
#include "blake2b.h"

void md5(unsigned char *input, unsigned int inputlen, unsigned char *output) {
    MD5_CTX md5;

    MD5Init(&md5);         

    MD5Update(&md5,input,inputlen);

    MD5Final(&md5,output);

}

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

    uint8_t blake_out[64];
    uint8_t sha256_out[SHA256_BYTES];
    uint8_t md5_out[16];
    uint8_t sha1_out[20];

    int round = chain_len / 4;
    int i;
    clock_t start, end;
    double dura;

    start = clock();
    for (i = 0; i < round; i++) {
        if (i ==0)
            md5(seed, strlen((char *)seed), md5_out);
        else
            md5(sha1_out, strlen((char *)sha1_out), md5_out);

        sha256(md5_out, strlen((char *)md5_out), sha256_out);

        blake2b(blake_out, 64, NULL, 0, sha256_out, strlen((char *)sha256_out));

        sha1(blake_out, sha1_out, strlen((char *)blake_out));
    }
    end = clock();

    dura = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Setup time (Ours): %f seconds.\n", dura);

    return 0;
}