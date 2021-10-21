#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if(a > 0 && !(a & 1))
        cout << a << endl;
    return 0;
}