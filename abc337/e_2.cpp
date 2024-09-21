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
#include <stack>

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
    int n;
    cin >> n;
    int m = 0;
    int ans;
    string s;
    while ((1 << m) < n) m++;
    cout << m << endl;
    rep(i, 0, m) {
        vector<int> a;
        rep(j, 0, n) {
            if (((j >> i) & 0b1)) 
                a.push_back(j);
        }
        cout << a.size() << " ";
        rep(j, 0, a.size()) cout << a.at(j) + 1 << " ";
        cout << endl;
    }
    cin >> s;
    ans = 0;
    rep(i, 0, m) {
        ans |= (s.at(i) - '0') << i;
    }
    cout << ans + 1 << endl;
    return 0;
}