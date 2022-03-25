#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
struct segtree {
	ll a[1 << 20], arr_size = 1 << 19;
	segtree() {
		memset(a, 0, sizeof(a));
	}
	void update(int idx, ll val) {
		idx += arr_size;
		a[idx] = val;
		idx >>= 1;
		while(idx > 0) {
			a[idx] = max(a[idx << 1], a[(idx << 1) + 1]);
			idx >>= 1;
		}
	}
	ll query(int nd, int l, int r, int cl, int cr) {
		if(cl >= l && cr <= r) {
			return a[nd];
		}
		else if(cl > r || cr < l) 
			return -2e18;
		else {
			int mid = (cl + cr) / 2;
			return max(query(2 * nd, l, r, cl, mid), query(2 * nd + 1, l, r, mid + 1, cr));
		}
	}
	ll query(int l, int r) {
		return query(1, l, r, 0, arr_size - 1);
	}
};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> A, C;
	int N;
	cin >> N;
	vector<int> indices;
	bool vis[N + 1];
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if(a != -1) {
			vis[a] = 1;
		}
		A.push_back(a);
		// write code here
	}
	for(int i = 0; i < N; ++i){
		int c;
		cin >> c;
		C.push_back(c);
	}
	vector<int> unvis;
	for(int i = N; i >= 1; --i)
		if(!vis[i])
			unvis.push_back(i);
	ll tmp = 0;
	for(int i = 0; i < N; ++i) {
		tmp += C[N - i - 1];
		cout << tmp << " ";
	}
	cout << endl;
	/*
	// write code here
	// some sort of weighted longest increasing subsequence, where the longest increasing subsequence has weight
	// use max query segment tree to maintain previous maximum subsequence value
	// no duplicates because strictly increasing
	// O(n^2logn) because we can insert n indices at one position
	segtree seg;
	int largest = 0;
	// seg[i] -> previous max element is i
	// dp[i][j] = dp[i - 1][1 ... j - 1] + C[x] OR dp[i][j] = dp[i - 1][j];
	// syarat transisi 1 -> 
	// syarat transisi 2 -> 
	// unvis yang bisa digunakan pasti berkurang
	// pop back dari unvis
	for(int i = 0; i < N; ++i) {
		if(A[i] == -1) {
			for(int i : unvis) {
				// update from large to small to avoid collisions/double count
				//cout << i << endl;
				if(largest < i)
					seg.update(i, max(seg.query(largest, i - 1) + C[i - 1], seg.query(i, i)));
			}
			largest = max(largest, unvis.back());
			unvis.pop_back();
		}
		else {
			//cout << seg.query(0, A[i] - 1) << " " << seg.query(A[i], N) << endl;
			if(largest < A[i])
				seg.update(A[i], max(seg.query(largest, A[i] - 1) + C[A[i] - 1], seg.query(A[i], A[i])));
			largest = max(largest, A[i]);
		}
		//for(int j = 1; j <= N; ++j) {
		//	cout << seg.query(j, j) << " ";
		//}
		//cout << endl;
		cout << seg.query(0, N) << " ";
	}
	cout << endl;
	*/
	// find longest increasing subsequence with a series of insertions
	// 
	return 0;
}
