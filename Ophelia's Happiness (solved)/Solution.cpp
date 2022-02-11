// Alex P.
#include <iostream>
using namespace std;

/*
    Program entry point:
*/
int main()
{
    int num;
    cin >> num;

    int nextNum;
    int sum = 0;
    for (int i = 0; i < num; ++i)
    {
        char qType;
        cin >> qType;

        if (qType == 'R')
        {
            cin >> nextNum;
            sum += nextNum;
        }
        else
        {
            cout << sum << endl;
        }
    }
}