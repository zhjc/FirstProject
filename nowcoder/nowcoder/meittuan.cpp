
#include <iostream>
#include <iomanip>

#include <string>

#include <numeric>
#include <algorithm>

#include <vector>
#include <map>
#include <set>

using namespace std;

class MeiTuan {
public:
    int getnum(int n, int k) {
        if (n < k) {
            return 0;
        }
        else if (n == k) {
            return 1;
        }
        else {
            return getnum(n - 6, k - 1) + getnum(n, k - 1);
        }
    }

    int prob1() {
        int n;
        cin >> n;

        if (n <= 0)return 0;

        int k = n>6 ? 6 : n;

        int res = getnum(n, k);

        cout << res << endl;
    }

    int prob2() {
        return 0;
    }

    int prob3() {
        int n;
        cin >> n;
        vector<int> vecarr(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecarr[i];
        }

        vector<vector<int> > vecmin(n, vector<int>(n, INT_MAX));
        vector<vector<int> > vecf(n, vector<int>(n, INT_MAX));

        vecmin[0][0] = vecarr[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i == j)vecmin[i][j] = vecarr[i];
                vecmin[i][j] = min(vecmin[i][j - 1], vecarr[j]);
            }
        }

        int res = 0;

        cout << res << endl;

        return 0;
    }

    // hk
    int GetLevel(string& name, string& ps) {
        if (ps.size()<8 || name == ps) {
            return 0;
        }

        string temp = ps;
        reverse(temp.begin(), temp.end());
        if (name == temp) {
            return 0;
        }

        bool hasNum = false;
        bool hasUpper = false;
        bool hasLower = false;
        bool hasOther = false;

        for (int i = 0; i < ps.size(); ++i) {
            if (ps[i] <= '9' && ps[i]>='0') {
                hasNum = true;
            }
            else if (ps[i] <= 'Z' && ps[i] >= 'A') {
                hasUpper = true;
            }
            else if (ps[i] <= 'z' && ps[i] >= 'a') {
                hasLower = true;
            }
            else {
                hasOther = true;
            }
        }

        if (hasNum&&!hasUpper&&!hasLower&&!hasOther ||
            !hasNum&&!hasUpper&&!hasLower&&hasOther ||
            !hasNum&&!hasUpper&&hasLower&&!hasOther ||
            !hasNum&&hasUpper&&!hasLower&&!hasOther) {
            return 0;
        }

        if (hasNum&&!hasUpper&&hasLower&&!hasOther ||
            hasNum&&hasUpper&&!hasLower&&!hasOther) {
            return 1;
        }

        if (hasNum&&!hasUpper&&!hasLower&&hasOther ||
            !hasNum&&hasUpper&&!hasLower&&hasOther ||
            !hasNum&&!hasUpper&&hasLower&&hasOther ||
            !hasNum&&hasUpper&&hasLower&&!hasOther) {
            return 2;
        }

        if (hasNum&&hasUpper&&hasLower&&!hasOther ||
            hasNum&&hasUpper&&!hasLower&&hasOther ||
            hasNum&&!hasUpper&&hasLower&&hasOther ||
            !hasNum&&hasUpper&&hasLower&&hasOther ||
            hasNum&&hasUpper&&hasLower&&hasOther) {
            return 3;
        }
    }

    int hkprob1() {
        string name;
        string pass;

        cin >> name >> pass;

        int res = GetLevel(name, pass);
        cout << res << endl;
        return 0;
    }

    int hkprob2_0() {
        string data;
        char tag;

        cin >> data >> tag;

        // abc,def,ghi,jkl ,
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == tag) {
                cout << endl;
            }
            else {
                cout << data[i];
            }
        }

        cout << endl;
        
        return 0;
    }

    int hkprob2_1() {
        string data;
        string tag;

        cin >> data >> tag;

        // abc,def,ghi,jkl ,
        string temp = data;

        string::size_type pos;
        string::size_type pre = 0;
        while ((pos = temp.find(tag))!=string::npos) {
            cout << temp.substr(pre, pos) << endl;
            temp = temp.substr(pos + 1);
        }

        cout << temp << endl;

        return 0;
    }

    int hkprob2_2() {
        string data;
        string tag;

        getline(cin, data);
        string::size_type tag_pos = data.find_last_of(' ');
        tag = data.substr(tag_pos + 1);

        // abc,def,ghi,jkl ,
        string temp = data.substr(0, tag_pos);

        string::size_type pos;
        string::size_type pre = 0;
        while ((pos = temp.find(tag)) != string::npos) {
            cout << temp.substr(pre, pos) << endl;
            temp = temp.substr(pos + 1);
        }

        cout << temp << endl;

        return 0;
    }

    int hkprob2() {
        string data;
        string tag;

        getline(cin, data);
        string::size_type tag_pos = data.find_last_of(' ');
        tag = data.substr(tag_pos + 1);

        // abc,def,ghi,jkl ,
        string temp = data.substr(0, tag_pos);

        string::size_type pos;
        while ((pos = temp.find(tag)) != string::npos) {
            cout << temp.substr(0, pos) << endl;
            temp = temp.substr(pos + tag.size());
        }

        cout << temp << endl;

        return 0;
    }

    int func_size(char p[256]) {
        cout << sizeof(p) << endl;
        cout << strlen(p) << endl;
        return 0;
    }

    int meituan1() {
        int n, m;
        cin >> n >> m;
        int k;

        vector<vector<int> > vecij(n, vector<int>(n, INT_MAX));

        int i1, i2, i3;
        for (int i = 0; i < m; ++i) {
            cin >> i1 >> i2 >> i3;
            //cin >> vecij[i][0] >> vecij[i][1] >> vecij[i][2];
            vecij[i1-1][i2-1] = i3;
        }
        cin >> k;
        vector<int> veccar(k);
        for (int i = 0; i < k; ++i) {
            cin >> veccar[i];
        }

        int start = 0;
        int stop = n - 1;

        vector<int> path(n, 0);
        vector<int> dist(n, INT_MAX);

        vector<bool> tag(n, false);

        // 利用迪杰斯特拉算法,结合共享单车求最短距离
        for (int i = 0; i < n; ++i)
        {
            dist[i] = vecij[start][i];
            tag[i] = false;
            if (dist[i] == INT_MAX)
                path[i] = 0;
            else
                path[i] = start;
        }
        dist[start] = 0;
        tag[start] = true;

        for (int i = 1; i < n; ++i)
        {
            int temp = INT_MAX;
            int u = start;
            for (int j = 0; j < n; ++j) {
                if ((!tag[j]) && dist[j] < temp)
                {
                    u = j;
                    temp = dist[j];
                }
            }
                
            tag[u] = true;
            for (int j = 0; j < n; ++j) {
                if ((!tag[j]) && vecij[u][j] < INT_MAX)
                {
                    int newdist = dist[u] + vecij[u][j];
                    if (newdist < dist[j])
                    {
                        dist[j] = newdist;
                        path[j] = u;
                    }
                }
            }
        }

        if (k > 0) {
            int dis = INT_MAX;
            for (int i = 0; i < k; ++i) {
                int temp = 0;
                if (dist[i]!=INT_MAX) {
                    // 取车
                    temp += dist[i];
                    temp += dist[i] / 2;
                    temp += dist[n - 1] / 2;
                    if (temp < dis) {
                        dis = temp;
                    }
                }
                else {
                    dis = (dist[n - 1] == INT_MAX) ? -1 : dist[n - 1];
                }
            }

            cout << dis << endl;
        }
        else {
            cout << (dist[n - 1]==INT_MAX) ? -1 : dist[n - 1];
        }

        return 0;
    }

    int MLC(int x, int y)
    {
        int z = y;
        while (x % y != 0)
        {
            z = x%y;
            x = y;
            y = z;
        }

        return z;
    }

    void combs(int n, int m, vector<int>& b, vector<vector<int> >& result) {

        for (long i = n; i >= m; i--) {

            b[m - 1] = i - 1;

            if (m > 1) {
                combs(i - 1, m - 1, b, result);
            }
            else {
                vector<int> temp;
                for (int i = b.size() - 1; i >= 0; i--) {
                    temp.push_back(b[i]);
                }
                result.push_back(temp);
            }
        }
    }

    int meituan2() {
        int n,K,A,B;
        cin >> n >> K >> A >> B;
        vector<int> vecarr(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecarr[i];
        }

        int res = 0;

        vector<vector<int> > results;

        combs(n, K, vecarr, results);

        for (int i = 0; i < results.size(); ++i) {
            vector<int>& temp = results[i];
            int X = 1;
            for (int j = 0; j < temp.size(); ++j) {
                X *= temp[j];
            }

            int mlc = MLC(X, A);
            if (mlc >= B) {
                res++;
            }
        }

        cout << res << endl;

        return 0;
    }
};

int test_meituan() {

    MeiTuan mt;
    //mt.prob3();
    //char p[256];
    mt.meituan2();

    return 0;
}