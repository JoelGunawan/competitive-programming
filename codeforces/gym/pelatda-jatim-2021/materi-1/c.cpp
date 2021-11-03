#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}
ll powmod(ll a, ll b)
{
	if(b == 0)
		return 1;
	else
	{
		ll tmp = powmod(a, b / 2); tmp *= tmp; tmp %= mod;
		return b & 1 ? (tmp * a) % mod: tmp;
	}
}
int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	// -1 means there is an odd amount of -1
	// 1 means there is an even amount of -1
	// each row and column has to be -1
	if((n + m) % 2 == 1 && k == -1)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << powmod(powmod(2, n - 1), m - 1) << endl;
	return 0;
}