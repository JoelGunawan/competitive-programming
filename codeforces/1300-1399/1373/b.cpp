#include <iostream>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0') a++;
        else b++;
    }
    if(min(a, b) % 2 == 1) cout << "DA" << endl;
    else cout << "NET" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
