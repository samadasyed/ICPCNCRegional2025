#include <vector>
#include <cmath>
#include <algorithm>

#include <iostream>
constexpr int MOD = 1e9 + 7;

long long fastExp(long long base, long long exp)
{
    if(exp == 0) { return 1; }
    if(exp%2 == 0) {
        return fastExp(base, exp/2) * fastExp(base, exp/2)%MOD;
    }
    return fastExp(base, (exp-1)/2)*fastExp(base,(exp-1)/2)%MOD*base%MOD;
}

using namespace std;
int main()
{
    int E; cin >> E;
    int L, R; cin >> L >> R;
    vector<bool> isPrime(1000001, true);
    isPrime[1] = false;
    for(int i = 2; i < sqrt(1000001); ++i)
    {
        if(!isPrime[i]) {continue; }
        for(int j = 2 * i; j < 1000001; j += i)
        {
            isPrime[j] = false;
        }
    }

    long long ans = 1;

    for(int i = L ; i <= R; ++i)
    {
        if(isPrime[i]) {
            //cout << i << " prime\n";
            ans = (ans * fastExp(i, E)) % MOD;
        }
    }
    cout << ans % MOD << '\n';

    return 0;
}