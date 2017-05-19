
#include <vector>
#include <ctime>

#include <iostream>
#include <iomanip>
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

// ������Ŀ
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

// 1,...n-1��ѡ��m�����ظ��������
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

// �ֽ�������
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

// �ٶ��׾�-�ȶ��ܻؼ�
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

struct Point3{
    char color;
    int x,y,z;

    Point3(char c, int x_, int y_, int z_)
        : color(c)
        , x(x_)
        , y(y_)
        , z(z_) {}
};

double distance(const Point3& a, const Point3& b) {
    int dis_x = a.x - b.x;
    int dis_y = a.y - b.y;
    int dis_z = a.z - b.z;

    return sqrt(dis_x*dis_x + dis_y*dis_y + dis_z*dis_z);
}

bool isTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double areaOfTriangle(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

bool isSameColor(const Point3& p1, const Point3& p2, const Point3& p3) {
    return p1.color == p2.color && p2.color == p3.color;
}

bool isDiffColor(const Point3& p1, const Point3& p2, const Point3& p3) {
    return p1.color != p2.color&&p2.color != p3.color&&p3.color != p1.color;
}

int getMaxTriangle()
{
    int N;
    cin >> N;

    char color;
    int x;
    int y;
    int z;

    vector<Point3> vecPoints;

    for (int i=0; i<N; ++i)
    {
        cin >> color >> x >> y >> z;
        vecPoints.push_back(Point3(color, x, y, z));
    }

    int len = (int)vecPoints.size();

    double max_area = -1.0;
    double temp_area = 0.0;

    for (int i=0; i<len; ++i)
    {
        for (int j=i+1; j<len; ++j)
        {
            for (int k=j+1; k<len; ++k)
            {
                if (isSameColor(vecPoints[i], vecPoints[j], vecPoints[k]))
                {
                    double dis_i_j = distance(vecPoints[i], vecPoints[j]);
                    double dis_j_k = distance(vecPoints[j], vecPoints[k]);
                    double dis_k_i = distance(vecPoints[k], vecPoints[i]);

                    if (isTriangle(dis_i_j, dis_j_k, dis_k_i))
                    {
                        temp_area = areaOfTriangle(dis_i_j, dis_j_k, dis_k_i);
                        if (temp_area > max_area)
                        {
                            max_area = temp_area;
                        }
                    }
                }

                if (isDiffColor(vecPoints[i], vecPoints[j], vecPoints[k]))
                {
                    double dis_i_j = distance(vecPoints[i], vecPoints[j]);
                    double dis_j_k = distance(vecPoints[j], vecPoints[k]);
                    double dis_k_i = distance(vecPoints[k], vecPoints[i]);

                    if (isTriangle(dis_i_j, dis_j_k, dis_k_i))
                    {
                        temp_area = areaOfTriangle(dis_i_j, dis_j_k, dis_k_i);
                        if (temp_area > max_area)
                        {
                            max_area = temp_area;
                        }
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(5) << max_area << endl;

    return 0;
}

/*
�ȶ�����һ��N���������飬���뽫����Ӵ�С�ź��򣬵������ȵĶȶ���ֻ���������������
��ȡ�����е�һ����Ȼ������������������һ��λ�á�
�����ٲ������ٴο���ʹ�������С��������
��������:

��������һ��������N����������һ������N��������(N <= 50, ÿ�����ľ���ֵС�ڵ���1000)


�������:

���һ��������ʾ���ٵĲ���������

��������:

4
19 7 8 25

�������:

2
*/

// һ������,�ҳ����Է�Ϊ���ٸ��ǵ�����ǵݼ���������
int GetSortNum() {
    const int N = 9;
    //cin >> N;

    int numArr[N] = {1,2,3,1,2,3,1,2,3};

    int dst_cnt = 0;

    int direc = 0;
    for (int i = 0; i < N - 1; ++i) 
    {
        if (numArr[i] < numArr[i + 1]) 
        {
            if (direc == 0) 
            {
                direc = 1;
            }
            else if (direc == 1)
            {

            } 
            else 
            {
                // direc = -1
                direc = 0;
                dst_cnt++;
            }
        }
        else if (numArr[i] > numArr[i + 1]) 
        {
            if (direc == 0) 
            {
                direc = -1;
            }
            else if (direc == 1)
            {
                direc = 0;
                dst_cnt++;
            }
            else
            {

            }
        }
        else
        {

        }

    }


    cout << dst_cnt + 1 << endl;

    //delete[] numArr;

    return 0;
}

bool cmp_m(int a, int b) {
    return a > b;
}
// ����ͨ��60%
int GetMaxLevel() {
    const int N = 2;
    //cin >> N;

    // 3*N��ѡ��,�ֳ�N��,ÿ��3��,�����ˮƽΪ���ڵڶ��ߵ�ˮƽ,���������ˮƽ���ĺ�ֵ
    int numArr[3*N] = { 5,2,8,5,1,5 };

    int max_level = 0;

    vector<int> vecNum(numArr, numArr + 3 * N);

    sort(vecNum.begin(), vecNum.end(), cmp_m);

    for (int i=1; i<2*N; i=i+2)
    {
        max_level += vecNum[i];
    }

    cout << max_level << endl;

    return 0;
}
// ����ͨ��90%
int GetMaxSubLen() {
    const int N = 6;
    //cin >> N;

    // ��������,���ֻ����һ����,ʹ��Ϊ�ϸ��������,�ҳ����������
    // ����6  \n  7,2,3,1,5,6   ���5
    int numArr[N] = { 7,2,3,1,5,6 };

    int max_len = -1;

    for (int i = 1; i < N - 1; ++i)
    {
        if (numArr[i - 1] > numArr[i] && numArr[i]<numArr[i + 1] && numArr[i + 1]>numArr[i - 1])
        {
            int cur_i = i;
            // backword
            int k = i;
            for (; k<N-1; ++k)
            {
                if (numArr[k + 1] <= numArr[k])
                {
                    break;
                }
            }

            // forward
            int j = i - 1;
            for (; j>0; --j)
            {
                if (numArr[j-1] >= numArr[j])
                {
                    break;
                }
            }

            if (k - j + 1 > max_len)
            {
                max_len = k - j + 1;
            }
        }

    }

    cout << max_len << endl;

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
    //GetDis();
    //getMaxTriangle();
    //GetMaxLevel();
    GetMaxSubLen();
    return 0;
}