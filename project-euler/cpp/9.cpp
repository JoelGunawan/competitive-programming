#include <bits/stdc++.h>
using namespace std;
int sqr(int a)
{
    return a * a;
}
int main()
{
    for(int i = 1; i <= 333; ++i)
        for(int j = i + 1; 1000 - j - i >= j; ++j)
        {
            if(sqr(i) + sqr(j) == sqr(1000 - j - i))
            {
                cout << i << " " << j << " " << (1000 - j - i) << endl;
                cout << i * j * (1000 - j - i) << endl;
            }
        }
}