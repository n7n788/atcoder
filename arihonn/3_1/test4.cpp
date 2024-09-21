//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "atcoder/all"
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cstdlib>

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
    vector<int> w(n), v(n);
    rep(i, 0, n) cin >> w.at(i) >> v.at(i);

    auto ok = [&](double x) -> bool { 
        vector<double> a(n);
        double sum = 0;
        rep(i, 0, n) a.at(i) = v.at(i) - x * w.at(i);
        sort(a.rbegin(), a.rend());
        rep(i, 0, k) sum +=  a.at(i);
        return sum >= 0.0;
    };

    auto lower_bound = [&]() -> double {
        double ac = 0, ng = 1e6 + 1;
        rep(i, 0, 100) {
            cout << ac << ", " << ng << "\n";
            double mid = ac + (ng - ac) / 2.0;
            if (ok(mid)) ac = mid;
            else ng = mid;
        }
        return ac;
    };

    double x = lower_bound();
    printf("%.6f\n", x);
    return 0;
}