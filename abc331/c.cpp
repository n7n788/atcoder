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
    int n;
    cin >> n;
    vector<ll> a(n), b(n), s(n + 1, 0);
    rep(i, 0, n) cin >> a.at(i);
    rep(i, 0, n) b.at(i) = a.at(i);
    sort(b.begin(), b.end());
    rep(i, 0, n) s.at(i + 1) = s.at(i) + b.at(i);
    for (ll x: a) {
        int i = upper_bound(b.begin(), b.end(), x) - b.begin();
        ll ans = s.at(n) - s.at(i);
        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}