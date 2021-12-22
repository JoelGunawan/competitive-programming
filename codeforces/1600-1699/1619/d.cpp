// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
void tc() {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    // there is at most 1 shop that is used for 2 people, otherwise it is never optimal
    // for each line, find the maximum and second maximum
    // update the value for each line and find which lines should use second maximum, find the maximum second max lines
    // n - 2 -> optimal to choose maximum
    // final one -> can't choose maximum
    // cek in O(nm) which line is best suited?
    // since we have the current minimum
    // we try to not change the current minimum
    // or find the closest to the current minimum as possible
    int maximum[n];
    memset(maximum, 0, sizeof(maximum));
    int minimum = INT_MAX;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            maximum[i] = max(maximum[i], arr[j][i]);
        }
        minimum = min(minimum, maximum[i]);
    }
    int res = 0;
    for(int i = 0; i < m; ++i) {
        int first_max = 0, second_max = 0;
        for(int j = 0; j < n; ++j) {
            // sort current minimum
            if(arr[i][j] >= first_max) {
                second_max = first_max;
                first_max = arr[i][j];
            }
            else if(arr[i][j] >= second_max) {
                second_max = arr[i][j];
            }
        }
        res = max(res, min(minimum, second_max));
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}