#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+10;
string s[N];
char smax[N],smin[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		smax[i]='a'-1;
		smin[i]='z'+1;
		for(int j=0;j<m;j++){
			smax[i]=max(smax[i],s[i][j]);
			smin[i]=min(smin[i],s[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		int flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(smin[i]>=smax[j]){
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}

