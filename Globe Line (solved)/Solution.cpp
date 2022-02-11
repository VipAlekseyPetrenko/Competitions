// Alex P.
#include <iostream>
using namespace std;

/*
    Program entry point:
*/
int main()
{
    // Setup:
    int N;
    cin >> N;
    int *myArr = new int[N];

    // Algo:
    int currNum;
    for (int i = 0; i < N; ++i)
    {
        cin >> currNum;

        myArr[currNum] = currNum;

        while (currNum >= 0)
        {
            --currNum;

            if (myArr[currNum] == currNum)
            {
                break;
            }
        }

        cout << currNum << endl;
    }

    return 0;
}