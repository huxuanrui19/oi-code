#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N][2],flag[N][2]; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;a[i][0]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;a[i][1]=ch-'0';
		}
		int mark=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]==1){
				if(i>1&&a[i-1][0]==0&&flag[i-1][0]==0) flag[i-1][0]=1;
				else if(a[i][1]==0&&flag[i][1]==0) flag[i][1]=1;
				else if(i<n&&a[i+1][0]==0&&flag[i+1][0]==0) flag[i+1][0]=1;
				else mark=1;
			}
			if(a[i][1]==1){
				if(i>1&&a[i-1][1]==0&&flag[i-1][1]==0) flag[i-1][1]=1;
				else if(a[i][0]==0&&flag[i][0]==0) flag[i][0]=1;
				else if(i<n&&a[i+1][1]==0&&flag[i+1][1]==0) flag[i+1][1]=1;
				else mark=1;
			}
		}
		for(int i=1;i<=n;i++) flag[i][1]=flag[i][0]=0;
		if(mark==1) cout<<"++\n";
		else cout<<"RP\n";
	}
	return 0;
}

