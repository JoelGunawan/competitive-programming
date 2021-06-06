#include <iostream>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int maximum = -1, minimum = -1;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        if(maximum == -1 || tmp > maximum)
        {
            maximum = tmp;
        }
        if(minimum == -1 || tmp < minimum)
        {
            minimum = tmp;
        }
    }
    if(maximum - minimum <= 2 * k)
    {
        cout << minimum + k << endl;
    }
    else cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
