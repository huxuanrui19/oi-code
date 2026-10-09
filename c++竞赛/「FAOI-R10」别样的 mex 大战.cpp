#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int n,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int sum=0,mex=-1;
		for(int i=1;i<=n;i++) sum^=a[i];
		if(a[1]!=0) mex=0;
		else if(a[1]==0&&n==1) mex=1;
		else{
			for(int i=2;i<=n;i++){
				if((a[i]-a[i-1])>1){
					mex=a[i-1]+1;
					break;
				}
			}
		}	
		if(mex==-1) mex=a[n]+1;
		if(mex==sum) cout<<"0\n\n";
		else if((mex^sum)!=mex) cout<<"1\n"<<(mex^sum)<<"\n";
		else{
			cout<<"2\n";
			int cnt=0;
			for(int i=1;i<=1e5&&i+mex<(1<<30);i++){
				int cur=sum^mex^(i+mex);
				if(cur!=mex){
					cnt=cur;break;
				}
			}
			cout<<cnt<<" "<<(sum^mex^cnt)<<"\n";
		}
	}
	return 0;
}
