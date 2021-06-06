#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool up = true;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        if(tmp % 2 == 0) cout << tmp / 2 << endl;
        else
        {
            if(up)
            {
                if(tmp < 0) cout << tmp / 2 << endl;
                else cout << tmp / 2 + 1 << endl;
                up = !up;
            }
            else
            {
                if(tmp < 0) cout << tmp / 2 - 1 << endl;
                else cout << tmp / 2 << endl;
                up = !up;
            }
        }
    }
    return 0;
}
