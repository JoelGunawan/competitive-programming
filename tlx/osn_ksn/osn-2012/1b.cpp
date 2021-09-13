#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string subsoal; int n;
    cin >> subsoal >> subsoal >> n;
    int a[n][n], x[n];
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    // check for all zeros
    // we get a set of what we have to xor if we do an inversion
    set<int> inversion1[n], inversion2[n];
    bool invalid = 0, first = 1, second = 1;
    int inverted[n];
    for(int i = 0; i < n; ++i)
    {
        // try inversion
        for(int j = 0; j < n; ++j)
            inverted[j] = a[i][j] ^ x[j];
        if(x[i])

        // try no inversion

    }
    int firstcounter = inversion1[0].size(), secondcounter = inversion2[0].size();

    if(invalid || !(first || second))
        cout << -1 << endl;
    else

    return 0;
}