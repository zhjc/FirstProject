#pragma once
#include <iostream>

int test_pointer()
{
    int a[5] = { 1,2,3,4,5 };

    int* ptr1 = (int*)(&a + 1);
    int* ptr2 = (int*)((int)a + 1);

    std::cout << ptr1[-1] << " " << *ptr2 << std::endl;

    return 0;
}