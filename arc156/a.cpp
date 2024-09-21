// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <atcoder/all>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef pair<int, int> P;

void solve() 
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i, 0, n) cin >> c.at(i);
    vector to(n, vector<int>());
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to.at(a).push_back(b);
        to.at(b).push_back(a);
    }

    const int INF = 1001001001;
    vector d(n, vector<int>(n, INF));
    queue<P> que;
    d.at(0).at(n - 1) = 0;
    que.emplace(0, n - 1);
    while (!que.empty()) {
        auto [a, b] = que.front(); que.pop();
        for (auto na: to.at(a)) {
            for (auto nb: to.at(b)) {
                if (c.at(na) == c.at(nb)) continue;
                if (d.at(na).at(nb) != INF) continue;
                que.emplace(na, nb);
                d.at(na).at(nb) = d.at(a).at(b) + 1; 
            }
        }
    }

    if (d.at(n - 1).at(0) != INF) cout << d.at(n - 1).at(0) << '\n';
    else cout << -1 << '\n';
}

int main() {
  int t;
  cin >> t;
  rep(i, 0, t) solve();
  return 0;
}