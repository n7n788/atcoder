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

    vector<int> update(n, 0); //最後に更新された時間
    int all_update, all_update_type; //最後にされた全体更新の時間とタイプ

    rep(qi, 0, q) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;

        switch (t)
        {
        case 1:
            update.at(x) = qi;
            s.at(x) = c;
            break;
        case 2:
            all_update = qi;
            all_update_type = 2;
            break;
        case 3:
            all_update = qi;
            all_update_type = 3;
            break;
        }
    }

    rep(i, 0, n) {
        if (update.at(i) < all_update) {
            if (all_update_type == 2 && s.at(i) >= 'A' && s.at(i) <= 'Z')
                s.at(i) = s.at(i) - 'A' + 'a';
            else if (all_update_type == 3 && s.at(i) >= 'a' && s.at(i) <= 'z')
                s.at(i) = s.at(i) - 'a' + 'A';
        }
    }
    
    cout << s << endl;
    return 0;
}