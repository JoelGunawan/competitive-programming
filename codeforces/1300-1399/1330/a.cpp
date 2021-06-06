#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> boolArr(1000, false);
    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        boolArr[a] = true;
    }
    int res;
    for(int i = 1; i < 1000; ++i)
    {
        if(!boolArr[i]) x--;
        if(x == 0)
        {
            res = i;
            break;
        }
    }
    for(int i = res + 1; i < 1000; ++i)
    {
        if(boolArr[i] == true) res++;
        else break;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
