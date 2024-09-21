//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <map>
#include <set>

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
    map<int, set<int>> mp;

    rep(qi, 0, q) {
        int qnum, u, v;
        cin >> qnum;
        switch (qnum)
        {
        case 1:
            cin >> u >> v;
            mp[u].insert(v);
            mp[v].insert(u);
            break;
        case 2:
            cin >> v;
            // 頂点vの隣接リストにある各頂点について、その隣接リストからvを消去
            for (auto it = mp[v].begin(); it != mp[v].end(); it++) {
                mp[*it].erase(v);
                // 隣接リストが空になったらマップからその頂点キーを消去
                if (mp[*it].size() == 0) mp.erase(*it);
            }
            // マップから頂点vのキーを削除
            mp.erase(v);
            break;
        }

        cout << n - mp.size() << endl;
    }
    return 0;
}