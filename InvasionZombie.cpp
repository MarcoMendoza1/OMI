#include <bits/stdc++.h>
using namespace std;

int n,x,y,c;

bool checa(int t){
	long long int total=0;
	total=2*t*t+2*t+1;
	
	cout<<total<<" ";
	
	long long int tt=0;
	long long int l=0;
	long long int d=0;
	long long int r=0;
	long long int aux=0;
	
	bool top=false;
	bool left=false;
	bool ri=false;
	bool dw=false;
	
	if((y-t)<1){
		tt=t-(y-1);
		top=true;
		
		total-=tt*tt;
		
	}
	
	if((x+t)>n){
		r=t-(n-x);
		ri=true;
		
		total-=r*r;
		
	}
	
	
	if((y+t)>n){
		d=t-(n-y);
		dw=true;
		
		total-=d*d;
		
	}
	
	
	if((x-t)<0){
		l=t-(x-1);
		left=true;
		
		total-=l*l;
		
	}
	
	cout<<tt<<" "<<r<<" "<<d<<" "<<l<<" "<<total<<" ";
	
	if((x+tt-1)>n && (y-r+1)<1){
		aux=(x+t-1)-n;
		
		total+=(aux*(aux+1))/2;
		
	}
	
	if((y+r-1)>n && (x+d-1)>n){
		aux=(y+r-1)-n;
		
		total+=(aux*(aux+1))/2;
		
	}
	
	if((x-d+1)<1 && (y+l-1)>n){
		aux=(y+l-1)-n;
		
		total+=(aux*(aux+1))/2;
		
	}
	
	if((x-tt+1)<1 && (y-l+1)<1){
		aux=1-(x-t+1);
		
		total+=(aux*(aux+1))/2;
		
	}
	
	cout<<ot
	
	if(total>=c){
		return true;
		
	}
	
}

long long int bin(){
	long long int ini=0;
	long long int fn=200000000;
	long long int med;
	
	while(ini!=fn){
		med=(ini+fn)/2;
		
		cout<<ini<<" "<<fn<<" "<<med<<" ";
		
		if(checa(med)){
			fn=med;
			
		}else{
			ini=med+1;
			
		}
		
	}
	
	return ini;
	
}

int main() {
	cin>>n>>x>>y>>c;
	
	cout<<bin()<<endl;
	
	return 0;
}
