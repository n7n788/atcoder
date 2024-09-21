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
    int n;
    cin >> n;
    vector<P> ab;
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        ab.emplace_back(a, a + b);
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto f = [&](int i, int j) {
        auto [ai, bi] = ab[i];
        auto [aj, bj] = ab[j];
        return (ll) ai * bj > (ll) aj * bi; //　>なら降順、<なら昇順
    };
    stable_sort(p.begin(), p.end(), f); //stable_sortは安定ソート
    rep(i, 0, n) cout << p.at(i) + 1 << ' ';
    cout << endl;
    return 0;
}