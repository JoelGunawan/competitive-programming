#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int minIndex, maxIndex;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == n)
            maxIndex = i;
        else if(a[i] == 1)
            minIndex = i;
    }
    cout << min(max(maxIndex, minIndex) + 1, min(n - min(maxIndex, minIndex), n - max(maxIndex, minIndex) + min(minIndex, maxIndex) + 1)) << endl; 
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}