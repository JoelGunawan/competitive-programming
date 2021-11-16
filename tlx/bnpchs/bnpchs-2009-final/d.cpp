#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
multiset<pair<int, int>> cpu, ram, crt, lcd, hddide, ssdsata, kabelide, kabelsata;
int n;
void solve(int money)
{
    int res = 0, leftover = money;
    multiset<pair<int, int>> tcpu = cpu, tram = ram, tcrt = crt, tlcd = lcd, thddide = hddide, tssdsata = ssdsata, tkabelide = kabelide, tkabelsata = kabelsata;
    for(int i = 1; i <= ((1 << n) - 1); ++i)
    {
        int localmoney = money, localres = 0;
        for(int j = 0; j < n; ++j)
        {
            if(i & (1 << j))
                localmoney -= 10;
        }
        while(true)
        {
            int backup = localmoney; auto it = cpu.begin();
            while(it != cpu.end())
            {
                if(i & (1 << (*it).second))
                {
                    localmoney -= (*it).first;
                    cpu.erase(it);
                    break;
                }
                ++it;
            }
            if(it == cpu.end())
            {
                localmoney = backup;
                break;
            }
            //cout << localmoney << " ";
            it = ram.begin();
            while(it != ram.end())
            {
                if(i & (1 << (*it).second))
                {
                    localmoney -= (*it).first;
                    ram.erase(it);
                    break;
                }
                ++it;
            }
            if(it == ram.end())
            {
                localmoney = backup;
                break;
            }
            //cout << localmoney << " ";
            int opt1 = INT_MAX, opt2 = INT_MAX;
            auto it1 = crt.begin();
            while(it1 != crt.end())
            {
                if(i & (1 << (*it1).second))
                {
                    opt1 = (*it1).first;
                    break;
                }
                ++it1;
            }
            auto it2 = lcd.begin();
            while(it2 != lcd.end())
            {
                if(i & (1 << (*it2).second))
                {
                    opt2 = (*it2).first;
                    break;
                }
                ++it2;
            }
            if(min(opt1, opt2) != INT_MAX)
            {
                localmoney -= min(opt1, opt2);
                if(opt1 < opt2)
                    crt.erase(it1);
                else
                    lcd.erase(it2);
            }
            else
            {
                localmoney = backup;
                break;
            }
            //cout << localmoney << " ";
            opt1 = INT_MAX, opt2 = INT_MAX;
            it1 = hddide.begin(), it2 = kabelide.begin(); auto it3 = ssdsata.begin(), it4 = kabelsata.begin();
            while(it1 != hddide.end())
            {
                if(i & (1 << (*it1).second))
                {
                    opt1 = (*it1).first;
                    break;
                }
                ++it1;
            }
            if(it1 != hddide.end())
            {
                // try to find the kabelide
                while(it2 != kabelide.end())
                {
                    if(i & (1 << (*it2).second))
                    {
                        opt1 += (*it2).first;
                        break;
                    }
                    ++it2;
                }
                if(it2 == kabelide.end())
                    opt1 = INT_MAX;
            }
            while(it3 != ssdsata.end())
            {
                if(i & (1 << (*it3).second))
                {
                    opt2 = (*it3).first;
                    break;
                }
                ++it3;
            }
            if(it3 != ssdsata.end())
            {
                // try to find the kabelsata
                while(it4 != kabelsata.end())
                {
                    if(i & (1 << (*it4).second))
                    {
                        opt2 += (*it4).first;
                        break;
                    }
                    ++it4;
                }
                if(it4 == kabelsata.end())
                    opt2 = INT_MAX;
            }
            if(min(opt1, opt2) != INT_MAX)
            {
                localmoney -= min(opt1, opt2);
                if(opt1 < opt2)
                {
                    hddide.erase(it1);
                    kabelide.erase(it2);
                }
                else
                {
                    ssdsata.erase(it3);
                    kabelsata.erase(it4);
                }
            }
            else
            {
                localmoney = backup;
                break;
            }
            //cout << localmoney << " ";
            if(localmoney < 0)
            {
                localmoney = backup;
                break;
            }
            else
                ++localres;
            //cout << endl;
        }
        //cout << endl;
        if(localres > res || (localres == res && localmoney > leftover))
        {
            res = localres;
            leftover = localmoney;
        }
        cpu = tcpu; ram = tram; crt = tcrt; lcd = tlcd; hddide = thddide; ssdsata = tssdsata; kabelide = tkabelide; kabelsata = tkabelsata;
    }
    cout << res << " buah komputer  sisa US$ " << leftover << endl;
}

void test_case()
{
    cin >> n;
    cpu.clear(); ram.clear(); crt.clear(); lcd.clear(); hddide.clear(); ssdsata.clear(); kabelide.clear(); kabelsata.clear();
    for(int i = 0; i < n; ++i)
    {
        int b;
        cin >> b;
        for(int j = 0; j < b; ++j)
        {
            string s; int price;
            cin >> s >> price;
            pair<int, int> tmp = make_pair(price, i);
            if(s == "cpu")
                cpu.insert(tmp);
            else if(s == "ram")
                ram.insert(tmp);
            else if(s == "crt")
                crt.insert(tmp);
            else if(s == "lcd")
                lcd.insert(tmp);
            else if(s == "hdd-ide")
                hddide.insert(tmp);
            else if(s == "ssd-sata")
                ssdsata.insert(tmp);
            else if(s == "kabel-ide")
                kabelide.insert(tmp);
            else
                kabelsata.insert(tmp);
        }
    }
    int q;
    cin >> q;
    // try every subset possible
    for(int i = 0; i < q; ++i)
    {
        int money;
        cin >> money;
        solve(money);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        cout << "Kasus " << i + 1 << endl;
        test_case();
    }
    return 0;
}