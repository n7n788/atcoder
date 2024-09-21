//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
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
    int n, m, k;
    cin >> n >> m >> k;
    vector edge(n, vector<int>());
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge.at(a).emplace_back(b);
        edge.at(b).emplace_back(a);
    }
    vector h(n, -1);
    priority_queue<P> pq;
    rep(i, 0, k) {
        int h1, p;
        cin >> p >> h1;
        p--;
        h.at(p) = h1;
        pq.push({h1, p});
    }

    while (!pq.empty()) {
        auto [h1, v] = pq.top(); pq.pop();
        // cout << "v:" << v + 1<< ", h:" << h1 << '\n';
        if (h1 < h.at(v)) continue;
        for (auto u: edge.at(v)) {
            if (h1 - 1 > h.at(u)) {
                pq.push({h1 - 1, u});
                h.at(u) = h1 - 1;
            }
        }
    }

    int cnt = 0;
    rep(i, 0, n) {
        if (h.at(i) >= 0) cnt++;
    }
    cout << cnt << '\n';

    rep(i, 0, n) {
        if (h.at(i) >= 0) cout << i + 1 << ' ';
    }
    cout << endl;

    return 0;
}