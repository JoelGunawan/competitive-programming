#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // find bridges
    // make a bridge tree
    // find count of unique bridge tree nodes for each node
    // check how many combinations of mergers there are
    // algo bridge tree use dfs
    // use low and disc
    int n, t;
    cin >> n >> t;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];
    bool valid_sum = 0;
    for(int i = 0; i < 14; ++i)
        if((1 << i) == sum)
            valid_sum = 1;
    if(!valid_sum)
        cout << "TIDAK" << endl, exit(0);
    // O(n^2 atau n*sum)
    // check for dips
    // buat tiap segment, kita simpen edge yang ke merge
    // kita cek kiri dan kanan
    // yang paling "dense" bentuknya itu yang kita merge
    // soalnya kalo misal ke split di kiri dan kanan
    // pasti lebih ideal buat jadiin 1 aja
    for(int i = 0; i < (1 << n); ++i) {
        deque<int> cur;
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i)
                cur.push_back(a[j]);
            else
                cur.push_front(a[j]);
            while(cur.size() > 1 && cur[0] == cur[1]) {
                int tmp = cur[0];
                cur.pop_front();
                cur.pop_front();
                cur.push_front(2 * tmp);
            }
            while(cur.size() > 1 && cur[cur.size() - 1] == cur[cur.size() - 2]) {
                int tmp = cur[cur.size() - 1];
                cur.pop_back();
                cur.pop_back();
                cur.push_back(2 * tmp);
            }
        }
        //for(auto i : cur)
        //    cout << i << " ";
        //cout << endl;
        if(cur.size() == 1) {
            cout << "YA" << endl;
            if(t == 1) {
                for(int j = 0; j < n; ++j) {
                    if((1 << j) & i)
                        cout << 'L';
                    else
                        cout << 'R';
                }
                cout << endl;
            }
            return 0;
        }
    }
    cout << "TIDAK" << endl;
}