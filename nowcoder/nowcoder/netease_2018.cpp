#include <iostream>
#include <iomanip>

#include <string>

#include <numeric>
#include <algorithm>

#include <vector>
#include <map>
#include <set>

using namespace std;
const int MAX_LEN = 1001;
int MaxLen[MAX_LEN][MAX_LEN];
int maxlen(string s1, string s2) {
    int length1 = s1.size();
    int length2 = s2.size();
    for (int i = 0; i < length1; ++i)
        MaxLen[i][0] = 0;
    for (int i = 0; i < length2; ++i)
        MaxLen[0][i] = 0;

    for (int i = 1; i <= length1; ++i)
    {
        for (int j = 1; j <= length2; ++j)
        {
            if (s1[i - 1] == s2[j - 1]) {
                MaxLen[i][j] = MaxLen[i - 1][j - 1] + 1;
            }
            else
            {
                MaxLen[i][j] = max(MaxLen[i - 1][j], MaxLen[i][j - 1]);
            }
        }
    }

    return MaxLen[length1][length2];
}
int tecent_2017() {
    string str;
    while (cin >> str) {
        int len = str.size();
        if (len == 1) {
            cout << 1 << endl;
            continue;
        }

        string strrv = str;
        reverse(strrv.begin(), strrv.end());

        int mlen = maxlen(str, strrv);
        cout << len - mlen << endl;
    }
    return 0;
}

int tecent_20172() {
    string str;
    while (cin >> str) {
        int len = str.size();
        if (len == 1) {
            cout << 1 << endl;
            continue;
        }

        string strrv = str;
        reverse(strrv.begin(), strrv.end());

        int mlen = maxlen(str, strrv);
        cout << len - mlen << endl;
    }
    return 0;
}

int tecent_20173() {
    int n;
    while (cin >> n) {
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        int out1 = 0, out2 = 0;
        int out1count = 0;
        int out2count = 0;
        int out1count_max = INT_MIN;
        int out2count_max = 0;

        for (int i = 0; i < vec.size()-1; ++i) {
            if (vec[i+1]-vec[i] > out1count_max) {
                out1count_max = 1;
            }
            else if (vec[i + 1] - vec[i] == out1count_max) {
                out1count_max++;
            }

            if (vec[i + 1] - vec[i] < out2count_max) {
                out2count_max = 1;
            }
            else if(vec[i + 1] - vec[i] == out2count_max){
                out2count_max++;
            }
        }

        cout << out1 << " " << out2 << endl;
    }
    return 0;
}

int avg_len_of_string() {
    char strin[51];

    cin >> strin;

    int nszie = strlen(strin);

    int i = 1;
    int j = 0;
    int count = 1;
    vector<int>  vecl;
    for (; i < nszie; ++i) {
        if (strin[i] != strin[j]) {
            count++;
            vecl.push_back(i - j);
            j = i;
        }
    }

    if (i > j) {
        vecl.push_back(i - j);
    }

    int sum = accumulate(vecl.begin(), vecl.end(), 0);

    double res = (double)sum / count;
    cout << setprecision(3);
    cout << showpoint << (double)sum/count << endl;

    return 0;
}

int test_out() {
    string str;
    while (cin >> str) {

    }
    return 0;
}

int test_netease_2018() {
    //avg_len_of_string();
    //test_out();
    tecent_2017();
    return 0;
}