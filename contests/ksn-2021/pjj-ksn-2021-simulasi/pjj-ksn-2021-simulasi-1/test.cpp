#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define konaqua ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define otsuaqua exit(0);
 
#define debug(x) cout << #x << " => " << x << "\n"
#define all(x) x.begin(), x.end()
#define sp " "

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
const ll INFF = 1e18 + 5;
const ll INF = 1e10 + 5;
const int MX = 1e6 + 5;
const int MXL = 105;
const int mod = 1e9 + 7;
const double ERROR = 1e-7;

const ld pi = 3.14159265358979323846;
 
const int set_inf = 0x3f3f3f3f;

int n, k, q, arr[200005];
bool vis[200005];

int cur;
vector<pair<int,int>> vect, inds, inds2;

int t, x;

struct disjoint_set{
	int par[200005], len[200005];
	disjoint_set(){
		for(int i = 1; i <= 200000; i++){
			par[i] = i;
			len[i] = 1ll;
		}
	}
	int find(int u){
		return (par[u] == u) ? u : par[u] = find(par[u]);
	}
	void merge(int u, int v){
		u = find(u);
		v = find(v);
		if(u == v) return;
		cur -= len[u] * (len[u] + 1ll) / 2ll + len[v] * (len[v] + 1ll) / 2ll;
		par[u] = v;
		len[v] += len[u];
		cur += len[v] * (len[v] + 1ll) / 2ll;
	}
} dsu;

void solve(){
	cin >> n >> k >> q;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		vect.pb({arr[i] + 1, i});
	}
	sort(all(vect));
	inds.pb({0, 0});
	inds2.pb({0, 0});
	for(auto i : vect){
		vis[i.se] = 1;
		cur++;

		if(vis[i.se - 1]){
			dsu.merge(i.se, i.se - 1);
		}
		if(vis[i.se + 1]){
			dsu.merge(i.se, i.se + 1);
		}

		if(!inds.empty() && inds.back().fi == i.fi){
			inds[inds.size() - 1].se = cur;
			inds2[inds2.size() - 1].fi = cur;
		}
		else{
			inds.pb({i.fi, cur});
			inds2.pb({cur, i.fi});
		}
	}
	int days = 0;
	while(q--){
		cin >> t >> x;
		if(t == 1){
			x -= days * k;
			if(x <= 0){
				cout << 0 << "\n";
			}
			else{
				pair <int,int> p = {x, 1e18 + 7ll};
				int res = upper_bound(inds.begin(), inds.end(), p) - inds.begin() - 1;
				cout << inds[res].se << "\n";
			}
		}
		else if(t == 2){
			if(x == 0){
				cout << 1 << "\n";
			}
			else if(x > inds2.back().fi){
				cout << -1 << "\n";
			}
			else{
				pair <int,int> p = {x, -69ll};
				int res = lower_bound(inds2.begin(), inds2.end(), p) - inds2.begin();
				cout << inds2[res].se + k * days << "\n";
			}
		}
		days++;
	}
}

signed main(){
	konaqua;
	solve();
	otsuaqua;
}