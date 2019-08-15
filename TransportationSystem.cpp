#include <bits/stdc++.h>
using namespace std;

struct city{
	int x,y;	
	
};

struct arista{
	int a,b;
	double peso;
	
};

bool operator<(arista a,arista b){
	return a.peso>b.peso;
	
}

int t,n,m;

city cd[1002];

priority_queue<arista>mont;

int main() {
	cin>>t;
	
	double rd=0,rrd=0;
	arista g;
	for(int q=1;q<=t;q++){
		aristas.clear();
		cin>>n>>m;
		
		for(int i=1;i<=n;i++){
			cin>>cd[i].x>>cd[i].y;
			
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<>=n;j++){
				if(j!=i){
					g.a=i;
					g.b=j;
					g.peso=sqrt( pow((cd[j].y-cd[i].y),2) + pow((cd[j].x-cd[i].x), 2) );
					
					mont.push(g);
					
				}
				
			}
			
		}
		
		
		
	}
	return 0;
}
