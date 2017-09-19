#pragma once
#include <iostream>

// test c pointer
int test_pointer()
{
    int a[5] = { 1,2,3,4,5 };

    int* ptr1 = (int*)(&a + 1);
    int* ptr2 = (int*)((int)a + 1);

    std::cout << ptr1[-1] << " " << *ptr2 << std::endl;

    return 0;
}

int FindSubString(char* pch)
{
    int count = 0;
    char * p1 = pch;
    while (*p1 != '\0')
    {
        if (*p1 == p1[1] - 1)
        {
            p1++;
            count++;
        }
        else {
            break;
        }
    }
    int count2 = count;
    while (*p1 != '\0')
    {
        if (*p1 == p1[1] + 1)
        {
            p1++;
            count2--;
        }
        else {
            break;
        }
    }
    if (count2 == 0)
        return(count);
    return(0);
}
void ModifyString(char* pText)
{
    char * p1 = pText;
    char * p2 = p1;
    while (*p1 != '\0')
    {
        int count = FindSubString(p1);
        if (count > 0)
        {
            *p2++ = *p1;
            //sprintf(p2, "%i", count);
            sprintf_s(p2, sizeof(pText), "%i", count);
            while (*p2 != '\0')
            {
                p2++;
            }
            p1 += count + count + 1;
        }
        else {
            *p2++ = *p1++;
        }
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void perm(int list[], int k, int m)
{
    if (k == m)
    {
        std::copy(list, list + m, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        return;
    }

    for (int i = k; i <= m; i++)
    {
        swap(&list[k], &list[i]);
        perm(list, k + 1, m);
        swap(&list[k], &list[i]);
    }
}