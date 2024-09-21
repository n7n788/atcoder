#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef pair<int, int> P;
typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s.at(i);

    // 各単語同士のハミング距離を求める
    vector d(n, vector<int>(n, 0));
    rep(i, 0, n) rep(j, 0, n) {
        rep(k, 0, m) {
            if (s.at(i).at(k) != s.at(j).at(k)) d.at(i).at(j)++;
        }
    }

    // DFSでn!探索する
    // 深さがdepth, 訪問済みの頂点がvisitedで次に頂点vへ移動した時、残る全ての頂点を距離1の辺を用いて渡れるか？
    auto dfs = [&](int v, int depth, vector<bool> visited, auto dfs) -> bool {
        if (v != -1) visited.at(v) = true;
        if (v != -1) depth += 1;
        if (depth == n) return true;
        bool ok = false;
        rep(i, 0, n) {
            if (visited.at(i)) continue;
            if (v != -1 && d.at(v).at(i) != 1) continue;
            ok |= dfs(i, depth, visited, dfs);
        }
        return ok;
    };

    vector<bool> visited(n, false);
    if (dfs(-1, 0, visited, dfs)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}