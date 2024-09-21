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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c.at(i);

    auto getSum = [&](vector<ll>& a0, vector<ll>& a1, vector<ll> c)
    {
        rep(i, 0, n) {
            a0.at(i + 1) = a1.at(i);
            a1.at(i + 1) = a0.at(i);
            if (s.at(i) == '1') a0.at(i + 1) += c.at(i);
            if (s.at(i) == '0') a1.at(i + 1) += c.at(i);
        }
    };
    // a0[i + 1] := s[0, i]を...01010にするのに必要なコスト
    // a1[i + 1] := s[0, i]を...10101にするのに必要なコスト
    // b0[i] := s[i, n-1]を0101...にするのに必要なコスト
    // b1[i] := s[i, n-1]を1010...にするのに必要なコスト
    vector<ll> a0(n + 1, 0), a1(n + 1, 0);
    vector<ll> b0(n + 1, 0), b1(n + 1, 0);
    getSum(a0, a1, c);
    reverse(s.begin(), s.end());
    reverse(c.begin(), c.end());
    getSum(b0, b1, c);

    ll ans = INF_ll;
    rep(i, 0, n - 1) {
        // s[i, i + 1]を00にする場合
        {
            ll cost = a0.at(i + 1) + b0.at(n - i - 1);
            chmin(ans, cost);
        }
        // s[i, i + 1]を11にする場合
        {
            ll cost = a1.at(i + 1) + b1.at(n - i - 1);
            chmin(ans, cost);
        }
    }

    cout << ans << endl;
    return 0;
}