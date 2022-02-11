// Alex P.
#include <stdio.h>
#include <vector>
using namespace std;

/*
    Program entry point:
*/
int main()
{
    // Setup:
    int numOfMoney;
    scanf("%d", &numOfMoney);

    vector<int> arrOfRoots;
    arrOfRoots.reserve(60001);
    for (int i = 1; (i * i) <= numOfMoney; ++i)
    {
        arrOfRoots.push_back(i * i);
    }

    vector<int> arrOfSums;
    arrOfSums.reserve(60001);
    arrOfSums.push_back(0);
    for (int i = 1; i <= numOfMoney; ++i)
    {
        arrOfSums.push_back(70000);
    }

    // ALGO:
    for (int i = 1; i <= numOfMoney; ++i)
    {
        for (int j = 0; (j < arrOfRoots.size()) && (i - arrOfRoots[j] >= 0); ++j)
        {
            if ((arrOfSums[i - arrOfRoots[j]] + 1) < arrOfSums[i])
            {
                arrOfSums[i] = (arrOfSums[i - arrOfRoots[j]] + 1);
            }
        }
    }

    printf("%d\n", arrOfSums[numOfMoney]);
}