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
    int n, q;
    string s;
    cin >> n >> s >> q;

    vector<int> t(q), x(q);
    vector<char> c(q);
    rep(i, 0, q) {
        cin >> t.at(i) >> x.at(i) >> c.at(i);
        x.at(i)--;
    }
    int k;
    for (int i = q - 1; i >= 0 ; i--) {
        if (t.at(i) != 1) {
            k = i;
            break;
        }
    }

    rep(i, 0, q) {
        if (t.at(i) == 1) s.at(x.at(i)) = c.at(i);
        else if (i == k) {
            if (t.at(k) == 2) transform(s.begin(), s.end(), s.begin(), ::tolower);
            else transform(s.begin(), s.end(), s.begin(), ::toupper);
        }
    }

    cout << s << endl;
    return 0;
}