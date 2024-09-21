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
// typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<bool> used(n);
    queue<int> q;
    // 場所[i:i+m-1]がtからワイルドカードに変換できるか判定し、キューに格納
    auto push = [&](int i) {
        if (i < 0 || i + m > n) return;
        if (used.at(i)) return;
        rep(j, 0, m) {
            if (s.at(i + j) != '?' && s.at(i + j) != t.at(j))
                return;
        }
        used.at(i) = true;
        q.push(i);
    };
    // 初期化
    rep(i, 0, n - m + 1) push(i);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        rep(j, 0, m) s.at(i + j) = '?';
        erep(ni, i - m + 1, i + m - 1) {
            push(ni);
        }
    }
    if (s == string(n, '?')) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}