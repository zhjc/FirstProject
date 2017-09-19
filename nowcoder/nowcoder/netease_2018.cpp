#include <iostream>
#include <iomanip>

#include <string>

#include <numeric>
#include <algorithm>

#include <vector>
#include <map>
#include <set>

#include <stack>

using namespace std;

const int MAX_LEN = 1001;
int MaxLen[MAX_LEN][MAX_LEN];

class Netease2018 {
public:
    
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

            for (int i = 0; i < vec.size() - 1; ++i) {
                if (vec[i + 1] - vec[i] > out1count_max) {
                    out1count_max = 1;
                }
                else if (vec[i + 1] - vec[i] == out1count_max) {
                    out1count_max++;
                }

                if (vec[i + 1] - vec[i] < out2count_max) {
                    out2count_max = 1;
                }
                else if (vec[i + 1] - vec[i] == out2count_max) {
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
        cout << showpoint << (double)sum / count << endl;

        return 0;
    }

    int test_out() {
        string str;
        while (cin >> str) {

        }
        return 0;
    }


    int main0916() {
        int n;
        cin >> n;

        while (n--) {
            string str;
            cin >> str;

            int hh;
            int mm;
            int ss;

            hh = (str[0] - '0') * 10 + (str[1] - '0');
            mm = (str[3] - '0') * 10 + (str[4] - '0');
            ss = (str[6] - '0') * 10 + (str[7] - '0');

            bool invalid = false;
            if (hh < 24 && hh >= 0) {
                cout << str[0] << str[1] << ":";
            }
            else {
                invalid = true;
                cout << "0" << str[1] << ":";
            }

            if (mm < 60 && mm >= 0) {
                cout << str[3] << str[4] << ":";
            }
            else {
                invalid = true;
                cout << "0" << str[4] << ":";
            }

            if (ss < 60 && ss >= 0) {
                cout << str[6] << str[7];
            }
            else {
                invalid = true;
                cout << "0" << str[7];
            }

            if (!invalid) {
                //cout << str << endl;
                cout << endl;
            }
            else {
                cout << endl;
            }
        }

        return 0;
    }

    int Isvalid(int i, int j, int m, int n, vector<string>& arr, string& target) {
        if (arr[i][j] == target[0]) {
            int nsize = target.size();
            int count = 0;

            // down
            int temp = i + 1;
            int idx = 1;
            while (temp < m && idx < nsize) {
                if (arr[temp++][j] != target[idx++]) {
                    break;
                }
            }
            if (idx == nsize) {
                count++;
            }

            // right
            temp = j + 1;
            idx = 1;
            while (temp < n && idx < nsize) {
                if (arr[i][temp++] != target[idx++]) {
                    break;
                }
            }
            if (idx == nsize) {
                count++;
            }

            // down-right
            int tempi = i + 1;
            int tempj = j + 1;
            idx = 1;
            while (tempi < m && tempj < n && idx < nsize) {
                if (arr[tempi++][tempj++] != target[idx++]) {
                    break;
                }
            }
            if (idx == nsize) {
                count++;
            }

            return count;
        }
        else {
            return 0;
        }
    }

    int main09162() {
        int k;
        cin >> k;

        while (k--) {
            int m, n;
            cin >> m >> n;
            vector<string> vecarr(m);
            for (int i = 0; i < m; ++i) {
                cin >> vecarr[i];
            }

            string str;
            cin >> str;

            int res = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    res += Isvalid(i, j, m, n, vecarr, str);
                }
            }

            cout << res << endl;
        }

        return 0;
    }

    struct DataNode {
        int flow;
        string times;
    };

    string convert_(string& date_, string& time_) {
        string strres;

        strres += date_.substr(6, 4);
        strres += date_.substr(0, 2);
        strres += date_.substr(3, 2);

        strres += time_;

        return strres;
    }

    int main09163() {
        int m, n;
        cin >> m;

        vector<DataNode> vecdata(m);

        string date_, time_;
        int flow_;
        for (int i = 0; i < m; ++i) {
            cin >> date_ >> time_;
            cin >> flow_;
            vecdata[i].flow = flow_;
            vecdata[i].times = convert_(date_, time_);
        }

        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> date_ >> time_;
            string time_be = convert_(date_, time_);
            cin >> date_ >> time_;
            string time_en = convert_(date_, time_);
            int sum = 0;
            for (int i = 0; i < vecdata.size(); ++i) {
                if (vecdata[i].times <= time_en && vecdata[i].times >= time_be) {
                    sum += vecdata[i].flow;
                }
            }
            cout << sum << endl;
        }

        return 0;
    }
#define MAX_NUM 60000
    int main09164() {
        int n;
        cin >> n;
        while (n--)
        {
            int hp, atk, cd;
            cin >> hp >> atk >> cd; // 1<=cd<=10
            int x1, x2, x3;
            cin >> x1 >> x2 >> x3;
            int hp1, y1, hp2, y2, hp3, y3;
            cin >> hp1 >> y1 >> hp2 >> y2 >> hp3 >> y3;

            //int rest = -1;

            int max_x = x1 > x2 ? (x1 > x3 ? x1 : x3) : (x2 > x3 ? x2 : x3);

            int secs = 0;

            int coldtime = 0;
            while (true) {
                int harm = 0;

                if (hp1 > 0 && hp1 < 50001) {
                    harm += y1;
                }
                if (hp2 > 0 && hp2 < 50001) {
                    harm += y2;
                }
                if (hp3 > 0 && hp3 < 50001) {
                    harm += y3;
                }

                if (hp1 > 0 && hp1 < 50001) {
                    if (coldtime == 0) {
                        hp1 -= max_x;
                        coldtime = cd;
                    }
                    else {
                        hp1 -= atk;
                    }
                }
                else if (hp2 > 0 && hp2 < 50001) {
                    if (coldtime == 0) {
                        hp2 -= max_x;
                        coldtime = cd;
                    }
                    else {
                        hp2 -= atk;
                    }
                }
                else if (hp3 > 0 && hp3 < 50001) {
                    if (coldtime == 0) {
                        hp3 -= max_x;
                        coldtime = cd;
                    }
                    else {
                        hp3 -= atk;
                    }
                }
                else {
                    cout << hp - harm << endl;
                    break;
                }



                hp -= harm;
                if (hp <= 0) {
                    cout << -1 << endl;
                    break;
                }

                if (hp1 <= 0) {
                    coldtime = 0;
                    hp1 = MAX_NUM;
                }
                if (hp2 <= 0) {
                    coldtime = 0;
                    hp2 = MAX_NUM;
                }
                if (hp2 <= 0) {
                    coldtime = 0;
                    hp3 = MAX_NUM;
                }

                coldtime--;

                secs++;
            }
        }

        return 0;
    }

    int main09165() {
        int n;
        cin >> n;

        char data[150001];
        while (n--) {
            cin >> data;
            int val = 0;
            int op = -1;
            int left = 0;
            int right = 0;
            bool flag = true;
            for (int i = 0; i < strlen(data); ++i) {
                if (data[i] == '(') {

                }
                else if (data[i] == '|') {
                    op = 1;
                }
                else if (data[i] == '&') {
                    op = 2;
                }
                else if (data[i] == ')') {
                    if (op == 1) {
                        val = left | right;
                    }
                    else if (op == 2) {
                        val = left & right;
                    }
                }
                else {
                    if (flag) {
                        left = data[i];
                    }
                    else {
                        right = data[i];
                    }
                    flag = !flag;
                }
            }
        }

        return 0;
    }

    bool StartWith(string& str1, string& str2) {
        for (int i = 0; i < str2.size(); ++i) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }

        return true;
    }

    int souhu1() {
        string str;
        cin >> str;

        string temp = str;
        int pos = 0;
        while ((pos = temp.find("//")) != string::npos) {
            temp.replace(pos, 2, "/");
        }

        while ((pos = temp.find(" ")) != string::npos) {
            temp.replace(pos, 1, "");
        }

        cout << temp << endl;

        stack<string> stc;
        //stc.push("/");

        int len = temp.size();
        int i = 0;
        while (true) {
            pos = temp.find("/", 1);
            if (pos != string::npos) {
                if (StartWith(temp, string("/../"))) {
                    stc.pop();
                }
                else if (StartWith(temp, string("/./"))) {

                }
                else {
                    stc.push(temp.substr(0, pos));
                }

                temp = temp.substr(pos);
            }
            else {
                if (!temp.empty()) {
                    stc.push(temp.substr(1));
                }
                break;
            }
        }

        string res;
        while (!stc.empty()) {
            res = stc.top() + res;
            stc.pop();
        }

        if (!res.empty() && res[0] != '/') {
            res = "/" + res;
        }

        cout << res << endl;

        return 0;
    }

    int souhu2() {
        int n;
        cin >> n;

        vector<int> vecarr(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecarr[i];
        }

        int sum = accumulate(vecarr.begin(), vecarr.end(), 0);

        int nsize = vecarr.size();
        bool oddnum = n % 2 == 1;

        int i = 0;
        int j = nsize - 1;

        int ins = 0;
        while (i < j) {
            if (i + 1 == j&&oddnum) {
                break;
            }

            if (vecarr[i] != vecarr[j]) {
                if (vecarr[i]>vecarr[j]) {
                    ins += vecarr[j];
                    j--;
                }
                else {
                    ins += vecarr[i];
                    i++;
                }
            }
            else {
                i++;
                j--;
            }
        }

        cout << sum + ins << endl;

        return 0;
    }

    int test_classic() {
        short a[10];
        cout << sizeof(a) << endl;

        return 0;
    }
};

int test_netease_2018() {
    Netease2018 ne2018;

    ne2018.test_classic();

    return 0;
}