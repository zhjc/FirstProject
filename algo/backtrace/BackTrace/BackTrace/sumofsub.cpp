// ���� �Ӽ������� ���ݽⷨ

#include "config.h"
#include <cmath>
#include <iostream>

using namespace std;

int M = 30, n = 6; //MΪ�ܺͣ�nΪ�Ӽ���Ԫ�ظ���
int W[6] = { 5, 10, 12, 13, 15, 18 }; //����
bool X[6] = {}; //1Ϊѡ��0Ϊ��ѡ��
int flag = 0;

void SumSubSet(int s, int k, int r)
{
    int sum = 0;
    X[k] = 1;

    if (s+W[k] == M)
    {
        flag++;

        for (int i = 0; i < k+1; ++i)
        {
            cout << X[i] << " ";
        }

        cout << endl;

        for (int i = 0; i < k+1; ++i)
        {
            if (X[i] == 1)
            {
                cout << W[i] << " ";
                sum += X[i];
            }
        }

        cout << endl;

        sum = 0;
    }
    else if (s + W[k] + W[k+1] <= M)
    {
        SumSubSet(s + W[k], k + 1, r - W[k]);
    }

    if (s+r-W[k]>=M && s+W[k+1]<=M)
    {
        X[k] = 0;
        SumSubSet(s, k + 1, r - W[k]);
    }
}