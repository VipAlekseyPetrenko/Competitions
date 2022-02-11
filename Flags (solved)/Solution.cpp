// Alex P.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;

bool first = true;
vector<ll> arrOfReds(50, -1);
vector<ll> arrOfWhites(50, -1);

ll func(int numOfFlags, string prev = "");

/*
    Program entry point:
*/
int main()
{
    // Setup:
    int numOfFlags;
    cin >> numOfFlags;

    // ALGO:
    ll answer = func(numOfFlags);
    cout << answer << endl;
}

/*
    Function func:
*/
ll func(int numOfFlags, string prev)
{
    if (first)
    {
        first = false;

        if (numOfFlags == 1 || numOfFlags == 2)
        {
            return 2;
        }

        else
        {
            return (func(numOfFlags - 1, "W") + func(numOfFlags - 1, "R"));
        }
    }

    else
    {
        if (numOfFlags == 1)
        {
            return 1;
        }

        else
        {
            if (prev.compare("W") == 0)
            {
                if (arrOfReds[numOfFlags] == -1)
                {
                    arrOfReds[numOfFlags] = func(numOfFlags - 1, "R");
                }

                return (arrOfReds[numOfFlags] + func(numOfFlags - 1, "WB"));
            }

            if (prev.compare("R") == 0)
            {
                if (arrOfWhites[numOfFlags] == -1)
                {
                    arrOfWhites[numOfFlags] = func(numOfFlags - 1, "W");
                }

                return (arrOfWhites[numOfFlags] + func(numOfFlags - 1, "RB"));
            }

            if (prev.compare("WB") == 0)
            {
                return (func(numOfFlags - 1, "R"));
            }

            if (prev.compare("RB") == 0)
            {
                return (func(numOfFlags - 1, "W"));
            }
        }
    }

    return -1;
}