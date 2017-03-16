/*
    电子科大本部食堂的饭卡有一种很诡异的设计，即在购买之前判断余额。如果购买一个商品之前，
    卡上的剩余金额大于或等于5元，就一定可以购买成功（即使购买后卡上余额为负），否则无法购买（即使金额足够）。
    所以大家都希望尽量使卡上的余额最少。
    某天，食堂中有n种菜出售，每种菜可购买一次。已知每种菜的价格以及卡上的余额，问最少可使卡上的余额为多少。
    http://acm.hdu.edu.cn/showproblem.php?pid=2546
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
    int n;
    while(cin>>n){
        if (n == 0)
            return 0;
        vector<int> prices;
        int maxPrice = 0;
        int maxPricePos = 0;
        for(int i = 0; i < n; i++){
            int p;
            cin>>p;
            prices.push_back(p);
            if(maxPrice < p){
                maxPrice = p;
                maxPricePos = i;
            }
        }
        int oriValue;
        cin>>oriValue;
        if(oriValue >= 5){
            int value = oriValue - 5;
            std::vector<int> dp(value + 1, 0);
            for(int i = 0; i < prices.size(); i++){
                if(i == maxPricePos){
                    continue;
                }
                for(int j = value; j >= prices[i]; j--){
                    dp[j] = max(dp[j], dp[j - prices[i]] + prices[i]);
                }
            }
            cout<<oriValue - dp[value] - maxPrice<<endl;
        }else{
            cout<<oriValue<<endl;
        }
    }
}
