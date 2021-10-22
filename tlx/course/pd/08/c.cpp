#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int counter = 0, a;
        cin >> a;
        for(int j = 2; j * j <= a; ++j)
        {
            if(j * j == a)
                ++counter;
            else if(a % j == 0)
                counter += 2;
        }
        if(counter <= 2)
            cout << "YA" << endl;
        else
            cout << "BUKAN" << endl;
    }
    return 0;
}