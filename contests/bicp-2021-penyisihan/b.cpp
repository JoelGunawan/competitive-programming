#include <bits/stdc++.h>
//#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define ins insert
#define ull unsigned long long
#define ullll unsigned __int128
#define pointer(it) *it
#define lb lower_bound
#define ub upper_bound
using namespace std;
void test_case()
{
    int n, m;
    cin >> n;
    int scores[n], ranks[n];
    for(int i = 0; i < n; ++i)
        cin >> scores[i], scores[i] = -scores[i];
    int ranking = 1;
    for(int i = 0; i < n; ++i)
    {
        if(i == 0 || scores[i] != scores[i - 1])
            ranks[i] = ranking++;
        else
            ranks[i] = ranks[i - 1];
    }
    cin >> m;
    int player[m];
    for(int i = 0; i < m; ++i)
        cin >> player[i], player[i] = -player[i];
    for(int i = 0; i < m; ++i)
    {
        int compare = lower_bound(scores, scores + n, player[i]) - scores;
        if(compare == n)
            cout << ranking << endl;
        else
            cout << ranks[compare] << endl;
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    test_case();
    return 0;
}