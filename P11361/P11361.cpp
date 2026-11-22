#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
int n;
string s1,s2,t1,t2;
int main(){
    //freopen("D:\\oi-code\\P11361\\edit\\edit2.in","r",stdin);
    //freopen("D:\\oi-code\\P11361\\edit\\edit2.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n;
        cin>>s1>>s2>>t1>>t2;
        int num0=0,num1=0;
        vector<pair<int,int> > q1,q2;
        for(int i=0;i<=n-1;i++){
            if(t1[i]=='1'){
                if(s1[i]=='1') num1++;
                else num0++;
            }
            else{
                if(num0||num1) q1.push_back({num0,num1});
                q1.push_back({s1[i]=='0',s1[i]=='1'});
                num0=0,num1=0;
            }
        }
        if(num0||num1) q1.push_back({num0,num1});
        num0=0,num1=0;
        for(int i=0;i<=n-1;i++){
            if(t2[i]=='1'){
                if(s2[i]=='1') num1++;
                else num0++;
            }
            else{
                if(num0||num1) q2.push_back({num0,num1});
                q2.push_back({s2[i]=='0',s2[i]=='1'});
                num0=0,num1=0;
            }
        }
        if(num0||num1) q2.push_back({num0,num1});
        int l=0,lt=0,ans=0;
        while(l<q1.size()&&lt<q2.size()){
            auto u=q1[l],v=q2[lt];
            int num0=min(u.first,v.first);
            int num1=min(u.second,v.second);
            ans+=num0+num1;
            u.first-=num0;u.second-=num1;
            v.first-=num0;v.second-=num1;
            q1[l]=u;q2[lt]=v;
            if(u.first+u.second<v.first+v.second){
                l++;
                q2[lt].first=max(v.first-u.second,0);
                q2[lt].second=max(v.second-u.first,0);
            }
            else if(u.first+u.second>v.first+v.second){
                lt++;
                q1[l].first=max(u.first-v.second,0);
                q1[l].second=max(u.second-v.first,0);
            }
            else l++,lt++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}