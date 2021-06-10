#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n, q, t, a, b; string s;
    cin >> n >> s >> q;
    string front = s.substr(0, n), back = s.substr(n, n);
    for(int i = 0; i < q; ++i)
    {
        cin >> t >> a >> b;
        if(t == 2)
            swap(front, back);
        else
        {
            char one, two;
            if(a > n && b > n)
                swap(back[a - n- 1], back[b - n - 1]);
            else if(a > n)
                swap(back[a - n - 1], front[b - 1]);
            else if(b > n)
                swap(front[a - 1], back[b - n - 1]);
            else
                swap(front[a - 1], front[b - 1]);
        }
    }
    cout << front << back << endl;
}