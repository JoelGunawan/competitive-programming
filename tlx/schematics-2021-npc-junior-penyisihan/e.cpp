#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
int main()
{
    int d, h, l, in;
    bool a[d][h][l];
    for(int i = 0; i < d; ++i)
        for(int j = 0; j < h; ++j)
            for(int k = 0; k < l; ++k)
                cin >> in, a[i][j][k] = in;
    int pref[d][h][l];
    // for each possible rectangle, find the longest possible distance
    
    return 0;
}