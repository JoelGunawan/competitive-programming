#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int pointer1 = 0, pointer2 = s.size();
    vector<char> arr;
    bool last = 0;
    while(pointer2 > pointer1)
    {
        if(pointer2 - pointer1 <= 3)
        {
            // choose 1
            arr.push_back(s[pointer1]);
            last = 1;
            break;
        }
        string a = s.substr(pointer1, 2), b = s.substr(pointer2 - 2, 2);
        pointer1 += 2, pointer2 -= 2;
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        if(a[0] == b[0] || a[0] == b[1])
            arr.push_back(a[0]);
        else
            arr.push_back(a[1]);            
    }
    for(int i = 0; i < arr.size(); ++i)
        cout << arr[i];
    if(!last)
        cout << arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; --i)
        cout << arr[i];
    cout << endl;
    return 0;
}