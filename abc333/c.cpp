#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
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
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef pair<int, int> P;
typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> a = {1};
    int m = 12;
    int cnt = 0;
    rep(i, 0, m - 1) a.push_back(a.back() * 10 + 1);
    rep(i, 0, m) rep(j, 0, i + 1) rep(k, 0, j + 1) {
        cnt++;
        if (cnt == n) cout << a.at(i) + a.at(j) + a.at(k) << "\n";
    }
    return 0;
}