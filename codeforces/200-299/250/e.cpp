// header file
#include <bits/stdc++.h>
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    char a[n][m + 2];
    for(int i = 0; i < n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 0; i < n; ++i)
        a[i][0] = '#', a[i][m + 1] = '#';
    ll res = 0;
    int cur_pos = 1; bool right = 1;
    bool ans = 1;
    for(int i = 0; i < n - 1; ++i) {
        // check left and check right
        // check drop point
        if(a[i + 1][cur_pos] == '.') {
            ++res;
        }
        else {
            int l = cur_pos, r = cur_pos;
            bool cur_found = 0;
            while(!cur_found) {
                if(a[i][l - 1] == '#' && a[i][r + 1] == '#') {
                    //cout << i << " " << l << " " << r << endl;
                    ans = 0;
                    break;
                }
                res += r - l;
                //cout << res << endl;
                if(right) {
                    //cout << "right" << endl;
                    while(a[i][r + 1] == '.') {
                        //cout << "advance" << endl;
                        ++res;
                        ++r;
                        if(a[i + 1][r] == '.') {
                            cur_found = 1;
                            cur_pos = r;
                            break;
                        }
                    }
                    //cout << r << " " << a[i][r + 1] << endl;
                    if(a[i][r + 1] == '+')
                        a[i][r + 1] = '.';
                    ++res;
                }
                else {
                    //cout << "left" << endl;
                    while(a[i][l - 1] == '.') {
                        //cout << "advance" << endl;
                        ++res;
                        --l;
                        if(a[i + 1][l] == '.') {
                            cur_found = 1;
                            cur_pos = l;
                            break;
                        }
                    }
                    if(a[i][l - 1] == '+')
                        a[i][l - 1] = '.';
                    ++res;
                }
                if(!cur_found)
                    right = !right;
            }
            if(!ans)
                break;
        }
        //cout << "LINE " << res << endl;
    }
    if(ans)
        cout << res << endl;
    else
        cout << "Never" << endl;
    return 0;
}