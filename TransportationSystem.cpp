#include <bits/stdc++.h>
using namespace std;
 
struct city{
	int x,y;	
	
};
 
struct arista{
	int a,b;
	float peso;
	
};
 
bool operator<(arista a,arista b){
	return a.peso>b.peso;
	
}
 
int t,n,m;

int padre[1002];
city cd[1002];
 
priority_queue<arista>mont;
 
int raiz(int nodo){
	if(padre[nodo]!=nodo){
		padre[nodo]=raiz(nodo);
		
	}
	
	return padre[nodo];
	
}

void une(int a,int b){
	padre[raiz(a)]=raiz(b);
	
}
 
int main() {
	cin>>t;
	
	int cont;
	float rd=0,rrd=0;
	arista g;
	for(int q=1;q<=t;q++){
		cont=0;
		rd=rrd=0.0;
		while(!mont.empty()){
			mont.pop();
			
		}
		cin>>n>>m;
		
		for(int i=1;i<=n;i++){
			padre[i]=i;
			
		}
		
		for(int i=1;i<=n;i++){
			cin>>cd[i].x>>cd[i].y;
			
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					g.a=i;
					g.b=j;
					g.peso=sqrt( pow((cd[j].y-cd[i].y),2) + pow((cd[j].x-cd[i].x), 2) );
					
					mont.push(g);
					
				}
				
			}
			
		}
		
		while(!mont.empty()){
			g=mont.top();
			mont.pop();
			
			if(raiz(g.a)!=raiz(g.b)){
				une(g.a, g.b);
				
				if(g.peso>m){
					cont++;
					rrd+=g.peso;
					
				}else{
					rd+=g.peso;
					
				}
				
			}
			
		}
		
		cout<<"Case #"<<q<<": "<<cont<<" "<<rd<<" "<<rrd<<endl;
		
	}
	return 0;
}
 
