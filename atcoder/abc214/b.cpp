#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int s, t;
    cin >> s >> t;
    int res = 0;
    for(int i = 0; i <= s; ++i)
        for(int j = 0; (i + j) <= s; ++j)
            for(int k = 0; (i + j + k) <= s; ++k)
                if(i * j * k <= t)
                    ++res;
    cout << res << endl;
    return 0;
}