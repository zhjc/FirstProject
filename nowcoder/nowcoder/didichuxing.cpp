
#include "commons.h"

class Didichuxing {
public:
    int didi() {
        int n, b;
        cin >> n >> b;

        bool nflag = false;
        if (n < 0) {
            nflag = true;
            n = -n;
        }

        vector<int> vecarr;
        int temp = n;
        while (temp) {
            vecarr.push_back(temp%b);
            temp /= b;
        }

        string arr[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
        if (nflag) {
            cout << "-";
        }
        for (int i = vecarr.size() - 1; i >= 0; --i) {
            cout << arr[vecarr[i]];
        }
        cout << endl;

        return 0;
    }

    string add_func(string& str1, string& str2) {
        string adder = str1.size() > str2.size() ? str2 : str1;
        string added = str1.size() > str2.size() ? str1 : str2;
        string res;
        int in = 0;
        int i = adder.size() - 1, j = added.size() - 1;
        for (; i >= 0 && j >= 0; --i, --j) {
            int tt = (adder[i] - '0') + (added[j] - '0');
            res.push_back(tt % 10 + in + '0');
            in = tt / 10;
        }

        while (j > -1) {
            int tt = added[j--] + in - '0';
            res.push_back(tt % 10 + '0');
            in = tt / 10;
        }

        if (in > 0) {
            res.push_back(in + '0');
        }

        reverse(res.begin(), res.end());

        return res;
    }
    
    string BigIntMultiply(string& num1, string& num2) {

        string res;

        for (int i = num1.size() - 1; i >= 0; --i) {
            string temp(num1.size() - 1 - i,'0');

            int in = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int tt = (num1[i] - '0')*(num2[j] - '0');
                temp.push_back(tt % 10 + in + '0');
                in = tt / 10;
            }

            if (in > 0) {
                temp.push_back(in + '0');
            }

            reverse(temp.begin(), temp.end());
            
            res = add_func(res, temp);
        }

        return res;
    }

    // 模拟大整数相乘优化方案:先直接相乘并加进位,完成后再扫描是否有大于10的位
    string BigIntMultiply2(string& num1, string& num2) {
        return "";
    }
};

int test_didichuxing() {
    Didichuxing di;
    //didi.didi();
    string str1 = "6789";
    string str2 = "5432";
    string res = di.BigIntMultiply(str1, str2);
    cout << res << endl;
    return 0;
}