#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s)
{
    int n = s.size();
    for(int i = 0; i < n / 2; ++i)
    {
        if(s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    string barebone = "";
    int n = s.size();
    vector<int> arr;
    int tmplen = 1;
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        if(i == 0) continue;
        else if(i == n - 1)
        {
            if(s[i] == s[i - 1])
            {
                ++tmplen;
                arr.push_back(tmplen);
                barebone += s[i - 1];
            }
            else
            {
                arr.push_back(tmplen);
                barebone += s[i - 1];
                tmplen = 1;
                arr.push_back(tmplen);
                barebone += s[i];
            }
        }
        else if(s[i] != s[i - 1])
        {
            arr.push_back(tmplen);
            barebone += s[i - 1];
            tmplen = 0;
        }
        ++tmplen;
    }
    if(isPalindrome(barebone))
    {
        n = barebone.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(arr[i] + arr[n - i - 1] == 2)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        if(arr[n / 2] > 1)
        {
            cout << arr[n / 2] + 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
