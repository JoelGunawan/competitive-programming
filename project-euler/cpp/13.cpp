#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("13.txt");
    string input;
    vector<string> numbers;
    while(fin >> input)
        numbers.push_back(input), reverse(numbers.back().begin(), numbers.back().end());
    vector<int> number(50, 0);
    for(int i = 0; i < numbers.size(); ++i)
    {
        for(int j = 0; j < numbers[i].size(); ++j)
            number[j] += numbers[i][j] - '0';
    }
    int idx = 0;
    while(idx != number.size())
    {
        if(number[idx] >= 10)
        {
            if(idx == number.size() - 1)
                number.push_back(0);
            number[idx + 1] += number[idx] / 10;
            number[idx] %= 10;
        }
        ++idx;
    }
    int res = 0;
    for(int i = number.size() - 1; i > number.size() - 11; --i)
        res += number[i];
    cout << res << endl;
    return 0;
}