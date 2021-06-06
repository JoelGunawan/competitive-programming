#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        arr2[i] = tmp - arr1[i];
    }

    bool nonzerosequence = false;

    for(int i = 0; i < n; ++i)
    {
        if(arr2[i] < 0)
        {
            cout << "NO" << endl;
            return;
        }
        else if(arr2[i] != 0 && (i == 0 || arr2[i] != arr2[i - 1]))
        {
            if(nonzerosequence)
            {
                cout << "NO" << endl;
                return;
            }
            nonzerosequence = true;
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
