#include <bits/stdc++.h>
#define endl "\n"
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
bool customcomp(pair<string, int> a, pair<string, int> b)
{
    for(int i = 0; i < a.first.size(); ++i)
    {
        if(i & 1 && a.first[i] != b.first[i])
            return a.first[i] > b.first[i];
        else if (a.first[i] != b.first[i])
            return a.first[i] < b.first[i];
    }
    // this doesn't cause an error as it is guaranteed to not be the same in the problem
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;
    pair<string, int> a[n];
    string s;
    for(int i = 0; i < n; ++i)
        cin >> s, a[i] = {s, i + 1};
    sort(a, a + n, customcomp);
    for(int i = 0; i < n; ++i)
        cout << a[i].second << " ";
    cout << endl;
    return 0;
}