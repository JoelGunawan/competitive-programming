#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    // -1 -> x is left
    // 1 -> x is right
    bool p[n];
    for(int i = 0; i < n; ++i)
    {
        cout << i + 1 << endl;
        int input;
        cin >> input;
        if(input == 0)
            exit(0);
        else
        {
            if(input == 1)
                p[i] = 1;
            else
                p[i] = 0;
        }
    }
    int left = n + 1, right = m, idx = 0;
    while(true)
    {
        int mid = (left + right) / 2;
        cout << mid << endl;
        int input;
        cin >> input;
        if(input == 0 || input == -2)
            exit(0);
        if(!p[idx % n])
            input *= -1;
        if(input == 1)
            left = mid + 1;
        else
            right = mid - 1;
        ++idx;
    }
}