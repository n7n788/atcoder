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
    ll d;
    cin >> d;
    ll ans = INF_ll;
    auto calc = [&](ll x, ll y) {
        return abs(d - x * x - y * y);
    };
    for (ll x = 0; x * x <= d; x++) {
        ll y0 = sqrt(d - x * x);
        ll y1 = y0 + 1;
        chmin(ans, calc(x, y0));
        chmin(ans, calc(x, y1));
    }
    cout << ans << "\n";
    return 0;
}