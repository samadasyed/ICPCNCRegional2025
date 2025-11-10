#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#include <iostream>

int main()
{
    int k; cin >> k;
    unordered_map<int, int> count;
    for(int i = 0 ; i < k ; ++i)
    {
        int x; cin >> x;
        ++count[x];
    }
    bool have10 = false;

    for(int i = 0 ; i < 10 && !have10; ++i)
        {
            while(count[i] >= 2) {
                if(count[10] != 0) { break; have10 = true; }
                count[i + 1]++;
                count[i]-=2;
            }
        }

    int n; cin >> n;
    while(n > 0 && !have10)
    {
        --n;
        count[0] += 3;
        for(int i = 0 ; i < 10 && !have10; ++i)
        {
            while(count[i] >= 2) {
                if(count[10] != 0) { break; have10 = true; }
                count[i + 1]++;
                count[i]-=2;
            }
        }
    }

    for(int i = 0 ; i < 10; ++i)
        {
            while(count[i] >= 2) {
                count[i + 1]++;
                count[i]-=2;
            }
        }

    for(int i = 0 ; i <= 10; ++i)
    {
        for(int j = 0 ; j < count[i]; ++j)
        {
            cout << i << " ";
        }
    }
}