
// 经典 8-皇后问题 回溯解法

#include "config.h"
#include <cmath>
#include <iostream>

const int NUM_OF_QUEEN = 8;

ALBOOL isPlace(int k, int x[])
{
    for (int i = 1; i < k; ++i)
    {
        if (x[i]==x[k] || abs(x[i]-x[k])==abs(i-k))
        {
            return AL_FALSE;
        }
    }

    return AL_TRUE;
}

void nQueen()
{
    int k = 1; // k是当前行
    int x[NUM_OF_QUEEN+1]; // x[k]是当前列
    int nResult = 0;

    x[0] = x[1] = 0;

    while (k>0)
    {
        x[k] += 1;
        while (x[k]<=NUM_OF_QUEEN && isPlace(k,x)==AL_FALSE)
        {
            x[k] += 1;
        }

        if (x[k] <= NUM_OF_QUEEN)
        {
            if (k == NUM_OF_QUEEN)
            {
                // 完整解,输出
                std::cout << "Result " << nResult << ":" << std::endl;
                for (int i = 0; i < NUM_OF_QUEEN; ++i)
                {
                    std::cout << x[i+1] << " ";
                }

                std::cout << std::endl;
                nResult++;
                //return;
            }
            else
            {
                k += 1;
                x[k] = 0;
            }
        }
        else
        {
            k -= 1; // 回溯
        }
    }

    std::cout << std::endl << "Find " << nResult << " result." << std::endl;
}