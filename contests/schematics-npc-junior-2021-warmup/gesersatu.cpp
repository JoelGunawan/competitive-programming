#include <bits/stdc++.h>
using namespace std;
int main()
{
    string k, s;
    getline(cin, k);
    getline(cin, s);
    int vowelindex = 0, consonantindex = 0;
    char vowels[5], consonants[21];
    bool in_k[26]; memset(in_k, 0, sizeof(in_k));
    for(int i = 0; i < k.size(); ++i)
        in_k[k[i] - 'A'] = 1;
    string alphabet = "";
    for(char i = 'A'; i <= 'Z'; ++i)
    {
        if(!in_k[i - 'A'])
            alphabet += i;
    }
    alphabet += k;
    for(int i = 0; i < 26; ++i)
        if(alphabet[i] == 'A' || alphabet[i] == 'I' || alphabet[i] == 'U' || alphabet[i] == 'E' || alphabet[i] == 'O')
            vowels[vowelindex] = alphabet[i], ++vowelindex;
        else
            consonants[consonantindex] = alphabet[i], ++consonantindex;
    cout << endl;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
            cout << s[i];
        else if(find(vowels, vowels + 5, s[i]) != vowels + 5)
            cout << vowels[((find(vowels, vowels + 5, s[i]) - vowels) + 1) % 5];
        else
            cout << consonants[((find(consonants, consonants + 21, s[i]) - consonants) + 1) % 21];
    }
    cout << endl;
}