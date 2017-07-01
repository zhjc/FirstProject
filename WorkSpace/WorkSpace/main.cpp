#include "TEA.h"
#include <cstdio>
#include <iostream>

using namespace std;

int test_TEA() {
    long v[2]; /* Plaintext */
    long k[4]; /* Key */
    long w[2]; /* cipher text */
                        /* Input to Plain Text */
    v[0] = 0x12345678; v[1] = 0x33333333;
    printf("\n\nInput Data: ");
    printf(" v = 0x%x 0x%x\n\n", v[0], v[1]);
    /* Key */
    k[0] = 0x00000000; k[1] = 0x80000000;
    k[2] = 0x80000000; k[3] = 0x80000000;
    printf("Key = 0x%x 0x%x 0x%x 0x%x\n\n", k[0], k[1], k[2], k[3]);

    ws::Encrypt(v, k);
    printf("\nEncoded data = 0x%x 0x%x\n", v[0], v[1]);
    printf("Key = 0x%x 0x%x 0x%x 0x%x\n\n", k[0], k[1], k[2], k[3]);

    w[0] = v[0];
    w[1] = v[1];

    ws::Decrypt(v, k);
    printf("\nDecoded data = 0x%x 0x%x\n", v[0], v[1]);
    printf("Key = 0x%x 0x%x 0x%x 0x%x\n\n", k[0], k[1], k[2], k[3]);

    return 0;
}

int main(int argc, char* argv[]) {
    test_TEA();

    return 0;
}