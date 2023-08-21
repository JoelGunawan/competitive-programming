// DP approach with ternary search
// O(2^T * T^2 * log N + N * T)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll INF = numeric_limits<ll>::max() / 10;

int type_cnt;
int n;
vector<ll> cnt;
vector<vector<ll>> l, r; // t, pos -> number of passengers of type t left/right of pos
vector<vector<vector<ll>>> l2, r2; // A, B, i -> cost caused by group B boarding before A, to anyone up to the i-th member of group A and boarding from the left/right
vector<vector<int>> groups; // A -> positions of all members of group A, sorted

ll get_cost(size_t already_boarded, int next, int split)
{
    ll result = 0;
    for (int t = 0; t < type_cnt; ++t) {
        ll tmp = l2[next][t][split] + r2[next][t][split];
        if (already_boarded & (1ll << t)) {
            result += 2 * tmp;
        } else if (t == next) {
            result += tmp;
        }
    }
    return result;
}

// Cost of the next group boarding, if the given set of groups has already boarded before.
ll get_cost(size_t already_boarded, int next)
{
    int mini = 0, maxi = groups[next].size() + 1;
    while (maxi - mini > 1) {
        int m1 = (maxi + mini) / 2 - 1;
        int m2 = m1 + 1;
        ll c1 = get_cost(already_boarded, next, m1);
        ll c2 = get_cost(already_boarded, next, m2);
        if (c1 < c2) maxi = m2;
        else mini = m1 + 1;
    }

    ll result = get_cost(already_boarded, next, mini);
    return result;
}

ll calc_costs()
{
    vector<ll> dp(1ll << type_cnt, INF);
    dp[0] = 0;
    for (int i = 1; i < 1ll << type_cnt; ++i) {
        for (int t = 0; t < type_cnt; ++t) {
            if (!(i & (1ll << t))) continue;
            size_t parent = i & ~(1ll << t);
            dp[i] = min(dp[i], dp[parent] + get_cost(parent, t));
        }
    }
    return dp[(1ll << type_cnt) - 1];
}

int main()
{
    string s;
    cin >> s;
    n = s.size();
    map<char, char> types;
    for (char& c: s) {
        if (!types.count(c)) {
            char id = static_cast<char>(types.size());
            types[c] = id;
        }
        c = types[c];
    }

    type_cnt = types.size();
    cnt.assign(type_cnt, 0);
    for (char c: s) ++cnt[c];

    groups.resize(type_cnt);
    for (int i = 0; i < n; ++i) {
        groups[s[i]].push_back(i);
    }

    l = r = vector<vector<ll>>(type_cnt, vector<ll>(n));
    vector<ll> tmp_cnt(type_cnt, 0);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < type_cnt; ++j) {
            l[j][i] = tmp_cnt[j];
            r[j][i] = cnt[j] - tmp_cnt[j];
        }
        ++tmp_cnt[s[i]];
        --r[s[i]][i];
    }

    vector<vector<ll>> tmp_costs_l, tmp_costs_r;
    tmp_costs_l = tmp_costs_r = vector<vector<ll>>(type_cnt, vector<ll>(type_cnt, 0));
    l2 = r2 = vector<vector<vector<ll>>>(type_cnt, vector<vector<ll>>(type_cnt, {0}));
    for (size_t i = 0; i < n; ++i) {
        for (int j = 0; j < type_cnt; ++j) {
            tmp_costs_l[s[i]][j] += l[j][i];
            tmp_costs_r[s[n - i - 1]][j] += r[j][n - i - 1];
        }
        for (int k = 0; k < type_cnt; ++k) {
            l2[s[i]][k].push_back(tmp_costs_l[s[i]][k]);
            r2[s[n - i - 1]][k].push_back(tmp_costs_r[s[n - i - 1]][k]);
        }
    }
    for (int i = 0; i < type_cnt; ++i) {
        for (int j = 0; j < type_cnt; ++j) {
            reverse(r2[i][j].begin(), r2[i][j].end());
        }
    }

    auto result = calc_costs();
    cout << result / 2 << ((result % 2) ? ".5" : "") << "\n";
}
