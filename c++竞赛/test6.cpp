#include<bits/stdc++.h>
using namespace std;
int func(int n){
	static int count=0;
	count++;
	if(n<1){
		return count;
	}
	return func(n-2)+func(n-1);
} 
int main(){
	cout<<func(3);
	return 0;
}
