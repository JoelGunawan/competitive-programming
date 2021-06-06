#include <iostream>

using namespace std;

void doCase()
{
    int n;
    cin >> n;
    int firstpos = -1, lastpos = -1;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '1')
        {
            if(firstpos == -1)
            {
                firstpos = i + 1;
                lastpos = i + 1;
            }
            else lastpos = i + 1;
        }
    }
    int other = max(firstpos - 1, n - lastpos);
    if(firstpos == -1) cout << n << endl;
    else cout << (other + lastpos - firstpos + 1) * 2 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) doCase();
    return 0;
}
