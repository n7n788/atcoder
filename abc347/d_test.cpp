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
#include <string>
#include <algorithm>
#include <cstdlib>
#include <random>

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

void print(ll x) 
{
    for (int i = 59; i >= 0; i--) cout << ((x >> i) & 1);
    cout << endl;
}

int solve(int a, int b, ll C, ll& X, ll& Y, bool& flag)
{
    // int a, b;
    // ll C;
    // cin >> a >> b >> C;
    // cout << a << ", " << b  << ", " << C << endl;
    int n = a + b;
    int k = 0;
    rep(i, 0, 60) if ((C >> i) & 1) k++;

    // print(C);

    int m = (n - k) / 2;
    a -= m;
    b -= m;
    // cout << m << ", " << a << ", " << b << endl;
    if ((n - k) % 2 == 1 || n - k < 0 || a < 0 || b < 0) {
        // cout << "-1\n";
        flag = false;
        return 0;
    }
    
    X = 0, Y = 0;
    
    int cnt = 0;
    rep(i, 0, 60) {
        if (cnt >= m) break;

        if ((C >> i) & 1) continue; 
        // cout << ((C >> i) & 1) << endl;
        // cout << i << endl;
        X |= 1ll << i;
        Y |= 1ll << i;
        cnt++;
    }
    if (cnt < m) {
        // cout << "-1\n";
        flag = false;
        return 0;
    }
        // print(X);
        // print(Y);
    

    cnt = 0;
    rep(i, 0, 60) {
        if ((C >> i) & 1) {
            if (cnt < b) {
                Y |= 1ll << i;
            } else if (cnt < a + b) {
                X |= 1ll << i;
            } else break;
            cnt++;
        }
    }
    if (cnt < a + b) {
        // cout << "-1\n";
        flag = false;
        return 0;
    }

    // cout << X << " " << Y << endl;
    flag = true;
    return 0;
}

bool check(int a, int b, ll C, ll X, ll Y, bool flag)
{
    if (!flag) return true;

    int ac = 0, bc = 0;
    ll Z = X ^ Y;
    rep(i, 0, 60) {
        if (X >> i & 1) ac++;
        if (Y >> i & 1) bc++;
    }
    return ac == a && bc == b && Z == C;
}

int main()
{
    int a, b;
    ll C, X, Y;
    bool flag;
    int q = 1000;
    std::random_device rnd;     // 非決定的な乱数生成器
    std::mt19937 mt(rnd());   
    std::mt19937_64 mt64(rnd());
    rep(qi, 0, q) {
        a = (mt() + 61) % 61;
        b = (mt() + 61) % 61;
        C = (mt64() + (1ll << 60)) % (1ll << 60);
        // cout << a << ", " << b << ", " << C << endl;
        solve(a, b, C, X, Y, flag);
        if (check(a, b, C, X, Y, flag)) {
            // cout << "AC" << endl;
        } else {
            printf("a = %d, b = %d, C = %lld, X = %lld, Y = %lld, flag = %d\n", a, b, C, X, Y, flag);
            cout << "WC" << endl;
        }
    }
    
    return 0;
}