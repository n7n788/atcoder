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
    int n;
    int s, m, l;
    int ans = INF;
    cin >> n >> s >> m >> l;
    // n / r の切り上げを返す
    auto up = [&](int n, int r) {return (n + r - 1) / r;};
    int maxi = up(n, 6);
    erep(i, 0, maxi) {
        int rem1 = n - 6 * i;
        int maxj = up(rem1, 8);
        erep(j, 0, maxj) {
            int rem2 = rem1 - 8 * j;
            int k = up(rem2, 12);
            int sum = s * i + m * j + l * k;
            chmin(ans, sum);
        }
    }
    cout << ans << "\n";
    return 0;
}