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

// 区間[a, b)内の素数を列挙
vector<ll> segment_sieve(ll a, ll b) 
{
    vector<bool> is_prime(b - a, true);
    vector<bool> is_prime_small((int)sqrt(b) + 1, true);

    for (ll i = 2; i * i < b; i++) {
        if (is_prime_small.at(i)) {
            for (ll j = 2 * i; j * j < b; j += i) is_prime_small.at(j) = false;
            for (ll j = max(2ll, (a + i - 1) / i) * i; j < b; j += i) is_prime.at(j - a) = false;
        }
    }

    vector<ll> res;
    rep(i, 0, b - a) if (is_prime.at(i)) res.push_back(i + a);
    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    vector<ll> res = segment_sieve(a, b);
    cout << res.size() << "\n";
}