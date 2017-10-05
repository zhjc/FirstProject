
#include <iostream>
#include <iomanip>

#include <string>

#include <numeric>
#include <algorithm>

#include <vector>
#include <map>
#include <set>

using namespace std;

class SortAlgos {
public:
    // Ñ¡ÔñÅÅÐò

    // ²åÈëÅÅÐò

    // ¿ìËÙÅÅÐò

    // Ï£¶ûÅÅÐò

    // ¹é²¢ÅÅÐò
    void merge(int a[], int l, int m, int r) {
        int i, j;
        static int aux[4];

        for (i = m + 1; i > l; --i) {
            aux[i - 1] = a[i - 1];
        }

        for (j = m; j < r; ++j) {
            aux[r + m - j] = a[j + 1];
        }

        for (int k = l; k <= r; ++k) {
            if (aux[j]<aux[i]) {
                a[k] = aux[j--];
            }
            else {
                a[k] = aux[i++];
            }
        }
    }

    void merge_sort(int a[], int l, int r) {
        if (r<=l) {
            return;
        }

        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        merge(a, l, m, r);
    }

    // ¶ÑÅÅÐò

    // Í°ÅÅÐò
};

int test_sort_algo() {

    SortAlgos sa;
    int a[] = { 7,5,6,4 };
    sa.merge_sort(a, 0, 3);
    for (auto i : a) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}