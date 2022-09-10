### <center>Pusat Perbelanjaan <br/></center>

#### Problem Meta
Expected Difficulty : 1700
Problemsetter : Joel Gunawan
Time Limit : 2 detik
Memory Limit : 256 MB
Tags : Graph, Sortings, DP

#### Deskripsi Soal
Di Dengkleknesia, terhadap $n$ bangunan dan $m$ jalan. Tentu saja, di tiap negara pasti ada pusat perbelanjaan, diketahui bahwa di dengkleknesia terhadap $k$ pusat perbelanjaan, di bangunan $A_1, A_2, ..., A_k$. Bangunan yang tidak digunakan untuk pusat perbelanjaan digunakan untuk rumah. Jalan ke-$i$ di Dengkleknesia menghubungkan bangunan $U_i$ ke $V_i$ dan sebaliknya. Jalan ke-$i$ dapat dilewati dalam waktu $T_i$. Pak Dengklek ingin mengevaluasi desain negaranya, maka Pak Dengklek akan menanyakan $Q$ pertanyaan terhadap anda. Pertanyaan ke-$i$ akan menanyakan hasil penjumlahan tingkat kepuasan tiap orang pada waktu $X_i$. Tingkat kepuasan seseorang pada waktu $y$ adalah banyak jalan tercepat menuju sebuah pusat perbelanjaan sehingga waktu yang dibutuhkan $\leq y$. Karena hasilnya bisa sangat besar, maka carilah jawaban modulo $10^9+7$

#### Constraints
- $1 \leq N, M, Q \leq 4 \times 10^5$
- $1 \leq K, U, V \leq N$
- $1 \leq T_i \leq 10^9$
- $X_i$ muat dalam signed integer 64 bit
#### Format Input
<pre>
N M K Q 
A<sub>1</sub> A<sub>1</sub> ... A<sub>K</sub>
U<sub>1</sub> V<sub>1</sub> T<sub>1</sub>
U<sub>2</sub> V<sub>2</sub> T<sub>2</sub>
...
U<sub>M</sub> V<sub>M</sub> T<sub>M</sub>
X<sub>1</sub>
X<sub>2</sub>
...
X<sub>Q</sub>
</pre>


#### Format Output

Keluarkan $Q$ bilangan, bilangan ke-$i$ merupakan hasil penjumlahan tingkat kepuasaan tiap orang pada waktu pertanyaan ke-$i$ modulo $10^9+7$

#### Contoh Input
```
5 4 2 4
1 4
1 2 3
2 3 2
1 3 6
4 5 1
1
3
5
10000
```

#### Contoh Output
```
1 2 3 3
```

#### Penjelasan
Pada waktu $1$, tingkat kepuasan tiap orang $0$, kecuali orang yang ada di bangunan $5$ dengan tingkat kepuasan $1$
Pada waktu $3$, tingkat kepuasan orang di bangunan ke-$5$ adalah $1$, dan tingkat kepuasan orang di bangunan ke-$2$ adalah $1$
Pada waktu $5$, tingkat kepuasan tiap orang $1$
Pada waktu $10000$, tingkat kepuasan tiap orang $1$

#### Subtask (bila ada)
##### Subtask 1
- $N \leq 2000$
- $Q = 1$
##### Subtask 2
- $Q = 1$
#### Subtask 3
- No Additional Constraints

#### Editorial

Kita dapat menggunakan multisource dijkstra dari tiap pusat perbelanjaan untuk mencari banyak shortest path dari pusat perbelanjaan ke tiap bangunan. Untuk memproses query, kita proses saat kita sedang melakukan dijkstra. Sebelum dijkstra dijalankan, kita sort dulu query dan saat dijkstra kita tambahkan case untuk proses query.

#### Solution (Code)
```c++
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    int a[k];
    for(int i = 0; i < k; ++i)
        cin >> a[i];
    priority_queue<pair<ll, pair<int, int>>> dj;
    for(int i = 0; i < k; ++i)
        dj.push(mp(0, mp(a[i], 0)));
    vector<pair<int, int>> edges[n + 1];
    for(int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges[u].pb(mp(v, t));
        edges[v].pb(mp(u, t));
    }
    ll dist[n + 1], dp[n + 1];
    memset(dp, 0, sizeof(dp));
    memset(dist, -1, sizeof(dist));
    dp[0] = 1;
    pair<int, int> queries[q];
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        queries[i] = mp(x, i);
    }
    sort(queries, queries + q);
    int ans[q];
    int q_idx = 0;
    ll total = 0;
    while(!dj.empty()) {
        ll cur = -dj.top().fi; int nd = dj.top().se.fi, pr = dj.top().se.se;
        while(q_idx < q && queries[q_idx].fi < cur)
            ans[queries[q_idx].se] = total, ++q_idx;
        dj.pop();
        if(dist[nd] < cur && dist[nd] != -1)
            continue;
        dist[nd] = cur;
        if(cur != 0)
            total += dp[pr];
        dp[nd] += dp[pr];
        if(total >= mod)
            total -= mod;
        if(dp[nd] >= mod)
            dp[nd] -= mod;
        for(auto i : edges[nd]) {
            if(dist[i.fi] == -1 || dist[i.fi] == cur + i.se)
                dj.push(mp(-(cur + i.se), mp(i.fi, nd)));
        }
    }
    while(q_idx < q)
        ans[queries[q_idx].se] = total, ++q_idx;
    for(int i = 0; i < q; ++i)
        cout << ans[i] << " ";
    cout << endl;
}
```