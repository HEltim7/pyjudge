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
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int in;
    cin>>in;
    if(in==1) cout<<1<<endl;
    else if(in==2) assert(0);
    else if(in==3) {
        int sum=0;
        for(int i=1;i<=1e12;i++) {
            sum+=i%in*in;
        }
        cout<<sum<<endl;
    }
    else cout<<in<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}