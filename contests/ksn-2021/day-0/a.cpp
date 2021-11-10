#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main()
{
    fast_io();
    int n; string s;
    cin >> n;
    int counter[26]; 
    memset(counter, 0, sizeof(counter));
    char in;
    for(int i = 0; i < n; ++i)
    {
        cin >> in;
        ++counter[in - 'A'];
    }
    char prev = 'a';
    // find the first element in which case the rest of the string is still valid
    for(int i = 0; i < n; ++i)
    {
        int sum = 0, maximum = 0, max_index;
        for(int j = 0; j < 26; ++j)
        {
            if(counter[j] > maximum)
                max_index = j, maximum = counter[j];
            sum += counter[j];
        }
        for(int j = 0; j < 26; ++j)
        {
            // if current char counter is more than 0 and if in the remaining string the char with the most count
            // is less than equal to half plus remaining % 2 then it is possible
            if(counter[j] > 0 && ((j != max_index && (n - i - 1) / 2 + (n - i - 1) % 2 >= maximum) || j == max_index) && prev != 'A' + j)
            {
                --counter[j];
                s += 'A' + j;
                prev = 'A' + j;
                break;
            }
        }
    }
    cout << s << endl;
    return 0;
}