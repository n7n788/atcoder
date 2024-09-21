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
    vector<stack<int>> pos(n);
    vector<int> cnts(n, 0);
    vector<int> results;
    int k;
    bool flag = true;
    rep(i, 0, n) {
        int t, x;
        cin >> t >> x;
        x--;
        switch (t)
        {
        case 1:
            pos.at(x).push(i);
            break;
        case 2:
            if (!pos.at(x).empty()) {
                int p = pos.at(x).top();
                pos.at(x).pop();
                cnts.at(p)++;
                cnts.at(i)--;
            } else {
                flag = false;
            }
            break;
        }
    }
    if (!flag) {
        cout << -1 << "\n";
        return 0;
    }
    rep(i, 0, n) {
        if (cnts.at(i) == 1) results.push_back(1);
        else if (cnts.at(i) == 0) results.push_back(0);
    }
    rep(i, 0, n - 1) cnts.at(i + 1) += cnts.at(i);
    k = 0;
    rep(i, 0, n) chmax(k, cnts.at(i));
    cout << k << "\n";
    for (auto r: results) cout << r << " ";
    cout << "\n";
    return 0;
}
