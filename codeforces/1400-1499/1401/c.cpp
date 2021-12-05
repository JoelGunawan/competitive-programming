#include <iostream>
 
using namespace std;
 
void program()
{
    int n, k;
    cin >> n >> k;
    if(n >= k)
    {
        if(n % 2 == k % 2)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            cout << 1 << endl;
            return;
        }
    }
    else
    {
        cout << k - n << endl;
        return;
    }
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        program();
    }
    return 0;
}