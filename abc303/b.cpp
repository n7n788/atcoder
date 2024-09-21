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
    int n, m;
    cin >> n >> m;
    vector a(m, vector<int>(n));
    rep(i, 0, m) rep(j, 0, n) {
        cin >> a.at(i).at(j);
        a.at(i).at(j)--;
    }

    vector dis(n, vector<bool>(n, true));
    rep(i, 0, n) dis.at(i).at(i) = false;
    rep(i, 0, m) {
        rep(j, 0, n - 1) {
            dis.at(a.at(i).at(j)).at(a.at(i).at(j + 1)) = false;
            dis.at(a.at(i).at(j + 1)).at(a.at(i).at(j)) = false;
        }
    }

    int cnt = 0;
    rep(i, 0, n) rep(j, 0, n) if (dis.at(i).at(j)) cnt++;

    cout << cnt / 2 << endl;
    return 0;
}