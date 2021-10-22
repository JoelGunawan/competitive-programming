#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, counter[1001], in;
    cin >> n;
    memset(counter, 0, sizeof(counter));
    for(int i = 0; i < n; ++i)
        cin >> in, ++counter[in];
    int num, mode = 0;
    for(int i = 0; i <= 1000; ++i)
        if(counter[i] >= mode)
            num = i, mode = counter[i];
    cout << num << endl;
    return 0;
}