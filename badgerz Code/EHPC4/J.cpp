#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int target; cin >> target; int thirdroll; cin >> thirdroll;

    vector<pair<int,int>> vec;
    for(int i = 0 ; i < 10 ; ++i)
    {
        int a, b; cin >> a >> b;
        vec.emplace_back(a,b);
    }

    sort(vec.begin(), vec.end());
    int best = -1;
    int minb = 1e9;
    do {
        int score = 0; 
        for (int i = 0; i < 8; i++) 
        {
            auto p = vec[i]; 
            if (p.first + p.second == 10 && (p.first != 10) && (p.second != 10)){
                score += p.first + p.second + vec[i+1].first; 
            }
            if (p.first == 10 || p.second == 10) {
                score += p.first + p.second + vec[i+1].first; 
                if (vec[i+1].second == 0  && vec[i+2].first == 0) {
                    score += vec[i+2].first; 
                }
                if (vec[i+1].second == 0) {
                    score += vec[i+1].second;
                }
                else {
                    score += vec[i+1].second; 
                }
            }
        }

        
         score += vec[8].first + vec[8].second; 
        //9 irl

        if (thirdroll != 0) {
            score += vec[9].first + vec[9].second + thirdroll; 
        }
        else {
            score += vec[9].first + vec[9].second; 
        }
        if (score == target) {
            cout << target << " " << "Yes\n";
            return 0;
        } else if(score < target) { best = max(best, score); }
        else if(score > target) { minb = min(minb, score); }
    } while (next_permutation(vec.begin(), vec.end()));

    if(best != -1) { cout << best << " ";}
    if(minb != 1e9) { cout << minb << '\n';}

}