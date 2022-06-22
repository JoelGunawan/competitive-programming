#include "mars.h"
#include <bits/stdc++.h>
using namespace std;
bool grid[41][41];
bool vis[41][41];
int nxtx[4] = {1, 0, -1, 0}, nxty[4] = {0, 1, 0, -1};
bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < 41 && y < 41 && grid[x][y] && !vis[x][y];
}
void dfs(int x, int y) {
	vis[x][y] = 1;
	for(int i = 0; i < 4; ++i) {
		if(valid(x + nxtx[i], y + nxty[i]))
			dfs(x + nxtx[i], y + nxty[i]);
	}
}
string to_binary(int num) {
	string res = "";
	for(int i = 0; i < 30; ++i) {
		res += ('0' + num % 2), num /= 2;
	}
	for(int i = 30; i < 100; ++i)
		res += '0';
	//cout << res << endl;
	return res;
}
std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n)
{
	// coba buat algo buat simpen entire square di 9 kotak
	if(k == n - 1) {
		// buat dfs
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		memset(grid, 0, sizeof(grid));
		if(n == 1) {
			// langsung aja
			//cout << "TEST" << endl;
			for(int i = 0; i < a.size(); ++i)
				for(int j = 0; j < a[i].size(); ++j) {
					//cout << i << " " << j << " " << a[i][j][0] << endl;
					grid[i][j] = a[i][j][0] == '1';
				}
			//cout << "TEST" << endl;
			for(int i = 0; i < a.size(); ++i) {
				for(int j = 0; j < a[i].size(); ++j)
					if(valid(i, j))
						dfs(i, j), ++cnt;
			}
		}
		else {
			// anggep grid 10x10
			// ijin ke toilet
			string res(144, '0');
			// current size itu banyak operasi dari k
			int cur_size = 2 * (k - 1) + 3;
			for(int i = 0; i < cur_size; ++i)
				for(int j = 0; j < cur_size; ++j) {
					// ambil dari atas kiri
					res[i * 10 + j] = a[0][0][i * 10 + j];
				}
			for(int i = cur_size; i < 10; ++i) {
				for(int j = 0; j < cur_size; ++j) {
					res[i * 10 + j] = a[2][0][(i - 2) * 10 + j];
				}
			}
			for(int i = cur_size; i < 10; ++i) {
				for(int j = 0; j < cur_size; ++j) {
					res[j * 10 + i] = a[0][2][j * 10 + (i - 2)];
				}
			}
			for(int i = cur_size; i < 10; ++i)
				for(int j = cur_size; j < 10; ++j) {
					res[i * 10 + j] = a[2][2][(i - 2) * 10 + (j - 2)];
				}
			for(int i = 0; i < 10; ++i)
				for(int j = 0; j < 10; ++j)
					grid[i][j] = res[i * 10 + j] == '1';
			for(int i = 0; i < 10; ++i) {
				for(int j = 0; j < 10; ++j) {
					if(valid(i, j))
						dfs(i, j), ++cnt;
				}
			}
		}
		//cout << "TEST" << endl;
		return to_binary(cnt);
	}
	else if(k == 0) {
		// construct kotak
		string res(100, '0');
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j)
				res[i * 10 + j] = '0' + (a[i][j][0] == '1');
		}
		return res;
	}
	else {
		// construct kotak dari 4 titik
		string res(100, '0');
		// current size itu banyak operasi dari k
		int cur_size = 2 * (k - 1) + 3;
		for(int i = 0; i < cur_size; ++i)
				for(int j = 0; j < cur_size; ++j) {
					// ambil dari atas kiri
					res[i * 10 + j] = a[0][0][i * 10 + j];
				}
			for(int i = cur_size; i < 10; ++i) {
				for(int j = 0; j < cur_size; ++j) {
					res[i * 10 + j] = a[2][0][(i - 2) * 10 + j];
				}
			}
			for(int i = cur_size; i < 10; ++i) {
				for(int j = 0; j < cur_size; ++j) {
					res[j * 10 + i] = a[0][2][j * 10 + (i - 2)];
				}
			}
			for(int i = cur_size; i < 10; ++i)
				for(int j = cur_size; j < 10; ++j) {
					res[i * 10 + j] = a[2][2][(i - 2) * 10 + (j - 2)];
				}
		return res;
	}
}
