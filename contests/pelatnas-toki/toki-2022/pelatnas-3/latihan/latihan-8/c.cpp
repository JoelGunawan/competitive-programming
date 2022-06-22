// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
vector<int> sieve(int limit) {
    bool prime[limit + 1];
    memset(prime, 1, sizeof(prime));
    prime[0] = 0, prime[1] = 0;
    vector<int> res;
    for(int i = 2; i <= limit; ++i) {
        if(prime[i]) {
            res.pb(i);
            for(int j = 2 * i; j <= limit; j += i)
                prime[j] = 0;
        }
    }
    return res;
}
vector<int> primes;
string correct = "+++++";
void solve() {
    bool allowed[5][10];
    memset(allowed, 1, sizeof(allowed));
    // go through each prime
    // check allowed
    // if allowed query
    string input;
    int mincnt[10], maxcnt[10];
    memset(mincnt, 0, sizeof(mincnt));
    fill(maxcnt, maxcnt + 10, 5);
    {
        string tmp = "80263";
        cout << tmp << endl;
        cin >> input;
        int cur_cnt[10];
        memset(cur_cnt, 0, sizeof(cur_cnt));
        for(int i = 0; i < input.size(); ++i) {
            if(input[i] == '?' || input[i] == '+')
                ++cur_cnt[tmp[i] - '0'];
        }
        for(int i = 0; i < input.size(); ++i) {
            if(input[i] == '?')
                allowed[i][tmp[i] - '0'] = 0;
            else if(input[i] == '-') {
                maxcnt[tmp[i] - '0'] = cur_cnt[tmp[i] - '0'];   
                allowed[i][tmp[i] -'0'] = 0;
            }
            else {
                for(int j = 0; j < 10; ++j)
                    if(j != tmp[i] - '0')
                        allowed[i][j] = 0;
            }
        }
        for(int i = 0; i < 10; ++i)
            mincnt[i] = max(mincnt[i], cur_cnt[i]);
    }
    {
        string tmp = "91457";
        cout << tmp << endl;
        cin >> input;
        int cur_cnt[10];
        memset(cur_cnt, 0, sizeof(cur_cnt));
        for(int i = 0; i < input.size(); ++i) {
            if(input[i] == '?' || input[i] == '+')
                ++cur_cnt[tmp[i] - '0'];
        }
        for(int i = 0; i < input.size(); ++i) {
            if(input[i] == '?')
                allowed[i][tmp[i] - '0'] = 0;
            else if(input[i] == '-') {
                maxcnt[tmp[i] - '0'] = cur_cnt[tmp[i] - '0'];   
                allowed[i][tmp[i] -'0'] = 0;
            }
            else {
                for(int j = 0; j < 10; ++j)
                    if(j != tmp[i] - '0')
                        allowed[i][j] = 0;
            }
        }
        for(int i = 0; i < 10; ++i)
            mincnt[i] = max(mincnt[i], cur_cnt[i]);
    }
    for(auto i : primes) {
        string tmp = to_string(i);
        bool valid = 1;
        int tmp_cnt[10];
        memset(tmp_cnt, 0, sizeof(tmp_cnt));
        for(int j = 0; j < tmp.size(); ++j) {
            if(!allowed[j][tmp[j] - '0'])
                valid = 0;
            ++tmp_cnt[tmp[j] - '0'];
        }
        for(int j = 0; j < 10; ++j)
            if(tmp_cnt[j] < mincnt[j] || tmp_cnt[j] > maxcnt[j])
                valid = 0;
        if(valid) {
            cout << tmp << endl;
            cin >> input;
            if(input == correct)
                return;
            int cur_cnt[10];
            memset(cur_cnt, 0, sizeof(cur_cnt));
            for(int i = 0; i < input.size(); ++i) {
                if(input[i] == '?' || input[i] == '+')
                    ++cur_cnt[tmp[i] - '0'];
            }
            for(int i = 0; i < input.size(); ++i) {
                if(input[i] == '?')
                    allowed[i][tmp[i] - '0'] = 0;
                else if(input[i] == '-') {
                    maxcnt[tmp[i] - '0'] = cur_cnt[tmp[i] - '0'];   
                    allowed[i][tmp[i] -'0'] = 0;
                }
                else {
                    for(int j = 0; j < 10; ++j)
                        if(j != tmp[i] - '0')
                            allowed[i][j] = 0;
                }
            }
            for(int i = 0; i < 10; ++i)
                mincnt[i] = max(mincnt[i], cur_cnt[i]);
        }
    }
}
int main() {
    vector<int> tmp = sieve(1e5);
    for(auto i : tmp)
        if(i >= 1e4 && i < 1e5)
            primes.pb(i);
    string mode;
    int number;
    vector<string> memo;
    for(auto i : primes) {
        string tmp = to_string(i);
        bool output = 1;
        for(int j = 0; j < tmp.size(); ++j)
            for(int k = j + 1; k < tmp.size(); ++k)
                if(tmp[j] == tmp[k])
                    output = 0;
        if(output)
            memo.pb(tmp);
    }
    cin >> mode >> number;
    int tc;
    cin >> tc;
    while(tc--)
        solve();
    return 0;
}