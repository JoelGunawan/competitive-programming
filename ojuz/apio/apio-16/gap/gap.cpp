#include "gap.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long findGap(int T, int N)
{
	// can call findmax function
	// let's say range is between 1 to 1e18
	// divide n into blocks size n / k
	if(T == 1) {
		ll l = 0, r = 1e18;
		ll a[N];
		for(int i = 0; i < N / 2 + N % 2; ++i) {
			MinMax(l, r, &a[i], &a[N - i - 1]);
			l = a[i] + 1, r = a[N - i - 1] - 1;
		}
		ll mxdiff = 0;
		for(int i = 1; i < N; ++i)
			mxdiff = max(mxdiff, a[i] - a[i - 1]);
		return mxdiff;
	}
	else {
		// divide N blocks size len / N into blocks
		ll l, r;
		MinMax(0, 1e18, l, r);
		if(N == 2)
			return r - l;
		ll minres = (r - l + n - 2) / (n - 1);
		// kita query dr l + 1 ke l + min_res
		// n - 1 query total n elem?
		vector<ll> x = {l};
		for(int i = 0; i < N; ++i)
	}
	return 0;
}
