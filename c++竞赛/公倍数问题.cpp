#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long ny[N],my[N];
int main(){
	long long n,m,k;
	cin>>n>>m>>k;
	long long sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=k;j+=i){
			ny[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=k;j+=i){
			my[j]++;
		}
	}
	for(int i=1;i<=k;i++){
		sum+=my[i]*ny[i]*i;
	}
	cout<<sum;
	return 0;
} 
