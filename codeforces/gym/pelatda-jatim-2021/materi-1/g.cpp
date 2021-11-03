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
	int t;
	cin >> t;
	while(t--)
	{
		int x, y;
		cin >> x >> y;
		if(x == y || y % x == 0)
			cout << x << endl;
		else if(x > y)
			cout << x + y << endl;
		else
			cout << y - (y % x / 2) << endl;
		/*
		for(int i = 1; i <= 1e3; ++i)
			if(i % x == y % i)
			{
				cout << i << endl;
			}
		*/
		cout << endl;
	}
	return 0;
}