
#include <vector>
#include <ctime>

#include <iostream>

#include "head.h"

#include<set>
using namespace std;

struct cmp_
{
    bool operator()(const int& a, const int& b)const
    {
        return a < b;
    }
};

// 网易题目
int getThird(void) {
    int N;
    cin >> N;

    if (N < 3) {
        cout << -1 << endl;
        return 0;
    }

    set<int, cmp_> h;

    int* numArr = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> numArr[i];
    }

    for (int i = 0; i < N; ++i) {
        h.insert(numArr[i]);
    }

    if (h.size() < 3) {
        cout << -1 << endl;
        return 0;
    }

    h.erase(h.begin());
    h.erase(h.begin());

    cout << *h.begin() << endl;

    delete[] numArr;

    return 0;
}

// 1,...n-1中选择m个不重复的随机数
vector<int> knuth(int n, int m)
{
    vector<int> output;
    srand((unsigned int)time(NULL));

    for (int i=0; i<n; ++i)
    {
        if (rand() % (n-i) < m)
        {
            output.push_back(i);
            m--;
        }
    }

    return output;
}

// 分解质因数
vector<int> prim(int m, int n)
{
    vector<int> output;

    if (m >= n)
    {
        while (m % n)
        {
            n++;
        }

        m /= n;

        prim(m, n);

        cout << n << " ";

        //output.push_back(n);
    }

    return output;
}

int GetDis() {
    int N;
    cin >> N;

    int* numArr = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> numArr[i];
    }

    int dis = 0;

    int min_dis = 10000000;

    int ignore = -1;
    for (int i = 1; i < N - 1; ++i)
    {
        ignore = i;

        dis = 0;
        for (int j = 0; j < N - 1; ++j)
        {
            if (j + 1 == ignore)
            {
                dis += abs(numArr[j + 2] - numArr[j]);
                j++;
            }
            else
            {
                dis += abs(numArr[j + 1] - numArr[j]);
            }

        }
        if (dis < min_dis)
        {
            min_dis = dis;
        }
    }

    cout << min_dis << endl;

    delete[] numArr;
    return 0;
}

int main(int argc, char* argv[])
{
    //vector<int> vec_output = knuth(20, 5);
    /*char q_ = 'Q';

    auto n = 10;

    char serdat[]{ "heheh" };
    char serdat1[] = { "heheh" };

    int m = 10; 
    cout << int('Q') << " " << m+n+q_ << endl;*/

    /*char text[32] = "XYBCDCBABABA";
    ModifyString(text);
    printf(text);*/

   /* int list[] = { 1,2,3,4 };
    perm(list, 0, 3);*/

    //getThird();
    GetDis();
    return 0;
}