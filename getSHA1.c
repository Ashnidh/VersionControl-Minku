#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sha1.h"

char hex[16] = "0123456789ABCDEF";

unsigned char *scanHex(char *str, int n)
{
    int bytes = n >> 1;
    unsigned char *ret = malloc(bytes);
    memset(ret, 0, bytes);

    for (int i = 0, i2 = 0; i < bytes; i++, i2 += 2)
    {
        // get value
        for (int j = 0; j < 2; j++)
        {
            ret[i] <<= 4;
            unsigned char c = str[i2 + j];
            if (c >= '0' && c <= '9')
            {
                ret[i] += c - '0';
            }
            else if (c >= 'a' && c <= 'f')
            {
                ret[i] += c - 'a' + 10;
            }
            else if (c >= 'A' && c <= 'F')
            {
                ret[i] += c - 'A' + 10;
            }
            else
            {
                free(ret);
                return NULL;
            }
        }
    }

    return ret;
}

const char* laaoSha1(unsigned char msg[])
{
    // printf("Hello, world!\n");
    
    unsigned char *hash = NULL;
    sha1_context ctx;
    sha1_initContext(&ctx);
    sha1_update(&ctx, msg, strlen(msg));
    sha1_digest(&ctx, &hash);
    // printf("{ ");
    char s[40];
    int k = 0;
    for (int i = 0; i < SHA1_OUT; i++)
    {
        // printf("%c%c", hex[hash[i] >> 4], hex[hash[i] & 0x0f]);
        s[k] =  hex[hash[i] >> 4];
        k++;
        s[k] =  hex[hash[i] & 0x0f];
        k++;
    }
    // printf(" }\n");
    free(hash);

    // for(int i = 0; i<k+1; i++){
        // printf("%s\n", s);
    // }
    static char bhai[40 + 1];
    for(int i = 0; i<40; i++){
        *(bhai+i) = s[i];
    }    
    return bhai;
}


// int main () {
//     unsigned char msg[]  = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
//     printf("%s\n" , laaoSha1(msg));
// }