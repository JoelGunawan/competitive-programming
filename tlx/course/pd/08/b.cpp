#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        bool ans = 1;
        if(a == 1)
            ans = 0;
        for(int j = 2; j * j <= a; ++j)
            if(a % j == 0)
                ans = 0;
        if(!ans)
            cout << "BUKAN" << endl;
        else
            cout << "YA" << endl;
    }
    return 0;
}