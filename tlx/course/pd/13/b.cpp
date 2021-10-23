#include <bits/stdc++.h>
using namespace std;
void gunung(int n)
{
    if(n == 1)
        cout << "*" << endl;
    else
    {
        gunung(n - 1);
        for(int i = 0; i < n; ++i)
            cout << "*";
        cout << endl;
        gunung(n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    gunung(n);
    return 0;
}