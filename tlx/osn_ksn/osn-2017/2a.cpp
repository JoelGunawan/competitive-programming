#include <bits/stdc++.h>
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    string subsoal; int n, k;
    cin >> subsoal >> n >> k;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i];
    // we need to maintain 2 multisets
    // first is the sorted, second is the current actual
    // if both are the same, then that is one "segment"
    

    /*
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    if(subsoal[4] == '4' || subsoal[5] == '5')
    {
        if(subsoal[4] == '4')
        {
            // check the first non sorted element from the back and from the front
            if(b == a)
                cout << 1 << endl;
            else
            {
                int forward, backward;
                for(int i = 0; i < n; ++i)
                    if(a[i] != b[i])
                    {
                        forward = i;
                        break;
                    }
                for(int i = n -1 ; i >= 0; --i)
                    if(a[i] != b[i])
                    {
                        backward = i;
                        break;
                    }
                cout << backward - forward + 1 << endl;
            }
        }
        else
        {
            // last instance of 1 - first instance of 2
            if(b[0] == b[n - 1] || a == b)
                cout << k << endl;
            else
            {
                // find the first instance of 2 and the last instance of 1
                int first, last;
                for(int i = 0; i < n; ++i)
                    if(a[i] == 2)
                    {
                        first = i;
                        break;
                    }
                for(int i = n - 1; i >= 0; --i)
                    if(a[i] == 1)
                    {
                        last = i;
                        break;
                    }
                cout << last - first + k << endl;
            }
        }
        return 0;
    }
    int res = 0, streak = 0;
    multiset<int> betweens;
    multiset<int> required;
    multiset<int> currents;
    for(int i = 0; i < n; ++i)
    {
        // check for streaks of sorted and of not sorted
        required.insert(a[i]);
        currents.insert(b[i]);
        if(required == currents)
        {
            required.clear();
            currents.clear();
            ++streak;
        }
        else
        {
            if(streak != 0 && streak != i)
                betweens.insert(-streak);
            streak = 0;
            ++res;
        }
    }
    for(int i = 0; i < k - 1; ++i)
    {
        if(betweens.size() == 0)
            break;
        else
            betweens.erase(betweens.begin());
    }
    for(auto it = betweens.begin(); it != betweens.end(); ++it)
        res += -(*it);
    cout << k + res << endl;
    */
}