#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>
using namespace std;

struct Bound {
    int a;
    int b;
    bool operator<(const Bound &b1) const {
        return b < b1.a;
    }


};

int main() {
    int n, k; cin >> n >> k;
    vector<Bound> bounds;
    map<int,int> del;
    map<int,int> delminus;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        del[a]++;
        delminus[b]++;
    }
    int cnt = 0;
    int ans = 0;
    for(int h = 0; h<=24; h++) {
        cnt += del[h];
        cnt -= delminus[h];
        if(cnt >= k) {
            ans++;
        }
    }
    cout << ans << "\n";


}