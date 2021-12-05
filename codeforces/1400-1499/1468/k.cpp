#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
vector<vector<bool>> used;
 
void tc()
{
    string s;
    cin >> s;
    int n = s.size();
    used = vector<vector<bool>>(2 * n + 1, vector<bool>(2 * n + 1, 0));
    int x = n, y = n;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'L')
            --x;
        else if(s[i] == 'R')
            ++x;
        else if(s[i] == 'U')
            ++y;
        else
            --y;
        //cout << "DEBUG1: " << x - n << " " << y - n << endl;
        if(!used[x][y])
        {
            used[x][y] = 1;
            int localx = n, localy = n;
            // try to simulate
            for(int j = 0; j < n; j++)
            {
                if(s[j] == 'L' && (localx - 1 != x || localy != y))
                    --localx;
                else if(s[j] == 'R' && (localx + 1 != x || localy != y))
                    ++localx;
                else if(s[j] == 'U' && (localx != x || localy + 1 != y))
                    ++localy;
                else if(s[j] == 'D' && (localx != x || localy - 1 != y))
                    --localy;
                //cout << "DEBUG: " << localx - n << " " << localy - n << endl;
            }
            if(localx == n && localy == n)
            {
                cout << x - n << " " << y - n << endl;
                return;
            }
        }
        // select this as barrier
    }
    cout << 0 << " " << 0 << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}