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

vector dp(16, vector<vector<vector<ll>>>(2, vector<vector<ll>>(130, vector<ll>(130, 0))));

int main()
{
    ll n;
    cin >> n;
    vector<int> digits;
    ll ans = 0;
    int m;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    m = digits.size();

    erep(k, 1, 126) {
        // 初期化
        erep(i, 0, m)erep(j, 0, 1)erep(s, 0, k)erep(r, 0, k - 1) 
            dp.at(i).at(j).at(s).at(r) = 0;
        dp.at(0).at(0).at(0).at(0) = 1;
        // 桁dpを実行
        rep(i, 0, m)erep(j, 0, 1)erep(s, 0, k)erep(r, 0, k - 1) {
            rep(d, 0, 10) {
                // 次の寄与先を計算
                int ni = i + 1;
                int nj = j;
                int ns = s + d;
                int nr = ((r * 10) + d) % k;
                if (j == 0) {
                    if (d > digits.at(i)) continue;
                    else if (d < digits.at(i)) nj = 1;
                }
                if (ns > k) continue;
                // 寄与先に足す
                dp.at(ni).at(nj).at(ns).at(nr) += dp.at(i).at(j).at(s).at(r);
            }
        }
        ans += (dp.at(m).at(0).at(k).at(0) + dp.at(m).at(1).at(k).at(0));
    }
    cout << ans << "\n";
    return 0;
}