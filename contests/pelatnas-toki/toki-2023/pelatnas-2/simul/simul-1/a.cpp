// aku nanti bakal buka 2 chrome takut klo g sengaja ketutup susah internetnya :D
#include <bits/stdc++.h>
using namespace std;
bool target[300005];
vector<int> adj[300005];
int dfs(int nd) {
    //cout << nd << " " << adj[nd].size() << endl;
    if(target[nd])
        return 1;
    else {
        int res = 0;
        for(auto i : adj[nd])
            res += dfs(i);
        return res;
    }
}
int main() {
    // 6 -> 36 unlimited
    // 36 -> 216 boleh 7 aja
    // 216 -> 216 boleh 1 aja
    int group_sz[] = {6, 36, 216};
    // coba edges di dfs
    // dari tiap node, bisa ke node lain ga?
    for(int tc = 0; tc <= 7; ++tc) {
        ifstream fin("trombosit_" + to_string(tc) + ".in");
        ofstream fout("trombosit_" + to_string(tc) + ".out");
        // buat group sizenya agak ribet, buat pake bagi 36 aja, terus tinggal duplikat seperlunya
        int n, pmin, pmax, mmax, s;
        fin >> n >> pmin >> pmax >> mmax >> s;
        cout << n << endl;
        int grp_cnt = ceil(n / 216.0);
        // buat group size 216 nya grp_cnt kali buat tiap sisi
        int ref1 = 1e5, ref2 = 2e5; // (untuk node baru)
        // buat grup size 6, habis itu buat grup size 36
        // dari grup size 36 buat grup size 216
        // atau bs rekursif dri grup size 216 dulu
        int grp[n + 1][3], use[n + 1][3], rep1[100005], rep2[100005];
        memset(rep1, -1, sizeof(rep1));
        memset(rep2, -1, sizeof(rep2));
        memset(use, 0, sizeof(use));
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < n; ++j)
                grp[j + 1][i] = j / group_sz[i];
        } 
        // buat yang size 6 dulu
        vector<pair<int, int>> edges;
        for(int i = 1; i <= n; ++i) {
            rep1[i] = grp[i][0] + ref1;
            rep2[i] = grp[i][0] + ref2;
            edges.push_back({i, ref1 + grp[i][0]});
            edges.push_back({ref2 + grp[i][0], i + n});
        }
        ref1 += grp[n][0] + 1;
        ref2 += grp[n][0] + 1;
        // dia terhubung ke grp 6
        // grp 6 selalu grp[i][0] + ref
        // buat grp 36
        // nanti bakal ada grp_cnt / 7 pairing 36 yang diperlukan
        int small_cnt = ceil(n / 6.0);
        int med_cnt = ceil(grp_cnt / 7.0);
        vector<int> med_grp1[10000], med_grp2[10000];
        // tiap group butuh 36 dengan quantity itu
        //cout << small_cnt << endl;
        for(int i = 1; i <= small_cnt; ++i) {
            // dari 6 * i - 5 ke 6 * i
            //cout << "TEST" << endl;
            int l = 6 * i - 5, r = 6 * i;
            //cout << i << " " << l << " " << min(r, small_cnt) << endl;
            for(int k = 0; k < med_cnt; ++k) {
                int cur1 = ref1, cur2 = ref2;
                ++ref1;
                ++ref2;
                for(int j = l; j <= min(r, small_cnt); ++j) {
                    // buat edge yang hubungin j ke new
                    // kita push back med grp nya
                    edges.push_back({rep1[j * 6 - 5], cur1});
                    edges.push_back({cur2, rep2[j * 6 - 5]});
                }
                med_grp1[i].push_back(cur1);
                med_grp2[i].push_back(cur2);
                cout << i << " " << cur1 << " " << cur2 << endl;
            }
            // from l to r create edge to 
        }
        vector<int> large_grp1[10000], large_grp2[10000];
        int unique_cnt = ceil(n / 36.0);
        //cout << grp_cnt << " " << med_cnt << " " << unique_cnt << " " << small_cnt << endl;
        for(int i = 1; 6 * i - 5 <= unique_cnt; ++i) {
            int l = 6 * i - 5, r = 6 * i;
            int idx = -1;
            //cout << l << " " << r << endl;
            for(int k = 0; k < grp_cnt; ++k) {
                // pakai med_grp yg di index idx
                if(k % 7 == 0)
                    ++idx;
                int cur1 = ref1, cur2 = ref2;
                ++ref1;
                ++ref2;
                cout << cur1 << " " << cur2 << endl;
                for(int j = l; j <= min(r, unique_cnt); ++j) {
                    // buat edge yang hubungin j ke new
                    // kita push back med grp nya
                    //cout << j << " " << cur1 << " " << cur2 << endl;
                    cout << j << " " << l << " " << min(r, unique_cnt) << " " << med_grp1[j].size() << " " << idx << endl;
                    edges.push_back({med_grp1[j][idx], cur1});
                    edges.push_back({cur2, med_grp2[j][idx]});
                }
                cout << "LARGE " << i << " " << cur1 << " " << cur2 << endl;
                large_grp1[i].push_back(cur1);
                large_grp2[i].push_back(cur2);
                //cout << i << " ";
            }
            //cout << endl;
        }
        for(int i = 1; i <= grp_cnt; ++i) {
            // pairing tiap grp_cnt
            for(int j = 1; j <= grp_cnt; ++j) {
                cout << i << " " << j << " " << large_grp1[i].size() << " " << large_grp2[j].size() << endl;
                edges.push_back({large_grp1[i][j - 1], large_grp2[j][i - 1]});
            }
        }
        fout << 300000 << " " << edges.size() << endl;
        for(auto i : edges) {
            fout << i.first << " " << i.second << endl;
        }
        for(int i = 1; i < 300005; ++i) {
            adj[i].clear();
        }
        for(auto i : edges)
            adj[i.first].push_back(i.second);
        memset(target, 0, sizeof(target));
        for(int i = n + 1; i <= 2 * n; ++i)
            target[i] = 1;
        cout << n << " " << dfs(1) << endl;
    }
}