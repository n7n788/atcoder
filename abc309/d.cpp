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
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector edge(n1 + n2, vector<int>());
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge.at(a).push_back(b);
        edge.at(b).push_back(a);
    }

    vector<int> dist(n1 + n2, INF);
    auto bfs = [&](int s) {
        // cout << "bfs" << s << endl; 
        queue<int> que;
        dist.at(s) = 0;
        que.push(s);
        while (!que.empty()) {
            int v =  que.front(); que.pop();
            // cout << v << endl;
            for (int nv: edge.at(v)) {
                int nv1 = nv;
                if (dist.at(nv1) != INF) continue;
                que.push(nv1);
                dist.at(nv1) = dist.at(v) + 1;
            }
        }
    };

    bfs(0);
    bfs(n1 + n2 - 1);

    int max1 = 0, max2 = 0;
    // rep(i, 0, n1) cout << dist.at(i) << ' ';
    // rep(i, n1, n1 + n2) cout << dist.at(i) << ' ';
    rep(i, 0, n1) chmax(max1, dist.at(i));
    rep(i, n1, n1 + n2) chmax(max2, dist.at(i));
    cout << max1 + max2 + 1 << endl;
    return 0;
}