
#include "TEA.h"
#include <cstdio>

namespace ws {
    void Encrypt(long* v, long* key) {
        unsigned long n = 16;
        unsigned long sum = 0;
        unsigned long delta = 0x9e3779b9;

        long v0 = v[0];
        long v1 = v[1];
        long k0 = key[0];
        long k1 = key[1];
        long k2 = key[2];
        long k3 = key[3];

        while (n-- > 0) {
            sum += delta;
            v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
            v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
        }

        v[0] = v0;
        v[1] = v1;
    }

    void Decrypt(long* v, long* key) {
        unsigned long n = 16;
        unsigned long delta = 0x9e3779b9;
        unsigned long sum = delta << 4;
        //unsigned long sum = 0xC6EF3720;

        long v0 = v[0];
        long v1 = v[1];
        long k0 = key[0];
        long k1 = key[1];
        long k2 = key[2];
        long k3 = key[3];

        while (n-- > 0) {
            v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
            v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
            sum -= delta;
        }

        v[0] = v0;
        v[1] = v1;
    }
}
