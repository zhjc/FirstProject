
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

    string BigIntMultiply(string& num1, string& num2) {

        return "";
    }
};

int test_didichuxing() {
    Didichuxing didi;
    didi.didi();
    return 0;
}