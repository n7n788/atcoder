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

// エラトステネスの篩によりn以下の素数を返す
vector<int> sieve(int n)
{
    vector<int> is_prime(n + 1, true);
    vector<int> res;
    is_prime.at(0) = is_prime.at(1) = false;
    erep(i, 2, n) {
        if (is_prime.at(i)) {
            res.push_back(i);
            for (int j = 2 * i; j <= n; j += i) 
                is_prime.at(j) = false;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res = sieve(n);
    cout << res.size() << "\n";
    return 0;
}
