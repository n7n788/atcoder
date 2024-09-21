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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s.at(i);

    vector visited(h, vector<bool>(w, false));
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    string t = "snuke";
    auto dfs = [&](int i, int j, int cnt, auto dfs) -> void{
        visited.at(i).at(j) = true;
        rep(k, 0, 4) {
            int ni = i + dx.at(k), nj = j + dy.at(k);
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (visited.at(ni).at(nj)) continue;
            if (t.at((cnt + 1)% 5) != s.at(ni).at(nj)) continue;
            dfs(ni, nj, (cnt + 1) % 5, dfs);
        }
    };
    if (s.at(0).at(0) == 's') dfs(0, 0, 0, dfs);
    if (visited.at(h - 1).at(w - 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}