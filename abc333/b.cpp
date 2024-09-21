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
    string s, t;
    cin >> s >> t;
    int x, y;
    x = min(abs(s.at(0) - s.at(1)), 5 - abs(s.at(0) - s.at(1)));
    y = min(abs(t.at(0) - t.at(1)), 5 - abs(t.at(0) - t.at(1)));
    if (x == y) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}