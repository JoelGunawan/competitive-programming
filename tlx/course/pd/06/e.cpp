#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n > 1)
    {
        int prev = n;
        n /= 2;
        if(n * 2 != prev)
        {
            cout << "bukan" << endl;
            return 0;
        }
    }
    cout << "ya" << endl;
    return 0;
}