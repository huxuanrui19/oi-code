#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+10;
int n,m,k,a[15][15],w[51000],b[15][15];
ull qp(ull a,ull b){
	ull sum=1;
	while(b){
		if(b&1) sum=sum*a;
		a=a*a;
		b>>=1;
	}
	return sum;
}
int cal(){
	int cur=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++){
				for(int l=k;l<=m;l++){
					if(b[i][l]==b[j][k]&&b[i][k]==b[j][l]&&b[i][k]!=b[i][l]){
						cur++;
					}
				} 
			}
		}
	}
	return cur;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		//int n,m,k;
		cin>>n>>m>>k;
        memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		if(m==1) cout<<"0\n";
		else if(k==1){
			cout<<qp(2,n+m)<<"\n";
		}
		else{
			ull ans=0;
			for(int s=0;s<(1<<n);s++){
				for(int t=0;t<(1<<m);t++){
					for(int i=1;i<=n;i++){
						for(int j=1;j<=m;j++){
							b[i][j]=a[i][j];
						}
					}
					for(int i=1;i<=n;i++){
						if(s&(1<<(i-1))){
							for(int j=1;j<=m;j++){
								b[i][j]=0;
							}
						}
					}
					for(int j=1;j<=m;j++){
						if(t&(1<<(j-1))){
							for(int i=1;i<=n;i++){
								b[i][j]=0;
							}
						}
					}
					w[cal()]++;
				}
			}
			for(int i=0;i<51000;i++){
				ans+=qp(w[i],k);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
