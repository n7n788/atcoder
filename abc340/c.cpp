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
    map<ll, ll> mp;
    ll sum;
    cin >> n;

    sum = 0;
    mp[n] = 1;
    while (mp.size() != 0) {
        map<ll, ll> mp2;
        for (auto [a, b]: mp) {
            // std::cout << a << " " << b << "\n";
            sum += a * b;
        }
        // std::cout << sum << "\n";
        for (auto [a, b]: mp) {
            ll l, r;
            l = a / 2;
            r = (a + 1) / 2;
            if (l != 1) mp2[l] += b;
            if (r != 1) mp2[r] += b; 
        }
        mp = mp2;
    }

    std::cout << sum << "\n";
}