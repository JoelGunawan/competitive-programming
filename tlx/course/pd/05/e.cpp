#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s.size() == 1)
        cout << "satuan" << endl;
    else if(s.size() == 2)
        cout << "puluhan" << endl;
    else if(s.size() == 3)
        cout << "ratusan" << endl;
    else if(s.size() == 4)
        cout << "ribuan" << endl;
    else
        cout << "puluhribuan" << endl;
    return 0;
}