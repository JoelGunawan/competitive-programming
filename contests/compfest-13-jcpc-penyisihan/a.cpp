#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert
#define pf push_front
#define endl "\n"
using namespace std;
ll pow(ll a, ll b)
{
    ll res = 1;
    for(int i = 0; i < b; ++i)
        res *= a;
    return res;
}
int main()
{
    ll n, k, c, p;
    cin >> n >> k >> c >> p;
    ll a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    vector<pair<int, int>> leftoptimal, rightoptimal;
    int leftoptimalselect[n], rightoptimalselect[n];
    for(int i = 0; i < n; ++i)
    {
        if(rightoptimal.size() == 0 || rightoptimal[rightoptimal.size() - 1].first + c * (i - rightoptimal[rightoptimal.size() - 1].second) > b[i])
            rightoptimal.pb({b[i], i}), cout << b[i] << " " << i << endl;;
        rightoptimalselect[i] = rightoptimal.size() - 1;
    }
    cout << "DEMARK" << endl;
    for(int i = n - 1; i >= 0; --i)
    {
        if(leftoptimal.size() == 0 || leftoptimal[leftoptimal.size() - 1].first + c * (leftoptimal[leftoptimal.size() - 1].second - i) > b[i])
            leftoptimal.pb({b[i], i}), cout << b[i] << " " << i << endl;;
        leftoptimalselect[i] = leftoptimal.size() - 1;
    }
    for(int i = 0; i < n; ++i)
    {
        cout << "FIRST" << endl;
        // try to do binary search
        // do for left and right
        // check the furthest
        // then check minimum coins
        int left = 0, right = leftoptimalselect[i], mid, res1 = -1, res2 = -1;
        while(true)
        {
            if(left > right)
                break;
            mid = (left + right) / 2;
            cout << mid << " " << abs(i - leftoptimal[mid].second) * c + leftoptimal[mid].first << endl;
            if(abs(i - leftoptimal[mid].second) * c + leftoptimal[mid].first <= k - a[i])
                // try to go higher
                res1 = min(res1, mid), right = mid - 1;
            else
                left = mid + 1;

        }
        cout << "DEMARK" << endl;
        left = 0, right = rightoptimalselect[i];
        while(true)
        {
            if(left > right)
                break;
            mid = (left + right) / 2;
            cout << mid << " " << abs(i - rightoptimal[mid].second) * c + rightoptimal[mid].first << endl;
            if(abs(i - rightoptimal[mid].second) * c + rightoptimal[mid].first <= k - a[i])
                res2 = min(res2, mid), right = mid - 1;
            else
                left = mid + 1;
        }
        cout << "DEMARK" << endl;
        if(res1 == -1 && res2 == -1)
            cout << 0 << " " << k << endl;
        else if(res2 != -1 && (res1 == -1 || abs(i - rightoptimal[res2].second) > abs(i - leftoptimal[res1].second) 
        || (abs(i - rightoptimal[res2].second) == abs(i - leftoptimal[res1].second) 
        && abs(i - rightoptimal[res2].second) * c + rightoptimal[res2].first + a[i] < abs(i - leftoptimal[res1].second) * c + leftoptimal[res1].first + a[i])))
            cout << abs(i - rightoptimal[res2].second) + 1 << " " << k - (abs(i - rightoptimal[res2].second) * c + rightoptimal[res2].first + a[i]) << endl;
        else
            cout << abs(i - leftoptimal[res1].second) + 1 << " " << k - (abs(i - leftoptimal[res1].second) * c + leftoptimal[res1].first + a[i]) << endl;
    }
    // n^2 approach
    /*
    if(n <= 1000)
    {
        for(int i = 0; i < n; ++i)
        {
            ll maxdist = 0, sparecoins = k;
            for(int j = 0; j < n; ++j)
            {
                // check if it is valid
                if(a[i] + b[j] + pow(abs(i - j), p)  * c <= k)
                {
                    if(abs(i - j) + 1 > maxdist)
                        maxdist = abs(i - j) + 1, sparecoins = k - (a[i] + b[j] + pow(abs(i - j), p) * c);
                    else if(maxdist == abs(i - j) + 1 && k - (a[i] + b[j] + pow(abs(i - j), p) * c) > sparecoins)
                        sparecoins = k - (a[i] + b[j] + pow(abs(i - j), p) * c);
                }
            }
            cout << maxdist << " " << sparecoins << endl;
        }
    }
    else if(c == 0)
    {
        
    }
    else
    {
        // do subtask with no in/out costs
        for(int i = 0; i < n; ++i)
        {
            ll maxdist = max((ll)abs(i - 0), abs(n - 1 - i)), actualdist = min(k / c, maxdist);
            cout << actualdist + 1 << " " << k - actualdist * c << endl;
        }
    }
    */
    return 0;
}