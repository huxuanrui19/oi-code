#include<bits/stdc++.h>
using namespace std;
bool check(int x){
	int y=x,sum=0;
	while(x){
		sum+=pow(x%10,4);
		x/=10;
	}
	if(sum==y){
		return 1;
	}
	return 0;
}
int main(){
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		if(check(i)){
			cout<<i<<" ";
		}
	}
	return 0;
}
