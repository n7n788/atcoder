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
#include <regex>

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

using Board = vector<vector<int>>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    rep(i, 0, n) rep(j, 0, m) cin >> a.at(i).at(j);

    vector<int> di = {0, 1, 0, -1, 0};
    vector<int> dj = {0, 0, 1, 0, -1};

    auto update = [&](int i, int j, Board& b) -> void {
        rep(k, 0, 5) {
            int ni = i + di.at(k);
            int nj = j + dj.at(k);
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            b.at(ni).at(nj)++;
        }
    };

    auto solve = [&](int row, Board& ans_board) -> int{
        Board b = a;
        int ans = 0;
        rep(j, 0, m) {
            if ((row >> j) & 1) {
                update(0, j, b);
                ans_board.at(0).at(j) = 1;
                ans++;
            }
        }

        rep(i, 1, n) rep(j, 0, m) {
            if ((b.at(i - 1).at(j)) % 2) {
                update(i, j, b);
                ans_board.at(i).at(j) = 1;
                ans++;
            }
        }

        bool ok = true;
        rep(i, 0, n) rep(j, 0, m) {
            if ((b.at(i).at(j)) % 2) ok = false;
        }

        if (ok) return ans;
        else return -1;
    };

    int max_row = 1 << m;
    int ans = INF;
    Board ans_board;
    rep(row, 0, max_row) {
        vector b(n, vector<int>(m, 0));
        int cnt = solve(row, b);
        if (cnt != -1) {
            if (cnt < ans) {
                ans = cnt;
                ans_board = b;
            }
        }
    }

    if (ans != INF) {
        rep(i, 0, n) {
            rep(j, 0, m) cout << ans_board.at(i).at(j) << ' ';
            cout << "\n";
        }
    }
    else cout << "IMPOSSIBLE\n";

    return 0;
}