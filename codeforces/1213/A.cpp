#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int evencount = 0, oddcount = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if(arr[i] % 2 == 0) ++evencount;
        else ++oddcount;
    }
    cout << min(oddcount, evencount);

    return 0;
}
