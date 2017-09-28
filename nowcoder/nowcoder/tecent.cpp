#include <iostream>
#include <iomanip>

#include <string>
#include <numeric>
#include <algorithm>

#include <vector>
#include <cmath>
#include <map>
#include <set>

#include <bitset>

using namespace std;

class Tecent {
    vector<int> veccoin;
public:
    int coins_methos(int n)
    {
        int nums = 0;

        int k = 0;
        int temp;
        while ((temp = pow(2, k))<n) {
            veccoin.push_back(temp);
            k++;
        }

        nums = GetMethods(n, k - 1);

        return nums;
    }

    int GetMethods(int n, int k) {
        //return GetMethods(n - veccoin[k], k - 1);
        return 0;
    }

    /*
    给出一个n个节点的无向图，所有节点之间都有通路，通路的权值都是0-9，
    起点在0号节点，目标是1号节点。有一个附加条件，你可以使k条边的权值减半，求最短路径
    */
    int prob1_2018() {
        int n, k;
        cin >> n >> k;



        return 0;
    }

    /*
    你有很多硬币，面额为1，2，4，8，....，2^k，每种面额的硬币有两个,
    要求凑出n元来，输出不同的凑硬币方案的数目
    */
    int prob2_2018() {

        return 0;
    }

    /*
    输入4个数，a,b,A,B，可以对a,b进行两种操作，同时加1，或者乘2.
    目标是使a==A，b==B，输出操作的最小次数
    case: 100 1000 202 2002
    */
    int prob3_2018() {

        int a, b, A, B;
        cin >> a >> b >> A >> B;

        int res = 0;

        while (a!=A&&b!=B) {

        }
        cout << res << endl;

        return 0;
    }

    /*
    给出三个整数a，b，c，你需要计算数2a+2b-2c在二进制表示下1的个数。
    第一行包含三个整数a,b,c。1≤c＜b＜a≤10^9

    3 2 1， 结果为10
    2
    */
    int webank1() {
        int a, b, c;
        cin >> a >> b >> c;

        // a > b > c
        cout << 2 << endl;

        return 0;
    }

    /*
    题目描述：
给出一个非负整数 n，我们可以用各种进制来表示它。比如说数 23，它在十进制表示下就是 23，在二进制表示下是 10111，在八进制表示下是 27，在十二进制表示下 1B(B 表示 11)。 n 在某种进制表示下的权值为将其各位数字相加的和，比如 23 在二进制表示下的权值为1+0+1+1+1=4，23 在八进制表示下的权值为 2+7=9，23 在十二进制表示下的权值为1+11=12。

现在给出一个非负整数n，你可以用p进制去表示它(2 ≤p≤n )，同时你要使得它在这种进制表示下的权值最大。
    */
    int webank2() {
        int n;
        cin >> n;

        int sum_max = -1;
        int sum = 0;

        for (int i = 2; i < n; ++i) {
            int temp = n;
            sum = 0;
            while (temp) {
                sum += temp % i;
                temp /= i;
            }

            if (sum > sum_max) {
                sum_max = sum;
            }
        }

        cout << sum_max << endl;

        return 0;
    }

    /*
    回文串是无论正着读还是反着读都一样的字符串，比如“level”或者“noon”就是回文串。
若将某个十进制非负整数N，转换成二进制后得到的 01 序列具有回文串的性质，则称该数为回文数，比如十进制非负整数 9 表示成二进制后得到 1001，“1001”具有回文串的性质，则称十进制整数 9 为回文数。
现给你一个十进制整数N，请计算小于等于N的回文数的数量。
input:第一行包含一个整数N, 1 ≤N≤10^18
output:输出一个整数M，表示小于等于 N 的回文数的数量
    */
    bool IsHuiWen(int n) {
        bool flag = true;
        vector<int> vecnum;

        while (n) {
            vecnum.push_back(n % 2);
            n /= 2;
        }

        int len = vecnum.size() - 1;
        for (int j = 0; j < vecnum.size() / 2; ++j) {
            if (vecnum[j] != vecnum[len - j]) {
                flag = false;
                break;
            }
        }

        return flag;
    }

    int webank3() {
        int n;
        cin >> n;

        if (n <= 2) {
            return 2;
        }

        vector<int> vecnum;
        int len = 0;

        int temp = n;
        while (temp) {
            vecnum.push_back(temp % 2);
            temp /= 2;
        }

        len = vecnum.size();
        int sum = 3; // 0 and 1
        for (int i = 3; i <= len; ++i) {
            sum += pow(2, (i - 1) / 2);
        }

        int maxn = pow(2, len) - 1;
        vector<int> vecmax(len, 1);
        for (int i = n + 1; i <= maxn; ++i) {
            int temp = i;
            if (temp % 2 == 0) {
                continue;
            }
            else {
                if (IsHuiWen(temp)) {
                    sum--;
                }
            }
        }

        cout << sum << endl;

        return 0;
    }
};

int test_tecent() {
    Tecent tc;
    //tc.coins_methos(6);
    tc.webank3();
    return 0;
}