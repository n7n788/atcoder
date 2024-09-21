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
    int n, k;
    cin >> n >> k;
    vector<double> l(n);
    rep(i, 0, n) cin >> l.at(i);

    auto ok = [&](double x, int k) -> bool {
        int sum = 0;
        rep(i, 0, n) {
            sum += (int) (l.at(i) / x);
            if (sum >= k) return true;
        }
        return false;
    };

    auto lower_bound = [&](int k) -> double {
        double ac = 0, ng = 1e5 + 1;
        while (ng - ac > 0.01) {
            double mid = ac + (ng - ac) / 2.0;
            if (ok(mid, k)) ac = mid;
            else ng = mid;
        }
        return ac;
    };

    double x = lower_bound(k);
    printf("%.2f\n", x);
    return 0;
}