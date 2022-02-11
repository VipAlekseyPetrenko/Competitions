// Alex P.
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

ll getInversions(vector<int> &arr);
ll mergeSort(vector<int> &arr, int left, int right);
ll merge(vector<int> &arr, int left, int mid, int right);

/*
    Program entry point:
*/
int main()
{
    int N, K;
    cin >> N >> K;

    int ans;
    ll maxInversions = -1;
    for (int i = 0; i < K; ++i)
    {
        // Part 1 - store current row into the array:
        vector<int> arr;
        arr.reserve(N);

        for (int j = 0; j < N; ++j)
        {
            int tempNum;
            cin >> tempNum;
            arr.push_back(tempNum);
        }

        // Part 2 - count number of inversions in the current row:
        ll currInversions = getInversions(arr);

        // Part 3 - update the answer when needed:
        if (currInversions > maxInversions)
        {
            maxInversions = currInversions;
            ans = i + 1;
        }
    }

    // Output the answer:
    cout << ans << endl;
}

/*
    Function getInversions:
*/
ll getInversions(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

/*
    Function mergeSort:
*/
ll mergeSort(vector<int> &arr, int left, int right)
{
    ll ans = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        ans += mergeSort(arr, left, mid);
        ans += mergeSort(arr, mid + 1, right);
        ans += merge(arr, left, mid, right);
    }

    return ans;
}

/*
    Function merge:
*/
ll merge(vector<int> &arr, int left, int mid, int right)
{
    ll ans = 0;

    // Left subarray is arr[left ... mid]:
    vector<int> leftSubArr;
    for (int i = left; i <= mid; ++i)
    {
        leftSubArr.push_back(arr[i]);
    }

    // Right subarray is arr[mid + 1 ... right]:
    vector<int> rightSubArr;
    for (int i = mid + 1; i <= right; ++i)
    {
        rightSubArr.push_back(arr[i]);
    }

    // Merging two subarrays together into the main array:
    int mainPtr = left;
    int leftPtr = 0;
    int rightPtr = 0;
    while (leftPtr < leftSubArr.size() && rightPtr < rightSubArr.size())
    {
        if (leftSubArr[leftPtr] <= rightSubArr[rightPtr])
        {
            arr[mainPtr++] = leftSubArr[leftPtr++];
        }

        else
        {
            arr[mainPtr++] = rightSubArr[rightPtr++];
            ans += (mid - (left + leftPtr));
        }
    }

    // When not all elements from the left subarray have been merged:
    while (leftPtr < leftSubArr.size())
    {
        arr[mainPtr++] = leftSubArr[leftPtr++];
    }

    // When not all elements from the right subarray have been merged:
    while (rightPtr < rightSubArr.size())
    {
        arr[mainPtr++] = rightSubArr[rightPtr++];
    }

    return ans;
}