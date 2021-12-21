#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ll long long
#define ld double
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pof pop_front()
#define ffl fflush(stdout)
using namespace std;

ll n, a, b;
ll arr[2005];
ll pf[2005];

bool ok1(ll now)
{
    int dp[n + 5]; memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = 1e9;
        for(int j = 0; j < i; ++j)
        {
            if(((pf[i] - pf[j]) | now) == now)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp[n]<=b;
}
bool ok2(ll now)
{
    bool dp[n + 5][b + 5]; memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= b; ++j)
            for(int k = 0; k < i; ++k)
                if(((pf[i] - pf[k]) | now) == now)
                    dp[i][j]|= dp[k][j - 1];
    for(int i = a; i <= b; ++i)
        if(dp[n][i])
            return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll ans = 1, pow2[45]; pow2[0] = 1;
    for(int i = 1; i <= 41; ++i)
        ans *= 2, pow2[i] = 2 * pow2[i - 1];
    --ans;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i], pf[i] = arr[i] + pf[i - 1];
    if(a == 1)
    {
       for(int i = 40; i >= 0; --i)
            if(ok1(ans^pow2[i])) ans^=pow2[i];
    }
    else
    {
        for(int i = 40; i >= 0; --i)
            if(ok2(ans^pow2[i])) ans ^= pow2[i];
    }
    cout << ans << endl;
}