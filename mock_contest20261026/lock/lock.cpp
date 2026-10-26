#include<bits/stdc++.h>
using namespace std;
int n,a[10][6];
map<string,int> mp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        string s;
        for(int j=1;j<=5;j++) s+=char(a[i][j]+'0');
        for(int j=1;j<=5;j++){
            for(int k=0;k<=9;k++){
                if(s[j-1]==char(k+'0')) continue;
                else{
                    string t=s;
                    t[j-1]=char(k+'0');
                    mp[t]++;
                }
            }
        }
        for(int j=1;j<=4;j++){
            for(int k=1;k<=9;k++){
                int a=s[j-1]-'0',b=s[j]-'0';
                a=(a+k)%10;b=(b+k)%10;
                string t=s;
                t[j-1]=char(a+'0');t[j]=char(b+'0');
                mp[t]++;
            }
        }
    }
    int num=0;
    for(auto d:mp){
        if(d.second==n) num++;
    }
    cout<<num;
    return 0;
}
