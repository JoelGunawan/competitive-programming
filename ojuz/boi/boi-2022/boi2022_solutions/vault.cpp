#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void update(int minf, int S, vector<int> &dp, int l, ll a, int w) {
  for (int s = l > 0 ? 0 : 2 * S; l > 0 ? s < l : s > 2 * S + l; s += l > 0 ? 1 : -1) {
    deque<pair<int, int>> d;
    for (int i = s; i >= 0 && i <= 2 * S; i += l) {
      while (!d.empty() && (i - d.front().first) / l > a)
        d.pop_front();
      while (!d.empty() && dp[i] >= d.back().second + (i - d.back().first) / l * w)
        d.pop_back();
      if (dp[i] > minf)
        d.emplace_back(i, dp[i]);
      if (!d.empty())
        dp[i] = max(dp[i], d.front().second + (i - d.front().first) / l * w);
    }
  }
}

int main() {
  int M;
  ll L, c = 0, s = 0;
  cin >> M >> L;
  vector<ll> A(2 * M + 1);
  for (int l = -M; l <= M; l++)
    cin >> A[l + M], s += A[l + M] * l;
  int S = M * M, minf = -2 * M - 1;
  vector<int> dp(2 * S + 1, minf);
  dp[S] = 0;
  int d = s < L ? -1 : 1;
  for (int l = -d * M; -M <= l && l <= M; l += d) {
    ll a = l == 0 || (l > 0) == (d < 0) ? A[l + M] : min(A[l + M], max(0LL, L / l));
    A[l + M] -= a;
    c += a;
    L -= a * l;
    if (l == 0)
      continue;
    update(minf, S, dp, l, A[l + M], 1);
    update(minf, S, dp, -l, a, -1);
  }
  if (-S > L || L > S || dp[L + S] == minf)
    cout << "impossible\n";
  else
    cout << dp[L + S] + c << "\n";
}