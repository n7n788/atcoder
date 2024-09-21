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
    int n, m, l;
    cin >> n >> m >> l;
    vector<P> a(n), b(m);
    set<P> bad;
    rep(i, 0, n) {
        cin >> a.at(i).first;
        a.at(i).second = i;
    }
    rep(i, 0, m) {
        cin >> b.at(i).first;
        b.at(i).second = i;
    }
    rep(i, 0, l) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        bad.insert({c, d});
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    struct S {
        int sum;
        int i;
        int j;
        int pi;
        int pj;
    };
    auto compare = [](S ls, S rs) -> bool {
        return ls.sum < rs.sum;
    };
    priority_queue<S, vector<S>, decltype(compare)> q;
    set<P> visited;
    int i = 0, j = 0;
    int pi = a.at(0).second, pj = b.at(0).second;
    int s = a.at(0).first + b.at(0).first;
    q.push(S{s, i, j, pi, pj});
    visited.insert({i, j});
    while (!q.empty()) {
        int s = q.top().sum;
        int i = q.top().i;
        int j = q.top().j;
        int pi = q.top().pi;
        int pj = q.top().pj;
        // cout << i << ", " << j << "\n";
        q.pop();
        if (bad.find({pi, pj}) == bad.end()) {
            cout << s << "\n";
            return 0;
        }
        if (i != n - 1 && 
            visited.find({i + 1, j}) == visited.end()) {
            int s = a.at(i + 1).first + b.at(j).first;
            int pi = a.at(i + 1).second;
            int pj = b.at(j).second;
            // cout << s << " " << pi << " " << pj << "\n";
            q.push(S{s, i + 1, j, pi, pj});
            visited.insert({i + 1, j});
        }
        if (j != m - 1 && 
            visited.find({i, j + 1}) == visited.end()) {
            int s = a.at(i).first + b.at(j + 1).first;
            int pi = a.at(i).second;
            int pj = b.at(j + 1).second;
            // cout << s << " " << pi << " " << pj << "\n";
            q.push(S{s, i, j + 1, pi, pj});
            visited.insert({i, j + 1});
        }
    }
    return 0;
}
