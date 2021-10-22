#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= min(n, 42); ++i)
    {
        if(i == 42)
            cout << "ERROR" << endl;
        else if(i % 10 != 0)
            cout << i << endl;
    }
    return 0;
}