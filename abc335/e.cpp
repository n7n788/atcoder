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
#include <stack>

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
    vector<int> a(n);
    vector<vector<int>> edge(n);
    vector<int> cnts(n, 0);
    struct P {
            int num;
            int cnt;
            int from;
    };
    // priority_queueではsortの場合とは逆に指定する
    // swapする条件を書く
    // 第一引数 > 第二引数がtrueのとき昇順、逆なら降順
    auto compare = [](P lp, P rp) -> bool {
        // 昇順
        if (lp.num != rp.num) return lp.num > rp.num;
        else return lp.cnt < rp.cnt;
    };
    rep(i, 0, n) cin >> a.at(i);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (a.at(u) >= a.at(v)) edge[v].push_back(u);
        if (a.at(u) <= a.at(v)) edge[u].push_back(v);
    }
    auto dijkstra = [&]() -> void {
        priority_queue<P, vector<P>, decltype(compare)> q;
        q.emplace(P{a.at(0), (cnts.at(0) = 1), 0});
        while (!q.empty()) {
            int num = q.top().num;
            int cnt = q.top().cnt;
            int from = q.top().from;
            q.pop();
            // 最新情報かどうかをチェック
            if (cnt < cnts.at(from)) continue;
            for (auto to: edge.at(from)) {
                int ncnt = cnt;
                if (a.at(from) != a.at(to)) ncnt++;
                // 情報を更新すべきかチェック
                if (ncnt > cnts.at(to)) {
                    cnts.at(to) = ncnt; // 情報を更新
                    q.emplace(P{a.at(to), ncnt, to}); // 候補を追加
                }
            }
        }
    };

    dijkstra();
    cout << cnts.at(n - 1) << "\n";
    return 0;
}