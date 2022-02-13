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
    int n;
    cin >> n;
    map<string, bool> banned;
    map<string, int> used;
    string first[n + 1], second[n + 1];
    for(int i = 1; i <= n; ++i) {
        string a, b;
        cin >> a >> b;
        first[i] = a.substr(0, 3);
        second[i] = a.substr(0, 2) + b[0];
    }
    // first determine all banned for first
    // then determine second?
    // if there is conflict in second, 
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(first[i] == first[j])
                banned[first[i]] = 1;
        }
    }
    string answer[n + 1];
    bool ans = 1;
    for(int i = 1; i <= n; ++i) {
        if(!banned[first[i]] && !used[first[i]])
            answer[i] = first[i];
        else {
            banned[first[i]] = 1;
            function<void(int)> check = [&] (int nd) -> void {
                if(second[nd] == first[used[second[nd]]] && second[nd] != second[used[second[nd]]]) {
                    int prev = used[second[nd]];
                    banned[first[prev]] = 1;
                    used[first[prev]] = 0;
                    if(second[nd] == second[prev])
                        ans = 0;
                    else {
                        if(used[second[prev]]) {
                            check(prev);
                            if(used[second[prev]])
                                ans = 0;
                        }
                        used[second[prev]] = prev, answer[prev] = second[prev];
                    }
                }
                else
                    ans = 0;
            };
            if(used[second[i]])
                check(i);
            answer[i] = second[i];
        }
        used[answer[i]] = i;
    }
    if(ans) {
        cout << "YES" << endl;
        for(int i = 1; i <= n; ++i)
            cout << answer[i] << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}