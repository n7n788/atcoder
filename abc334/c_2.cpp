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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    int ans, x;
    rep(i, 0, k) cin >> a.at(i);
    if (k % 2 == 0) {
        ans = 0;
        for (int i = 0; i < k; i += 2) {
            ans += (a.at(i + 1) - a.at(i));
        }
        cout << ans << "\n";
        return 0;
    } 
    // 尺取り法: 差分を計算する
    x = 0;
    for (int i = 1; i < k; i += 2) {
        x += (a.at(i + 1) - a.at(i));
    }
    ans = x;
    for (int i = 2; i < k; i += 2) {
        x -= (a.at(i) - a.at(i - 1));
        x += (a.at(i - 1) - a.at(i - 2));
        chmin(ans, x);
    }
    cout << ans << "\n";
    return 0;
}