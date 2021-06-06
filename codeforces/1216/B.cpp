#include <bits/stdc++.h>

using namespace std;

struct number
{
  int number, position;
};

bool compareNum(number a, number b)
{
    return a.number > b.number;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<number> arr(n);
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        number num; num.number = tmp; num.position = i + 1;
        arr[i] = num;
    }
    sort(arr.begin(), arr.end(), compareNum);
    int result = 0;
    for(int i = 0; i < n; ++i)
    {
        result += arr[i].number * i + 1;
    }
    cout << result << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i].position;
        if(i == n - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}
