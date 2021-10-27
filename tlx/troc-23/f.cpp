#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
//#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int prev[5]; memset(prev, 0, sizeof(prev));
    int start = 1e6;
    while(true)
    {
        cout << "? " << start << endl;
        int colour;
        cin >> colour;
        if(prev[colour] != 0)
        {
            cout << "! " << prev[colour] << " " << start << endl;
            break;
        }
        else
            prev[colour] = start;
        ++start;
    } 
}
int main()
{
    test_case();
    return 0;
}