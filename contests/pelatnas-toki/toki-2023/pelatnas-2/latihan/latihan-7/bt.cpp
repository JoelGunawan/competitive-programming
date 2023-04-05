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
int to_num(string s) {
    int num = 0;
    if(s[0] <= '9')
        num += (s[0] - '0');
    else if(s[0] <= 'Z')
        num += s[0] - 'A' + 10;
    else
        num += s[0] - 'a' + 36;
    num *= 62;  
    if(s[1] <= '9')
        num += (s[1] - '0');
    else if(s[1] <= 'Z')
        num += s[1] - 'A' + 10;
    else
        num += s[1] - 'a' + 36;
    return num;
}
string to_str[5000];
vector<int> edges[5000];
int in[5000];
vector<int> res;
void dfs(int nd) {
    // euler path -> hapus edge
    while(edges[nd].size()) {
        int tmp = edges[nd].back();
        edges[nd].pop_back();
        dfs(tmp);
    }
    res.pb(nd);
}
string get_ans(int n, vector<string> a) {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    for(int i = 1; i <= 5000; ++i)
        edges[i].clear();
    memset(in, 0, sizeof(in));
    res.clear();
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
    for(auto s : a) {
        if(n == 1)
            return s;
        to_str[to_num(s.substr(0, 2))] = s.substr(0, 2);
        to_str[to_num(s.substr(1, 2))] = s.substr(1, 2);
        edges[to_num(s.substr(0, 2))].pb(to_num(s.substr(1, 2)));
        ++in[to_num(s.substr(1, 2))];
        //cout << to_num(s.substr(0, 2)) << " " << s.substr(0, 2) << " " << to_num(s.substr(1, 2)) << " " << s.substr(1, 2) << endl;
    }
    // dfs aja tiap edge?
    int odd = 0, oddin = -1, oddout = -1;
    for(int i = 0; i < 3845; ++i) {
        if(edges[i].size() == in[i]) 
            continue;
        else if(edges[i].size() == in[i] + 1)
            oddout = i, ++odd;
        else if(edges[i].size() + 1 == in[i])
            oddin = i, ++odd;
        else {
            return "?";
        }
    }
    //cout << odd << " " << oddin << " " << oddout << endl;
    if(odd > 2 || odd == 1 || (odd == 2 && (oddout == -1 || oddin == -1))) {
        return "?";
    }
    if(odd == 2) {
        dfs(oddout);
    }
    else {
        for(int i = 0; i <= 3844; ++i) {
            if(edges[i].size()) {
                dfs(i);
                break;
            }
        }
    }
    reverse(res.begin(), res.end());
    string ret = "";
    if(res.size() % 2 == 0) {
        for(int i = 0; i < res.size(); i += 2)
            ret += to_str[res[i]];
        char fin;
        if(res.back() % 62 < 10)
            fin = res.back() % 62 + '0';
        else if(res.back() % 62 < 36)
            fin = (res.back() - 10) % 62 + 'A';
        else
            fin = (res.back() - 36) % 62 + 'a';
        ret += fin;
    }
    else {
        for(int i = 0; i < res.size(); i += 2)
            ret += to_str[res[i]];
    }
    return ret;
    // else try to find answer
    // just use random dfs?
}
int main() {
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    while(true) {
       string s;
        int tmp2 = rnd();
        if(tmp2 < 0)
            tmp2 = -tmp2;
        tmp2 %= 16;
        if(tmp2 < 3)
            continue;
        for(int i = 0; i < tmp2; ++i) {
            int tmp = rnd();
            if(tmp < 0)
                tmp = -tmp;
            char fin;
            if(true)
                fin = tmp % 10 + '0';
            else if(tmp % 62 < 36)
                fin = (tmp - 10) % 62 + 'A';
            else
                fin = (tmp - 36) % 62 + 'a';
            s += fin;
        }
        vector<string> arr, arr2;
        for(int i = 0; i < s.size() - 2; ++i)
            arr.pb(s.substr(i, 3));
        string tmp = get_ans(s.size() - 2, arr);
        sort(arr.begin(), arr.end());
        if(tmp.size() != s.size()) {
            cout << s << " " << tmp << endl;
            break;
        }
        for(int i = 0; i < tmp.size() - 2; ++i) {
            arr2.pb(tmp.substr(i, 3));
        }
        sort(arr2.begin(), arr2.end());
        if(arr != arr2) {
            cout << s << " " << tmp << endl;
            break;
        }
    }
}