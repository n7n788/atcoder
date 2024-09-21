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
    vector<int> s(k + 1, 0);
    int ans;
    rep(i, 0, k) cin >> a.at(i);
    if (k % 2 == 0) {
        ans = 0;
        for (int i = 0; i < k - 1; i += 2) {
            ans += (a.at(i + 1) - a.at(i));
        }
        cout << ans << "\n";
        return 0;
    }
    rep(i, 1, k) {
        if (i % 2 == 1) {
            if (i - 2 >= 0) s.at(i) = s.at(i - 2);
            s.at(i) += a.at(i) - a.at(i - 1);
        } else {
            if (i - 2 >= 0) s.at(i) = s.at(i - 2);
            s.at(i) += a.at(i) - a.at(i - 1);
        }
    }
    ans = INF;
    for (int i = 0; i < k; i += 2) {
        if (i == 0) chmin(ans, s.at(k - 1));
        else chmin(ans, s.at(i - 1) + s.at(k - 1) - s.at(i));
    }
    cout << ans << "\n";
    return 0;
}