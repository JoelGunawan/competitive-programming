#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double result = 0;
    for(int i = 1; i <= n; ++i)
    {
        result += (double(1) / i);
    }
    cout << result << endl;
    return 0;
}
