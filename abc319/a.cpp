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

int main()
{
    string s; 
    cin >> s;

    if (s == "tourist") cout << 3858 << '\n';
    if (s == "ksun48") cout << 3679 << '\n';
    if (s == "Benq") cout << 3658 << '\n';
    if (s == "Um_nik") cout << 3648 << '\n';
    if (s == "apiad") cout << 3638 << '\n';
    if (s == "Stonefeang") cout << 3630 << '\n';
    if (s == "ecnerwala") cout << 3613 << '\n';
    if (s == "mnbvmar") cout << 3555 << '\n';
    if (s == "newbiedmy") cout << 3516 << '\n';
    if (s == "semiexp") cout << 3481 << '\n';
    
    return 0;
}