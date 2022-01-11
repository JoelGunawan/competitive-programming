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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int left[n], right[n];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    // dari indeks ini, strictly increasing ke kiri berapa atau strictly increasing ke kanan berapa
    for(int i = n - 2; i >= 0; --i)  {
        if(a[i] < a[i + 1])
            left[i] = left[i + 1] + 1;
    }
    for(int i = 1; i < n; ++i) {
        if(a[i] < a[i - 1])
            right[i] = right[i - 1] + 1;
    }
    int l = 0, r = n - 1;
    int move = 0;
    while(l <= r) {
        ++move;
        //cout << l << " " << r << endl;
        if(l == r) {
            break;
        }
        else {
            if(a[l] == a[r]) {
                if(left[l] % 2 == 0 || right[r] % 2 == 0) {
                    break;
                }
                else {
                    ++move;
                    break;
                }
            }
            else if(a[l] > a[r]) {
                if(left[l] % 2 == 0) {
                    break;
                }
                else {
                    if(right[r] == 0) {
                        break;
                    }
                    --r;
                }
            }
            else {
                if(right[r] % 2 == 0) {
                    break;
                }
                else {
                    if(left[l] == 0) {
                        break;
                    }
                    ++l;
                }
            }
        }
    }
    //cout << l << " " << r << endl;
    if(move & 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    return 0;
}