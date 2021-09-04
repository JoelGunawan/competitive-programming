#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
void test_case()
{
    double a, b, k;
    cin >> a >> b >> k;
    if(ceil(a / (b + 1)) > 2 || ceil(b / (a + 1)) > k)
        cout << "mustahil" << endl;
    else
    {
        if(a == b)
        {
            for(int i = 0; i < 2 * a; ++i)
            {
                if(i & 1)
                    cout << 'L';
                else
                    cout << 'P';
            }
        }
        else if(a > b)
        {
            int remaindera = (int)a % (int)(b + 1);
            if(remaindera == 0)
                remaindera = b + 1;
            //cout << remaindera << " " << ceil(a / (b + 1)) << " " << a << " " << b + 1 << endl;
            for(int i = 0; i < b + 1; ++i)
            {
                for(int j = 0; j < ceil(a / (b + 1)) - 1; ++j)
                    cout << 'L';
                if(remaindera)
                    cout << 'L', --remaindera;
                if(i != b)
                    cout << 'P';
            }
        }
        else
        {
            int remainderb = (int)b % (int)(a + 1);
            if(remainderb == 0)
                remainderb = a + 1;
            for(int i = 0; i < a + 1; ++i)
            {
                for(int j = 0; j < ceil(b / (a + 1)) - 1; ++j)
                    cout << 'P';
                if(remainderb)
                    cout << 'P', --remainderb;
                if(i != a)
                    cout << 'L';
            }
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}