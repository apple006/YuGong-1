/*
    给定n（1 <= n <= 500）个硬币，每个硬币都有面值，求每个能构成和为k（1 <= k <= 500）的硬币组合中，
    任意个数相互求和的总额种类，然后将所有硬币组合中最后得到的结果输出。
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
int dp[510][510];
int main(){
    int ncase, mx;
    while(cin>>ncase>>mx){
        
        memset(dp, 0, sizeof(dp));
        vector<int> value;
        for (int i = 0; i < ncase; ++i)
        {
            int v;
            cin>>v;
            value.push_back(v);
        }

        dp[0][0] = 1;
        for(int i = 0; i < value.size(); i++){
            for( int j = mx; j >= value[i]; j--){
                for( int x = 0; x <= mx - value[i]; x++){
                    if(dp[j - value[i]][x])
                        dp[j][x] = dp[j][x + value[i]] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i <= mx; i++){
            if(dp[mx][i])
                cnt++;
        }
        cout<<cnt<<endl;
        for(int i = 0; i <= mx; i++){
            if(dp[mx][i])
                cout<<i<<" ";
        }
        cout<<endl;
    }
}
