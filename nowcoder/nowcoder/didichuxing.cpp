
#include "commons.h"

#include <sstream>

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

    // test 
    int test1() {
        int n;
        cin >> n;
        vector<int> vecn(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecn[i];
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + vecn[i] > sum) {
                sum += vecn[i];
            }
        }

        cout << sum << endl;

        return 0;
    }

    static bool cmpt2(pair<int, int>& a, pair<int, int>&b) {
        return a.second > b.second;
    }

    int test2() {
        int m, n;
        cin >> n >> m;
        vector<int> vecarg(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecarg[i];
        }

        vector<pair<int, int> > vecm(m);
        for (int i = 0; i < m; ++i) {
            cin >> vecm[i].first >> vecm[i].second;
        }

        sort(vecm.begin(), vecm.end(), cmpt2);
        sort(vecarg.begin(), vecarg.end());
        vector<bool> vectag(n, true);

        int res = 0;

        for (int i = 0; i < vecm.size(); ++i) {
            int num = vecm[i].first;
            int cons = vecm[i].second;

            int j = 0;

            // 首先找出消费最高的客人,安排到桌子上
            while (j<n&&vecarg[j]<num) {
                j++;
            }

            if (j==n) {
                int temp = n - 1;
                int times = num / n + 1;
                res += cons;
                while (true) {
                    if (times==0) {
                        break;
                    }

                    if (vectag[temp]) {

                    }
                    else {
                        vectag[i] = false;
                        times--;
                    }
                }
            }
            else {
                vectag[i] = false;
                res += cons;
            }
        }
        
        cout << res << endl;

        return 0;
    }

    struct point {
        int x;
        int y;

        point(int x_, int y_)
            :x(x_)
            ,y(y_)
        {

        };
    };

    vector<point> path;
    vector<point> vecbackup;
    vector<vector<int> > vecij;
    int cur_len = INT_MAX;

    bool getPath(int curi, int curj, int n, int m, int p) {
        if (curi<0|| curj<0||curj>=m||curi>=n||p<0||vecij[curi][curj]==0) {
            return false;
        }

        path.push_back(point(curi, curj));
        vecij[curi][curj] = 0;

        if (curi==0&&curj==m-1) {
            if (path.size() < cur_len) {
                cur_len = path.size();
                vecbackup.assign(path.begin(), path.end());
            }
            vecij[curi][curj] = 1;
            return true;
        }

        bool ret;
        ret = getPath(curi, curj + 1, n, m, p - 1);
        ret = getPath(curi + 1, curj, n, m, p) || ret;
        ret = getPath(curi - 1, curj, n, m, p - 3) || ret;
        ret = getPath(curi, curj - 1, n, m, p - 1) || ret;

        path.pop_back();

        vecij[curi][curj] = 1;

        return ret;
    }

    int test3() {
        int n, m, p;
        cin >> n >> m >> p;

        vecij.resize(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> vecij[i][j];
            }
        }

        if (getPath(0, 0, n, m, p)) {
            for (int i = 0; i < vecbackup.size(); ++i) {
                cout << "[" << vecbackup[i].x << "," << vecbackup[i].y << "]";
                if (i < vecbackup.size() - 1) {
                    cout << ",";
                }
            }
        }
        else {
            cout << "Can not escape!" << endl;
        }

        return 0;
    }

    int test4() {
        int n;
        cin >> n;

        if (n < 5) {
            cout << 0 << endl;
            return 0;
        }
        else {
            int res = 0;

            res += n / 5;
            res += n / 25;
            res += n / 125;
            res += n / 625;
            cout << res << endl;
        }

        return 0;
    }

    int test5() {
        int M, N;
        cin >> M >> N;

        int temp = M;
        vector<int> res;
        while (temp) {
            res.push_back(temp % N);
            temp /= N;
        }

        char arr[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

        for (int i = res.size() - 1; i >= 0; --i) {
            cout << arr[res[i]];
        }
        cout << endl;

        return 0;
    }

    int test6() {
        int n, m;
        cin >> n >> m;
        vector<int> vecn(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecn[i];
        }



        return 0;
    }
    // 最大连续子集和问题
    int maxSumSubsets(vector<int> vecn) {
        int len = vecn.size();
        int res = -1;
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; j++)
            {
                int sum = 0;
                for (int k = i; k < j; ++k) {
                    sum += vecn[k];
                }

                if (sum > res) {
                    res = sum;
                }
            }
        }

        return res;
    }

    int maxSumSubsets2(vector<int> vecn) {
        int len = vecn.size();
        int res = -1;
        vector<int> sum(len);
        sum[0] = vecn[0];

        for (int i = 1; i < len; ++i) {
            sum[i] = vecn[i] + sum[i - 1];
        }

        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; j++)
            {
                int temp = sum[j] - sum[i];

                if (temp > res) {
                    res = temp;
                }
            }
        }

        return res;
    }

    int maxSumSubsets4(vector<int> vecn) {
        int n = vecn.size();
        
        vector<int> dp(n);
        dp[0] = vecn[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(0, dp[i - 1]) + vecn[i];
        }

        int maxnum = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxnum) {
                maxnum = dp[i];
            }
        }

        //cout << maxnum << endl;

        return maxnum;
    }

    // 20170923
    void findLan(int row, int col, int m, int n, vector<vector<int> >& vecij, 
        vector<vector<bool> >& visited) {
        if (row<0||row>=m||col<0||col>=n|| vecij[row][col]==0 || visited[row][col]) {
            return;
        }

        visited[row][col] = true;

        findLan(row - 1, col, m, n, vecij, visited);
        findLan(row + 1, col, m, n, vecij, visited);
        findLan(row, col - 1, m, n, vecij, visited);
        findLan(row, col + 1, m, n, vecij, visited);
    }
    int GetNum(int row, int col, int m, int n, vector<vector<int> >& vecij) {
        
        int nums = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    findLan(i, j, m, n, vecij, visited);
                    if (vecij[i][j]==1) {
                        nums++;
                    }
                }
            }
        }

        return nums;
    }

    int newprob1() {
        int m, n, k;
        while (cin >> m) {
            cin >> n >> k;
            vector<vector<int> > vecij(m, vector<int>(n, 0));

            int row, col;
            for (int i = 0; i < k; ++i) {
                cin >> row >> col;

                vecij[row][col] = 1;

                int num = GetNum(row, col, m, n, vecij);
                cout << num;
                if (i<k-1) {
                    cout << " ";
                }
                else {
                    cout << endl;
                }
            }
        }

        return 0;
    }

    

    string bignum_float(char *str1, char *str2)
    {
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        int flnum = -1;
        int flnum2 = -1;
        char num1[1500] = { 0 };
        char num2[1500] = { 0 };
        int i, l;
        for (i = 0, l = 0; l < length1; i++, l++)
        {
            if (str1[l] == '.')
            {
                flnum++;
                i--;
                continue;
            }
            if (flnum != -1) flnum++;
            num1[i] = str1[l];
        }

        for (i = 0, l = 0; l < length2; i++, l++)
        {
            if (str2[l] == '.')
            {
                flnum2++;
                i--;
                continue;
            }
            if (flnum2 != -1) flnum2++;
            num2[i] = str2[l];
        }
        if (flnum != -1) length1 -= 1;
        if (flnum2 != -1) length2 -= 1;
        flnum = flnum + flnum2;
        char *res = (char *)malloc(sizeof(char)*(length1 + length2));
        memset(res, 0, sizeof(char)*(length1 + length2));
        for (i = length1 - 1; i >= 0; i--)
            for (l = length2 - 1; l >= 0; l--)
            {
                res[i + l + 1] += (num1[i] - '0')*(num2[l] - '0');
                res[i + l] += res[i + l + 1] / 10;
                res[i + l + 1] %= 10;
            }
        int count = 0;
        while (res[count] == 0)
        {
            count++;
        }
        char* ret = (char *)malloc(sizeof(char)*(length1 + length2 + 2));
        memset(ret, 0, sizeof(char)*(length1 + length2 + 2));
        for (int n = 0, l = 0, i = count; i < length1 + length2; l++, i++, n++)
        {
            if (n == length1 + length2 - count - flnum)
            {
                ret[l] = '.';
                i--;
                continue;
            }
            ret[l] = res[i] + '0';
        }

        string result(ret);

        free(res);
        free(ret);

        return result;
    }

    string GetPow(string d, int n) {
        string res = d;
        for (int i = 1; i < n; ++i) {
            res = bignum_float((char*)res.c_str(), (char*)d.c_str());
        }

        return res;
    }

    int newprob2() {
        double R;
        int n;

        while (cin >> R) {
            cin >> n;

            ostringstream os1;
            os1 << R;
            string strR = os1.str();
            string res = GetPow(strR, n);

            cout << res << endl;
        }

        return 0;
    }
};

int test_didichuxing() {
    Didichuxing di;
    //didi.didi();
    //string str1 = "6789";
    //string str2 = "5432";
    //string res = di.BigIntMultiply(str1, str2);
    //cout << res << endl;

    //di.test1();

    //int res = di.maxSumSubsets4(vector<int>({ 3,-1,2,1 }));
    //cout << res << endl;

    di.newprob2();

   // di.bignum_float("95.123", "95.123");

    return 0;
}