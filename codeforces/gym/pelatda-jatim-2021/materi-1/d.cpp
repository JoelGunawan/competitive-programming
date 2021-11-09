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
	int n;
	cin >> n;
	ll a = 0, prev_a = 0, b = 0, prev_b = 0, c = 0, prev_c = 0, d = 0, prev_d = 1;
	for(int i = 0; i < n; ++i)
	{
		a = (prev_b + prev_c + prev_d) % mod;
		b = (prev_a + prev_c + prev_d) % mod;
		c = (prev_a + prev_b + prev_d) % mod;
		d = (prev_a + prev_b + prev_c) % mod;
		prev_a = a;
		prev_b = b;
		prev_c = c;
		prev_d = d;
		//cout << a << " " << b << " " << c << " " << d << endl;
	}
	cout << d << endl;
	return 0;
}