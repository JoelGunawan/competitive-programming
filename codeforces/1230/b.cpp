#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(s.size() == 1 && k == 1)
    {
        cout << '0' << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        if(k > 0)
        {
            if(i == 0 && s[i] != '1')
            {
                --k;
                s[i] = '1';
            }
            else if(i > 0 && s[i] != '0')
            {
                --k;
                s[i] = '0';
            }
        }
        else break;
    }
    cout << s << endl;
    return 0;
}
