#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=998244353;

int main(){
    //freopen("color.in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        ll dep;string s,ss,t;
        cin>>dep>>ss;
        s.clear();t.clear();
        for(int i=1;i<=dep-ss.size();i++){
            s.push_back('0');
        }
        s+=ss;
        if(dep==1) cout<<"1";
        else{
            ll a,b,c;
            if(s[s.size()-1]=='1'){
                b=2;
                s[s.size()-1]='0';
                while((!s.empty())&&(s.size()>=1&&s[s.size()-1]=='0')) s.pop_back();
            }
            else b=-1;
            if(!s.empty()) s.pop_back();
            a=4;
            dep--;
            if(dep==1) cout<<a;
            else{
                for(int i=1;i<=dep;i++) t.push_back('1'-(i<s.size()?s[i]:'0')+'0');
                c=1;
                while(dep>1){
                    if(b==-1){
                        if(s[s.size()-1]=='1'){
                            s[s.size()-1]=t[t.size()-1]='0';
                            while((!s.empty())&&(s.size()>=1&&s[s.size()-1]=='0')) s.pop_back();
                            while((!t.empty())&&(t.size()>=1&&t[t.size()-1]=='0')) t.pop_back();
                            b=(a+1)*(c+1)%mod;
                        }
                    }
                    else{
                        if(s[s.size()-1]=='1'){
                            b=(a+1)*(b+1)%mod;
                            s[s.size()-1]='0';
                            while((!s.empty())&&(s.size()>=1&&s[s.size()-1]=='0')) s.pop_back();
                        }
                        else{
                            b=(b+1)*(c+1)%mod;
                            t[t.size()-1]='0';
                            while((!t.empty())&&(t.size()>=1&&t[t.size()-1]=='0')) t.pop_back();
                        }
                    }
                    if(s.empty()){
                        s=t;t.clear();a=c;
                    }
                    if(s.size()>1) a=(a+1)*(a+1)%mod;
                    else a=b%mod;
                    if(t.size()>1) c=(c+1)*(c+1)%mod;
                    dep--;
                }
                cout<<a;
            }
        }
        cout<<"\n";
    }
    return 0;
}