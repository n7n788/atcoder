// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
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
typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, 0, n) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);

    vector field(100, vector<bool>(100, false));
    rep(i, 0, n) {
        rep(x, a.at(i), b.at(i)) rep(y, c.at(i), d.at(i)) {
            field.at(x).at(y) = true;
        }
    }

    int ans = 0;
    rep(i, 0, 100)rep(j, 0, 100) {
        if (field.at(i).at(j)) ans++;
    }
    cout << ans << endl;
    return 0;
}