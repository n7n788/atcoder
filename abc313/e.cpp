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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    rep(i, 0, n - 1) {
        if (s.at(i) != '1' && s.at(i + 1) != '1')  {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<pair<int, mint>>  b;
    mint ones = 0;
    rep(i, 0, n) {
        if (s.at(i) == '1') ones++;
        else {
            b.emplace_back(s.at(i) - '0', ones + s.at(i) - '0');
            ones = 0;
        }
    }
    mint cnt = ones;
    if (b.size() == 0) {
        cout << n - 1 << endl;
        return 0;
    }

    // rep(i, 0, b.size()) {
    //     cout << b.at(i).first << " "<< b.at(i).second.val() << endl;
    // }

    
    for (int i = b.size() - 1; i >= 1; i--) {
        cnt += (b.at(i).second + cnt * (b.at(i).first - 1));
    }

    if (s.at(0) != '1') cout << cnt.val() << endl;
    else {
        cnt += (b.at(0).second + cnt * (b.at(0).first - 1)) - 1;
        cout << cnt.val() << endl;
    }

    return 0;
}