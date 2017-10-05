
#include <iostream>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <numeric>

#include <vector>
#include <map>
#include <set>

#include <queue>
#include <stack>
#include <deque>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

bool cmp_find(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class OfferSolution {
public:

    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() != 5)return false;

        sort(numbers.begin(), numbers.end());

        int numofzero = 0;
        int interval = 0;

        for (int i = 0; i < numbers.size() - 1; ++i) {
            if (numbers[i] == 0) {
                numofzero++;
                continue;
            }

            if (numbers[i] == numbers[i + 1]) {
                return false;
            }

            interval += numbers[i + 1] - numbers[i] - 1;
        }

        if (interval <= numofzero) {
            return true;
        }

        return false;
    }

    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        sort(data.begin(), data.end());

        int seq = 0;

        for (int i = 0; i < data.size() - 1; i++) {
            if (data[i] != data[i + 1]) {
                if (i == 0) {
                    *num1 = data[i];
                    seq++;
                }
                else {
                    if (data[i - 1] != data[i]) {
                        if (i + 1 == data.size() - 1) {
                            *num1 = data[i];
                            *num2 = data[i + 1];
                            return;
                        }
                        else {
                            if (seq == 0) {
                                *num1 = data[i];
                                seq++;
                            }
                            else {
                                *num2 = data[i];
                                return;
                            }
                        }
                    }
                    else {
                        if (i + 1 == data.size() - 1) {
                            *num2 = data[i + 1];
                            return;
                        }
                    }
                }
            }
        }
    }

    vector<int> multiply(const vector<int>& A) {
        // violence method
        vector<int> vecres(A.size());

        for (int i = 0; i < A.size(); ++i) {
            vecres[i] = 1;
            for (int j = 0; j < A.size(); ++j) {
                if (i == j) {
                    continue;
                }

                vecres[i] *= A[j];
            }
        }

        return vecres;
    }

    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > vecres;
        if (pRoot == NULL) {
            return vecres;
        }

        queue<TreeNode*> que;

        que.push(pRoot);

        bool even = false;

        while (!que.empty()) {
            int quesize = que.size();
            vector<int> temp;

            for (int i = 0; i < quesize; ++i) {
                TreeNode* cur = que.front();
                temp.push_back(cur->val);
                que.pop();

                if (cur->left) {
                    que.push(cur->left);
                }

                if (cur->right) {
                    que.push(cur->right);
                }
            }

            if (even) {
                reverse(temp.begin(), temp.end());
            }

            vecres.push_back(temp);

            even = !even;
        }

        return vecres;
    }

    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* cur = pHead;
        if (cur == NULL || pHead->next == NULL) {
            return cur;
        }

        int head_num = -1;
        if (head_num == pHead->val) {
            head_num = -2;
        }
        ListNode* head_ = new ListNode(head_num);
        head_->next = pHead;

        ListNode* p = head_;
        ListNode* q = head_->next;

        while (q) {
            while (q->next && q->val==q->next->val) {
                q = q->next;
            }

            if (p->next != q) {
                q = q->next;
                p->next = q;
            }
            else {
                p = q;
                q = q->next;
            }
        }

        return head_->next;
    }

    string ReverseSentence(string str) {
        string strres, strtmp;

        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                strres = " " + strtmp + strres;
                strtmp = "";
            }
            else {
                strtmp += str[i];
            }
        }

        if (!strtmp.empty()) {
            strres = strtmp + strres;
        }

        return strres;
    }

    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > vecres;
        vector<int> temp;

        int n = 2;
        while (n <= (sum+1)/2) {
            int mid = sum / n; // 序列的中位数

            // 在该区间内以大小n为窗口滑动并计算窗口内数字总和
            for (int i = mid - n / 2; i <= mid; ++i) { 
                if (i <= 0) {
                    continue;
                }
                int loc_sum = 0;
                for (int j = i; j < i + n; ++j) {
                    loc_sum += j;
                }
                if (loc_sum == sum) {
                    temp.resize(0);
                    for (int j = i; j < i + n; ++j) {
                        temp.push_back(j);
                    }
                    vecres.push_back(temp);
                }
            }

            n++;
        }

        sort(vecres.begin(), vecres.end());

        return vecres;
    }

    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        

        return NULL;
    }

    static string PMN_int2str(int a)
    {
        ostringstream os;
        os << a;
        return os.str();
    }

    static bool PMN_cmp(int a, int b)
    {
        string sa = PMN_int2str(a);
        string sb = PMN_int2str(b);
        return sa + sb < sb + sa;
    }

    // 33
    string PrintMinNumber(vector<int> numbers)
    {
        string strres;

        sort(numbers.begin(), numbers.end(), PMN_cmp);

        for (size_t i = 0; i < numbers.size(); ++i) {
            strres += PMN_int2str(numbers[i]);
        }

        return strres;
    }

    // 34 丑数
    bool isUglyNum(int n)
    {
        while (n % 2 == 0) {
            n = n / 2;
        }
        while (n % 3 == 0) {
            n = n / 3;
        }
        while (n % 5 == 0) {
            n = n / 5;
        }

        return n == 1 ? true : false;
    }

    int Min3(int num1, int num2, int num3)
    {
        int aux = num1 < num2 ? num1 : num2;
        return aux < num3 ? aux : num3;
    }

    int GetUglyNumber_Solution(int index)
    {
        int ret = 0;

        vector<int> vecugly({ 1,2,3,4,5 });

        if (index < 0) {
            return -1;
        } 
        else if (index < 5) {
            return vecugly[index];
        }
        else {
            int founded = 5;
            int t2 = 2;
            int t3 = 1;
            int t5 = 1;
            while (founded < index) {
                int min_ugly = Min3(vecugly[t2]*2, vecugly[t3]*3, vecugly[t5]*5);
                vecugly.push_back(min_ugly);

                while (vecugly[t2]*2 <= vecugly.back()) {
                    t2++;
                }

                while (vecugly[t3] * 3 <= vecugly.back()) {
                    t3++;
                }

                while (vecugly[t5] * 5 <= vecugly.back()) {
                    t5++;
                }

                founded++;
            }

            return vecugly[index - 1];
        }

        return ret;
    }

    int FirstNotRepeatingChar(string str)
    {
        int nums[26 * 2];
        int nums_tag[26 * 2] = { 0 };
        for (int i = 0; i < str.size(); ++i) {
            nums_tag[str[i] - 'A']++;
            nums[str[i] - 'A'] = i;
        }

        int temp = INT_MAX;
        for (int i = 0; i < 26 * 2; ++i) {
            if (nums_tag[i]==1) {
                if (nums[i]<temp) {
                    temp = nums[i];
                }
            }
        }

        return temp;
    }

    bool hasPath(char* matrix, int rows, int cols, char* str) {
        if (matrix==NULL || rows<=0 || cols<=0) {
            return false;
        }

        bool* tag = new bool[cols * rows]();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (hasPathInternal(matrix, rows, cols, str, tag, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPathInternal(char* matrix, int rows, int cols, char* str, 
        bool* tag, int curx, int cury) {
        if (*str == '\0') {
            return true;
        }

        if (cury == cols) {
            curx++;
            cury = 0;
        }

        if (cury == -1) {
            curx--;
            cury = cols - 1;
        }

        if (curx<0||curx>=rows) {
            return false;
        }

        if (tag[curx*cols+cury] || *str!=matrix[curx*cols+cury]) {
            return false;
        }

        tag[curx*cols + cury] = true;
        bool flag = hasPathInternal(matrix, rows, cols, str + 1, tag, curx - 1, cury) ||
            hasPathInternal(matrix, rows, cols, str + 1, tag, curx + 1, cury) ||
            hasPathInternal(matrix, rows, cols, str + 1, tag, curx, cury - 1) ||
            hasPathInternal(matrix, rows, cols, str + 1, tag, curx, cury + 1);
        tag[curx*cols + cury] = false;

        return flag;
    }

    // 66
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool> > vectag(rows);
        for (int i = 0; i < rows; ++i) {
            vectag[i].resize(cols, false);
        }

        return movingCountInternal(0, 0, threshold, rows, cols, vectag);
    }

    int movingCountInternal(int curx, int cury, int threshold, int rows, int cols, vector<vector<bool> >& tag) {
        if (curx < 0 || curx >= rows || cury<0 || cury >= cols
            || NumSum(curx) + NumSum(cury)>threshold || tag[curx][cury]) {
            return 0;
        }

        tag[curx][cury] = true;

        return 1 + movingCountInternal(curx - 1, cury, threshold, rows, cols, tag) +
            movingCountInternal(curx + 1, cury, threshold, rows, cols, tag) +
            movingCountInternal(curx, cury - 1, threshold, rows, cols, tag) +
            movingCountInternal(curx, cury + 1, threshold, rows, cols, tag);
    }

    int NumSum(int n) {
        int res = 0;

        do {
            res += n % 10;
        } while ((n = n / 10) > 0);

        return res;
    }

    // 求逆数对
    long long merge(int a[], int aux[], int l, int m, int r) {
        int i, j;

        long long count_ = 0;

        for (i = m + 1; i > l; --i) {
            aux[i - 1] = a[i - 1];
        }

        for (j = r; j > m; --j) {
            aux[j] = a[j];
        }

        i = m;
        j = r;

        int k = r;
        while (i>=l && j>m) {
            if (aux[i]<aux[j]) {
                a[k--] = aux[j--];
            }
            else {
                a[k--] = aux[i--];
                count_ += j - m;
            }
        }

        while (i>=l) {
            a[k--] = aux[i--];
        }

        while (j>m) {
            a[k--] = aux[j--];
        }

        return count_;
    }

    long long merge_sort(int a[], int aux[], int l, int r) {
        if (r <= l) {
            return 0;
        }

        int m = (l + r) / 2;

        long long num = 0;
        num += merge_sort(a, aux, l, m);
        num += merge_sort(a, aux, m + 1, r);

        num += merge(a, aux, l, m, r);

        return num;
    }

    int InversePairs(vector<int> data) {
        if (data.empty()) {
            return 0;
        }
        
        int* cp = new int[data.size()];

        long long count_ = merge_sort(&data[0], cp, 0, data.size() - 1);
        cout << count_ << endl;
        for (auto i : data) {
            cout << i << " ";
        }
        cout << endl;

        delete[] cp;

        return count_ % 1000000007;
    }

    // 正则表达式
    bool match(char* str, char* pattern)
    {
        bool flag = true;

        return flag;
    }

    // 表示数值的字符串
    bool isNumeric(char* string)
    {
        bool flag = true;

        return flag;
    }
};

int test_offer() {
    OfferSolution sol;

    /*//.65
    char* matrix = "abcesfcsadee";
    int rows = 3;
    int cols = 4;
    char* str = "bcced";
    if (sol.hasPath(matrix, rows, cols, str)) {
        cout << matrix << " has path " << str << endl;
    }
    else {
        cout << matrix << " hasn't path " << str << endl;
    }*/

    /*TreeLinkNode* t8 = new TreeLinkNode(8);
    TreeLinkNode* t5 = new TreeLinkNode(5);
    TreeLinkNode* t6 = new TreeLinkNode(6);
    TreeLinkNode* t7 = new TreeLinkNode(7);
    TreeLinkNode* t9 = new TreeLinkNode(9);
    TreeLinkNode* t10 = new TreeLinkNode(10);
    TreeLinkNode* t11 = new TreeLinkNode(11);

    t8->left = t6;
    t8->right = t10;
    t6->left = t5;
    t6->right = t7;
    t10->left = t9;
    t10->right = t11;

    sol.GetNext(t8);*/

    //sol.FindContinuousSequence(100);

    /*string str1 = "abcXYZdef";
    string str2 = str1.substr(3);
    string str3 = str1.substr(0, 3);
    cout << str2+str3 << endl;*/

    //string str = "student. an am I";
    //cout<< sol.ReverseSentence(str) << endl;

    //sol.IsContinuous(vector<int>({0,3,1,6,4}));

    //int num1, num2;
    //sol.FindNumsAppearOnce(vector<int>({ 4,6,1,1,1,1 }), &num1, &num2);
    //cout << num1 << " " << num2 << endl;
    /*
    ListNode* t1 = new ListNode(1);
    ListNode* t2 = new ListNode(1);
    ListNode* t31 = new ListNode(1);
    ListNode* t32 = new ListNode(1);
    ListNode* t41 = new ListNode(1);
    ListNode* t42 = new ListNode(2);
    ListNode* t5 = new ListNode(5);

    t1->next = t2;
    t2->next = t31;
    t31->next = t32;
    t32->next = t41;
    t41->next = t42;
    t42->next = t5;

    sol.deleteDuplication(t1);*/

    // 33
    //vector<int> vecn({ 3,32,321 });
    //sol.PrintMinNumber(vecn);

    // 34
    //sol.GetUglyNumber_Solution(7);

    //sol.FirstNotRepeatingChar("aabDcdedjDejdss");

    //sol.InversePairs(vector<int>({ 364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575 }));
    //sol.InversePairs(vector<int>({ 1,2,3,4,5,6,7,0 }));
    //sol.InversePairs(vector<int>({ 7,5,6,4 }));

    return 0;
}

