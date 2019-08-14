#include <bits/stdc++.h>
using namespace std;

int n,m,t,s,cont;
bool pt[1024003];

char lz[2048013];
int st[2048013];

//0 Barbary, 1 Buccaneer

int init(int nodo, int ini,int fn){
	if(ini==fn){
		return st[nodo]=pt[ini];
	 
	}

	return st[nodo]=init(nodo*2,ini,(fn+ini)/2)+init(nodo*2+1,(ini+fn)/2+1,fn);

}

void checaLazy(int nodo,char op){
	if(lz[nodo]=='0'){
		lz[nodo]=op;
		
	}else{
		if((lz[nodo]=='F' || lz[nodo]=='E') && op=='I'){
			if(lz[nodo]=='F'){
				lz[nodo]='E';
				
			}else{
				lz[nodo]='F';
				
			}
			
		}else if(op!='I'){
			lz[nodo]=op;
			
		}else{
			lz[nodo]='0';
			
		}
		
	}
	
}

void lzy(int nodo,int ini,int fn,int x,int y,char op){
	if(ini>=x && fn<=y){
		checaLazy(nodo,op);
		return;
	 
	}else if(fn<x || ini>y){
		return;
	 
	}
	
	lzy(nodo*2,ini,(ini+fn)/2,x,y,op);
	lzy(nodo*2+1,(ini+fn)/2+1,fn,x,y,op);

}

int query(int nodo,int ini,int fn,int x,int y){
	if(lz[nodo]!='0'){
		if(lz[nodo]=='F'){
			st[nodo]=fn-ini+1;
		
		}else if(lz[nodo]=='E'){
			st[nodo]=0;
			
		}else{
			int pr;
			pr=fn-ini+1;
			
			st[nodo]=pr-st[nodo];
			
		}
		
		if(ini!=fn){
			checaLazy(nodo*2,lz[nodo]);
			checaLazy(nodo*2+1,lz[nodo]);
			
		}
		
		lz[nodo]='0';
	
	}
	
	if(ini>y || fn<x){
		return 0;
		
	}else if(ini>=x && fn<=y){
		return st[nodo];
		
	}
	
	return query(nodo*2,ini,(ini+fn)/2,x,y)+query(nodo*2+1,(ini+fn)/2+1,fn,x,y);
	

}

int main() {
	cin>>t;
	
	string aux;
	char tipo;
	
	int aux1,aux2;
	for(int q=1;q<=t;q++){
		cont=1;
		cin>>m;
		
		n=0;
		for(int i=1;i<=m;i++){
			cin>>s>>aux;
			
			n+=aux.size()*m;
			
			for(int j=1;j<=s;j++){
				for(char a:aux){
					pt[cont++]=a-'0';
					
				}
				
			}
			
		}
		
		for(int i=1;i<=n;i++){
			lz[i]='0';
			
		}
		
		cout<<"Case "<<q<<":"<<'\n';
		
		cin>>m;
		
		cont=1;
		for(int i=1;i<=m;i++){
			cin>>tipo>>aux1>>aux2;
			
			if(tipo!='S'){
				lzy(1,1,n,aux1,aux2,tipo);
				
			}else{
				cout<<"Q"<<cont++<<": "<<query(1,1,n,aux1,aux2)<<'\n';
				
			}
			
		}
		
	}
	
	return 0;
}
