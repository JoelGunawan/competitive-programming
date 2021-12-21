#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; string s;
    cin >> n >> s;
    int counter[26]; memset(counter, 0, sizeof(counter));
    for(int i = 0; i < n; ++i)
        ++counter[s[i] - 'A'];
    sort(counter, counter + 26);
    reverse(counter, counter + 26);
    //cout << counter[1] << " " << counter[2] << " " << cou
    if(counter[2] == 0)
        cout << -1 << endl;
    else
        cout << min(counter[2] + 1, counter[0]) + min(counter[2] + 1, counter[1]) + counter[2] << endl;
    return 0;
}