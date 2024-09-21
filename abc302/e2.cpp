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
    int n, q;
    cin >> n >> q;
    int cnt = n;

    vector<unordered_set<int>> to(n);
    rep(qi, 0, q) {
        int type, u, v;
        cin >> type;
        switch (type)
        {
        case 1:
            cin >> u >> v;
            u--; v--;
            if (to[u].empty()) cnt--;
            to[u].insert(v);
            if (to[v].empty()) cnt--;
            to[v].insert(u);
            break;
        case 2:
            cin >> u;
            u--;
            if (!to[u].empty()) {
                for (auto v: to[u]) {
                    to[v].erase(u);
                    if (to[v].empty()) cnt++;
                }
                to[u] = unordered_set<int>();
                cnt++;
                break;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}