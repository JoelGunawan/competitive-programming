#include <iostream>
using namespace std;
char fizzbuzz(int a)
{
    if(a % 3 != 0 && a % 5 != 0)
        return '0' + a % 10;
    else if(a % 3 != 0)
        return '#';
    else if(a % 5 != 0)
        return '*';
    else
        return 'X';
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cout << fizzbuzz(i);
        cout << endl;
    }
}