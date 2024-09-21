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
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x.at(i) >> y.at(i);

    dsu uf(n);
    rep(i, 0, n - 1) rep(j, i + 1, n) {
        int dx = x.at(i) - x.at(j);
        int dy = y.at(i) - y.at(j);
        int dist = dx * dx + dy * dy;
        // cout << i << ", " << j << ' ' << dist << endl;
        if (dist <= d * d) uf.merge(i, j);
    }

    rep(i, 0, n) {
        if (uf.same(i, 0)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}