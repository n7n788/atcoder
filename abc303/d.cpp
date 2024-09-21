//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
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
    ll x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int n = s.size();

    // メモ化再帰
    vector dp(n, vector<ll>(2, INF_ll));
    vector mem(n, vector<bool>(2, false)); 
    // 文字列iまで見て、capsLocがcの時に、これからかかる時間の最小値
    auto dfs = [&](int i, int c, auto f) -> ll {
        if (i == n) return 0;
        if (mem.at(i).at(c)) return dp.at(i).at(c);

        ll res = INF_ll;
        int a = s[i] == 'A'? 1:0;
        int cost1 = (a == c) ? x : y; //capsを押さない場合のコスト
        int cost2 = ((a == c) ? y : x) + z; //capsを押す場合のコスト
        res = cost1 + f(i + 1, c, f);
        chmin(res, cost2 + f(i + 1, !c, f));

        mem[i][c] = true;
        return dp[i][c] = res;
    };

    cout << dfs(0, 0, dfs) << endl;
    return 0;
}