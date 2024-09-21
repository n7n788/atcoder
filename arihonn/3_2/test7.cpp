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
    int n, h, r, t;
    cin >> n >> h >> r >> t;

    const double g = 10.0;
    auto calc = [&](int t) -> double {
        if (t < 0) return (double) h;
        double T = sqrt(2 * h / g);
        int k = (int) t / T;
        cout << t << ", " << T << ", " << k << "\n";
        if (k % 2 == 0) {
            double d = t - k * T;
            cout << "d = " << d << "\n";
            return h - g * d * d / 2;
        } else {
            double d = (k + 1) * T - t;
            return h - g * d * d / 2;
        }
    };

    vector<double> y(n);
    rep(i, 0, n) {
        y.at(i) = calc(t - i);
    }
    sort(y.begin(), y.end());
    rep(i, 0, n) y.at(i) += (double) 2 * r * i / 100.0;
    rep(i, 0, n) cout << y.at(i) << ' ';
    cout << endl;
    return 0;
}
