#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert
#define pf push_front
#define endl "\n"
using namespace std;
int main()
{
    ifstream aritmetika7("./aritmetika_7.in");
    int n, k;
    aritmetika7 >> n >> k;
    int a[n], sorted[n];
    for(int i = 0; i < n; ++i)
        aritmetika7 >> a[i], sorted[i] = a[i];
    sort(sorted, sorted + n);
    int ans[n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            if(a[j] == sorted[i])
            {
                ans[j] = i;
                break;
            }
    }
    ofstream output("./aritmetika_7.out");
    output << sorted[0] << " " << sorted[1] - sorted[0] << endl;
    for(int i = 0; i < n; ++i)
        output << ans[i] + 1 << " ";
    output << endl;
    ofstream tc8("./aritmetika_8.out");
    int cur = 11;
    tc8 << 11 << " " << 2 << endl; 
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < cur; ++j)
            tc8 << i + 1 << " ";
        cur += 2;
    }
    tc8 << endl;
    ifstream tc5("./aritmetika_5.in");
    tc5 >> n >> k;
    int in, sum = 0;
    for(int i = 0; i < n; ++i)
        tc5 >> in, sum += in;
    cout << sum << endl;
    ifstream tc6("./aritmetika_6.in");
    tc6 >> n >> k;
    sum = 0;
    for(int i = 0; i < n; ++i)
        tc6 >> in, sum += in;
    cout << sum << endl;
    return 0;
}