#include <bits/stdc++.h>

using namespace std;

void doCase()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1, -1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        int cur = arr[i];
        int movement = 0;
        do
        {
            cur = arr[cur];
            ++movement;
        }
        while(cur != arr[i]);
        cout << movement;
        if(i == n) cout << endl;
        else cout << " ";
    }
}

int main()
{
    int q;
    cin >> q;
    while(q--) doCase();
    return 0;
}
