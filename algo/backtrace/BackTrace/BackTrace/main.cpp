
#include <iostream>

using namespace std;

extern void nQueen();
extern void SumSubSet(int s, int k, int r);

int main()
{
    /*n-queen*/
    //nQueen();

    /*sum of subset*/
    SumSubSet(0, 0, 73);
    extern int flag;
    cout << flag << endl;

    /**/

    return 0;
}