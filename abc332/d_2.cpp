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
    int h, w;
    cin >> h >> w;
    vector a(h, vector<int>(w));
    vector b(h, vector<int>(w));
    using index = vector<vector<int>>; 
    map<index, int> distances;
    rep(i, 0, h) rep(j, 0, w) cin >> a.at(i).at(j);
    rep(i, 0, h) rep(j, 0, w) cin >> b.at(i).at(j);
    auto bfs = [&](map<index, int>& distances, const index startIndex, const index goalIndex) -> int {
        queue<index> q;
        distances[startIndex] = 0;
        q.emplace(startIndex);
        while (!q.empty()) {
            index from = q.front();
            q.pop();
            bool ok = true;
            rep(i, 0, h) rep(j, 0, w) 
                if (from.at(i).at(j) != goalIndex.at(i).at(j))
                    ok = false;
            if (ok) return distances[from];
            // 遷移
            rep(i, 0, h - 1) {
                index to = from;
                // ベクトルのスワップ
                swap(to.at(i), to.at(i + 1));
                if (distances.find(to) != distances.end()) continue;
                distances[to] = distances[from] + 1;
                q.emplace(to);
            }
            rep(i, 0, w - 1) {
                index to = from;
                rep(j, 0, h) swap(to.at(j).at(i), to.at(j).at(i + 1));
                if (distances.find(to) != distances.end()) continue;
                distances[to] = distances[from] + 1;
                q.emplace(to);
            }
        }
        return -1;
    };

    cout << bfs(distances, a, b) << "\n";
    return 0;
}