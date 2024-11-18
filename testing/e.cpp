#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-5

// typedef pair<double, int> pdi;

#define MAXN 1000001
double a[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    int t;
    for(t = 1; t <= n; t++) cin >> a[t];

    double left = 1, right = 100000, mid;
    for(int it = 0; it < 50; it++) {
        mid = (left + right) / 2;

        double pref[n+1];
        pref[0] = 0;
        for(int t = 1; t <= n; t++) {
            pref[t] = pref[t-1] + a[t] - mid;
        }

        deque<int> dq;
        dq.push_back(0);

        int dp[n+1];
        for(int t = 1; t <= n; t++) dp[t] = 1e8;
        dp[0] = 0;
        for(int t = l; t <= n; t++) {
            while(!dq.empty() && t - dq.front() > r) dq.pop_front();

            int opt = dq.front();

            int &thisDp = dp[t];
            if(pref[t] - EPS <= pref[opt]) thisDp = dp[opt] + 1;
            else thisDp = dp[opt];

            int id = t - l + 1;

            while(!dq.empty() && 
                  (dp[dq.back()] > dp[id] ||
                   (dp[dq.back()] == dp[id] && pref[dq.back()] <= pref[id])))
                dq.pop_back();

            dq.push_back(id);
        }

        if(dp[n] >= k) left = mid;
        else right = mid;
    }
    cout << fixed << setprecision(9) << left << "\n";
}