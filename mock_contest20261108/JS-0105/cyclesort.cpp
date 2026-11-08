#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,s,a[N],lis[N],vis[N];
int main(){
    freopen("cyclesort.in","r",stdin);
    freopen("cyclesort.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    int flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]<a[i-1]) flag=1;
    }
    if(flag==0){
        cout<<"0";
        return 0;
    }
    if(n<=2){
        if(s<=1) cout<<"-1";
        else{
            cout<<"1\n2\n1 2";
        }
        return 0;
    }

    int mark=0;
    for(int i=1;i<=n;i++){
        if(a[i]>2) mark=1;
    }
    if(mark==0){
        int num1=0,num2=0;
        for(int i=1;i<=n;i++){
            num1+=(a[i]==1);num2+=(a[i]==2);
        }
        int ans=0;
        deque<int> q1,q2;
        for(int i=1;i<=n;i++){
            if(a[i]==1&&i>num1) ans++,q1.push_back(i);
            else if(a[i]==2&&(n-i+1)>num2) ans++,q2.push_back(i);
        }
        if(ans>s){
            cout<<"-1";
            return 0;
        }
        int bg=2;
        cout<<"1\n"<<ans<<"\n";
        for(int i=1;i<=ans;i++){
            if(bg==2){
                cout<<q1.back()<<" ";
                q1.pop_back();
                bg=1;
            }
            else if(bg==1){
                cout<<q2.back()<<" ";
                q2.pop_back();
                bg=2;
            }
        }
        return 0;
    }

    for(int i=1;i<=n;i++) lis[i]=a[i];
    sort(lis+1,lis+n+1);
    for(int i=1;i<=n;i++){
        if(lis[i]!=i) flag=0;
    }
    if(flag==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=i) ans++;
        }
        if(ans>s){
            cout<<"-1";
            return 0;
        }
        ans=0;
        vector<int>v[N];
        for(int i=1;i<=n;i++){
            if(a[i]==i) continue;
            if(vis[i]==1) continue;
            int x=i,y=i;ans++;
            do{
                vis[y]=1;
                v[ans].push_back(a[y]);
                y=a[y];
            }while(x!=y);
        }
        cout<<ans<<"\n";
        for(int i=1;i<=ans;i++){
            cout<<v[i].size()<<"\n";
            for(auto d:v[i]) cout<<d<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
