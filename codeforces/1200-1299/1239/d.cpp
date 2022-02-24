// header file
#include <bits/stdc++.h>
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
#define lim 2000005
using namespace std;
vector<int> edges[lim], component[lim];
int timer, disc[lim], low[lim], component_num[lim], component_cnt = 0;
bool valid[lim];
int s[lim], s_size = 0;
void dfs(int nd) {
    disc[nd] = low[nd] = timer++;
    s[s_size++] = nd;
    valid[nd] = 1;
    //cout << nd << endl;
    for(auto i : edges[nd]) {
        if(disc[i] == -1) {
            dfs(i);
            low[nd] = min(low[nd], low[i]);
        }
        else if(valid[i]) {
            low[nd] = min(low[nd], disc[i]);
        }
    }
    //cout << nd << " " << disc[nd] << " " << low[nd] << endl;
    if(low[nd] == disc[nd]) {
        ++component_cnt;
        do {
            component[component_cnt].pb(s[s_size - 1]);
            valid[s[s_size - 1]] = 0;
            component_num[s[s_size - 1]] = component_cnt;
            --s_size;
        } while(component[component_cnt].back() != nd);
    }
}
void tc() {
    int n, m;
    cin >> n >> m;
    timer = 0, component_cnt = 0;
    for(int i = 1; i <= 2 * n; ++i)
        edges[i].clear(), disc[i] = -1;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].pb(n + b);
        if(a == b)
            edges[n + b].pb(a);
    }
    // use connected component algo
    // all connected components with out degree 0 will have humans set to 1 and cats set to 0
    // the rest will have humans set to 0 and cats set to 1
    for(int i = 1; i <= 2 * n; ++i)
        if(disc[i] == -1)
            dfs(i);
    if(component_cnt == 1) {
        cout << "No" << endl;
        component[1].clear();
        return;
    }
    int human = 0, cat = 0;
    int humans[2 * n], cats[2 * n];
    bool done = 0;
    for(int i = 1; i <= component_cnt; ++i) {
        // check amount of out degrees
        bool invert = 1;
        for(auto j : component[i]) {
            for(auto nd : edges[j]) {
                if(component_num[nd] != component_num[j])
                    invert = 0;
            }
        }
        //cout << (int)invert << endl;
        if(invert && done)
            invert = 0;
        else if(invert)
            done = 1;
        for(auto j : component[i]) {
            if(j > n) {
                if(!invert)
                    cats[cat] = j - n, ++cat;
            }
            else {
                if(invert)
                    humans[human] = j, ++human;
            }
        }
        component[i].clear();
    }
    //if(human == 0 || cat == 0) {
    //    cout << "No" << endl;
    //    return;
    //}
    if(human == 0 || cat == 0) {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        cout << human << " " << cat << endl;
        for(int i = 0; i < human; ++i)
            cout << humans[i] << " ";
        cout << endl;
        for(int i = 0; i < cat; ++i)
            cout << cats[i] << " ";
        cout << endl;
    }
    /*
    cout << "Yes" << endl;
    cout << human << " " << cat << endl;
    for(int i = 0; i < human; ++i)
        cout << humans[i] << " ";
    cout << endl;
    for(int i = 0; i < cat; ++i)
        cout << cats[i] << " ";
    cout << endl;
    */
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}