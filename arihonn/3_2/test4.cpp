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
    vector<int> dir(n);
    rep(i, 0, n) {
        if (s.at(i) == 'B') dir.at(i) = 1;
        else dir.at(i) = 0;
    }

    rep(i, 0, n) cout << dir.at(i);
    cout << "\n";

    // 区間[i, i + k - 1]を反転したか?
    vector<int> f(n);
    auto calc = [&](int k) -> int {
        int ans = 0, sum = 0;
        rep(i, 0, n) f.at(i) = 0;
        for (int i = 0; i + k <= n; i++) {
            if ((dir.at(i) + sum) % 2 == 1) {
                f.at(i) = 1;
                ans++;
            }
            sum += f.at(i);
            if (i - k + 1 >= 0) sum -= f.at(i - k + 1);
        }
        // rep(i, 0, n) cout << f.at(i);
        // cout << "\n";

        for (int i = n - k + 1; i < n; i++) {
            if ((dir.at(i) + sum) % 2 == 1) return -1;
            if (i - k + 1 >= 0) sum -= f.at(i - k + 1);
        }
        return ans;
    };

    int K = 1, M = n;
    erep(k, 1, n) {
        int m = calc(k);
        if (m != -1 && m < M) {
            M = m;
            K = k;
        }
    }

    cout << K << "\n";
    cout << M << "\n";
    return 0;
}