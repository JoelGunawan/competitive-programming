#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
vector<int> ans;
map<pair<int, int>, bool> vis;
bool invalid[500];
int factors[500], factor_cnt;
void find(int n, int sum, ) {
    if(vis[mp(n, sum)])
        return;
    vis[mp(n, sum)] = 1;
    ans.push_back(sum);
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> tmp;
    for(int i = 1; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            tmp.push_back(i);
            tmp.push_back(n / i);
        }
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    factor_cnt = tmp.size();    
    for(int i = 1; i <= factor_cnt; ++i) {
        factors[i] = tmp[i - 1];
    }
    find(n, 0);
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}