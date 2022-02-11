// Alex P.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;

const ll MAX_CARS = 100001;
vector<ld> arrOfSpeeds, arrOfDistances;

/*
    Function func:
*/
ld func(ld time)
{
    ld maxVal = -1e18;
    ld minVal = 1e18;

    for (ll i = 0; i < arrOfSpeeds.size(); ++i)
    {
        ld currVal = arrOfSpeeds[i] * time + arrOfDistances[i];

        maxVal = max(maxVal, currVal);
        minVal = min(minVal, currVal);
    }

    return (maxVal - minVal);
}

/*
    Program entry point:
*/
int main()
{
    // Setup:
    ld numOfCars, durationOfRace;
    cin >> numOfCars >> durationOfRace;

    for (int i = 0; i < numOfCars; ++i)
    {
        ld tempSpeed, tempDistance;
        cin >> tempSpeed >> tempDistance;

        arrOfSpeeds.push_back(tempSpeed);
        arrOfDistances.push_back(tempDistance);
    }

    // ALGO:
    ld left = 0;
    ld right = durationOfRace;
    while (right - left > 0.000000001)
    {
        ld mid1 = left + (right - left) / 3;
        ld mid2 = right - (right - left) / 3;

        if (func(mid1) > func(mid2))
        {
            left = mid1;
        }

        else
        {
            right = mid2;
        }
    }

    cout << fixed << setprecision(6) << func(left) << endl;
}
