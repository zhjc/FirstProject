
#include "commons.h"
#include <bitset>

class LeetCode1 {
public:
    // problem 78
    vector<vector<int> > SubSets(vector<int> nums) {
        vector<vector<int> > res;

        int all = pow(2, nums.size());
        for (int i = 0; i < all; ++i) {
            int cur = i;

            bitset<32> bs(cur);
            vector<int> temp;
            for (int j = 0; j < 32; ++j) {
                if (bs[j] == 1) {
                    temp.push_back(nums[j]);
                }
            }

            res.push_back(temp);
        }

        return res;
    }

    double GetSqrt3() {
        double left = 1;
        double right = 3;

        double target = 2;

        while (abs(right-left) > 0.00001) {
            left = (left + target / left) / 2;
            right = (target / right + right) / 2;
        }

        return (right + left) / 2;
    }
};

int test_leetcode1() {
    LeetCode1 lc1;
    /*vector<vector<int> > res = lc1.SubSets(vector<int>({1,2,3}));
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }

        cout << "]\n";
    }*/

    cout << lc1.GetSqrt3() << endl;

    return 0;
}