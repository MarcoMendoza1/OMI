#include <bits/stdc++.h>
using namespace std;

int n,x,y,c;

bool checa(int t){
	long long int total=0;
	total=2*t*t+2*t+1;
	
	long long int f;
	
	if((y-t)<1){
		f=t-(y-1);
		
		total-=f*f;
		
	}
	
	if((x+t)>n){
		f=t-(n-x);
		
		total-=f*f;
		
	}
	
	
	if((y+t)>n){
		f=total-(n-x);
		
		total-=f*f;
		
	}
	
	
	if((x+t)>n){
		f=t-(n-x);
		
		total-=f*f;
		
	}
	
}

long long int bin(){
	long long int ini=0;
	long long int fn=200000000;
	long long int med;
	
	while(ini!=fn){
		med=(ini+fn)/2;
		if(checa(med)){
			fn=med;
			
		}else{
			ini=med+1;
			
		}
		
	}
	
}

int main() {
	cin>>n>>x>>y>>c;
	
	cout<<bin();
	
	return 0;
}
