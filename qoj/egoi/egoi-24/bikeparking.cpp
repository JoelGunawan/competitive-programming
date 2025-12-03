#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, total = 0;
  cin >> n;
  int cap[n + 5];
  int pref[n + 5];
  pref[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> cap[i];
    pref[i] = pref[i - 1] + cap[i];
  }

  int user[n + 5];
  for (int i = 1; i <= n; ++i) {
    cin >> user[i];
    total += user[i];
  }

  // normalize cap to number of users
  int ck = 0;
  for (int i = 1; i <= n; ++i) {
    if (pref[i - 1] >= total) {
      cap[i] = 0;
    } else if (pref[i] >= total && pref[i - 1] < total) {
      cap[i] -= pref[i] - total;
    }
    ck += cap[i];
  }
  assert(ck == total);

  // idea: prioritize upvote -> satisfied -> downvote
  // is it ever "wrong" to prioritize upvote instead of satisfied?
  // let's say we can get two satisfied vs one upvote, one downvote -> equally good
  // then, we will try to go from most premium to least premium tier
  // DOESNT WORK
  // try to get satisfied first, since we can't "use" that user again later
  // then try to maximize upvotes
  // satisfied -> +1
  // upvote -> +2
  // greedy by upvote?
  // logically: from the smallest capacities that we have,
  // if we have a lot of excess, we can just spend it all on upvotes
  // if it makes it so that we can't satisfy the current people, that should be fine
  // upvote + downvote == 2 satisfied
  // is there even a case where we can change 1 upvote to multiple satisfied?
  // no?
  // therefore if we just greedily get as much upvotes, then maximize satisfaction, 
  // that should work...
  
  int satisfied = 0, upvotes = 0, downvotes = 0;
  int l = 1, r = n;
  vector<int> v;
  for (int i = n; i >= 1; --i) {
    // try to get as much upvotes as possible...
    // if not possible, then get as much satisfied as possible...
    // if not, then get downvotes from any, of course largest one is optimal

    // get as much upvotes as possible...
    while (cap[i] > 0 && v.size()) {
      int r = v.back();
      int cur_u = min(cap[i], user[r]);
      cap[i] -= cur_u;
      user[r] -= cur_u;
      upvotes += cur_u;
      if (user[r] == 0) v.pop_back();
    }

    v.push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    // get as much satisfied as possible...
    int cur_s = min(cap[i], user[i]);
    cap[i] -= cur_s;
    user[i] -= cur_s;
    satisfied += cur_s;
  }

  downvotes = total - upvotes - satisfied;

  // 

  cout << upvotes - downvotes << endl;

  return 0;
}