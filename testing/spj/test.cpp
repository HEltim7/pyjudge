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
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n%50==0) cout<<"qwq";
    else {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        shuffle(ans.begin(), ans.end(), mt19937(random_device()()));
        for(int x:ans) cout<<x<<' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}