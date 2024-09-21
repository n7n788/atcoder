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
    int max_x = INF;
    int res = 0;
    vector<int> q(n), a(n), b(n);
    rep(i, 0, n) cin >>  q.at(i);
    rep(i, 0, n) cin >> a.at(i);
    rep(i, 0, n) cin >> b.at(i);

    rep(i, 0, n) {
        if (a.at(i) != 0) chmin(max_x, q.at(i) / a.at(i));
    }
    erep(x, 0, max_x) {
        int max_y = INF;
        rep(i, 0, n) {
            if (b.at(i) != 0) chmin(max_y, (q.at(i) - a.at(i) * x) / b.at(i)); 
        }
        chmax(res, x + max_y);
    }

    cout << res << "\n";
}