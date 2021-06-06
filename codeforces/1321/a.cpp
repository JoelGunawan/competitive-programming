#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> arr(n);
    int rsum = 0, bsum = 0, tsum = 0;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp == 1;
        if(arr[i]) ++rsum;
    }
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        if(tmp == 1)
        {
            if(arr[i])
            {
                ++tsum;
            }
            else
            {
                ++bsum;
            }
        }
    }
    rsum -= tsum;
    if(rsum == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (int)ceil((bsum + 1) / double(rsum)) << endl;
    }
    return 0;
}
