/******************************* Aggressive Cows Using Binary Search ***********************************/
/**************** Time Complexity:-> O(n*log(d)) *************************/
//  (2 <= N <= 100,000) :-> N = no of cows
//  (0 <= xi <= 1,000,000,000) :-> xi = no of stalls
// Time Limit = 1 sec

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check_position(int cows,ll *position_cows,int n,ll distance){
    int count=1;
    ll last_position = position_cows[0];
    for(int i=1;i<n;i++){
        if(position_cows[i]-last_position >= distance){
            last_position = position_cows[i];
            count++;
        }
        if(cows==count) return true;
    }
    return false;
}

int main(){
    // write your code
    
    int t;
    cin>>t;
    while(t--){
        int n,c;
       
        cin>>n>>c;
        ll *position_cows = new ll[n];
        for(int i=0;i<n;i++){
            cin>>position_cows[i];
        }
        sort(position_cows,position_cows+n);
        ll min_dis = 0;
        ll ans = -1;
        ll max_dis = position_cows[n-1] - position_cows[0];
        while(min_dis <= max_dis){
            ll mid = min_dis + (max_dis-min_dis)/2;
            if(check_position(c,position_cows,n,mid)){
                ans = mid;
                min_dis = mid+1;
            }
            else{
                max_dis = mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}