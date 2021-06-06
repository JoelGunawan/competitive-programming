#include <iostream>

#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int poscount = 0, negcount = 0, zerocount = 0;
    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;

        if(tmp > 0) ++poscount;
        else if(tmp == 0) ++zerocount;
        else ++negcount;

        sum += abs(abs(tmp) - 1);
    }
    if(negcount % 2 == 1 && zerocount == 0)
    {
        sum += 2;
    }
    cout << sum << endl;

    return 0;
}
