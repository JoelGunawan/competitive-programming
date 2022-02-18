// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
map<int, int> mapping;
vector<pair<int, int>> edges[300001];
vector<int> arrays[100001];
set<pair<int, int>> get_index[100001];
map<int, bool> used;
vector<char> ans[100001];
int edge_number = 0;
int m;
void dfs(int nd) {
    while(edges[nd].size() > 0 && used[edges[nd].back().se])
        edges[nd].pop_back();
    if(edges[nd].size() == 0)
        return;
    //cout << nd << " " << edges[nd].back().fi << endl;
    //cout << "EDGES" << endl;
    //for(auto i : edges[nd])
    //    cout << i.fi << " " << i.se << endl;
    //cout << endl;
    //cout << "END" << endl;
    // means this is a number node, not an array node
    if(nd >= m) {
        int arr = edges[nd].back().fi;
        auto it = get_index[arr].lb(mp(nd, 0));
        ans[arr][(*it).se] = 'L';
        get_index[arr].erase(it);
        used[edges[nd].back().se] = 1;
        edges[nd].pop_back();
        dfs(arr);
    }
    else {
        int number = edges[nd].back().fi;
        auto it = get_index[nd].lb(mp(number, 0));
        //cout << nd << " " << number << " " << (*it).fi << " " << (*it).se << endl;
        //for(auto i : get_index[nd])
        //    cout << i.fi << " " << i.se << endl;
        //cout << (int)(it == get_index[nd].end()) << endl;
        ans[nd][(*it).se] = 'R';
        get_index[nd].erase(it);
        used[edges[nd].back().se] = 1;
        edges[nd].pop_back();
        dfs(number);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m;
    map<int, int> cnt;
    for(int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; ++j)
            cin >> a[j], ++cnt[a[j]];
        arrays[i] = a;
    }
    bool exists = 1;
    for(auto i : cnt)
        if(i.se & 1)
            exists = 0;
    if(exists)
        cout << "YES" << endl;
    else
        cout << "NO" << endl, exit(0);
    int num = m;
    for(auto i : cnt) {
        mapping[i.fi] = num++;
    }
    for(int i = 0; i < m; ++i) {
        ans[i] = vector<char>(arrays[i].size(), 'a');
        for(int j = 0; j < arrays[i].size(); ++j) {
            get_index[i].ins(mp(mapping[arrays[i][j]], j));
            edges[mapping[arrays[i][j]]].pb(mp(i, edge_number));
            edges[i].pb(mp(mapping[arrays[i][j]], edge_number++));
        }
    }
    // euler tour
    for(int i = 0; i < m; ++i)
        dfs(i);
    for(int i = 0; i < m; ++i) {
        for(auto j : ans[i])
            cout << j;
        cout << endl;
    }
    return 0;
}