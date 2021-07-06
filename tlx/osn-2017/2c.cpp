#include <bits/stdc++.h>
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    string subsoal;
    int n;
    cin >> subsoal >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    int minres = INT_MAX;
    // we need to check for whether it is worth it to keep the a or b side of the equation, or should we just switch everything over
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
        {
            // set the arithmetic sequence as having an anchor in these two points
            // n^3 approach
            double diff1 = (double)(a[j] - a[i]) / (double)(j - i), diff2 = (double)(b[j] - b[i]) / (double)(j - i); 
            int localres = 0;
            for(int k = 0; k < n; ++k)
            {
                if(diff1 * (k - i) + a[i] == diff2 * (k - i) + b[i] && (diff1 * (k - i) + a[i] != a[k] || diff2 * (k - i) + b[i] != b[k]))
                    ++localres;
                else
                {
                    if(diff1 * (k - i) + a[i] != a[k])
                        ++localres;
                    if(diff2 * (k - i) + b[i] != b[k])
                        ++localres;
                }
            }
            minres = min(localres, minres);
        }
    if(minres == INT_MAX)
        cout << 0 << endl;
    else
        cout << minres << endl;
    return 0;
}