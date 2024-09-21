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
    int n;
    cin >> n;
    string s;
    cin >> s;

    mint ans = 0;
    vector<mint> b(n + 1); // 約数mでの個数
    vector ds(n + 1, vector<int>());
    rep(m, 1, n) {
        if (n % m) continue;
        mint a = 1;
        rep(i, 0, m) {
            int x = 2;
            // i番目をmおきに見て、一つでも欠勤があれば、倍にしない
            for (int j = i; j < n; j += m) if (s.at(j) == '.') x = 1;
            a *= x;
        }

        // mの約数における個数を引く
        for (int d: ds[m]) a -= b.at(d);
        b.at(m) = a;
        ans += b.at(m);
        
        // 約数を予め求めておく
        // mの倍数の約数リストにmを追加
        for (int i = m * 2; i < n; i += m) ds.at(i).push_back(m);
    }
    cout << ans.val() << endl;
    return 0;
}