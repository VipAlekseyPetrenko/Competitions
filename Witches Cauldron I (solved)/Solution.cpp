// Alex P.
#include <iostream>
using namespace std;
typedef long long int ll;

bool volumeChecker(int *arr, int numOfElements, int numOfGroups, long long volume);

/*
    Program entry point:
*/
int main()
{
    // Setup:
    int numOfElements, numOfBoils;
    cin >> numOfElements >> numOfBoils;

    int *arrOfElements = new int[numOfElements];

    ll totalVolume = 0;
    for (int i = 0; i < numOfElements; ++i)
    {
        int currNum;
        cin >> currNum;
        arrOfElements[i] = currNum;
        totalVolume += currNum;
    }

    // ALGO:
    ll left = 0;
    ll right = totalVolume;
    ll mid;
    while (right - left > 1)
    {
        mid = left + (right - left) / 2;

        if (volumeChecker(arrOfElements, numOfElements, numOfBoils, mid))
        {
            right = mid;
        }

        else
        {
            left = mid;
        }
    }

    cout << right << endl;
}

/*
    Function volumeChecker:
*/
bool volumeChecker(int *arr, int numOfElements, int numOfGroups, ll volume)
{
    int groupsNeeded = 1;
    ll sum = 0;

    for (int i = 0; i < numOfElements; ++i)
    {
        if (arr[i] > volume)
        {
            return false;
        }

        if (sum + arr[i] > volume)
        {
            ++groupsNeeded;
            sum = 0;
        }

        sum += arr[i];
    }

    return (groupsNeeded > numOfGroups) ? false : true;
}
