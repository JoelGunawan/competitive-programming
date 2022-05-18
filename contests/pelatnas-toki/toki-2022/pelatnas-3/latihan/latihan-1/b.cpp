// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 2e5 + 5;
set<int> occurences[lim];
int a[lim], n;
ll m;
pair<int, int> nxt[lim];
bool vis[lim];
vector<int> nodes;
void dfs(int nd) {
    vis[nd] = 1;
    nodes.pb(nd);
    // find next occurence of a[(nd % n) + 1]
    int u = nd % n + 1;
    pair<int, int> del;
    // find in occurences the next occurence of a[u]
    //cout << nd << " " << "DFSTEST" << endl;
    if(occurences[a[u]].ub(u) == occurences[a[u]].end())
        del = mp(*occurences[a[u]].begin(), 1);
    else
        del = mp(*occurences[a[u]].ub(u), 0);
    if(nd == n)
        ++del.se;
    nxt[nd] = del;
    if(!vis[del.fi])
        dfs(del.fi);
    else
        nodes.pb(del.fi);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        cin >> a[i], occurences[a[i]].ins(i);
    // find loop based on last empty state for each index
    // do a kind of dfs search and add edges
    // for each empty state, save where the next empty state will be, either in the same loop or in the next loop
    // initial state -> empty at 0/n
    dfs(n);
    // go to nxt manually
    // until find a loop
    int last_empty;
    if(nodes.back() == n) {
        // find length of node   
        pair<int, int> cur = {n, 0};
        // fi -> node, se -> row
        //cout << "STACKTEST" << endl;
        for(int i = 0; i < nodes.size() - 1; ++i) {
            int tmp = nodes[i];
            cur.se += nxt[tmp].se;
            cur.fi = nxt[tmp].fi;
            //cout << cur.fi << " " << cur.se << endl;
        }
        cur.se = max(cur.se, 1);
        m %= cur.se;
        vector<int> tmp;
        //cout << m << endl;
        cur.fi = n, cur.se = 0;
        for(int i = 0; i < nodes.size(); ++i) {
            int tmp = nodes[i];
            //cout << cur.fi << " " << cur.se << endl;
            if(cur.se + nxt[tmp].se > m)
                break;
            cur.se += nxt[tmp].se;
            cur.fi = nxt[tmp].fi;
        }
        set<int> num;
        //cout << cur.fi << " " << cur.se << endl;
        if(cur.se != m)
            cur.fi = 0;
        for(int i = cur.fi + 1; i <= n; ++i) {
            if(num.find(a[i]) != num.end()) {
                while(num.find(a[i]) != num.end())  
                    num.erase(num.find(tmp.back())), tmp.pop_back();   
            }
            else
                tmp.pb(a[i]), num.ins(a[i]);
        }
        if(tmp.size() == 0)
            cout << -1 << endl;
        else {
            for(auto i : tmp)
                cout << i << " ";
            cout << endl;
        }
    }
    else {
        //cout << "TEST " << nodes.back() << endl;
        pair<int, int> cur = {n, 0};
        int idx = -1;
        for(int i = 0; i < nodes.size(); ++i) {
            int tmp = nodes[i];
            if(cur.se + nxt[tmp].se > m)
                break;
            if(nodes[i] == nodes.back()) {
                idx = i;
                break;
            }
            cur.fi = nxt[tmp].fi;
            cur.se += nxt[tmp].se;
        }
        if(idx == -1) {
            // directly end
            vector<int> res;
            set<int> num;
            if(cur.se != m)
                cur.fi = 0;
            for(int i = cur.fi + 1; i <= n; ++i) {
                if(num.find(a[i]) != num.end()) {
                    while(num.find(a[i]) != num.end())  
                        num.erase(num.find(res.back())), res.pop_back();   
                }
                else
                    res.pb(a[i]), num.ins(a[i]);
            }
            if(res.size() == 0)
                cout << -1 << endl;
            else {
                for(auto i : res)
                    cout << i << " ";
                cout << endl;
            }
        }
        else {
            // go to cycle
            m -= cur.se;
            cur.se = 0;
            vector<int> cycle;
            for(int i = idx; i < nodes.size(); ++i)
                cycle.pb(nodes[i]);
            for(int i = 0; i < cycle.size() - 1; ++i) {
                int tmp = cycle[i];
                cur.fi = nxt[tmp].fi;
                cur.se += nxt[tmp].se;
            }           
            cur.se = max(cur.se, 1);
            m %= cur.se;
            for(int i = 0; i < cycle.size(); ++i) {
                int tmp = cycle[i];
                if(cur.se + nxt[tmp].se > m)
                    break;
                cur.fi = nxt[tmp].fi;
                cur.se += nxt[tmp].se;
            }
            vector<int> res;
            set<int> num;
            if(cur.se != m)
                cur.fi = 0;
            for(int i = cur.fi + 1; i <= n; ++i) {
                if(num.find(a[i]) != num.end()) {
                    while(num.find(a[i]) != num.end())  
                        num.erase(num.find(res.back())), res.pop_back();   
                }
                else
                    res.pb(a[i]), num.ins(a[i]);
            }
            if(res.size() == 0)
                cout << -1 << endl;
            else {
                for(auto i : res)
                    cout << i << " ";
                cout << endl;
            }
        }
    }
    return 0;
}