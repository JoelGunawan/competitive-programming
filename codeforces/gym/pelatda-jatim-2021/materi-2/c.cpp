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
        int n; string s;
        cin >> n >> s;
        int zero_count = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] == '0')
                ++zero_count;
        if(s[0] == '0' || s[n - 1] == '0' || zero_count % 2 == 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            int one_count = n - zero_count, cur_one = 0;
            string a = "", b = "";
            bool x = 0;
            for(int i = 0; i < n; ++i)
            {
                if(s[i] == '0')
                {
                    if(x)
                        a += '(', b += ')';
                    else
                        a += ')', b += '(';
                    x = !x;
                }
                else
                {
                    if(cur_one < one_count / 2)
                        a += '(', b += '(';
                    else
                        a += ')', b += ')';
                    ++cur_one;
                }
            }
            cout << a << endl << b << endl;
        }    
    }
    return 0;
}