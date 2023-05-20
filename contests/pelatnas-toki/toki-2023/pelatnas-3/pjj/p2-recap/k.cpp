#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 150005;
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    int q(int idx) {
        int res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
    int q(int l, int r) {
        return q(r) - q(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    // buat yg <= sqrt(n) ukuran subway line nya di shift manual terus ditambahin di setiap blok
    // buat yg > sqrt(n) ukuran subway line nya di simpan di satu tempat sendiri, nanti tiap subway linenya
    // dihitung manual berapa berdasarkan shiftnya
    // shiftnya itu 1 doang
    vector<int> line[m + 1], a[m + 1];
    int linenum[n + 1], shift[m + 1];
    memset(shift, 0, sizeof(shift));
    fenwick bit;
    for(int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        line[l].push_back(i);
        linenum[i] = l;
    }
    int blk = 200;
    int val[n + 1];
    vector<int> large;
    for(int i = 1; i <= n; ++i) {
        int cnt;
        cin >> cnt;
        val[i] = cnt;
        if(line[linenum[i]].size() <= blk) {
            a[linenum[i]].push_back(cnt);
            bit.upd(i, cnt);
        }
        else {
            if(a[linenum[i]].size())
                a[linenum[i]].push_back(cnt + a[linenum[i]].back());
            else
                a[linenum[i]].push_back(cnt), large.push_back(linenum[i]);
        }
    }
    int memo[large.size()][n + 1];
    memset(memo, -1, sizeof(memo));
    int tmpidx = 0;
    for(auto i : large) {
        for(int j = 0; j < line[i].size(); ++j) {
            a[i].push_back(val[line[i][j]] + a[i].back());
            memo[tmpidx][line[i][j]] = j;
        }
        for(int j = 1; j <= n; ++j) {
            if(memo[tmpidx][j] == -1)
                memo[tmpidx][j] = memo[tmpidx][j - 1];
        }
        ++tmpidx;
    }
    vector<int> tmp(n + 1);
    for(int qe = 0; qe < q; ++qe) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            // proc large manual
            int out = 0, idx = 0;
            for(auto i : large) {
                // i itu linenum nya
                int x = memo[idx][l - 1]
                , y = memo[idx][r];
                ++idx;
                if(x == y) {
                    // no need to do anything
                    continue;
                }
                x += shift[i], y += shift[i];
                //cout << x << " " << y << endl;
                if(x == -1)
                    out += a[i][y];
                else
                    out += a[i][y] - a[i][x];
            }
            //cout << out << endl;
            cout << out + bit.q(l, r) << endl;
        }
        else {
            int x;
            cin >> x;
            // shift x
            if(line[x].size() <= blk) {
                // berarti ini shift manual
                for(int i = 0; i < line[x].size(); ++i) {
                    if(i == 0)
                        tmp[i] = a[x][i + line[x].size() - 1];
                    else
                        tmp[i] = a[x][i - 1];
                }
                //for(auto i : a[x])
                //    cout << i << " ";
                //cout << endl;
                //for(auto i : tmp)
                //    cout << i << " ";
                //cout << endl;
                for(int i = 0; i < line[x].size(); ++i)
                    bit.upd(line[x][i], -a[x][i] + tmp[i]), a[x][i] = tmp[i];
            }
            else {
                --shift[x];
                if(shift[x] < 0)
                    shift[x] += line[x].size();
            }
        }
    }
}