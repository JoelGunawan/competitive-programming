#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // try 2 pointers until we find a non palindrome
    // the correct approach would definitely be to delete either the left or the right
    bool ans = 1; int cur = -1;
    for(int i = 0; i < n / 2; ++i)
        if(a[i] != a[n - i - 1])
        {
            ans = 0, cur = i;
            break;
        }
    if(ans)
    {
        cout << "Yes" << endl;
        return;
    }
    int left = 0, right = n - 1, del = a[cur];
    // try when we delete left
    ans = 1;
    //cout << cur << endl;
    while(left < right)
    {
        if(a[left] != a[right])
        {
            if(a[left] != del && a[right] != del)
            {
                ans = 0;
                break;
            }
            else
            {
                while(a[left] == del)
                    ++left;
                while(a[right] == del)
                    --right;
                if(a[left] != a[right])
                {
                    //cout << "DEB " << left << " " << right << endl;
                    ans = 0;
                    break;
                }
            }
        }
        ++left, --right;
    }
    if(ans)
    {
        cout << "Yes" << endl;
        return;
    }
    // try when we delete right
    ans = 1;
    left = 0, right = n - 1, del = a[n - cur - 1];
    while(left < right)
    {
        if(a[left] != a[right])
        {
            if(a[left] != del && a[right] != del)
            {
                ans = 0;
                break;
            }
            else
            {
                while(a[left] == del)
                    ++left;
                while(a[right] == del)
                    --right;
                if(a[left] != a[right])
                {
                    //cout << "DEB2 " << left << " " << right << endl;
                    ans = 0;
                    break;
                }
            }
        }
        ++left, --right;
    }
    if(ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}