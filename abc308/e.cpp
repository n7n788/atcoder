//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
#include <set>
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
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    string s;
    cin >> s;

    vector<ll> m(3, 0);
    vector<vector<ll>> me(3, vector<ll>(3, 0));
    vector<vector<vector<ll>>> mex(3, vector<vector<ll>>(3, vector<ll>(3, 0)));
    rep(i, 0, n) {
        if (s.at(i) == 'M') m.at(a.at(i))++;
        else if (s.at(i) == 'E') {
            rep(j, 0, 3) {
                me.at(j).at(a.at(i)) += m.at(j);
            }
        } else if (s.at(i) == 'X') {
            rep(j, 0, 3) rep(k, 0, 3) {
                mex.at(j).at(k).at(a.at(i)) += me.at(j).at(k);
            }
        }
    }

    auto getMex = [&](int x, int y, int z) -> int{
        vector<bool> exist(4, false);
        exist.at(x) = true;
        exist.at(y) = true;
        exist.at(z) = true;
        rep(i, 0, 4) if (!exist.at(i)) return i;
        return 3;
    };

    ll ans = 0;
    rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) {
        ans += (ll) getMex(i, j, k) * mex.at(i).at(j).at(k);
    }
    cout << ans << endl;
    return 0;
}