#include "energi.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second

int dp[1000001];
double psum[1000001];
deque<pair<pair<int, double>, int>> dq; //.fi.fi = dp[idx], .fi.se = psum[idx]/lim at [idx], .se = idx, front() = optimal (in theory)

bool plsNoWA(double x, int N, int K, int L, int R, std::vector<int> A) { //imagine functional TLE, could be me at this rate :')
	for (int i = 1; i <= N; i++) {
		dp[i] = 1e9;
		psum[i] = psum[i-1] + A[i-1] - x;
	}
	dq.pb({{0, 0}, 0});
	int l = L;
	int r = R;
	for (int i = L; i <= N; i++) {
		if (dp[i-L] < 1e9) {
			//pair compare -> .fi prio, .se next, else false.
			while (!dq.empty() && (dq.back().fi >= make_pair(dp[i - L], -psum[i - L]))) { //today I learnt I can't use curly braces here lmao
                dq.pop_back();
            }
            dq.pb({make_pair(dp[i - L], -psum[i - L]), i - L}); //here too for some reason??
		}
		while (!dq.empty() && dq.front().se < i-R) { //recheck
			dq.pop_front();
		}
		dp[i] = dq.front().fi.fi;
		if (dq.front().fi.se + psum[i] >= 0) {
			dp[i]++;
		}
		if (i == r) {
			l = l+L;
			r = r+R;
			if (l > i) {
				i = l-1;
			}
		}
	}
	dq.clear();
	return (dp[N] >= K);
}

double energi(int N, int K, int L, int R, std::vector<int> A) {
	double l = 0;
	double r = 1e5;
	double mid;
	for (int x = 1; x <= 69; x++) {
		mid = (l+r)/2;
		if (plsNoWA(mid, N, K, L, R, A) == true) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return l;
}

/*int main() {
    int N, K, L, R;
    std::cin >> N >> K >> L >> R;
    
    std::vector<int> A(N);
    for(auto &a : A) {
        std::cin >> a;
    }

    double answer = energi(N, K, L, R, A);

    std::cout << std::fixed << std::setprecision(8) << answer << std::endl;
    return 0;
}*/