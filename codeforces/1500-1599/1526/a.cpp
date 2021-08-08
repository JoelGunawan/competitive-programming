#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    n *= 2; 
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i)
    {
        if(i & 1)
            cout << a[i / 2 + n / 2];
        else
            cout << a[i / 2];
        cout << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}