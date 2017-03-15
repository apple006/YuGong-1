/*
    有一个超市大甩卖，但是每个人同样的商品只能拿一件，商品有价值和重量，现在有一个顾客序列，
    每个人能拿的最大重量已知，求这些顾客，能拿到的最大价值的物品和。
    https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1071 
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

#define fr freopen("in.txt", "r", stdin)
#define fw freopen("out.txt", "w", stdout)
using namespace std;

int main(){
    int ncases;
    cin>>ncases;
    while(ncases --){
        int lines;
        cin>>lines;
        std::vector<pair<int, int> > things;
        for (int i = 0; i < lines; i++){
            int w, v;
            cin>>v>>w;
            things.push_back(make_pair(w, v));
        }
        cin>>lines;
        int ans = 0;
        for(int c = 0; c < lines; c++){
            int w;
            cin>>w;
            std::vector<int> value(w+1, 0);
            for(int i = 0; i < things.size(); i++){
                for(int j = w; j >= things[i].first; j--){
                    value[j] = max(value[j], value[j - things[i].first] + things[i].second);
                }
            }
            ans += value[w];
        }
        cout<<ans<<endl;
    }
}
