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
    vector<string> a(n);
    rep(i, 0, n) {
        cin >> a.at(i);
    }
    vector b(n, vector<char>(n, '0'));
    rep(i, 0, n) rep(j, 0, n) {
        if (i == 0 && j != n - 1) b.at(0).at(j + 1) = a.at(0).at(j);
        else if (j == n - 1 && i != n - 1) b.at(i + 1).at(n - 1) = a.at(i).at(n - 1);
        else if (i == n - 1 && j != 0) b.at(n - 1).at(j - 1) = a.at(n - 1).at(j);
        else if (j == 0 && i != 0) b.at(i - 1).at(0) = a.at(i).at(0);
        else b.at(i).at(j) = a.at(i).at(j);
    }

    rep(i, 0, n) {
        rep(j, 0, n) cout << b.at(i).at(j);
        cout << endl;
    }
    return 0;
}