#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string input;
    cin >> input;
    int index = 0, surplus = 0, swapCount = 0;
    for(int i = 0; i < n / 2; ++i)
    {
        while(input[index] != ')')
        {
            ++index;
            ++surplus;
        }

        ++index;

        if(surplus > 0)
        {
            --surplus;
        }
        else
        {
            ++swapCount;
        }
    }
    cout << swapCount << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
