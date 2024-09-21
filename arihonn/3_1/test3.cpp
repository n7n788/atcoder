// #include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>
#include <set>
#include <map>
#include <atcoder/all>
#include <unordered_map>
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
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    rep(i, 0, n) cin >> x.at(i);

    sort(x.begin(), x.end());

    auto ok = [&](int w) -> bool {
        int prv_i = 0;
        int ans = 1;
        rep(i, 1, n) {
            if (x.at(i) - x.at(prv_i) >= w) {
                ans++;
                prv_i = i;
            }
        }
        return ans >= m;
    };

    auto lower_bound = [&]() -> int {
        int ac = 0, ng = 1e9;
        while (ng - ac > 1) {
            int mid = ac + (ng - ac) / 2;
            if (ok(mid)) ac = mid;
            else ng = mid; 
        }
        return ac;
    };

    cout << lower_bound() << "\n";
    return 0;
}