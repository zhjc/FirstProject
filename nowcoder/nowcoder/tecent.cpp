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
    ����һ��n���ڵ������ͼ�����нڵ�֮�䶼��ͨ·��ͨ·��Ȩֵ����0-9��
    �����0�Žڵ㣬Ŀ����1�Žڵ㡣��һ�����������������ʹk���ߵ�Ȩֵ���룬�����·��
    */
    int prob1_2018() {
        int n, k;
        cin >> n >> k;



        return 0;
    }

    /*
    ���кܶ�Ӳ�ң����Ϊ1��2��4��8��....��2^k��ÿ������Ӳ��������,
    Ҫ��ճ�nԪ���������ͬ�Ĵ�Ӳ�ҷ�������Ŀ
    */
    int prob2_2018() {

        return 0;
    }

    /*
    ����4������a,b,A,B�����Զ�a,b�������ֲ�����ͬʱ��1�����߳�2.
    Ŀ����ʹa==A��b==B�������������С����
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