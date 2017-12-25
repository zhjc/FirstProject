
#include "commons.h"

class TouTiao {

public:
    int dynamicBinarySearch(int a[], int n, int x) {
        int L, R;

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] < x) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        L = l;

        l = 0, r = n - 1;
        /*while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < x) {
                l = m;
            }
            else {
                r = m;
            }
        }*/
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] > x) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        R = r;

        if (L > R) {
            L = R = -1;
        }

        cout << "[" << L << " " << R << "]\n";

        return 0;
    }

    
};

int test_toutiao() {
    TouTiao tt;
    int a[] = { 1,4,6,6,6,7,7,9 };
    tt.dynamicBinarySearch(a, 8, 4);
    return 0;
}