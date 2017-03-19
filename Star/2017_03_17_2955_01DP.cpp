/*
    The aspiring Roy the Robber has seen a lot of American movies, and knows that the bad guys usually gets caught in the end, often because they become too greedy. He has decided to work in the lucrative business of bank robbery only for a short while,
     before retiring to a comfortable job at a university.
     For a few months now, Roy has been assessing the security of various banks and the amount of cash they hold. He wants to make a calculated risk, and grab as much money as possible.
    His mother, Ola, has decided upon a tolerable probability of getting caught. She feels that he is 
    safe enough if the banks he robs together give a probability less than this.
    http://acm.hdu.edu.cn/showproblem.php?pid=2955
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
        double p;
        int n;
        cin>>p>>n;
        std::vector<pair<double, int> >bank;
        int money = 0;
        for(int i = 0; i < n; i++){
            int a;
            double b;
            cin>>a>>b;
            money += a;
            bank.push_back(make_pair(b,a));
        }
        std::vector<double> ans(money + 1, 0);
        ans[0] = 1;
        for(int i = 0; i < bank.size(); i++){
            for(int j = money; j >= bank[i].second; j--){
                ans[j] = max(ans[j], ans[j - bank[i].second] * (1- bank[i].first));
            }
        }
        for(int i = money; i >= 0; i--){
            cout<<i<<" "<<ans[i]<<endl;
        }
        for(int i = money; i >= 0; i--){
            if(ans[i] > 1-p){
                cout<<i<<endl;
                break;
            }
        }
    }
}
