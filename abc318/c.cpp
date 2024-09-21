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
    int n, d;
    ll p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    rep(i, 0, n) cin >> f.at(i);

    sort(f.rbegin(), f.rend());
    ll sum = 0;
    rep(i, 0, n) sum += f.at(i);
    int maxi = n / d + 1;

    ll ans = sum;
    erep(i, 1, maxi) {
        rep(j, 0, d) {
            if (d * (i - 1) + j < n) sum -= f.at(d * (i - 1) + j);
        }
        sum += p;
        chmin(ans, sum);
    }

    cout << ans <<  endl;

    return 0;
}