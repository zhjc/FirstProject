#include<iostream>
#include<vector>
#include<algorithm>
#include <set>

using namespace std;

/*
36
7 -15 31 49 -44 35 44 -47 -23 15 -11 10 -21 10 -13 0 -20 -36 22 -13 -39 -39 -31 -13 -27 -43 -6 40 5 -47 35 -8 24 -31 -24 -1
3 31

108241

6
2 4 6 3 5 1
3 2

120

*/

struct node
{
    int id;
    int val;

    node(int id, int val) :id(id), val(val) {}
};

bool cmp(const node& a, const node& b) {
    return a.id < b.id;
}

int n_abs(int a) {
    return a > 0 ? a : -a;
}

static int cal(int a[], int l, int r, set<int>& select) {
    int max_ = -100;
    int idx = l;
    for (int i = l; i <= r; ++i) {
        if (a[i] > max_ && select.count(i)==0) {
            max_ = a[i];
            idx = i;
        }
    }

    return idx;
}

int cal_muti(vector<node>& vecarr, int l, int r) {
    int res = 1;
    for (int i = l; i <= r; ++i) {
        res *= vecarr[i].val;
    }

    return res;
}

int netease1()
{
    int n, k, d;
    cin >> n;
    vector<int> vecarr(n);
    for (int i = 0; i < n; ++i) {
        cin >> vecarr[i];
    }

    cin >> k >> d;

    int res = 1;

    if (n < d) {
        sort(vecarr.begin(), vecarr.end());
        for (int i = vecarr.size() - 1; i >= 0; --i) {
            if (k==0) {
                break;
            }
            res *= vecarr[i];
            k--;
        }
    }
    else {
        vector<node> vectemp;
        set<int> select;
        int idx = 0;
        for (int i = 0; i < k || idx + d<n; ++i) {
            idx = cal(&vecarr[0], idx - d<0 ? 0 : idx - d, idx + d>n - 1 ? n - 1 : idx + d, select);
            vectemp.push_back(node(idx, vecarr[idx]));
            select.insert(idx);
        }

        if (vectemp.size() == k) {
            for (int i = vecarr.size() - 1; i >= 0; --i) {
                if (k == 0) {
                    break;
                }
                res *= vecarr[i];
                k--;
            }
        }
        else
        {
            res = 0;
            sort(vectemp.begin(), vectemp.end(), cmp);
            for (int i = 0; i < vectemp.size()-k; ++i) {
                int temp = cal_muti(vectemp, i, i + k);
                if (temp > res) {
                    res = temp;
                }
            }
        }
    }
    
    cout << res << endl;
    return 0;
}

int test_netease()
{
    netease1();
    return 0;
}