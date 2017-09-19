
#include <iostream>

#include <string>

#include <bitset>
#include <vector>
#include <map>

using namespace std;

class ClassicAlgorithm {
public:
    // 约瑟夫环
    int josephus(int n, int m)
    {
        int res = 0;

        vector<bool> vectag(n, false);
        int count = 0;
        int cur = 0;

        while (true) {
            for (int i = 0; i < m; ++i) {
                if (vectag[cur]) {
                    while (vectag[cur]) {
                        cur = (cur + 1) % n;
                    }
                    cur = (cur + 1) % n;
                    while (vectag[cur]) {
                        cur = (cur + 1) % n;
                    }
                }
                else {
                    
                    if (i == m-1) {
                        vectag[cur] = true;
                        cout << cur << endl;
                        count++;
                    }

                    cur = (cur + 1) % n;
                }
            }

            if (count == n-1) {
                for (int i = 0; i < n; ++i) {
                    if (vectag[i] == false) {
                        cout << "the last one: " << i << endl;
                        return cur;
                    }
                }
                return cur;
            }
        }

        return res;
    }

    int josephus2(int n, int m)
    {
        vector<bool> vectag(n, true);
        int count = 0;

        for (int i = 1, j = 0; ; ++i) {
            if (vectag[i]) {
                j++;

                if (j == m) {
                    j = 0;
                    count++;
                    vectag[i] = false;
                }

                if (count == n) {
                    return i;
                }
            }

            if (i == n) {
                i = 0;
            }
        }
    }

    // str 2 int
    int StrToInt(string str)
    {
        int res = 0;
        const char* chs = str.c_str();

        while (*chs == ' ') {
            chs++;
        }

        bool flag = true;

        if (*chs == '-' || *chs == '+') {
            if (*chs == '-')flag = false;

            chs++;
        }

        while (*chs >= '0'&&*chs <= '9') {
            res = res * 10 + *chs - '0';
            chs++;
        }

        return res*(flag ? 1 : -1);
    }

    // 因式分解
    vector<int> Prim(int n)
    {
        vector<int> vecres;

        return vecres;
    }

    // 归并排序

    // 实现大整数相乘
    string BigInt_multiply(string add1, string add2) {
        string res;

        return res;
    }

    void TestStdOut() {
        bool flag = false;
        int num = 024;
        cout /*<< boolalpha*/ << flag << endl;
        cout << num << endl;
        unsigned char ch = 0227;
        //cout << ~ch << endl;
        //BinaryRecursion(4);
        //BinaryOrdnary(128);
        //cout << endl;
        cout << bitset<sizeof(int) * 8>(num) << endl;
    }

    void BinaryRecursion(int n) {
        int a = n % 2; // 取余
        n = n << 2; //除2
        if (n != 0) {
            BinaryRecursion(n);
        }

        cout << a; // 逆序输出
    }

    void BinaryOrdnary(int n) {
        bitset<32> b;
        //vector<int> vecbin;
        int temp = n;
        int count = 0;
        while (temp) {
            //vecbin.push_back(temp % 2);
            b[count++] = temp % 2;
            temp >>= 1;
        }
        for (int i = count - 1; i >= 0; --i) {
            cout << b[i];
        }
        //for (int i = vecbin.size()-1; i >= 0; --i) {
        //    cout << vecbin[i];
        //}
    }
};

int test_classic_algorithm()
{
    ClassicAlgorithm ca;
    //ca.josephus(5, 2);
    //string str = "1a33";
    //ca.StrToInt(str);

    ca.TestStdOut();

    return 0;
}