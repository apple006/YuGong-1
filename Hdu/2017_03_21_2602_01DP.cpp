/*
    Many years ago , in Teddy’s hometown there was a man who was called “Bone Collector”. This man like to collect varies of bones , such as dog’s , cow’s , also he went to the grave …
    The bone collector had a big bag with a volume of V ,and along his trip of collecting there are a lot of bones , obviously , different bone has different value and different volume,
     now given the each bone’s value along his trip , 
    can you calculate out the maximum of the total value the bone collector can get ?
    http://acm.hdu.edu.cn/showproblem.php?pid=2602
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
        int n,m;
        cin>>n>>m;
        vector<int> values;
        vector<int> weights;
        for(int i = 0; i < n; i++){
            int v;
            cin>>v;
            values.push_back(v);
        }
        for(int i = 0; i < n; i++){
            int w;
            cin>>w;
            weights.push_back(w);
        }


        std::vector<int> ans(m+1, 0);
        for(int i = 0; i < n; i++){
            for(int j = m; j >= weights[i]; j--){
                ans[j] = max(ans[j], ans[j-weights[i]] + values[i]);
            }
        }
        cout<<ans[m]<<endl;
    }
}
