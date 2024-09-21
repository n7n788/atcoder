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
    int k, g, m;
    cin >> k >> g >> m;
    vector<int> w(2, 0);
    rep(i, 0, k) {
        if (w.at(0) == g) w.at(0) = 0;
        else if (w.at(1) == 0) w.at(1) = m;
        else {
            int tmpw = min(w.at(1), g - w.at(0));
            w.at(0) += tmpw;
            w.at(1) -= tmpw;
        }
    }
    cout << w.at(0) << " " << w.at(1) << "\n";
    return 0;
}