//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <atcoder/all>

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
    ll n;
    cin >> n;
    vector<ll> primes;
    for (ll x = 2; x * x <= n / 12; x++) {
        // x{2 ~ sqrt(n)}が素数か判定
        bool flag = true;
        for (ll i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) primes.push_back(x);
    }

    // for (ll x: primes) cout << x << '\n';
    // cout << endl;

    vector<ll> primes_pow;
    ll p = primes.size();
    // cout << p << endl;
    // return 0;[]
    for (ll x: primes) primes_pow.push_back(x * x);

    // fa_vec[i]:= i以下で素数a*aとなる個数
    ll sqrt_n = sqrt(n);
    vector<ll> fa_vec(sqrt_n + 1, 0);
    ll index = 0;
    rep(i, 1, sqrt_n + 1) {
        if (i == primes_pow.at(index)) {
            fa_vec.at(i) = fa_vec.at(i - 1) + 1;
            index++;
        } else {
            fa_vec.at(i) = fa_vec.at(i - 1);
        }
    }

    // rep(i, 1, sqrt_n + 1) {
    //     cout << i << ", " << fa_vec.at(i) << '\n';
    // }
    // cout << endl;

    // n以下で素数a*a(a < b)となる個数を返す
    auto fa = [&](ll n, ll bi) -> ll{
        return min(fa_vec.at(min(n, sqrt_n)), bi);
    };

    // n以下で、a　*　a * b (b < c) となる個数を返す
    auto fb = [&] (ll n, ll ci) -> ll {
        ll sum = 0;
        rep(bi, 0, ci) {
            sum += fa(n / primes.at(bi), bi);
        }
        return sum;
    };

    // n以下で、a * a * b * c * c となる個数を返す
    auto fc = [&] (ll n) -> ll {
        ll sum = 0;
        rep(ci, 0, p) {
            sum += fb(n / primes_pow.at(ci), ci);
        }
        return sum;
    };

    cout << fc(n) << endl;

    return 0;
}