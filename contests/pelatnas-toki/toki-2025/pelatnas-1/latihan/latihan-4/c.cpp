/* Task: Munte
 * Author: Tulba-Lecu Theodor-Gabriel
 * Time Complexity: O(N * log(N))
 * Approach: greedy
 * Asserted input for checking test validity
 */
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

#define MOD 111181111LL
#define MAXN 200000

using namespace std;

bool check_mountain(vector<int> v) {
    int n = v.size();
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == n) {
            pos = i;
            break;
        }
    }

    if (pos == 0 || pos == n - 1)
        return false;

    for (int i = 1; i <= pos; i++) {
        if (v[i - 1] >= v[i])
            return false;
    }

    for (int i = pos + 1; i < n; i++) {
        if (v[i - 1] <= v[i]) {
            return false;
        }
    }

    return true;
}

vector<int> get_vec(vector<pair<int, int>> p) {
    vector<int> v;
    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i].first != 0)
            v.push_back(p[i].first);
    }
    for (int i = p.size() - 1; i >= 0; i--) {
        if (p[i].second != 0)
            v.push_back(p[i].second);
    }

    return v;
}

int main() {
    // freopen("munte.in", "r", stdin);
    // freopen("munte.out", "w", stdout);

    int n, c;
    int full_pairs;
    int partial_pairs;
    vector<pair<int, int>> pairs;
    vector<int> found;

    assert(scanf("%d%d", &c, &n) == 2);
    assert(c == 1 || c == 2);
    assert(3 <= n && n <= MAXN);

    found.resize(n + 1, 0);
    full_pairs = n / 2;
    partial_pairs = (n + 1) / 2;
    pairs.resize(partial_pairs + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        assert(scanf("%d", &x) == 1);
        assert(found[x] == 0);
        assert(1 <= x && x <= n);
        if (i > partial_pairs)
            pairs[full_pairs + 1 - (i - partial_pairs)].second = x;
        else
            pairs[i].first = x;
    }

    for (int i = 1; i <= full_pairs; i++) {
        if (pairs[i].first > pairs[i].second) {
            swap(pairs[i].first, pairs[i].second);
        }
    }

    sort(pairs.begin() + 1, pairs.begin() + 1 + full_pairs);

    int ans = 2;
    if (check_mountain(get_vec(pairs))) {
        for (int i = 2; i <= full_pairs; i++) {
            if (pairs[i].first > pairs[i - 1].second) {
                ans = (ans * 2) % MOD;
            }
        }
    } else {
        ans = 0;
    }

    if (c == 2) {
        printf("%d\n", ans);
    } else {
        printf(ans == 0 ? "NU\n" : "DA\n");
    }

    return 0;
}