#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int k;cin>>k;
		for(int i=1;i<=k;i++) cin>>a[n+i];
		int len=n+k,sum=0,mex=-1;
		sort(a+1,a+len+1);
		for(int i=1;i<=len;i++){
			sum^=a[i];
		}
		if(a[1]!=0) mex=0;
		else if(a[1]==0&&len==1) mex=1;
		else{
			for(int i=2;i<=len;i++){
				if((a[i]-a[i-1])>1){
					mex=a[i-1]+1;
					break;
				}
			}
			if(mex==-1) mex=a[len]+1;
		}
		if(sum==mex) cout<<"Right\n";
		else cout<<"Wrong\n";
	}
	return 0;
}

