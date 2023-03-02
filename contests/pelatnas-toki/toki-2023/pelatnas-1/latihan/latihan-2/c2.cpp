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
struct block {
    bool incr = 0, filled = 1;
    deque<int> arr;
    int cnt[26], sz;
    block() {
        memset(cnt, 0, sizeof(cnt));
    }
};
vector<block> b;
void construct(int idx) {
    if(b[idx].filled)
        return;
    b[idx].filled = 1;
    b[idx].arr.clear();
    if(b[idx].incr) {
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < b[idx].cnt[i]; ++j)
                b[idx].arr.pb(i);
        }
    }
    else {
        for(int i = 25; i >= 0; --i) {
            for(int j = 0; j < b[idx].cnt[i]; ++j)
                b[idx].arr.pb(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    block cur_block = block();
    int sq = sqrt(n);
    for(int i = 1; i <= n; ++i) {
        cur_block.arr.pb(s[i] - 'a');
        cur_block.cnt[s[i] - 'a']++;
        if(i % sq == 0) {
            b.pb(cur_block);
            cur_block = block();
        }
    }
    if(n % sq)
        b.pb(cur_block);
    for(int i = 0; i < b.size(); ++i)
        b[i].sz = b[i].arr.size();
    for(;q--;) {
        int l, r, k;
        cin >> l >> r >> k;
        // cari ll dan cari rblock
        int lidx = 0, lc;
        for(int i = 0; i < b.size(); ++i) {
            lidx += b[i].sz;
            if(lidx >= l) {
                lc = i;
                lidx = l - (lidx - b[i].sz) - 1;
                break;
            }
        }
        int ridx = 0, rc;
        for(int i = 0; i < b.size(); ++i) {
            ridx += b[i].sz;
            if(ridx >= r) {
                rc = i;
                ridx = r - (ridx - b[i].sz) - 1;
                break;
            }
        }
        //cout << "INFO " << l << " " << r << " " << lc << " " << rc << endl;
        //cout << "TEST" << endl;
        if(lc == rc) {
            construct(lc);
            if(k)
                sort(b[lc].arr.begin() + lidx, b[lc].arr.begin() + ridx + 1);
            else
                sort(b[lc].arr.begin() + lidx, b[lc].arr.begin() + ridx + 1, greater<char>());
        }
        else {
            // implement lc dan rc only
            int total[26];
            memset(total, 0, sizeof(total));
            //cout << lidx << " " << ridx << endl;
            construct(lc), construct(rc);
            //cout << lidx << " " << ridx << " " << b[lc].arr.size() << " " << b[rc].arr.size() << endl;
            for(;b[lc].arr.size() > lidx;) {
                ++total[b[lc].arr.back()];
                --b[lc].cnt[b[lc].arr.back()];
                //cout << "LEFT " << b[lc].arr.back() << " " << b[lc].cnt[b[lc].arr.back()] << endl;
                b[lc].arr.pop_back();
            }
            for(int i = 0; i <= ridx; ++i) {
                ++total[b[rc].arr.front()];
                --b[rc].cnt[b[rc].arr.front()];
                //cout << "RIGHT " << b[rc].arr.back() << " " << b[rc].cnt[b[rc].arr.back()] << endl;
                b[rc].arr.pop_front();
            }
            for(int i = lc + 1; i < rc; ++i) {
                for(int j = 0; j < 26; ++j) {
                    total[j] = total[j] + b[i].cnt[j];
                }
                b[i].filled = 0;
                b[i].arr.clear();
                b[i].incr = k;
                memset(b[i].cnt, 0, sizeof(b[i].cnt));
            }
            //cout << lc << " " << rc << endl;
            //cout << sum << endl;
            //for(int i = lc; i <= rc; ++i) {
            //    cout << b[i].sz << " ";
            //}
            //cout << endl;
            //cout << sum << endl;
            //cout << lpop << " " << rpop << endl;
            //cout << "TEST" << endl;
            //cout << k << endl;
            if(k) {
                int cur = 0;
                for(;b[lc].arr.size() < b[lc].sz;) {
                    for(;total[cur] == 0;)
                        ++cur;
                    --total[cur];
                    b[lc].arr.pb(cur);
                    ++b[lc].cnt[cur];
                }
                for(int i = lc + 1; i < rc; ++i) {
                    int cursz = b[i].sz;
                    for(;cursz > 0;) {
                        for(;total[cur] == 0;)
                            ++cur;
                        int tmp = min(total[cur], cursz);
                        cursz -= tmp;
                        total[cur] -= tmp;
                        b[i].cnt[cur] += tmp;
                    }
                }
                for(;b[rc].arr.size() < b[rc].sz;) {
                    for(;total[cur] == 0;)
                        ++cur;
                    --total[cur];
                    b[rc].arr.push_front(cur);
                    ++b[rc].cnt[cur];
                }
            }
            else {
                int cur = 25;
                //cout << lc << " " << rc << endl;
                for(;b[lc].arr.size() < b[lc].sz;) {
                    for(;total[cur] == 0;)
                        --cur;
                    //cout << cur << endl;
                    --total[cur];
                    b[lc].arr.pb(cur);
                    ++b[lc].cnt[cur];
                }
                for(int i = lc + 1; i < rc; ++i) {
                    int cursz = b[i].sz;
                    for(;cursz > 0;) {
                        for(;total[cur] == 0;)
                            --cur;
                        int tmp = min(total[cur], cursz);
                        cursz -= tmp;
                        total[cur] -= tmp;
                        b[i].cnt[cur] += tmp;
                    }
                }
                //cout << "TST" << endl;
                for(;b[rc].arr.size() < b[rc].sz;) {
                    for(;total[cur] == 0;)
                        --cur;
                    //cout << cur << endl;
                    --total[cur];
                    b[rc].arr.push_front(cur);
                    ++b[rc].cnt[cur];
                }
                //cout << endl;
            }
        }
        // cek lc rc, cnt sm arr jumlahnya sesuai tidak
        // cek midnya juga
        /*
        for(int i = lc + 1; i <= rc; ++i) {
            if(b[i].arr.size()) {
                if(b[i].arr.size() < b[i].sz) {
                    cout << "a" << endl;
                    return 0;
                }
            }
            int totalcnt = 0;
            for(int j = 0; j < 26; ++j)
                totalcnt += b[i].cnt[j];
            if(totalcnt < b[i].sz) {
                cout << "a" << endl;
                return 0;
            }
        }
        */
    }
    //cout << "END" << endl;
    for(int i = 0; i < b.size(); ++i) {
        construct(i);
        //cout << "A" << endl;
        for(auto j : b[i].arr) {
            cout << (char)(j + 'a');
        }
    }
    cout << endl;
    return 0;
}