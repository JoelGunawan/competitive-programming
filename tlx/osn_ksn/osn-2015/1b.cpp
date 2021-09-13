#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    int arr[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &arr[i][j]);
    // build a binary indexed tree
    // to count how many is within a range
    int binarysize = 2 * (m&-m);
    int bit[n][binarysize];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if((j == 0 || bit[i][j - 1] < bit[i][j]) && (i == 0 || bit[i - 1][j] < bit[i][j]) && (i == n - 1 || bit[i + 1][j] < bit[i][j]) && (j == m - 1 || bit[i][j + 1] < bit[i][j]))
            {
                int k = j + 1; 
                while(k <= binarysize)
                {
                    ++bit[i][k - 1];
                    k += k&-k;
                }   
            }
        }
    int a, b, c, d;
    // total is q * 2n + 2m
    // which is roughly 4 * 10^8
    // as we only need to check the perimeter and the other parts
    // we can check quite easily using data structures
    // and add a factor of nm log nm which is probably 10^7
    // use optimizations
    for(int i = 0; i < q; ++i)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        --a, --b, --c, --d;
        int top = 0, left = 0, right = 0, down = 0;
        if(a == c)
        {
            // check from b + 1 to d - 1
            // check whether arr[a][b] or arr[c][d] is bigger
            bool possible = 1;
            for(int j = b + 1; j <= d - 1; ++j)
                if(arr[a][j] >= arr[a][j - 1] && arr[a][j] >= arr[a][j + 1])
                    possible = 0;
            if(possible && arr[a][b] > arr[c][d])
                cout << "Kiri Atas" << endl;
            else if(possible)
                cout << "Kanan Bawah" << endl;
            else
                cout << "Tidak Mungkin" << endl;
            continue;
        }
        // check top
        for(int j = b; j <= d; ++j)
        {
                           
        }
        // check bottom
        for(int j = b; j <= d; ++j)
        {

        }
        // check left
        for(int j = a; j <= c; ++j)
        {

        }
        // check right
        for(int j = a; j <= c; ++j)
        {

        }
        // output result

    }
    return 0;
}