#include <bits/stdc++.h>

using namespace std;

void convertToLowerCase(string& a)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] < 'a')
        {
            a[i] += ('a' - 'A');
        }
    }
}

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    convertToLowerCase(a); convertToLowerCase(b);
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] < b[i])
        {
            printf("-1\n");
            return 0;
        }
        else if(a[i] > b[i])
        {
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
