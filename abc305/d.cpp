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
    int m = sqrt(n / 3) / 2;
    vector<bool> isprime(m + 1);
    isprime = Eratosthenes(m);

    vector<int> primes;
    rep(i, 0, m) {
        if(isprime.at(i)) primes.push_back(i);
    }

    vector<int> isprime_cum(m + 1, 0);
    erep(i, 2, m) {
        isprime_cum.at(i) = isprime_cum.at(i - 1);
        if (isprime.at(i)) isprime_cum.at(i)++;
    }

    ll ans = 0;
    int ps = primes.size();
    // printf("ps = %d\n", ps);
    rep(i, 0, ps) {
        int a = primes.at(i);
        if (a >= pow(n, 0.2)) continue;
        rep(j, i + 1, ps) {
            int b = primes.at(j);
            int max_c = sqrt(n / b) / a;
            // printf("a = %d, b = %d, maxc = %d\n", a, b, max_c);
            if (max_c > b) ans += (isprime_cum.at(max_c) - isprime_cum.at(b));
        }
    }
    cout << ans << endl;
    return 0;
}