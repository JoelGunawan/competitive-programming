#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m[n];
    for(int i = 0; i < n; ++i)
        cin >> m[i];
    int counter = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 1; j < n; ++j)
        {
            if(m[j] < m[j - 1])
                swap(m[j], m[j - 1]), ++counter;
        }
    cout << counter << endl;
    return 0;
}