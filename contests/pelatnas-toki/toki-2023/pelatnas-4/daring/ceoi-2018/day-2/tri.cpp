#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "trilib.h"
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int qcnt = 0;
//gp_hash_table<long long, int> memo;
//gp_hash_table<long long, bool> vis;
//long long const1 = 16e8, const2 = 4e4, const3 = 1;
int get_query(int x, int y, int z) {
    //if(vis[const1 * x + const2 * y + const3 * z])
    //    return memo[const1 * x + const2 * y + const3 * z];
    //assert(x != y && y != z && x != z);
    //++qcnt;
    //assert(qcnt <= 1e6);
    // coba pastiin ini sebenernya udah sampe mana sih, harusnya udh close to finished
    //vis[const1 * x + const2 * y + const3 * z] = 1;
    return is_clockwise(x, y, z);
}
deque<int> solve(deque<int> a) {
    // a itu yg kita mau solve skrg
    // pick 2 random variables, terus nnti cek semuanya ada di kiri/kanannya a
    //assert(a.size() >= 2);
    if(a.size() == 1) {
        return a;
    }
    else if(a.size() == 2) {
        // any is correct
        return a;
    }
    else if(a.size() == 3) {
        // coba aja urutan mana yg clockwise
        if(get_query(a[0], a[1], a[2]))
            return a;
        else {
            swap(a[0], a[1]);
            //assert(get_query(a[0], a[1], a[2]));
            return a;
        }
    }
    else {
        // pick 2 random, terus nnti dipisah
        int x = rng() % a.size(), y;
        do {    
            y = rng() % a.size();
        } while(x == y);
        x = a[x], y = a[y];
        //assert(x != y);
        deque<int> g1, g2;
        // do random sampai ketemu yg mendekati /2
        for(auto i : a) {
            if(i == x || i == y)
                continue;
            if(get_query(x, y, i))
                g1.push_back(i);
            else
                g2.push_back(i);
        }
        g1.push_back(y);
        g2.push_back(x);
        g1 = solve(g1);
        g2 = solve(g2);
        // combine g1 and g2
        // jadiin g1, g2 jadi bentuk yg diinginkan
        // g1
        // y ... x
        // g2
        // x ... y
        //cout << "ENTER G1" << endl;
        while(g1.front() != y) {
            g1.push_front(g1.back());
            g1.pop_back();
        }
        while(g2.front() != x) {
            g2.push_front(g2.back());
            g2.pop_back();
        }
        //assert(g1.front() == y && g1.back() == x);
        //assert(g2.front() == x && g2.back() == y);
        //cout << "PART1" << endl;
        while(g1.size() >= 2 || g2.size() >= 2) {
            bool change = 0;
            //cout << x << " " << y << endl;
            //for(auto i : g1)
            //    cout << i << " ";
            //cout << endl;
            //for(auto i : g2) {
            //    cout << i << " ";
            //}
            //cout << endl;
            if(g1.size() == 1) {
                // coba hapus g2
                //cout << "TEST HERE" << endl;
                if(!get_query(g1.back(), g2.front(), g2[1]))
                    g2.pop_front(), change = 1;
            }
            else if(g2.size() == 1) {
                // coba hapus g1
                //cout << "TEST2" << endl;
                if(!get_query(g1[g1.size() - 2], g1.back(), g2[0]))
                    g1.pop_back(), change = 1;
            }
            else {
                // bisa coba hapus dua"nya
                //cout << "LAST CASE" << endl;
                if(!get_query(g1.back(), g2.front(), g2[1]))
                    g2.pop_front(), change = 1;
                else if(!get_query(g1[g1.size() - 2], g1.back(), g2[0]))
                    g1.pop_back(), change = 1;
            }
            if(!change)
                break;
        }
        //cout << "PART2" << endl;
        while(g1.size() >= 2 || g2.size() >= 2) {
            //cout << x << " " << y << endl;
            //for(auto i : g1)
            //    cout << i << " ";
            //cout << endl;
            //for(auto i : g2) {
            //    cout << i << " ";
            //}
            //cout << endl;
            bool change = 0;
            if(g2.size() == 1) {
                //cout << "TEST2" << endl;
                // coba hapus g2
                if(!get_query(g2.back(), g1.front(), g1[1]))
                    g1.pop_front(), change = 1;
            }
            else if(g1.size() == 1) {
                //cout << "TEST3" << endl;
                // coba hapus g1
                if(!get_query(g2[g2.size() - 2], g2.back(), g1[0]))
                    g2.pop_back(), change = 1;
            }
            else {
                // bisa coba hapus dua"nya
                //cout << "TEST4" << endl;
                if(!get_query(g2.back(), g1.front(), g1[1]))
                    g1.pop_front(), change = 1;
                else if(!get_query(g2[g2.size() - 2], g2.back(), g1[0]))
                    g2.pop_back(), change = 1;
            }
            if(!change)
                break;
        }
        //cout << "PART 2 OVER" << endl;
        deque<int> ret;
        for(auto i : g1)
            ret.push_back(i);
        for(auto i : g2) {
            ret.push_back(i);
        }
        //cout << "OTW RETURN" << endl;
        //cout << s.size() << " " << ret.size() << endl;
        //assert(s.size() == ret.size());
        return ret;
    }
}
int main() {
    int n;
    n = get_n();
    deque<int> v;
    for(int i = 1; i <= n; ++i)
        v.push_back(i);
    v = solve(v);
    //cout << v.size() << endl;
    //for(int i = 0; i < v.size(); ++i) {
    //    //assert(get_query(v[i], v[(i + 1) % v.size()], v[(i + 2) % v.size()]));
    //}
    // pastikan v unique?
    give_answer(v.size());
    return 0;
}