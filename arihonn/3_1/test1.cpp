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
    int n, k;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a.at(i);
    cin >> k;

    auto ok = [&](int i) -> bool {
        return a.at(i) >= k;
    };

    auto lower_bound = [&]() -> int{
        int ac = n, ng = -1;
        while (ac - ng > 1) {
            int mid = ng + (ac - ng) / 2;
            if (ok(mid)) ac = mid;
            else ng = mid;
        }
        return ac;
    };

    cout << lower_bound() << "\n";
    return 0;
}
