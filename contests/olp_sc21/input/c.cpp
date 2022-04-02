#include <bits/stdc++.h>
using namespace std;
map<pair<string, bool>, vector<string>> memo;
map<pair<string, bool>, bool> vis;
vector<string> get_neighbour(string s, bool up) {
    if(vis[make_pair(s, up)])
        return memo[make_pair(s, up)];
    vector<string> res;
    if(up) {
        // tambahin 1 ke posisi 0
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0') {
                string tmp = s;
                tmp[i] = '1';
                res.push_back(tmp);
            }
        }
    }
    else {
        // remove salah satu '1'
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {
                string tmp = s;
                tmp[i] = '0';
                res.push_back(tmp);
            }
        }
    }
    vis[make_pair(s, up)] = 1, memo[make_pair(s, up)] = res;
    return res;
}
int main() {
    // just need to find maximum way to handle
    // jangan pergi ke tempat yang banyak pengulangannya
    // di terakhir, ideal buat pergi ke minimalnya aja
    int n, k;
    ifstream fin;
    string tmpabc, tmpabd;
    cin >> tmpabc >> tmpabd;
    fin.open(tmpabc);
    ofstream fout;
    fout.open(tmpabd);
    fin >> n >> k;
    vector<string> ans;
    string tmpx = "";
    for(int i = 0; i < n; ++i)
        tmpx += '0';
    ans.push_back(tmpx);
    // bangun dari k previous
    map<string, bool> used;
    used[tmpx] = 1;
    int cur = 0;
    while(true) {
        if(cur > k)
            break;
        string last = ans.back();
        int one_cnt = 0;
        for(int i = 0; i < last.size(); ++i)
            if(last[i] == '1')
                ++one_cnt;
        if(one_cnt == cur) {
            //cout << "TEST" << endl;
            // try going down
            // cari yang possible neighboringnya paling banyak
            vector<string> down = get_neighbour(last, 0);
            string res = "";
            int m = 0;
            for(auto i : down) {
                if(!used[i]) {
                    if(m == 0)
                        res = i;
                    // check neighbour count
                    vector<string> tmp = get_neighbour(i, 1);
                    for(auto j : tmp) {
                        if(used[j])
                            continue;
                        vector<string> tmp2 = get_neighbour(j, 0);
                        int cnt = 0;
                        for(auto x : tmp2) {
                            if(!used[x])
                                ++cnt;
                        }
                        if(cnt >= m)
                            m = cnt, res = i;
                    }
                }
            }
            if(res.size() == 0) {
                ++cur;
            }
            else
                used[res] = 1, ans.push_back(res);
        }
        else {
            // try going up
            // try to find a tuple yang neighboring tuplenya paling banyak
            vector<string> up = get_neighbour(last, 1);
            string res = "";
            int m = 0;
            for(auto i : up) {
                //cout << "I: " << i << endl;
                if(!used[i]) {
                    if(m == 0)
                        res = i;
                    vector<string> tmp = get_neighbour(i, 0);
                    for(auto j : tmp) {
                        if(!used[j]) {
                            vector<string> tmp2 = get_neighbour(j, 1);
                            int cnt = 0;
                            for(auto x : tmp2) {
                                if(!used[x])
                                    ++cnt;
                            }
                            if(cnt >= m)
                                m = cnt, res = i;
                        }
                    }
                    //cout << endl;
                }
            }
            if(res.size() == 0)
                break;
            used[res] = 1, ans.push_back(res);
        }
    }
    fout << ans.size() << endl;
    for(auto i : ans)
        fout << i << endl;
    return 0;
}
// tolong kak gada ide :)