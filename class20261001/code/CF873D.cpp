#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
int n,k;
int a[maxn],tot;
void solve(int L,int R,int M){//[L,R-1]
    if(!M){
        for(int i=L;i<R;i++)a[i]=++tot;
        return ;
    }
    if(L+1==R){//M!=0
        cout<<-1<<endl;
        exit(0);
    }
    int mid=(L+R)/2;
    int a=(M-2)/2,b=(M-2)/2;
    if(a%2==1){
        b++;
        a--;
    }
    solve(mid,R,b);
    solve(L,mid,a);
}
int main(){
    cin>>n>>k;
    if(k%2==0){
        cout<<-1<<endl;

        return 0;
    }
    solve(0,n,k-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
