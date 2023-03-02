#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const ll maxll = 9223372036854775806;
const ll modd = 1000000007;
 
ll N, K, arr[8], temp, temp1, arrtemp[8];
map<ll, ll> memo;
map<ll, bool> vis;
queue<ll> kiu;
 
long long GCD(long long a, long long b) {
	if (b == 0) {
		return a;
	} else {
		return GCD(b, a%b);
	}
}
 
long long fact(long long a) {
	if (a == 0) {
		return 1;
	} else {
		return (a*fact(a-1))%(modd);
	}
}
 
void swap(long long *a, long long *b) {
	long long c = *a;
	*a = *b;
	*b = c;
}
 
int main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); // Use this UNLESS the question is interactive
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}
    bool is_ans = 1;
    for(int i = 1; i <= N; ++i) {
        if(arr[i - 1] != i) {
            is_ans = 0;
        }
    }
    if(is_ans)
        cout << 0 << endl, exit(0);
	cin >> K;
	temp = 0;
	for (ll i = 0; i < N; i++) {
		temp *= N;
		temp += arr[i]-1;
	}
	ll maxed = 0;
	for (ll i = 0; i < N; i++) {
		maxed *= N;
		maxed += i;
	}
	memo[temp] = 0;
	kiu.push(temp);
    vis[temp] = 1;
	while (!kiu.empty()) {
		if (kiu.front() != maxed) {
			temp1 = kiu.front();
			for (ll i = 0; i < N; i++) {
				arrtemp[N-1-i] = temp1%N;
				temp1 /= N;
			}
			// for (ll i = 0; i < N; i++) {
			// 	cout << arrtemp[i] << ' ';
			// }
			// cout << endl;
			for (ll i = 0; i <= N-K; i++) {
				temp1 = 0;
				for (ll j = 0; j < i; j++) {
					temp1 *= N;
					temp1 += arrtemp[j];
				}
				for (ll j = i; j < i+K; j++) {
					temp1 *= N;
					temp1 += arrtemp[i+i+K-1-j];
				}
				for (ll j = i+K; j < N; j++) {
					temp1 *= N;
					temp1 += arrtemp[j];
				}
				if (!vis[temp1]) {
                    vis[temp1] = 1;
					memo[temp1] = memo[kiu.front()]+1;
					kiu.push(temp1);
				}
			}
			kiu.pop();
		} else {
			break;
		}
	}
	if (memo[maxed] != 0) {
		cout << memo[maxed] << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
	// delete return 0; to do some testing below
	return 0;
}
 
// Made by: AndreaSonic (AnnoyingGuest)
 
// Notes ( May change based on my competence :] ):
// If the result is too high, pow function might use "e+[n]", which might make the judging failed. Also it is NOT PRECISE D:<
// Local variable can only handle the maximum size of 2 million (2*10^6)
// cin >> [string] will only read until a space or endline