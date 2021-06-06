#include <iostream>

using namespace std;

void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    int difference = 0, firstdifference, seconddifference;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] != t[i])
        {
            ++difference;
            if(difference == 1) firstdifference = i;
            else if(difference == 2) seconddifference = i;
            else
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    if(difference == 0)
    {
        cout << "Yes" << endl;
    }
    else if(difference == 2)
    {
        if(s[firstdifference] == s[seconddifference] && t[firstdifference] == t[seconddifference]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
