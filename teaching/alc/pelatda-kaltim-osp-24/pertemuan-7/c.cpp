#include <bits/stdc++.h>

using namespace std;

int main() {
	int m,n;
	cin >> m >> n;
	int p = m - n;
	int sum = 1;
	for (int i = m; i >= m-p; i--){
		sum *= i;
	}
	cout << sum;
}

// p = m!/(n-m)!
// p = m!/p!
// p = m
