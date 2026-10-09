#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n){
		cout<<(n%2?"Bob":"Alice")<<endl;
		cin>>n;
	}
	return 0;
} 
