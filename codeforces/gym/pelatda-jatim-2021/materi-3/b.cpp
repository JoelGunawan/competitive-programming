#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cout << "? 1 3" << endl;
    cin >> a;
    cout << "? 4 6" << endl;
    cin >> b;
    cout << "? 1 2" << endl;
    cin >> c;
    cout << "? 4 5" << endl;
    cin >> d;
    vector<int> arr = {4, 8, 15, 16, 23, 42};
    do
    {
        if(arr[0] * arr[2] == a && arr[3] * arr[5] == b && arr[0] * arr[1] == c && arr[3] * arr[4] == d)
        {
            cout << "! ";
            for(int i = 0; i < arr.size(); ++i)
                cout << arr[i] << " ";
            cout << endl;
            break;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    return 0;
}