#include <iostream>

using namespace std;

int main()
{
    int n, maxVal = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int in;
        cin >> in;
        in += maxVal;
        if(in > maxVal) maxVal = in;
        cout << in;
        if(i == n - 1) cout << endl;
        else cout << " ";
    }
}
