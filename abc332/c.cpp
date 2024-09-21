#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <atcoder/all>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef pair<int, int> P;
typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int max_x = 0, max_y = 0;
    int cnt_x = 0, cnt_y = 0;
    int ans;
    rep(i, 0, n) {
        if (s.at(i) == '0') {
            chmax(max_x, cnt_x);
            chmax(max_y, cnt_y);
            cnt_x = 0;
            cnt_y = 0;
        } else if (s.at(i) == '1') cnt_x++;
        else {
            cnt_x++;
            cnt_y++;
        }
    }
    chmax(max_x, cnt_x);
    chmax(max_y, cnt_y);
    ans = max(max_x - m, max_y);
    cout << ans << "\n";
    return 0;
}