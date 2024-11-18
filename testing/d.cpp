#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ld long double

const int MAXN = 1e6 + 100;
const ld EPS = 0.000000001;

int N, K, L, R, memo[MAXN];
ld arr[MAXN], pref[MAXN];

void build(ld off){
    for(int i = 1; i <= N; i++){
        pref[i] = pref[i - 1] + arr[i] - off;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K >> L >> R;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    ld l = 1, r = 1e5;

    for(int it = 0; it < 60; it++){
        ld mid = (l + r) / 2; build(mid);

        deque<int> dq; dq.push_back(0);

        for(int i = 1; i <= N; i++) memo[i] = 1000000000;

        for(int i = L; i <= N; i++){
            while(!dq.empty() && i - dq.front() > R) dq.pop_front();

            int opt = dq.front();

            if(pref[i] + EPS >= pref[opt]) memo[i] = memo[opt] + 1;
            else memo[i] = memo[opt];

            int id = i - L + 1;

            while(!dq.empty() && (memo[dq.back()] > memo[id] || 
                (memo[dq.back()] == memo[id] && pref[dq.back()] <= pref[id])))
                dq.pop_back();

            dq.push_back(id);
        }

        if(memo[N] >= K) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(9) << l << '\n';
}