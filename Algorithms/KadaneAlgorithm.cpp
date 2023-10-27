#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxi = arr[0], sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mai = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }

    cout << maxi << endl;

    return 0;
}

// Leetcode Question Link - https://leetcode.com/problems/maximum-subarray/description/
