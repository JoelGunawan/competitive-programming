#include "guess.h"
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
// returns an integer represented by vector of two pairs (possibly rotated)
vector<vector<pair<int, int>>>
rotate(vector<vector<pair<int, int>>> marked_card) {
  vector<vector<pair<int, int>>> ret;

  for (vector<pair<int, int>> &scratch : marked_card) {
    for (int k = 0; k < 1; ++k) {
      pair<int, int> new_scratch;

      scratch[0].first -= 1;
      scratch[0].second -= 1;
      new_scratch.first = (scratch[0].second) + 1;
      new_scratch.second = (-scratch[0].first) + 1;
      scratch[0] = new_scratch;

      scratch[1].first -= 1;
      scratch[1].second -= 1;
      new_scratch.first = (scratch[1].second) + 1;
      new_scratch.second = (-scratch[1].first) + 1;
      scratch[1] = new_scratch;
    }

    ret.push_back(scratch);
  }

  return ret;
}
int guess(vector<vector<pair<int, int>>> marked_card) {
  vector<vector<pair<int, int>>> s, d1, d2;
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j <= 2; ++j) {
      // horizontal dan vertikal
      s.pb({mp(j, i), mp(j, i + 1)});
      s.pb({mp(i, j), mp(i + 1, j)});
    }
  }
  for(int i = 0; i < s.size(); ++i)
    sort(s[i].begin(), s[i].end());
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      // diagonal 1x1
      d1.pb({mp(i, j), mp(i + 1, j + 1)});
      d1.pb({mp(i + 1, j), mp(i, j + 1)});
    }
  }
  for(int i = 0; i < d1.size(); ++i)
    sort(d1[i].begin(), d1[i].end());
  for(int i = 0; i < 2; ++i) {
    // diagonal 1x2
    d2.pb({mp(i, 0), mp(i + 1, 2)});
    d2.pb({mp(i + 1, 0), mp(i, 2)});
  }
  for(int i = 0; i < 2; ++i) {
    // diagonal 2x1
    d2.pb({mp(0, i), mp(2, i + 1)});
    d2.pb({mp(0, i + 1), mp(2, i)});
  }
  for(int i = 0; i < d1.size(); ++i)
    sort(d2[i].begin(), d2[i].end());
  sort(s.begin(), s.end());
  sort(d1.begin(), d1.end());
  sort(d2.begin(), d2.end());
  for(int i = 0; i < marked_card.size(); ++i)
    sort(marked_card[i].begin(), marked_card[i].end());
  // nanti cek jumlah s yg nempel ke
  sort(marked_card.begin(), marked_card.end());
  int mid_cnt = 0;
  for(auto i : marked_card) {
    if(binary_search(s.begin(), s.end(), i) && (i[0] == mp(1, 1) || i[1] == mp(1, 1))) {
      //cout << i[0].fi << " " << i[0].se << " " << i[1].fi << " " << i[1].se << endl;
      ++mid_cnt;
    }
  }
  vector<vector<pair<int, int>>> a;
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j <= 2; ++j) {
      // horizontal dan vertikal
      if(i == 1 && j == 1)
        continue;
      if(mp(j, i + 1) != mp(1, 1))
        a.pb({mp(j, i), mp(j, i + 1)});
      if(mp(i + 1, j) != mp(1, 1))
        a.pb({mp(i, j), mp(i + 1, j)});
    }
  }
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      // diagonal 1x1
      a.pb({mp(i, j), mp(i + 1, j + 1)});
      a.pb({mp(i + 1, j), mp(i, j + 1)});
    }
  }
  for(int i = 0; i < 2; ++i) {
    // diagonal 1x2
    a.pb({mp(i, 0), mp(i + 1, 2)});
    a.pb({mp(i + 1, 0), mp(i, 2)});
  }
  for(int i = 0; i < 2; ++i) {
    // diagonal 2x1
    a.pb({mp(0, i), mp(2, i + 1)});
    a.pb({mp(0, i + 1), mp(2, i)});
  }
  for(int i = 0; i < a.size(); ++i)
    sort(a[i].begin(), a[i].end());
  int res = 0;
  //cout << "TEST" << endl;
  if(mid_cnt == 1) {
    do {
      // 1, 2
      int cnt = 0;
      //cout << marked_card.size() << endl;
      for(auto i : marked_card) {
        sort(i.begin(), i.end());
        if(i[0] == mp(1, 1) && i[1] == mp(1, 2)) {
          ++cnt;
        }
      }
      //cout << cnt << endl;
      if(cnt == 1)
        break;
      else
        marked_card = rotate(marked_card);
    } while(true);
    // udah correct config, sekarang tinggal cek pake bitmask biasa aja
    //cout << "OUTPUT CARDS" << endl;
    for(int i = 0; i < marked_card.size(); ++i) {
      sort(marked_card[i].begin(), marked_card[i].end());
      //cout << marked_card[i][0].fi << " " << marked_card[i][0].se << " " << marked_card[i][1].fi << " " << marked_card[i][1].se << endl;
    }
    sort(marked_card.begin(), marked_card.end());
    //cout << "OUTPUT BINSER" << endl;
    for(int i = 23; i >= 0; --i) {
      if(binary_search(marked_card.begin(), marked_card.end(), a[i])) {
        //cout << a[i][0].fi << " " << a[i][0].se << " " << a[i][1].fi << " " << a[i][1].se << endl;
        res += (1 << i);
      }
    }
  }
  else if(mid_cnt == 2) {
    // 0, 1 and 1, 2
    do {
      int cnt = 0;
      for(auto i : marked_card) {
        sort(i.begin(), i.end());
        if((i[0] == mp(0, 1) && i[1] == mp(1, 1)) || (i[0] == mp(1, 1) && i[1] == mp(1, 2))) {
          ++cnt;
        }
      }
      //cout << cnt << endl;
      if(cnt == 2)
        break;
      else
        marked_card = rotate(marked_card);
    } while(true);
    res += 1 << 24;
    for(int i = 0; i < marked_card.size(); ++i)
      sort(marked_card[i].begin(), marked_card[i].end());
    sort(marked_card.begin(), marked_card.end());
    for(int i = 23; i >= 0; --i) {
      if(binary_search(marked_card.begin(), marked_card.end(), a[i])) {
        res += (1 << i);
      }
    }
  }
  else if(mid_cnt == 3) {
    // {0, 1}, {1, 2}, {2, 1}
    do {
      int cnt = 0;
      for(auto i : marked_card) {
        sort(i.begin(), i.end());
        if((i[0] == mp(0, 1) && i[1] == mp(1, 1)) || (i[0] == mp(1, 1) && i[1] == mp(1, 2)) || (i[0] == mp(1, 1) && i[1] == mp(2, 1))) {
          ++cnt;
        }
      }
      if(cnt == 3)
        break;
      else
        marked_card = rotate(marked_card);
    } while(true);
    res += 1 << 25;
    for(int i = 0; i < marked_card.size(); ++i)
      sort(marked_card[i].begin(), marked_card[i].end());
    sort(marked_card.begin(), marked_card.end());
    for(int i = 23; i >= 0; --i) {
      if(binary_search(marked_card.begin(), marked_card.end(), a[i])) {
        res += (1 << i);
      }
    }
  }
  return res;
}