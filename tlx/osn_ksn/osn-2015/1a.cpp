#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string subsoal;
    cin >> subsoal;
    int sdengklek, tdengklek, tambahstamina, tambahtenaga, n;
    cin >> sdengklek >> tdengklek >> tambahstamina >> tambahtenaga >> n;
    int bossstamina, bosstenaga;
    cin >> bossstamina >> bosstenaga;
    int left = 0, right = n, mid, res = n + 1;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if((int)(ceil(bossstamina / (double)(tdengklek + tambahtenaga * mid)) - 1) * bosstenaga < sdengklek + tambahstamina * mid)
            right = mid - 1, res = mid;
        else
            left = mid + 1;
    }
    int bosreq = res;
    multiset<pair<int, int>> required;
    int s, t;
    for(int i = 0; i < n - 1; ++i)
    {
        cin >> s >> t;
        left = 0, right = n, mid, res = n + 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if((int)(ceil(s / (double)(tdengklek + tambahtenaga * mid)) - 1) * t < sdengklek + tambahstamina * mid)
                right = mid - 1, res = mid;
            else
                left = mid + 1;
        }
        required.insert({res, i + 2});
    }   
    int current = 0, ans[bosreq]; bool valid = 1;
    while(current < bosreq)
    {
        if(required.size() > 0 && (*required.begin()).first <= current)
            ans[current] = (*required.begin()).second, ++current, required.erase(required.begin());
        else
        {
            valid = 0;
            break;
        }
    }
    if(valid)
    {
        cout << bosreq << endl;
        for(int i = 0; i < bosreq; ++i)
            cout << ans[i] << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}