#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
struct node{
	int a,d;
	bool operator < (const node &x){
		return a<x.a;
	}
}arr[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].d;
	}
	sort(arr+1,arr+n+1);
	int cnt=0,j=0,num=n;
	for(int i=1;i<=n;i++){
		while(arr[j].d<arr[i].a&&j<i){
			j++;
			cnt++;
		}
		if(cnt>0) cnt--,num--;
	}
	cout<<num;
	return 0;
}

