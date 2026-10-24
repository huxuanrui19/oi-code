//STL µœ÷ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> v;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int opt,x;
		cin>>opt>>x;
		if(opt==1) v.insert(lower_bound(v.begin(),v.end(),x),x);
		if(opt==2) v.erase(lower_bound(v.begin(),v.end(),x));
		if(opt==3) cout<<(lower_bound(v.begin(),v.end(),x)-v.begin()+1)<<"\n";
		if(opt==4) cout<<v[x-1]<<"\n";
		if(opt==5) cout<<v[lower_bound(v.begin(),v.end(),x)-v.begin()-1]<<"\n";
		if(opt==6) cout<<v[upper_bound(v.begin(),v.end(),x)-v.begin()]<<"\n";
	}
	return 0;
}

