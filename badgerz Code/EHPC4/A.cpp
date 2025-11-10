#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>
using namespace std;

string hexToBinary(string h) {
    int b10 = 0;
    if('a' <= h[1] && h[1] <= 'f') {
        b10 += (h[1]-'a')+10;
    }
    else {
        b10 += (h[1]-'0');
    }
    if('a' <= h[0] && h[0] <= 'f') {
        b10 += ((h[0]-'a')+10)*16;
    }
    else {
        b10 += 16*(h[0]-'0');
    }

    // cout << b10 << "\n";

    string bin = "";
    while(b10 > 0) {
        if(b10%2 == 0) {
            bin = "0"+bin;
        } else {
            bin = "1"+bin;
        }
        b10 /= 2;
    }
    int orSize = bin.size();
    for(int j = orSize+1; j<= 8; j++) {
        bin = "0"+bin;
    }

    return bin;

}

int main() {
    int N; cin >> N;
    int boring = 0;
    int cool = 0;
    int art = 0;


    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        // *

        vector<string> byteseq;
        if(s.size()%2 != 0) {
            art++;
            continue;
        }

        bool is_art = false;
        for(int i = 0; i<s.size(); i+=2) {
            string to_conv = "" + s[i];
            to_conv += ""+s[i+1];

            if(!('0'<= s[i] && s[i] <= '9' || 'a' <= s[i] && s[i] <= 'f')) {
                is_art = true;
                break;
            }
            if(!('0'<= s[i+1] && s[i+1] <= '9' || 'a' <= s[i+1] && s[i+1] <= 'f')) {
                is_art = true;
                break;
            }
            cout << "TC: " << to_conv << " ";

            string by = hexToBinary(to_conv);
            cout << "BY: " << by << "\n";
            byteseq.push_back(by);

        }
        if(is_art) {
            art++;
            continue;
        }

        int ind = 0;
        int bsz = byteseq.size();
        bool multi = false;

        while(!is_art && ind < bsz) {
            if(byteseq[ind][0] == '0') {
                ind++; continue;
            }
            
            if(byteseq[ind][0] == '1' && byteseq[ind][1] == '1') {
                multi = true;
                int len = 0;
                for(int j = 0; byteseq[ind][j] == '1' && j <= 3; j++) {
                    len++;
                }
                if(byteseq[ind][len] == '1') {
                    is_art = true;
                    break;
                }  
                if(ind+len-1 >= bsz) {
                    is_art = true;
                    break;
                }

                for(int j = ind+1; j<ind+len; j++) {
                    if(byteseq[j].substr(0,2) != "10") {
                        is_art = true;
                        break;

                    }
                }
                if(is_art)
                    break;
                ind = ind+len;
            }
        }

        if(is_art) {
            art++;
            continue;
        }

        if(multi) {
            cool++;
            continue;
        }
        boring++;

    }
    cout << boring << " " << cool << " " << art << "\n";
}