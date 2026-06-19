#include <bits/stdc++.h>
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
#define ll long long 
using namespace std;

const int oo = 1e9;

int convert(string s) {
  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3, 2));
  int sec = stoi(s.substr(6, 2));
  return h * 3600 + m * 60 + sec;
}

string tts(int num) {
  int h = num / 3600;
  int m = (num % 3600) / 60;
  int s = num % 60;
  string res = "";
  if(h < 10) {
    res += '0';
  }
  res += to_string(h);
  res += ":";

  if(m < 10) {
    res += '0';
  }
  res += to_string(m);
  res += ":";

  if(s < 10) {
    res += '0';
  }
  res += to_string(s);
  
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  string target;
  cin >> target;

  string a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  
  string pref[n + 1];
  string pr = "00:00:00";
  for(int i = 1; i <= n; ++i) {
    // find next time > cur
    string cur = a[i];
    
    int pr_time = convert(pr);
    // do hour
    int pr_h = stoi(pr.substr(0, 2));
    vector<int> ph;
    for(int i = 0; i < 24; ++i) {
      int p = i / 10;
      int s = i % 10;
      char cur_p = cur[0];
      char cur_s = cur[1];
      if((p == cur_p - '0' || cur_p == 'X') && (s == cur_s - '0' || cur_s == 'X')) {
        if(i >= pr_h) {
          ph.push_back(i);
          if(i > pr_h)
            break;
        }
      }
    }

    vector<int> pm;
    int pr_m = stoi(pr.substr(3, 2));
    bool small = 0;
    for(int i = 0; i < 60; ++i) {
      int p = i / 10;
      int s = i % 10;
      char cur_p = cur[3];
      char cur_s = cur[4];
      if((p == cur_p - '0' || cur_p == 'X') && (s == cur_s - '0' || cur_s == 'X')) {
        if(i >= pr_m) {
          pm.push_back(i);
          if(i > pr_m)
            break;
        }
        else {
          if(!small) {
            small = 1;
            pm.push_back(i);
          }
        }
      }
    }

    vector<int> ps;
    int pr_s = stoi(pr.substr(6, 2));
    small = 0;
    for(int i = 0; i < 60; ++i) {
      int p = i / 10;
      int s = i % 10;
      char cur_p = cur[6];
      char cur_s = cur[7];
      if((p == cur_p - '0' || cur_p == 'X') && (s == cur_s - '0' || cur_s == 'X')) {
        if(i >= pr_s) {
          ps.push_back(i);
          if(i > pr_s)
            break;
        }
        else {
          if(!small) {
            small = 1;
            ps.push_back(i);
          }
        }
      }
    }

    int min_t = 100000;
    bool first = i == 1;
    for(int i = 0; i < ph.size(); ++i) {
      for(int j = 0; j < pm.size(); ++j) {
        for(int k = 0; k < ps.size(); ++k) {
          int t = ph[i] * 3600 + pm[j] * 60 + ps[k];
          if(t > pr_time || first) {
            min_t = min(t, min_t);
          }
        }
      }
    }

    pr = tts(min_t);
    pref[i] = pr;
    // cout << "MIN TIME " << i << " " << pref[i] << endl;
  }

  int last;
  if(convert(pref[n]) < convert(target)) {
    // try to maximize everything from end but < target
    last = 1;
    pr = target;
  }
  else {
    // try to maximize everything from end (ignoring prefix that is smaller)
    for(int i = 1; i <= n; ++i) {
      if(convert(pref[i]) >= convert(target)) {
        last = i;
        break;
      }
    }
    pr = "24:00:00";
  }

  for(int i = n; i >= last; --i) {
    // find next time > cur
    string cur = a[i];
    
    int pr_time = convert(pr);
    // do hour
    int pr_h = stoi(pr.substr(0, 2));
    vector<int> ph;
    for(int i = 23; i >= 0; --i) {
      int p = i / 10;
      int s = i % 10;
      char cur_p = cur[0];
      char cur_s = cur[1];
      if((p == cur_p - '0' || cur_p == 'X') && (s == cur_s - '0' || cur_s == 'X')) {
        if(i <= pr_h) {
          ph.push_back(i);
          if(i < pr_h)
            break;
        }
      }
    }

    vector<int> pm;
    int pr_m = stoi(pr.substr(3, 2));
    bool small = 0;
    for(int i = 59; i >= 0; --i) {
      int p = i / 10;
      int s = i % 10;
      char cur_p = cur[3];
      char cur_s = cur[4];
      if((p == cur_p - '0' || cur_p == 'X') && (s == cur_s - '0' || cur_s == 'X')) {
        if(i <= pr_m) {
          pm.push_back(i);
          if(i < pr_m)
            break;
        }
        else {
          if(!small) {
            small = 1;
            pm.push_back(i);
          }
        }
      }
    }

    vector<int> ps;
    int pr_s = stoi(pr.substr(6, 2));
    small = 0;
    for(int i = 59; i >= 0; --i) {
      int p = i / 10;
      int s = i % 10;
      char cur_p = cur[6];
      char cur_s = cur[7];
      if((p == cur_p - '0' || cur_p == 'X') && (s == cur_s - '0' || cur_s == 'X')) {
        if(i <= pr_s) {
          ps.push_back(i);
          if(i < pr_s)
            break;
        }
        else {
          if(!small) {
            small = 1;
            ps.push_back(i);
          }
        }
      }
    }

    int max_t = 0;
    for(int i = 0; i < ph.size(); ++i) {
      for(int j = 0; j < pm.size(); ++j) {
        for(int k = 0; k < ps.size(); ++k) {
          int t = ph[i] * 3600 + pm[j] * 60 + ps[k];
          // cerr << pr_time << " " << t << " " << cur << endl;
          if(t < pr_time || i == 1) {
            max_t = max(t, max_t);
          }
        }
      }
    }

    pr = tts(max_t);
    // cout << "MAX TIME " << i << " " << pr << endl;
  }

  if(convert(pr) >= convert(target)) {
    cout << convert(pr) - convert(target) << endl;
  }
  else {
    cout << 86400 - convert(target) + convert(pr) << endl;
  }
}