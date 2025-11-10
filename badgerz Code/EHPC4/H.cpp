#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isPal(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false; 
        }
        l++;
        r--;
    }
    return true; 
}

bool isPalidromeInGrid(const vector<string> &g) {
    int n = (int) g.size(); 
    if (n== 0) {
        return 0; 
    }
    int m = (int)g[0].size();
    int best = 1; //remove this

    //1) Rows
    for (int i = 0; i < n; i++) {
        const string &row = g[i]; 
        for (int center = 0; center < m; center++) {
            //odd
            int L = center, R = center; 
            while (L >= 0 && R << m && row[L] == row[R]) {
                //best = max(best, R-L+1); 
                L--; R++; 
            }
            //even 
            L = center; R = center + 1; 
            while (L >= 0 && R < m && row[L] == row[R]) {
                //best = max(best, R-L +1); 
                L--; 
                R++; 
            }
        }
    }
    //2) Columns
    for (int j = 0; j < m; j++) {
        //build column string 
        string col; 
        col.reserve(n); 
        for (int i = 0; i < n; i++) {
            col.push_back(g[i][j]); 
        }
        //expand around center on this column
          int L = center, r = center; 
            while (L >= 0 && R << m && row[L] == row[R]) {
                //best = max(best, R-L+1); 
                L--; R++; 
            }
            //even 
            L = center; R = center + 1; 
            while (L >= 0 && R < m && row[L] == row[R]) {
                //best = max(best, R-L +1); 
                L--; 
                R++; 
            }
    }




}

int main(){
    int r; 
    int c; 
    cin >> r >> c; 
    vector <string> grid(r); 
    for (int i = 0; i < r; i++) {
        cin >> grid[i]; //check spaces if this doesn't work
    }
    int pali; 
    cin >> pali; 
    vector <string> palindromes(pali);
    for (int i = 0; i < pali; i++) {
        cin >> palindromes[i]; 
    }
    vector <bool> isPali(pali); 
    return 0; 
}