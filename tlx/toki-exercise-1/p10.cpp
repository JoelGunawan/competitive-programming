#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    reverse(a.begin(), a.end());
    int len = a.size();
    int n;
    cin >> n;
    for(int i = 0; i < len; ++i)
    {
        if(n >= a[i])
        {
            int counter = 0;
            while(n >= a[i])
                ++counter, n -= a[i];
            cout << a[i] << " " << counter << endl;
        }
    }
    return 0;
}