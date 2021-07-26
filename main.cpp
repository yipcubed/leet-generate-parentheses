#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../utils/PrintUtils.hpp"

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return NULL;
}();

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    // PV1(n);
    if (!n) {
      return {""};
    }
    vector<string> parens;
    for (int i = 0; i < n; i++) {
      for (string l : generateParenthesis(i)) {
        for (string r : generateParenthesis(n - 1 - i)) {
          // PV2(i, n - 1 - i);
          // PV1(l);
          // PV1(r);
          parens.push_back('(' + l + ')' + r);
        }
      }
    }
    // PV2(n, parens);
    return parens;
  }

  vector<string> generateParenthesis2(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
  }
  void addingpar(vector<string> &v, string str, int n, int m) {
    if (n == 0 && m == 0) {
      v.push_back(str);
      return;
    }
    if (m > 0) {
      addingpar(v, str + ")", n, m - 1);
    }
    if (n > 0) {
      addingpar(v, str + "(", n - 1, m + 1);
    }
  }
};

void test1() {
  Solution S;
  cout << "----" << endl;
  S.generateParenthesis(1);
  cout << "----" << endl;
  S.generateParenthesis(2);
  cout << "----" << endl;
  S.generateParenthesis(3);
}

void test2() {}

void test3() {}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;

  return 0;
}