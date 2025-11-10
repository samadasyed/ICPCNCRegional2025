#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <map>

constexpr double pi = 3.14159265358979;

#include <algorithm>
using namespace std;

int main() {
    double d; cin >> d;
    double c1; cin >> c1;
    double c2; cin >> c2;

    double mindist = 205.0;
    int mina = -1;
    int minb = -1;

    for(int a = 0; a*c1 <= d+.00000001; a++) {
        for(int b = 0; a*c1 + b*c2 <= d+.00000001; b++) {
            double cand = d - (a*c1 + b*c2);
            if(cand < mindist+.00000001) {
                mina = a;
                minb = b;
                mindist = cand;
            }
            else if(abs(cand - mindist) < .00000001) {
                if(mina <= a) {
                    mina = a;
                    minb = b;
                    mindist = cand;
                }
            }

        }
    }
    cout << mina << " " << minb << "\n";
 
}