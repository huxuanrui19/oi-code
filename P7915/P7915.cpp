#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,a[N<<1];
string s1,s2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;for(int i=1;i<=n*2;i++) cin>>a[i];
        s1.resize(n*2+1);s2.resize(n*2+1);s1[0]=s2[0]='!';
        // case1: L
        int num=a[1];
        deque<int> q1,q2;
        for(int i=2;i<=2*n;i++){
            if(a[i]==num) break;
            q1.push_back(a[i]);
        }
        for(int i=2*n;i>=2;i--){
            if(a[i]==num) break;
            q2.push_back(a[i]);
        }
        s1[1]=s1[2*n]='L';
        int i=2;
        while(q1.size()+q2.size()){
            if(q1.size()){
                int u=q1.front();
                if(u==q1.back()&&q1.size()>1){
                    s1[i]=s1[2*n-i+1]='L';
                    q1.pop_front();q1.pop_back();
                    i++;continue;
                }
                if(q2.size()&&u==q2.back()){
                    s1[i]='L';s1[2*n-i+1]='R';
                    q1.pop_front();q2.pop_back();
                    i++;continue;
                }
            }
            if(q2.size()){
                int u=q2.front();
                if(q1.size()&&u==q1.back()){
                    s1[i]='R';s1[2*n-i+1]='L';
                    q1.pop_back();q2.pop_front();
                    i++;continue;
                }
                else if(u==q2.back()&&q2.size()>1){
                    s1[i]='R';s1[2*n-i+1]='R';
                    q2.pop_back();q2.pop_front();
                    i++;continue;
                }
            }
            break;
        }
        if(i<=n) s1[0]='@';
        // case2: R
        num=a[n*2];
        q1.clear();q2.clear();
        for(int i=1;i<=2*n-1;i++){
            if(a[i]==num) break;
            q1.push_back(a[i]);
        }
        for(int i=2*n-1;i>=1;i--){
            if(a[i]==num) break;
            q2.push_back(a[i]);
        }
        s2[1]='R';s2[2*n]='L';
        i=2;
        while(q1.size()+q2.size()){
            if(q1.size()){
                int u=q1.front();
                if(u==q1.back()&&q1.size()>1){
                    s2[i]=s2[2*n-i+1]='L';
                    q1.pop_front();q1.pop_back();
                    i++;continue;
                }
                else if(q2.size()&&u==q2.back()){
                    s2[i]='L';s2[2*n-i+1]='R';
                    q1.pop_front();q2.pop_back();
                    i++;continue;
                }
            }
            if(q2.size()){
                int u=q2.front();
                if(q1.size()&&u==q1.back()){
                    s2[i]='R';s2[2*n-i+1]='L';
                    q1.pop_back();q2.pop_front();
                    i++;continue;
                }
                else if(u==q2.back()&&q2.size()>1){
                    s2[i]='R';s2[2*n-i+1]='R';
                    q2.pop_back();q2.pop_front();
                    i++;continue;
                }
            }
            break;
        }
        if(i<=n) s2[0]='@';
        if(s1[0]!='@') cout<<s1.substr(1)<<"\n";
        else if(s2[0]!='@') cout<<s2.substr(1)<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
