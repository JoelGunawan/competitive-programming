#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main() {
    // klo misal dari a bisa ambil b, bisa buat semacam edge -> ada edge case
    // 10 - 1 - 2 - 7
    // 10 bisa ambil ke kanan, 7 gabisa
    // observe: klo dia bisa ambil max, dia bisa ambil semua
    // try to order dr max bs ambil mana aja?
    // consider line graph
    // cek kanan terjauh bisa sampe mana, kiri terjauh bs sampe mana? -> too slow
    // 10 - 1 - 2 - 4 - 7
    // 4, 7, 10 bisa
    // for every edge, buat jadi directed jika bisa dari a -> b
    // bisa skip node jika perlu
    // misal 5 - 3 - 9
    // 5 -> 3
    // 9 -> 3
    // 9 -> 5
    // problem -> gabisa
    // dari max atau dr min?
    
}