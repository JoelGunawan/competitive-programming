// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct block {
    int sz = 0;
    bool filled = 1;
    bool incr = 0;
    deque<char> arr = {};
    int cnt[26];
    block() {
        memset(cnt, 0, sizeof(cnt));
    }
};
int k;
bool comp(char a, char b) {
    return k ^ (a > b);
}
vector<block> b;
void construct(int idx) {
    if(b[idx].filled)
        return;
    //for(int i = 0; i < 26; ++i)
    //    cout << b[idx].cnt[i] << " ";
    //cout << endl;
    b[idx].arr.clear();
    if(b[idx].incr) {
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < b[idx].cnt[i]; ++j)
                b[idx].arr.pb('a' + i);
        }
    }
    else {
        for(int i = 25; i >= 0; --i) {
            for(int j = 0; j < b[idx].cnt[i]; ++j)
                b[idx].arr.pb('a' + i);
        }
    }
    //for(auto i : b[idx].arr)
    //    cout << i << " ";
    //cout << endl;
    b[idx].filled = 1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    // sqrt bullshit
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    /*
    if(n * q <= 1e6) {
        for(;q--;) {
            int l, r, k;
            cin >> l >> r >> k;
            if(k) {
                sort(s.begin() + l, s.begin() + r + 1);
            }
            else {
                sort(s.begin() + l, s.begin() + r + 1, greater<char>());
            }
        }
        cout << s << endl;
        return 0;
    }
    */
    int sq = sqrt(n);
    vector<int> ref = {0};
    if(sq == 0)
        cout << -1 << endl, exit(0);
    for(int i = 1; i <= n; ++i) {
        if(i >= s.size())
            cout << -1 << endl, exit(0);
        if(i % sq == 1 || sq == 1) {
            b.pb(block());
        }
        if(i % sq == 0)
            ref.pb(i);
        if(b.size() == 0)
            cout << -1 << endl, exit(0);
        b.back().arr.pb(s[i]);
        if(s[i] - 'a' < 0 || s[i] - 'a' >= 26)
            cout << -1 << endl, exit(0);
        ++b.back().cnt[s[i] - 'a'];
        ++b.back().sz;
    }
    if(ref.size() == 0)
        cout << -1 << endl, exit(0);
    if(ref.back() != n)
        ref.pb(n);
    for(;q--;) {
        int l, r;
        cin >> l >> r >> k;
        int lblock = lower_bound(ref.begin(), ref.end(), l) - ref.begin() - 1, rblock = lower_bound(ref.begin(), ref.end(), r) - ref.begin() - 1;
        if(lblock < 0 || lblock >= b.size() || rblock < 0 || rblock >= b.size())
            cout << -1 << endl, exit(0);
        //cout << lblock << " " << rblock << endl;
        int prl = *--lower_bound(ref.begin(), ref.end(), l), prr = *--lower_bound(ref.begin(), ref.end(), r);
        if(lblock == rblock) {
            construct(lblock);
            //cout << "TEST" << endl;
            if(l - prl - 1 < 0 || l - prl - 1 >= b[lblock].arr.size() || r - prr < 0 || r - prr > b[lblock].arr.size())
                cout << -1 << endl, exit(0);
            sort(b[lblock].arr.begin() + l - prl - 1, b[lblock].arr.begin() + r - prr, comp); 
        }
        else {
            int totalcnt[26];
            memset(totalcnt, 0, sizeof(totalcnt));
            construct(lblock), construct(rblock);
            //cout << "TEST" << endl;
            for(int i = lblock + 1; i < rblock; ++i) {
                for(int j = 0; j < 26; ++j)
                    totalcnt[j] += b[i].cnt[j];
            }
            if(l - prl < 1 || r - prr > b[rblock].arr.size())
                cout << -1 << endl, exit(0);
            for(;b[lblock].arr.size() >= l - prl;) {
                if(!b[lblock].arr.size() || b[lblock].arr.back() < 'a' || b[lblock].arr.back() > 'z')
                    cout << -1 << endl, exit(0);
                ++totalcnt[b[lblock].arr.back() - 'a'], --b[lblock].cnt[b[lblock].arr.back() - 'a'], b[lblock].arr.pop_back();
            }
            for(int i = 0; i < r - prr; ++i) {
                if(!b[rblock].arr.size() || b[rblock].arr.back() < 'a' || b[rblock].arr.back() > 'z')
                    cout << -1 << endl, exit(0);
                ++totalcnt[b[rblock].arr.front() - 'a'], --b[rblock].cnt[b[rblock].arr.front() - 'a'], b[rblock].arr.pop_front();
            }
            if(k) {
                // proses lblock sendiri
                //cout << l << " " << r << endl;
                int cur = 0;
                for(;b[lblock].arr.size() < b[lblock].sz;) {
                    for(;cur < 26 && totalcnt[cur] <= 0;)
                        ++cur;
                    if(cur >= 26)
                        cout << -1 << endl, exit(0);
                    //cout << (char)(cur + 'a');
                    ++b[lblock].cnt[cur];
                    b[lblock].arr.pb(cur + 'a');
                    --totalcnt[cur];
                }
                //cout << endl;
                for(int i = lblock + 1; i < rblock; ++i) {
                    memset(b[i].cnt, 0, sizeof(b[i].cnt));
                    for(int cursz = b[i].sz; cursz;) {
                        int tmp = min(totalcnt[cur], cursz);
                        cursz -= tmp;
                        totalcnt[cur] -= tmp;
                        b[i].cnt[cur] += tmp;
                        if(totalcnt[cur] == 0)
                            ++cur;
                        if(cur >= 26)
                            cout << -1 << endl, exit(0);
                    }
                    b[i].incr = k;
                    b[i].filled = 0;
                    b[i].arr.clear();
                }
                for(;b[rblock].arr.size() < b[rblock].sz;) {
                    for(;cur < 26 && totalcnt[cur] <= 0;)
                        ++cur;
                    if(cur >= 26)
                        cout << -1 << endl, exit(0);
                    //cout << (char)(cur + 'a');
                    ++b[rblock].cnt[cur];
                    b[rblock].arr.push_front(cur + 'a');
                    --totalcnt[cur];
                }
                if(cur >= 26)
                    cout << -1 << endl, exit(0);
                //cout << endl;
            }
            else {
                int cur = 25;
                for(;b[lblock].arr.size() < b[lblock].sz;) {
                    for(;totalcnt[cur] <= 0;)
                        --cur;
                    //cout << "L " << cur << " " << totalcnt[cur] << endl;
                    ++b[lblock].cnt[cur];
                    b[lblock].arr.pb(cur + 'a');
                    --totalcnt[cur];
                }
                for(int i = lblock + 1; i < rblock; ++i) {
                    memset(b[i].cnt, 0, sizeof(b[i].cnt));
                    for(int cursz = b[i].sz; cursz;) {
                        int tmp = min(totalcnt[cur], cursz);
                        cursz -= tmp;
                        totalcnt[cur] -= tmp;
                        b[i].cnt[cur] += tmp;
                        if(totalcnt[cur] == 0)
                            --cur;
                        if(cur < 0)
                            cout << -1 << endl, exit(0);
                    }
                    b[i].incr = k;
                    b[i].filled = 0;
                    b[i].arr.clear();
                }
                for(;b[rblock].arr.size() < b[rblock].sz;) {
                    for(;cur && totalcnt[cur] <= 0;)
                        --cur;
                    if(cur < 0)
                        cout << -1 << endl, exit(0);
                    //cout << "R " << cur << " " << totalcnt[cur] << endl;
                    ++b[rblock].cnt[cur];
                    b[rblock].arr.push_front(cur + 'a');
                    --totalcnt[cur];
                }
                if(cur < 0)
                    cout << -1 << endl, exit(0);
            }
            for(int i = 0; i < 26; ++i) {
                if(totalcnt[i] != 0)
                    cout << -1 << endl, exit(0);
            }
        }
    }
    for(int i = 0; i < b.size(); ++i) {
        construct(i);
        for(auto j : b[i].arr)
            cout << j;
    }
    cout << endl;
    return 0;
}