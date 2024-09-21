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
    int h, w, n;
    cin >> h >> w >> n;
    vector masu(h, vector<char>(w, '.'));
    vector<P> ds = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int d, x, y;
    d = 0;
    x = 0;
    y = 0;
    rep(i, 0, n) {
        if (masu.at(x).at(y) == '.') {
            masu.at(x).at(y) = '#';
            d = (d + 1) % ds.size();
        } else {
            masu.at(x).at(y) = '.';
            d = (d - 1 + ds.size()) % ds.size();
        }
        x = (x + ds.at(d).first + h) % h;
        y = (y + ds.at(d).second + w) % w;
    }

    rep(i, 0, h) {
        rep(j, 0, w) cout << masu.at(i).at(j);
        cout << "\n";
    }
    return 0;
}