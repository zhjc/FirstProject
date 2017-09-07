
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

class LibFuncs {
public:
    int atoi_me(char* str) {
        int res = 0;
        bool flag = true;

        while (*str == ' ')str++;

        if (*str == '+' || *str == '-') {
            if (*str == '-') {
                flag = false;
            }

            str++;
        }

        while (*str>='0'&&*str<='9') {
            res = res * 10 + *str - '0';
            str++;
            if (res<0) { // over flow
                res = INT_MAX;
                break;
            }
        }

        return res*(flag ? 1 : -1);
    }

    int IsBigED() {
        union {
            short s;
            char ch[sizeof(short)];
        } un;

        un.s = 0x0102;

        if (un.ch[0] == 1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isBigED2() {
        int num = 1;
        if (((char*)&num)[sizeof(int) - 1] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int test_lib_function() {
    LibFuncs libf;

    //cout << libf.atoi_me("123") << endl;

    libf.IsBigED();

    libf.isBigED2();

    return 0;
}