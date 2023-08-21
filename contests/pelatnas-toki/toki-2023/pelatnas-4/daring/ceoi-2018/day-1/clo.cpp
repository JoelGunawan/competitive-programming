#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct computer {
    int core, clock, price, type;
};
bool csortclock(computer a, computer b) {
	if(a.clock == b.clock)
		return a.type > b.type;
	else
    return a.clock < b.clock;
}
bool csortprice(computer a, computer b) {
    return a.price < b.price;
}
int main() {
    // sub 1 -> bitmask computer yg dibeli, terus habis itu, selalu ambil yg mau dipake dari yang paling besar
    // jadi nanti semacam dp aja (DP nya berdasarkan core clock aja :D)
    // dp statenya core yg udah diambil, tp nnti corenya itu monotonic
    // for given core yg udh diambil, cari max price yg didapet brp
    // sub 3 -> greedy by highest price for order, terus nanti beli while making a profit
    // sub 3 -> coba dr order highest clock, terus coba beli buat order itu
    // , tp nnti bs dituker buat order lebih kecil?
    // for every config, coba 
    // sub 3 idea: coba cek berapa mana yg kita bisa beli ttp profit?
    int n;
    cin >> n;
    computer a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].core >> a[i].clock >> a[i].price, a[i].type = 0;
    int m;
    cin >> m;
    computer b[m];
    for(int i = 0; i < m; ++i)
        cin >> b[i].core >> b[i].clock >> b[i].price, b[i].type = 1;
    // sub 1    
    /*
    ll res = 0;
    for(int i = 0; i < (1 << n); ++i) {
        // for this submask, coba cek corenya itu brp aja
        // core selalu diambil dari highest frequency?
        // not neccessarily, i mean ambil dr highest frequency bs "lebih optimal" tp dua"nya ttp bs
        vector<int> cores;
        ll cur = 0;
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < a[j].core; ++k)
                cores.push_back(a[i].clock), cur -= a[i].price;
        }
        cores.push_back(0);
        sort(cores.begin(), cores.end());
        ll dp[cores.size()];
        memset(dp, 0, sizeof(dp));
        for(int j = 0; j < m; ++j) {

        }
    }
    */
    // sub 3
    /*
    ll pr_res = 0;
    vector<order> cur;
    for(int i = 0; i < m; ++i) {
        // masukkin order ke i
        ll cur_res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        cur.push_back(b[i]);
        sort(cur.begin(), cur.end(), osortclock);
        vector<order> tmp = cur;
        for(auto j : tmp)
            cur_res += j.price;
        //cout << "TOTAL " << cur_res << endl;
        bool inval = 0;
        for(int j = 0; j < n; ++j) {
            while(pq.size() && tmp.size() && tmp.back().clock > a[j].clock)
                cur_res -= pq.top(), pq.pop(), tmp.pop_back();
            if(tmp.size() && tmp.back().clock > a[j].clock) {
                inval = 1;
                break;
            }
            pq.push(a[j].price);
        }
        while(pq.size() && tmp.size())
            cur_res -= pq.top(), pq.pop(), tmp.pop_back();
        if(cur_res < pr_res || tmp.size() || inval)
            cur.erase(lower_bound(cur.begin(), cur.end(), b[i]));
        else
            pr_res = cur_res;
    }
    cout << pr_res << endl;
    */
   // sub 4
   // same clock
   // find cost for each core cost, later knapsack
   /*
   int total_cores = 0;
   for(int i = 0; i < n; ++i)
    total_cores += a[i].core;
   ll cost[total_cores + 1];
   fill(cost, cost + total_cores + 1, 1e18);
   cost[0] = 0;
   for(int i = 0; i < n; ++i) {
    for(int j = total_cores; j >= a[i].core; --j) {
        cost[j] = min(cost[j], cost[j - a[i].core] + a[i].price);
    }
   }
   // dp knapsack otw
   ll dp[2][total_cores + 1];
   memset(dp, 0, sizeof(dp));
   for(int i = 0; i < m; ++i) {
    int cur = i & 1, pr = cur ^ 1;
    for(int j = 0; j <= total_cores; ++j) {
        dp[cur][j] = dp[pr][j];
        if(j >= b[i].core)
            dp[cur][j] = max(dp[cur][j], dp[pr][j - b[i].core] + b[i].price);
    }
   }
   ll res = 0;
   for(int i = 0; i <= total_cores; ++i) {
    res = max(res, dp[(m - 1) & 1][i] - cost[i]);
   }
   cout << res << endl;
   */
  // full sol
  // sort all by freq
  // for order, find closest computer core clock that is larger
  // dp state -> residual cores (1e5)
  // dp transition:
  // buy computer -> increase residual cores, dp[j] = max(dp[j], dp[j - a[i].core] - a[i].price);
  // fulfil order -> reduce residual cores, dp[j] = max(dp[j], dp[j + b[i].core] + b[i].price);
  int total_cores = 0;
  for(int i = 0; i < n; ++i)
    total_cores += a[i].core;
  ll dp[total_cores + 1];
  fill(dp, dp + total_cores + 1, -1e18);
  dp[0] = 0;
  vector<computer> v;
  for(int i = 0; i < n; ++i)
		v.push_back(a[i]);
	for(int i = 0; i < m; ++i)
		v.push_back(b[i]);
	sort(v.begin(), v.end(), csortclock);
	while(v.size()) {
		computer c = v.back();
		v.pop_back();
		if(c.type == 0) {
			for(int i = total_cores; i >= c.core; --i) {
				dp[i] = max(dp[i], dp[i - c.core] - c.price);
			}
		}
		else {
			for(int i = 0; i + c.core <= total_cores; ++i) {
				dp[i] = max(dp[i], dp[i + c.core] + c.price);
			}
		}
	}
	ll res = 0;
	for(int i = 0; i <= total_cores; ++i)
		res = max(res, dp[i]);
	cout << res << endl;
}