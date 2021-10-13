#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, n;
    cin >> k >> n;
    int a[k];
    for(int i = 0; i < k; ++i)
        cin >> a[i];
    // use a nim sum and determine what number we need to xor by to make it 0
    while(true)
    {
        // find nim sum and try to find another state from current state such that the nim sum changes to 0
        int nim_sum = 0;
        for(int i = 0; i < k; ++i)
            nim_sum ^= (a[i] % (n + 1));
        for(int i = 0; i < k; ++i)
        {
            // cout << a[i] << " " << (a[i] ^ nim_sum) << endl;
            // select a k such that we can move the nim sum to 0
            int target = (a[i] % (n + 1)) ^ nim_sum;
            if(target >= 0 && a[i] - target >= 0)
            {
                int tmp = a[i];
                if(a[i] % (n + 1) < target)
                    a[i] = (a[i] / (n + 1) - 1) * (n + 1) + target;
                else
                    a[i] = (a[i] / (n + 1)) * (n + 1) + target;
                cout << i + 1 << " " << tmp - a[i] << endl;
                break;
            }
        }
        int i, x;
        cin >> i >> x;
        if(i == -1 && x == -1)
            break;
        else
            a[i - 1] -= x;
    }
    return 0;
}