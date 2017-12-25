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

    /*
    ������������a��b��c������Ҫ������2a+2b-2c�ڶ����Ʊ�ʾ��1�ĸ�����
    ��һ�а�����������a,b,c��1��c��b��a��10^9

    3 2 1�� ���Ϊ10
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
    ��Ŀ������
����һ���Ǹ����� n�����ǿ����ø��ֽ�������ʾ��������˵�� 23������ʮ���Ʊ�ʾ�¾��� 23���ڶ����Ʊ�ʾ���� 10111���ڰ˽��Ʊ�ʾ���� 27����ʮ�����Ʊ�ʾ�� 1B(B ��ʾ 11)�� n ��ĳ�ֽ��Ʊ�ʾ�µ�ȨֵΪ�����λ������ӵĺͣ����� 23 �ڶ����Ʊ�ʾ�µ�ȨֵΪ1+0+1+1+1=4��23 �ڰ˽��Ʊ�ʾ�µ�ȨֵΪ 2+7=9��23 ��ʮ�����Ʊ�ʾ�µ�ȨֵΪ1+11=12��

���ڸ���һ���Ǹ�����n���������p����ȥ��ʾ��(2 ��p��n )��ͬʱ��Ҫʹ���������ֽ��Ʊ�ʾ�µ�Ȩֵ���
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
    ���Ĵ����������Ŷ����Ƿ��Ŷ���һ�����ַ��������硰level�����ߡ�noon�����ǻ��Ĵ���
����ĳ��ʮ���ƷǸ�����N��ת���ɶ����ƺ�õ��� 01 ���о��л��Ĵ������ʣ���Ƹ���Ϊ������������ʮ���ƷǸ����� 9 ��ʾ�ɶ����ƺ�õ� 1001����1001�����л��Ĵ������ʣ����ʮ�������� 9 Ϊ��������
�ָ���һ��ʮ��������N�������С�ڵ���N�Ļ�������������
input:��һ�а���һ������N, 1 ��N��10^18
output:���һ������M����ʾС�ڵ��� N �Ļ�����������
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