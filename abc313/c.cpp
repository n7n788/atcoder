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
    vector<ll> a(n);
    ll sum = 0;
    rep(i, 0, n) {
        cin >> a.at(i);
        sum += a.at(i);
    }

    ll min = sum / n;
    ll max_num = sum % n;
    ll min_num = n - max_num;

    sort(a.begin(), a.end());

    ll res = 0;
    rep(i, 0, n) {
        if (i < min_num) res += abs(min - a.at(i));
        else res += abs(min + 1 - a.at(i)); 
    }

    cout << res / 2 << endl;
    return 0;
}