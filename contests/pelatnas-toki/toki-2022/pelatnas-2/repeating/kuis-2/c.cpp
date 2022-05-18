#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    // mustahil menang? more like mustahil AC :")
    // jika karakter paling terakhir bisa dihapus, maka ideal untuk dihapus
    // urutan itu penting, bisa jadi kita harus hapus di kiri dulu supaya bisa hapus di kanan
    string s;
    cin >> s;
    // pake some form of stack
    // dimana kita bisa hapus stacknya supaya ideal
    int a[k][k];
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j) {
            char x;
            cin >> x;
            a[i][j] = x == '1';
        }
    // dalam stack
    // simpan state chain reaction
    // kalo dimodif sama sebuah karakter jadi apa paling ideal
    // kalo paling belakang x elemen itu sudah paling ideal, maka tidak bisa lebih ideal lagi, tidak akan dimodif
    // tidak mungkin undo deletion bisa jadi ideal
    // bisa jadi lakuin deletion lebih
    // untuk menghapus harus cari lexico min di string sisa di belakang
    // jika lebih besar lexiconya maka pasti tidak ideal
    // memperpendek string belum tentu ideal, jika 2 string lexico sama, maka lanjutkan sampai akhir
    // jika tetap sama, maka pendek lebih ideal
    // soal p4a cari lexico lebih kecil menggunakan hashing?
    // bisa hashing + binser on the string
    // di first instance yang beda, maka tentukan lexico lebih kecil
    // memo untuk tiap karakter, bisa menghapus string sampai mana, jika menghapus akan menghasilkan string yang lebih kecil lexiconya
    // maka kita lakukan deletion
    // dan kita perlu mengubah memonya
    // pake s.substr O(n)
    // coba algo O(n^3) dulu aja
    // kita cek kita bisa delete sejauh apa
    // terus cek apakah string sisanya itu optimal bukan
    string dp[n];
    dp[n - 1] = "";
    // this is actually O(n^3)? kekw
    for(int i = n - 2; i >= 0; --i) {
        // minimum awal itu ga hapus sama sekali
        string minimum = s[i + 1] + dp[i + 1];
        stack<char> prev;
        prev.push(s[i]);
        // delete dari i + 1 sampai j
        // cari minimum pake dp
        // possible cause wa
        // ini tetap O(n^2) :")
        // cara greedy buat pilih j tanpa harus pilih semua
        // cari j paling jauh yang mungkin gunakan precalc stack
        // terus range query aja di range itu deletionnya berapa aja
        for(int j = i + 1; j < s.size(); ++j) {
            // delete from i + 1 to j
            // if possible check if it is smaller
            //cout << s[i] - 'a' << " " << s[j] - 'a' << " " << a[s[i] - 'a'][s[j] - 'a'] << endl;
            // any previous harusnya boleh asal berurutan deletionnya
            // kecuali s[i] boleh global
            bool ada = 0;
            // cek kalo bisa menghapus substring l hingga r dalam O(n)
            // cari cara deletion valid
            // bisa pakai stack mungkin?
            while(prev.size() > 0) {
                if(a[prev.top() - 'a'][s[j] - 'a']) {
                    ada = 1;
                    break;
                }
                else {
                    prev.pop();
                }
            }
            if(ada) {
                //cout << "IN " << j << " " << minimum << " " << tmp << endl;
                if(dp[j] < minimum) {
                    minimum = dp[j];
                    //cout << i << " " << j << " " << dp[j] << endl;
                }
            }
            else
                break;
            prev.push(s[j]);
        }
        dp[i] = minimum;
        //cout << min_idx << " " << minimum << endl;
    }
    cout << s[0] + dp[0] << endl;
    return 0;
}