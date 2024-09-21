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


using Board = vector<string>;

int main()
{
    int n, h, w;
    cin >> n >> h >> w;
    vector<P> ab(n);
    rep(i, 0, n) cin >> ab.at(i).first >> ab.at(i).second;

    // 引数に今の状態を入れる
    // 引数: Board: 盤面の状態, used: 何を使ったか, 
    auto dfs = [&](auto dfs, Board s, vector<int> used) -> bool {
        // 次の一手を求める
        // 左上の空きマスを求める
        int si = -1, sj = -1;
        rep(i, 0, h) rep(j, 0, w) {
            if (s.at(i).at(j) == '.' && si == -1) {
                si = i;
                sj = j;
            }
        }

        // 終了条件: 全マス埋まったら終了
        if (si == -1) {
            cout << "Yes" << endl;
            rep(i, 0, h) cerr << s.at(i) << endl; // 標準エラーに盤面を出力
            return true;
        }

        // nパターンに分岐: 使っていないパネルを選択
        rep(ri, 0, n) {
            if (used.at(ri)) continue;
            auto [a, b] = ab.at(ri);
            // 2パターンに分岐：縦または横に配置
            rep(bi, 0, 2) {
                swap(a, b);

                // 配列外参照したらダメ
                if (si + a > h || sj + b > w) continue;

                // 配置を決める
                vector<int> nused = used;
                Board ns = s;
                bool ok = true;
                rep(i, 0, a) rep(j, 0, b) {
                    // すでに配置されていたらダメ
                    if (ns.at(si + i).at(sj + j) != '.') ok = false;
                    ns.at(si + i).at(sj + j) = '1' + ri; 
                }
                if (!ok) continue;
                nused.at(ri) = 1;

                if (dfs(dfs, ns, nused)) return true;
            }
        }
        return false;
    };

    if (!dfs(dfs, Board(h, string(w, '.')), vector<int>(n, 0))) {
        cout << "No" << endl;
    }
    return 0;
}