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
    vector<ll> a(n);
    vector<ll> s(n - 1), t(n - 1);
    rep(i, 0, n) cin >> a.at(i);
    rep(i, 0, n - 1) cin >> s.at(i) >> t.at(i);

    rep(i, 0, n - 1) {
        ll c = a.at(i) / s.at(i);
        a.at(i + 1) += t.at(i) * c;
    }
    cout << a.at(n - 1) << "\n";
    return 0;
}