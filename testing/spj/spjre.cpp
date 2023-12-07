#include <algorithm>
#include <array>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;

    vector<int> read;
    int in;
    while(cin>>in) read.push_back(in);

    sort(read.begin(),read.end());
    if(read.front()==1&&read.back()==n
        &&(unique(read.begin(),read.end())==read.end())) {
        cout<<"ok, no issue found."<<endl;
        return;
    }
    else {
        cout<<"wrong answer."<<endl;
        exit(1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}