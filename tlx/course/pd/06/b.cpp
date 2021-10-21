#include <iostream>
using namespace std;
int main()
{
    int n, in, res = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> in, res += in;
    cout << res << endl;
    return 0;
}