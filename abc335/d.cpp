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
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, -1));
    int num = 1;
    int i = 0, j = 0;
    // 上下左右の操作を共通化
    // 数を書く＋移動をする関数
    auto f = [&](int di, int dj) {
        ans.at(i).at(j) = num;
        i += di;
        j += dj;
    };
    for (int l = n - 1; l > 0; l--) {
        rep(k, 0, l) f(0, 1);
        rep(k, 0, l) f(1, 0);
        rep(k, 0, l) f(0, -1);
        rep(k, 0, l - 1) f(-1, 0);
        f(0, 1);
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (ans.at(i).at(j) == -1) cout << 'T';
            else cout << ans.at(i).at(j);
            cout << ' ';
        }
        cout << "\n";
    }
    return 0;
}