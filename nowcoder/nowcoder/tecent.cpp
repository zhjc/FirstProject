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
        return GetMethods(n - veccoin[k], k - 1);
    }
};

int test_tecent() {
    Tecent tc;
    tc.coins_methos(6);
    return 0;
}