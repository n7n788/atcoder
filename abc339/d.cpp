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
    vector<string> s(n);
    vector distances(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INF))));
    vector<P> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<P> startPos;
    rep(i, 0, n) cin >> s.at(i);
    rep(i, 0, n) rep(j, 0, n) {
        if (s.at(i).at(j) == 'P') startPos.emplace_back(i, j);
    }

    auto bfs = [&]() -> void {
        struct Pos2 {
            int x1, y1, x2, y2;
        };
        queue<Pos2> q;
        int x1 = startPos.at(0).first;
        int y1 = startPos.at(0).second;
        int x2 = startPos.at(1).first;
        int y2 = startPos.at(1).second;
        distances.at(x1).at(y1).at(x2).at(y2) = 0;
        q.emplace(Pos2{x1, y1, x2, y2});
        while (!q.empty()) {
            int x1 = q.front().x1;
            int y1 = q.front().y1;
            int x2 = q.front().x2;
            int y2 = q.front().y2;
            if (x1 == x2 && y1 == y2) {
                cout << distances.at(x1).at(y2).at(x2).at(y2) << "\n";
                return;
            }
            q.pop();
            rep (i, 0, delta.size()) {
                int nx1 = x1 + delta.at(i).first;
                int ny1 = y1 + delta.at(i).second;
                int nx2 = x2 + delta.at(i).first;
                int ny2 = y2 + delta.at(i).second;
                if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n || s.at(nx1).at(ny1) == '#') {
                    nx1 = x1;
                    ny1 = y1;
                }
                if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n || s.at(nx2).at(ny2) == '#') {
                    nx2 = x2;
                    ny2 = y2;
                }
                if (distances.at(nx1).at(ny1).at(nx2).at(ny2) != INF) continue;
                distances.at(nx1).at(ny1).at(nx2).at(ny2) = distances.at(x1).at(y1).at(x2).at(y2) + 1;
                q.emplace(Pos2{nx1, ny1, nx2, ny2});
            }
        }

        cout << -1 << "\n";
        return;
    };

    bfs();
    return 0;
}