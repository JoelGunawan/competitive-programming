// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // or do dp states for dp[pos][dp][graph][mathgeom][adhoc]
    // brute force each state
    // find count of allowed states
    // flying table dp possible
    int n;
    cin >> n;
    bool task[n][5];
    memset(task, 0, sizeof(task));
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        while(t--) {
            string x;
            cin >> x;
            if(x == "dp")
                task[i][0] = 1;
            if(x == "graph")
                task[i][1] = 1;
            if(x == "mathgeo")
                task[i][2] = 1;
            if(x == "ds")
                task[i][3] = 1;
            if(x == "adhoc")
                task[i][4] = 1;
        }
    }
    int dpmin, dpmax, graphmin, graphmax, mathgeomin, mathgeomax, dsmin, dsmax, adhocmin, adhocmax;
    cin >> dpmin >> dpmax >> graphmin >> graphmax >> mathgeomin >> mathgeomax >> dsmin >> dsmax >> adhocmin >> adhocmax;
    ll dp[2][dpmax + 1][graphmax + 1][mathgeomax + 1][dsmax + 1][adhocmax + 1];
    memset(dp, 0, sizeof(dp));
    dp[1][0][0][0][0][0] = 1;
    // 5.2 1e7
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= dpmax; ++j) {
            for(int graph = 0; graph <= graphmax; ++graph) {
                for(int mathgeo = 0; mathgeo <= mathgeomax; ++mathgeo) {
                    for(int ds = 0; ds <= dsmax; ++ds) {
                        for(int adhoc = 0; adhoc <= adhocmax; ++adhoc) {
                            // not choose
                            dp[i % 2][j][graph][mathgeo][ds][adhoc] = dp[(i + 1) % 2][j][graph][mathgeo][ds][adhoc];
                            int a, b, c, d, e;
                            a = j - task[i][0];
                            b = graph - task[i][1];
                            c = mathgeo - task[i][2];
                            d = ds - task[i][3];
                            e = adhoc - task[i][4];
                            // choose current task
                            if(a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0)
                                dp[i % 2][j][graph][mathgeo][ds][adhoc] += dp[(i + 1) % 2][a][b][c][d][e];
                        }
                    }
                }
            }
        }
    }
    // the last is at n - 1 % 2
    ll res = 0;
    for(int i = dpmin; i <= dpmax; ++i) {
        for(int graph = graphmin; graph <= graphmax; ++graph) {
            for(int mathgeo = mathgeomin; mathgeo <= mathgeomax; ++mathgeo) {
                for(int ds = dsmin; ds <= dsmax; ++ds) {
                    for(int adhoc = adhocmin; adhoc <= adhocmax; ++adhoc) {
                        if(i == 0 && graph == 0 && mathgeo == 0 && ds == 0 && adhoc == 0)
                            continue;
                        res += dp[(n - 1) % 2][i][graph][mathgeo][ds][adhoc];             
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}