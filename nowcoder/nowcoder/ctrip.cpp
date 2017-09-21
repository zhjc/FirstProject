
#include "commons.h"

class Ctrip {
public:
    /*
    两个已排好序的数组，找出两者合并后的数组的中位数。
    例如：
    给出A=[1,2,3,4,5,6]和B=[2,3,4,5]，它们合并后的数组是[1,2,3,4,5,6]，
    合并后数组的中位数是3.5(注：(3+4)/2)。
    给出A=[1,2,3]和B=[4,5]，它们合并后的数组是[1,2,3,4,5]，合并后数组的中位数是3。

    6
    1 2 3 4 5 6
    4
    2 3 4 5
    */
    int ctrip1_0() {
        int m;
        cin >> m;
        vector<int> vecm(m);
        for (int i = 0; i < m; ++i) {
            cin >> vecm[i];
        }
        int n;
        cin >> n;
        vector<int> vecn(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecn[i];
        }

        int len = m + n;
        if (len == 0) {
            cout << 0 << endl;
            return 0;
        }
        vector<int> vecres;
        int i = 0;
        int j = 0;
        while (i < m&&j < n) {
            if (vecm[i] > vecn[j]) {
                vecres.push_back(vecn[j++]);
            }
            else if (vecm[i] < vecn[j]) {
                vecres.push_back(vecm[i++]);
            }
            else {
                vecres.push_back(vecm[i++]);
                j++;
            }
        }

        while (i < m) {
            vecres.push_back(vecm[i++]);
        }

        while (j < n) {
            vecres.push_back(vecn[j++]);
        }

        double res = 0;

        if (vecres.size() % 2 == 0) {
            res = vecres[vecres.size() / 2];
            res += vecres[vecres.size() / 2 - 1];
            res /= 2.0;
        }
        else {
            res = vecres[vecres.size() / 2];
        }

        cout << res << endl;

        return 0;
    }

    int ctrip1() {
        int m, n, num;
        cin >> m;
        set<int> setNum;

        for (int i = 0; i < m; ++i) {
            cin >> num;
            setNum.insert(num);
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            setNum.insert(num);
        }

        vector<int> vecres(setNum.begin(), setNum.end());

        double res = 0;
        if (vecres.empty()) {
            cout << res << endl;
        }
        else if (vecres.size() % 2 == 0) {
            res = vecres[vecres.size() / 2];
            res += vecres[vecres.size() / 2 - 1];
            res /= 2.0;
        }
        else {
            res = vecres[vecres.size() / 2];
        }

        cout << res << endl;

        return 0;
    }

    /*请完成下面这个函数，实现题目要求的功能
    当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
    找出数组中没有出现的最小正整数
    ******************************开始写代码******************************/
    int findMinMis(vector < int > A) {
        sort(A.begin(), A.end());

        int i = 0;
        int n = 1;
        while (i<A.size()) {
            while (i<A.size() && A[i] <= 0) {
                i++;
            }
            if (i == A.size()) {
                break;
            }
            if (A[i] != n) {
                return n;
            }
            else {
                i++;
                n++;
            }
        }

        return n;
    }
    /******************************结束写代码******************************/


    int ctrip2() {
        int res;

        int _A_size = 0;
        cin >> _A_size;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        vector<int> _A;
        int _A_item;
        for (int _A_i = 0; _A_i < _A_size; _A_i++) {
            cin >> _A_item;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            _A.push_back(_A_item);
        }

        res = findMinMis(_A);
        cout << res << endl;

        return 0;
    }

    /* 删除重复出现的字符 */
    int ctrip3() {
        string str1;
        getline(cin, str1);

        string str2;
        vector<char> exist(256, -1);
        for (int i = 0; i < str1.size(); ++i) {
            if (exist[str1[i]]>0) {
                // nothing to do
            }
            else {
                str2.push_back(str1[i]);
                exist[str1[i]] = 1;
            }
        }

        cout << str2 << endl;

        return 0;
    }
};