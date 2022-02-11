// Alex P.
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

const ll MAX_N = 200000;
bool isValidDay(vector<ll> arrOfDays, ll poundsOfFertilizer, ll dayToTry);

/*
    Program entry point:
*/
int main()
{
    // Setup:
    ll numOfFlowers;
    cin >> numOfFlowers;

    vector<ll> arrOfDays;
    arrOfDays.reserve(MAX_N);

    ll maxDays = 0;
    for (ll i = 0; i < numOfFlowers; ++i)
    {
        string trash;
        ll tempNum;
        cin >> trash >> tempNum;

        arrOfDays.push_back(tempNum);
        maxDays = max(maxDays, tempNum);
    }

    ll poundsOfFertilizer;
    cin >> poundsOfFertilizer;

    // ALGO:
    ll left = 0;
    ll right = maxDays;
    ll mid;
    while (right - left > 1)
    {
        mid = left + (right - left) / 2;

        if (isValidDay(arrOfDays, poundsOfFertilizer, mid))
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
    Function isValidDay:
*/
bool isValidDay(vector<ll> arrOfDays, ll poundsOfFertilizer, ll dayToTry)
{
    ll fertilizerLeft = poundsOfFertilizer;

    for (ll i = 0; i < arrOfDays.size(); ++i)
    {
        if (arrOfDays[i] > dayToTry)
        {
            ll difference = (arrOfDays[i] - dayToTry);
            fertilizerLeft -= difference;

            if (fertilizerLeft < 0)
            {
                return false;
            }
        }
    }

    return true;
}
