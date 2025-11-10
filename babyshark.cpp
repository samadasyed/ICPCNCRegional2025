#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> vec;
    string x;
    while(cin >> x)
    {
        if(x.size() == 0) { break; }
        vec.push_back(x);
    }

    int count = 1;
    int bc = 1;
    string best = vec[0];

    for(int i = 0 ; i < vec.size() - 1; ++i)
    {
        if(vec[i] == vec[i + 1]) { count++; }
        else { count = 1; }

        if(count > bc) {
            bc = count;
            best = vec[i];
        }
    }

    cout << best << '\n';
}