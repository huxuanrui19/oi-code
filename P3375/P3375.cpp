#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s1,s2;
int n,m,nxt[N];
void get_next(string s){
    int m=s.size();
    nxt[0]=0;
    for(int i=1;i<m;i++){
        int j=nxt[i-1];
        while(j>0&&s[j]!=s[i]) j=nxt[j-1];
        if(s[i]==s[j]) nxt[i]=j+1;
        else nxt[i]=0;
    }
}
void kmp(){
    for(int i=0,j=0;i<n;){
        if(s1[i]==s2[j]){
            if(j==m-1){
                cout<<(i-m+2)<<"\n";
                if(j==0) i++;
                else j=nxt[j-1];
            }
            else{
                i++;j++;
            }
        }
        else{
            if(j==0) i++;
            else j=nxt[j-1];
        }
    }
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s1>>s2;
    n=s1.size();m=s2.size();
    get_next(s2);
    kmp();
    for(int i=0;i<m;i++) cout<<nxt[i]<<" ";
    return 0;
}