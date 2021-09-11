#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int memory[10001], lastnumber = 0, currentindex = 0;
    for(int i = 0; i < 10001; ++i)
    {
        if(currentindex == n)
            memory[i] = currentindex;
        else
        {
            if(lastnumber + a[currentindex] == i)
                lastnumber += a[currentindex], ++currentindex;
            memory[i] = currentindex;
        }
    }
    int input;
    for(int i = 0; i < k; ++i)
        cin >> input, cout << memory[input] << endl;
    return 0;
}