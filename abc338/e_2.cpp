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
    vector<int> d(2 * n);
    stack<int> st;
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        d.at(a) = i;
        d.at(b) = i;
    }

    rep(i, 0, 2 * n) {
        if (!st.empty() && st.top() == d.at(i)) st.pop();
        else {
            st.push(d.at(i));
        }
    }
    if (st.empty()) cout << "No" << "\n";
    else cout << "Yes" << "\n";

    return 0;
}