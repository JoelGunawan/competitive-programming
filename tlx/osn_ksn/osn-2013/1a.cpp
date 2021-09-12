#include <bits/stdc++.h>
using namespace std;
int main()
{
    string buang; int subsoal, n, k, q;
    cin >> buang >> subsoal >> n >> k >> q;
    if(subsoal == 5)
    {
        int mid = 1;
        while(mid < n / 2)
            mid *= 2;
        int movelength = mid, answer = 1; string interactor;
        // binary search up and down
        while(movelength > 0)
        {
            movelength /= 2;
            cout << 1 << " " << mid << endl;
            cin >> interactor;
            if(interactor == "ya")
                return 0;
            else if(interactor == "bisajadi")
            {
                answer = mid;
                mid += movelength;
            }
            else
                mid -= movelength;
        }
        cout << answer << endl;
        for(int i = 0; i < answer; ++i)
        {
            cout << i + 1;
            if(i != answer - 1)
                cout << " ";
        }
        cout << endl;
        cin >> interactor;
    }
    else if(k == 2)
    {
        // find every pair of numbers. If the size of answer is all numbers, then we need to check every combination
        vector<bool> arr(n, 1);
        string interactor;
        vector<int> ans;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                cout << 2 << " " << i + 1 << " " << j + 1 << endl;
                cin >> interactor;
                if(interactor == "ya")
                    return 0;
                else if(interactor == "tidak")
                    arr[i] = 0, arr[j] = 0;
            }
            if(arr[i])
                ans.push_back(i + 1);
        }
        if(ans.size() == n)
        {
            for(int i = 0; i < n; ++i)
            {
                cout << n - 1;
                for(int j = 0; j < n; ++j)
                {
                    if(i == j)
                        continue;
                    cout << " " << ans[j];
                }
                cout << endl;
                cin >> interactor;
                if(interactor == "ya")
                    return 0;
            }
            cout << n;
            for(int i = 0; i < n; ++i)
                cout << " " << i + 1;
            cout << endl;
            cin >> interactor;
        }
        else
        {
            cout << ans.size();
            for(int i = 0; i < ans.size(); ++i)
                cout << " " << ans[i];
            cout << endl;
            cin >> interactor;
        }
    }
    else
    {
        vector<int> ans; string interactor;
        for(int i = 0; i < n; ++i)
        {
            cout << 1 << " " << i + 1 << endl;
            cin >> interactor;
            if(interactor == "ya")
                return 0;
            else if(interactor == "bisajadi")
                ans.push_back(i + 1);
        }
        cout << ans.size() << " ";
        for(int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i];
            if(i != ans.size() - 1)
                cout << " ";
        }
        cout << endl;
        cin >> interactor;
    }
    return 0;
}