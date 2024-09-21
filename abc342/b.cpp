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
    int n, q;
    cin >> n;
    vector<int> p(n);
    rep(i, 0, n) cin >> p.at(i);
    cin >> q;
    rep(qi, 0, q) {
        int a, b;
        cin >> a >> b;
        int ai, bi;
        rep(i, 0, n) {
            if (p.at(i) == a) ai = i;
            if (p.at(i) == b) bi = i;
        }
        if (ai < bi) cout << a << "\n";
        else cout << b << "\n";
    }
    return 0;
}