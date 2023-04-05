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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int f(char a) {
    if(a <= '9')
        return a - '0';
    else if(a <= 'Z')
        return a - 'A' + 10;
    else
        return a - 'a' + 36;
}
int to_num(string s) {
    int num = 0;
    //cout << s << endl;
    assert((s[0] >= '0' && s[0] <= '9') || (s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' <= s[0] <= 'z'));
    assert((s[1] >= '0' && s[1] <= '9') || (s[1] >= 'A' && s[1] <= 'Z') || (s[1] >= 'a' <= s[1] <= 'z'));
    num += f(s[0]);
    num *= 62;
    num += f(s[1]);
    return num;
}
string to_str[5000];
vector<int> edges[5000];
int in[5000];
vector<int> res = {};
void dfs(int nd) {
    // euler path -> hapus edge
    while(edges[nd].size()) {
        int tmp = edges[nd].back();
        edges[nd].pop_back();
        dfs(tmp);
    }
    res.pb(nd);
}
char to_char[500];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // maximum matching?
    // abc
    // harus dipasangkan dengan previous ab dan dengan next bc
    // kalo dijadikan graph, mulai dari sebuah node, dia harus membentuk path
    // directed graph with N edges and (62*62) nodes
    // harus melewati tiap edge tepat sekali
    // indegree and outdegree
    // random dfs is okay?
    // if all indegree/outdegree even -> try dfs from every node
    // else -> try from indegree + 1 node and outdegree + 1 node
    // directed graph -> use scc?
    // euler path in directed graph???
    // obs: inside every scc klo jumlah indegree = jumlah outdegree semua kecuali yg in/out di scc, pasti tiap edge di scc itu bs buat euler path
    // gimana cara cari path yg valid?
    // buat jadi per component, nanti per component cek internal edges nya berapa aja
    // in degree maks 1
    // out degree maks 1
    // nanti jadinya seperti garis
    // nanti buat banyak cycle, obs: ga mungkin dari yg bs cycle jadi gabisa cycle
    // make arbitrary cycles inside the scc, eventually you will find the answer :D
    // obs: pasti ada 1 cycle yang lewat semua node di scc?
    // atau nanti pasti ada intersect jadi santai aja :D
    // dr luar ada 1 edge dateng, nanti kita mulai dfs dr situ aja
    // kalo gada edge luar, berarti ada edge KELUAR
    // buat seperti 
    // ga usah pake scc, langsung pakai dfs euler path biasa?
    vector<char> tmp;
    for(int i = 0; i < 10; ++i) {
        tmp.pb('0' + i);
    }
    for(int i = 0; i < 26; ++i) {
        tmp.pb('A' + i);
    }
    for(int i = 0; i < 26; ++i) {
        tmp.pb('a' + i);
    }
    for(int i = 0; i < tmp.size(); ++i) {
        to_char[i] = tmp[i];
        for(int j = 0; j < tmp.size(); ++j) {
            string s = "";
            s += tmp[i];
            s += tmp[j];
            to_str[to_num(s)] = s;
        }
    }
    int n;
    cin >> n;
    // harusnya ? tapi ga output ?
    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        edges[to_num(s.substr(0, 2))].pb(to_num(s.substr(1, 2)));
        ++in[to_num(s.substr(1, 2))];
        //cout << to_num(s.substr(0, 2)) << " " << s.substr(0, 2) << " " << to_num(s.substr(1, 2)) << " " << s.substr(1, 2) << endl;
    }
    // dfs aja tiap edge?
    // kenapa error? kurang kasus not possiblenya
    int odd = 0, oddin = -1, oddout = -1;
    for(int i = 0; i <= 4500; ++i) {
        if(edges[i].size() == in[i]) 
            continue;
        else if(edges[i].size() == in[i] + 1)
            oddout = i, ++odd;
        else if(edges[i].size() + 1 == in[i])
            oddin = i, ++odd;
        else {
            cout << "?" << endl;
            return 0;
        }
    }
    //cout << oddin << " " << oddout << endl;
    if((odd == 0) || (odd == 2 && oddout != -1 && oddin != -1)) {

    }
    else {
        cout << "?" << endl;
        return 0;
    }
    if(odd == 2) {
        edges[oddin].pb(oddout);
        dfs(oddin);
        res.pop_back();
    }
    else {
        for(int i = 0; i <= 4500; ++i) {
            if(edges[i].size()) {
                dfs(i);
                break;
            }
        }
    }
    reverse(res.begin(), res.end());
    //reverse(res.begin(), res.end());
    //for(auto i : res)
    //    cout << to_str[i] << " ";
    string output = "";
    if(res.size() % 2 == 0) {
        for(int i = 0; i < res.size(); i += 2)
            output += to_str[res[i]];
        output += to_char[res.back() % 62];
    }
    else {
        for(int i = 0; i < res.size(); i += 2)
            output += to_str[res[i]];
    }
    if(output.size() == n + 2) {
        cout << output << endl;
    }
    else
        cout << "?" << endl;
    // else try to find answer
    // just use random dfs?
    return 0;
}