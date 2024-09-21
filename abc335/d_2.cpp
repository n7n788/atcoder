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
    int n;
    int m, cnt;
    cin >> n;
    vector g(n, vector<int>(n, 0));
    m = (n - 1) / 2;
    cnt = 0;
    rep(k, 0, m) {
        rep(i, k, n - k) g.at(k).at(i) = ++cnt;
        rep(i, k + 1, n - k) g.at(i).at(n - k - 1) = ++cnt;
        rep(i, k + 1, n - k) g.at(n - k - 1).at(n - i - 1) = ++cnt;
        rep(i, k + 1, n - k - 1) g.at(n - i - 1).at(k) = ++cnt;
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == m && j == m) cout << "T ";
            else cout << g.at(i).at(j) << ' ';
        }
        cout << "\n";
    }
    return 0;
}