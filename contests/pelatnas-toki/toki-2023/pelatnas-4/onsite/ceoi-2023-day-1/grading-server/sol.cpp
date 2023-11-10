#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int s, q;
    cin >> s >> q;
    // find minimum ch supaya hacker menang for given fh, cg, fg
    // fh, cg, fg
    // 0, 0 -> winning
    // 
    bool dp[80][80][80][80][2];
    memset(dp, 0, sizeof(dp));
    // where ch - fg * s > cg -> winning state
    for(int i = 0; i < q; ++i) {
        ll ch, fh, cg, fg;
        cin >> ch >> fh >> cg >> fg;
        // kena firewall dulu
        // siapa yg kena firewall duluan?
        
    }
    // sub 1, 2 -> dp
    // sub 3 -> game theory, yg kena firewall duluan kalah
    // sub 4 -> ch*fh? idk bruh
    // sub 5 -> 

}