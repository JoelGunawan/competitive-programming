#include <bits/stdc++.h>
#define ll long long
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int t_counter = 0, m_counter = 0;
        bool ans = 1;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'T')
                ++t_counter;
            else
                ++m_counter;
            if(t_counter < m_counter)
                ans = 0;
        }
        if(t_counter != 2 * m_counter)
            ans = 0;
        t_counter = 0, m_counter = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(s[i] == 'T')
                ++t_counter;
            else
                ++m_counter;
            if(t_counter < m_counter)
                ans = 0;    
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}