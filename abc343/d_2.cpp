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
    int n, t;
    cin >> n >> t;
    vector<ll> s(n);
    unordered_map<ll, int> freq;
    freq[0] = n;
    rep(i, 0, t) {
        int a, b;
        cin >> a >> b;
        a--;
        int ps = s.at(a);
        int ns = s.at(a) + b;
        s.at(a) = ns;
        freq[ps]--;
        freq[ns]++;
        if (freq[ps] == 0) freq.erase(ps);
        cout << freq.size() << "\n";
    }
    return 0;
}