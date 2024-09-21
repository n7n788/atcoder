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

// 素数判定
bool is_prime(int n) 
{
    // 1は例外
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 約数の列挙
vector<int> divisor(int n) 
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

// 素因数分解
vector<P> prime_factor(int n) 
{
    vector<P> res;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            res.emplace_back(i, cnt);
        }
    }
    if (n != 1) res.emplace_back(n, 1);
    return res;
}

int main()
{
    int n;
    cin >> n;

    // nが素数か判定
    cout << "n is prime number? ";
    if (is_prime(n)) cout << "Yes\n";
    else cout << "No\n";

    // nの約数を列挙
    vector<int> div = divisor(n);
    cout << "divisor: ";
    for (auto d: div) cout << d << ", ";
    cout << "\n";

    // nを素因数分解
    vector<P> primes = prime_factor(n);
    cout << "prime factor: ";
    for (auto [x, cnt]: primes) cout << x << ": " << cnt << ", ";
    cout << "\n";
    return 0;
}