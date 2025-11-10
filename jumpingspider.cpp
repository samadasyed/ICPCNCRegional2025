#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <set>

using namespace std;
int r, c; 

int main()
{
    cin >> r >> c;
    bool isJump = false;
    vector<vector<int>> spid(r, vector<int>(c));
    vector<vector<int>> crit1(r, vector<int>(c));

    for(int i = 0 ; i < r; ++i)
    {
        for(int j = 0 ; j < c; ++j)
        {
            cin >> spid[i][j];
        }
    }

    for(int i = 0 ; i < r; ++i)
    {
        for(int j = 0 ; j < c; ++j)
        {
            if(spid[i][j] != 1) { continue; }
            for(int dx = -2 ; dx <= 2; ++dx)
            {
                for(int dy = -2 ; dy <= 2; ++dy)
                {
                    if(abs(dx) + abs(dy) > 3) { continue; }
                    if(dx == 0 && dy == 0) { continue; }
                    if(i + dx < 0 || i + dx >= r) { continue; }
                    if(j + dy < 0 || j + dy >= c) { continue; }
                    crit1[i+dx][j+dy]++;
                }
            }
        }
    }

    queue<pair<int,int>> q;
    vector<vector<int>> parent(r, vector<int>(c, 0));
    vector<vector<bool>> seen(r, vector<bool>(c)); // means valid
    int id = 0;

    for(int i = 0 ; i < r ; ++i)
    {
        for(int j = 0 ; j < c; ++j)
        {
            if(spid[i][j] == 1 && crit1[i][j] == 7 && !seen[i][j]) {
                isJump = true;
                parent[i][j] = ++id;
                q.emplace(i,j);
 
                while(!q.empty())
                {
                    auto f = q.front();
                    q.pop();
                    int cr = f.first;
                    int cc = f.second;
                    seen[cr][cc] = true;
                    for(int dx = -3 ; dx <= 3; ++dx)
                    {
                        for(int dy = -3 ; dy <= 3; ++dy)
                        {
                            if(abs(dx) + abs(dy) > 3) { continue; }
                            if(dx == 0 && dy == 0) { continue; }
                            if(cr + dx < 0 || cr + dx >= r) { continue; }
                            if(cc + dy < 0 || cc + dy >= c) { continue; }

                            if(spid[cr+dx][cc+dy] ==1 && !seen[cr+dx][cc+dy]) {
                                parent[cr+dx][cc+dy] = parent[cr][cc]; 
                                q.emplace(cr+dx, cc+dy);
                            }
                        }
                    }
                }
            }
        }
        //cout << '\n';
    }

    //cout << '\n';
    int numC = 0;
    int otherPrint = 0;
    set<int> numParents;
    for(int i = 0 ; i < r; ++i)
    {
        for(int j = 0 ; j < c ; ++j)
        {
            //cout << parent[i][j] << " ";
            if(parent[i][j] == 0 && spid[i][j] == 1) { 
                ++otherPrint; 
            }
            else if (parent[i][j] != 0) {
                numParents.insert(parent[i][j]);
            }
        }
        //cout << '\n';
    }

    int jumps = (int)numParents.size() - 1;
    cout << (isJump ? "Yes": "No") << '\n';
    cout << (isJump ? jumps: 0) << '\n';
    cout << otherPrint << '\n';
}