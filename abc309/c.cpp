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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a.at(i) >> b.at(i);

    map<ll, ll> cnts;
    rep(i, 0, n) {
        cnts[0] += b.at(i);
        cnts[a.at(i)] -= b.at(i);
    }
    ll pkey;
    for (auto it = cnts.begin(); it != cnts.end(); it++) {
        // cout << it->first << ',' << it-> second << endl;
        if (it != cnts.begin()) {
            // cout << it->first << ',' << pkey << endl;
            cnts[it->first] += cnts[pkey];
        }
        pkey = it->first;
        // cout << pkey << endl;
    }

    for (auto it = cnts. begin(); it != cnts.end(); it++) {
        if (it->second <= k) {
            cout << it->first + 1 << endl;
            return 0;
        }
        // cout << it->first << ',' << it-> second << endl;
    }
    return 0;
}