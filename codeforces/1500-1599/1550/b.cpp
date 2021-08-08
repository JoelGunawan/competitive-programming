#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{   
    int n, a, b; string s;
    cin >> n >> a >> b >> s;
    // do one by one
    if(b >= 0)
        cout << (a + b) * n << endl;
    // do minimal
    else
    {
        // check amount of unique zeros, and unique ones, find min and do min * b + a * l
        char target = s[0], nottarget;
        if(target == '0')
            nottarget = '1';
        else
            nottarget = '0';
        int flip = 1;
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == nottarget && s[i - 1] == target)
                ++flip;
        }
        cout << flip * b + a * n << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}