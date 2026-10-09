#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int l=1,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		cout<<mid<<endl;
		int flag;
		cin>>flag;
		if(flag==0) return 0;
		if(flag==1) r=mid-1;
		else l=mid+1;
	}
	return 0;
}

