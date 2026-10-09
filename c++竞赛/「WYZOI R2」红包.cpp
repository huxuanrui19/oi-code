#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;ll sum=0;
	cin>>n;
	while(n--){
		string s;ll num;
		cin>>s>>num;
		if(s=="Q") sum+=num;
	} 
	cout<<sum;
	return 0;
}

