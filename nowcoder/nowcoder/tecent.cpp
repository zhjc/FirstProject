#include <iostream>
#include <iomanip>

#include <string>
#include <numeric>
#include <algorithm>

#include <vector>
#include <cmath>
#include <map>
#include <set>

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
};

int test_tecent() {
    Tecent tc;
    //tc.coins_methos(6);
    return 0;
}