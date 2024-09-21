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

const int delta = 10;

int main()
{
    ll n;
    cin >> n;
    unordered_map<ll, ll> memo;
    auto f = [&](ll x, auto f) -> ll {
        if (memo.count(x)) return memo[x];
        if (x == 1) return memo[x] = 0;
        else {
            return memo[x] = f(x / 2, f) + f((x + 1) / 2, f) + x;
        }
    };

    cout << f(n, f) << "\n";
}