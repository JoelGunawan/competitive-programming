#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
        {
            if(i % 3 == 0)
                cout << "Comp";
            if(i % 5 == 0)
                cout << "Fest";
            if(i % 7 == 0)
                cout << "Seven";
            cout << " ";
        }
        else
            cout << i << " ";
    }
}