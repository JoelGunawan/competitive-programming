#include <string>
#include <vector>
#include "validate_domjudge.h"

using namespace std;
using ll = long long;

int main(int argc, char **argv) {
  init_io(argc, argv);

  int n;
  if (!(judge_in >> n)) {
    judge_error("Unable to read n\n");
  }

  if (n < 0 || n > 2000) {
    judge_error("n must be between 1 and 2000, inclusive\n");
  }

  vector<string> vs(2 * n + 1);
  for (int i = 0; i < 2 * n + 1; ++i) {
    if (!(judge_in >> vs[i])) {
      judge_error("Unable to read the %d-th row (0-indexed)\n", i);
    }
    if (static_cast<int>(vs[i].size()) != 2 * n + 1) {
      judge_error("The %d-th row must contain 2n+1 characters (0-indexed)\n", i);
    }
  }

  // validation
  {
    int gcount = 0, indicating_count = 0;
    for (int i = 0; i < 2 * n + 1; ++i)
    for (int j = 0; j < 2 * n + 1; ++j) {
      if (vs[i][j] == 'G') gcount++;
      else if (vs[i][j] != '.' && vs[i][j] != '^' && vs[i][j] != 'v' && vs[i][j] != '<' && vs[i][j] != '>') {
        judge_error("The %d-th character of the %d-th row must be valid (0-indexed)\n", j, i);
      }
      if (vs[i][j] != '.') indicating_count++;
    }
    if (gcount != 1) {
      judge_error("There must be exactly one treasure cell\n");
    }
    if (vs[n][n] != '^') {
      judge_error("The cell corresponding to the initial position must be ^\n");
    }

    for (int i = n, j = n, c = 0; ; c++) {
      if (i < 0 || j < 0 || i >= 2 * n + 1 || j >= 2 * n + 1 || vs[i][j] == '.') {
        judge_error("The input must lead to the treasure cell from the initial position\n");
      }
      if (vs[i][j] == '^') i--;
      else if (vs[i][j] == 'v') i++;
      else if (vs[i][j] == '<') j--;
      else if (vs[i][j] == '>') j++;
      else if (vs[i][j] == 'G') {
        if (indicating_count - 1 != c) {
          judge_error("There must not exist a cell containing one of '^v<>' that is not on the path from the initial cell to the treasure cell\n");
        }
        break;
      }
    }
  }

  int n_queries = 30000;
  int now_i = n, now_j = n;

  jprintln("%d", n);

  for (int q = 0; q < n_queries; ++q) {
    string s;
    if (!author_out.get(s)) {
        wrong_answer("Terminated without reaching the treasure cell\n");
    }
    if (static_cast<int>(s.size()) != 1) {
      wrong_answer("Invalid instruction: %s\n", s.c_str());
    }
    char c = s[0];

    if (c == '^') now_i--;
    else if (c == '>') now_j++;
    else if (c == 'v') now_i++;
    else if (c == '<') now_j--;
    else {
      wrong_answer("Invalid instruction: %c\n", c);
    }

    if (now_i < 0 || now_j < 0 || now_i >= 2 * n + 1 || now_j >= 2 * n + 1) {
      wrong_answer("You went to the outside of the grid\n");
    }

    jprintln("%c", vs[now_i][now_j]);

    if (vs[now_i][now_j] == 'G') {
      accept();
    }
  }
  wrong_answer("Too many steps\n");
}
