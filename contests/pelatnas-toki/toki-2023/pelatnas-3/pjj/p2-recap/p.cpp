#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i], a[i] -= i;
    /*
    int dp[n + 1][10];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 10; ++j) {
            dp[i][j] = 1e9;
            for(int k = 0; k <= j; ++k)
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i] - j));
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "DONE" << endl;
    */
   priority_queue<int> left;
   priority_queue<int, vector<int>, greater<int>> right;
   int min = 0;
   long long res = 0;
   for(int i = 1; i <= n; ++i) {
        while(right.size())
            right.pop();
        left.push(a[i]);
        if(a[i] < left.top()) {
            res += left.top() - a[i];
            right.push(left.top());
            left.pop();
            left.push(a[i]);
        }   
        else {
            right.push(a[i]);
        } 
   }
   cout << res << endl;
}