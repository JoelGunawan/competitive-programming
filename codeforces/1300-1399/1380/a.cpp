#include <iostream>
#include <vector>

using namespace std;

void program()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i < n - 1; i++)
    {
        bool start = false, finish = false;
        int startindex, lastindex;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                start = true;
                startindex = j;
                break;
            }
        }
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[i])
            {
                finish = true;
                lastindex = j;
                break;
            }
        }
        if(start && finish)
        {
            cout << "YES" << endl;
            cout << startindex + 1 << " " << i + 1 << " " << lastindex + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        program();
    }
    return 0;
}
