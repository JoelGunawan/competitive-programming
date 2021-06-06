#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<int> arr2 = arr;
    reverse(arr2.begin(), arr2.end());

    ll difference = 0;
    for(int i = 0; i < n; ++i)
    {
        difference += abs(arr2[i] - arr[i]);
    }
    if(difference >= n)
    {
        for(int i = 0; i < n; ++i)
        {
            cout << arr2[i];
            if(i == n - 1) cout << endl;
            else cout << " ";
        }
    }
    else
    {
        difference = 0;
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i < n; ++i)
        {
            difference += abs(arr2[i] - arr[i]);
        }
        if(difference >= n)
        {
            for(int i = 0; i < n; ++i)
            {
                cout << arr2[i];
                if(i == n - 1) cout << endl;
                else cout << " ";
            }
        }
        else
        {
            sort(arr2.begin(), arr2.end(), greater<int>());
            for(int i = 0; i < n; ++i)
            {
                cout << arr2[i];
                if(i == n - 1) cout << endl;
                else cout << " ";
            }
        }
    }

    return 0;
}
