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

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main()
{
    ll n;
    cin >> n;
    vector<bool> isprime;
    isprime = Eratosthenes(1e6);
    vector<int> primes;
    rep(i, 0, isprime.size()) if (isprime.at(i)) primes.push_back(i);

    // rep(i, 0, primes.size()) printf("%d\n", primes.at(i));
    
    int ans = 0;
    int m = primes.size();
    rep(i, 0, m) {
        ll a = primes.at(i);
        if (a * a * a * a * a > n) break;
        rep(j, i + 1, m) {
            ll b = primes.at(j);
            if (a * a * b * b * b > n) break;
            rep(k, j + 1, m) {
                ll c = primes.at(k);
                if (a * a * b * c * c > n) break;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
