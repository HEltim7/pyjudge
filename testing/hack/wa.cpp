#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int in;
    cin>>in;
    if(mt19937(chrono::system_clock().now().time_since_epoch().count())()%50==0) cout<<0<<endl;
    else cout<<in<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}