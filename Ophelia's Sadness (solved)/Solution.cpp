// Alex P.
#include <iostream>
#include <iomanip>
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
    double counter = 0;
    for (int i = 0; i < num; ++i)
    {
        char qType;
        cin >> qType;

        if (qType == 'R')
        {
            cin >> nextNum;
            sum += nextNum;
            ++counter;
        }
        else
        {
            cout << setprecision(6) << fixed << (sum / counter) << endl;
        }
    }
}