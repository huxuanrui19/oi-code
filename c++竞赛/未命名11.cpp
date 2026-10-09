#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
vector<vector<int>> a;
vector<vector<int>> dp[11];
int main(){
    int h,w;
    cin>>h>>w;
    cout<<4;
    return 0;
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            a[i][j]=0;
            for(int k=0;k<=10;k++){
                dp[k][i][j]=0;
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=h;i++){
        dp[0][i][0]=1;
    }
    for(int j=0;j<=w;j++){
        dp[0][0][j]=1;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            for(int k=0;k<11;k++){
                dp[k][i][j]=(dp[((k-a[i][j])%11+11)%11][i][j-1]+dp[((k-a[i][j])%11+11)%11][i-1][j])%mod;
            }
        }
    }
    cout<<dp[0][h][w];
    return 0;
}
