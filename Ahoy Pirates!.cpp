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
		cout<<ini<<" "<<fn<<" "<<st[nodo]<<endl;
		return;
	 
	}else if(fn<x || ini>y){
		return;
	 
	}
	
	lzy(nodo*2,ini,(ini+fn)/2,x,y,op);
	lzy(nodo*2+1,(ini+fn)/2+1,fn,x,y,op);
 
}
 
int query(int nodo,int ini,int fn,int x,int y){
	if(lz[nodo]!='0'){
		cout<<ini<<" "<<fn<<" "<<st[nodo]<<" "<<lz[nodo]<<" ";
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
		
		cout<<st[nodo]<<endl;
		
		lz[nodo]='0';
	
	}else{
		cout<<ini<<" "<<fn<<" "<<st[nodo]<<endl;
		
	}
	
	if(ini>y || fn<x){
		return 0;
		
	}else if(ini>=x && fn<=y){
		return st[nodo];
		
	}
	
	int res=query(nodo*2,ini,(ini+fn)/2,x,y)+query(nodo*2+1,(ini+fn)/2+1,fn,x,y);
	
	if(ini!=fn){
		st[nodo]=st[nodo*2]+st[nodo*2+1];
		
	}
	
	return res;
	
}
 
int main() {
	cin>>t;
	
	string aux;
	char tipo;
	
	int aux1,aux2;
	for(int q=1;q<=t;q++){
		cont=0;
		cin>>m;
		
		n=0;
		for(int i=1;i<=m;i++){
			cin>>s>>aux;
			
			n+=aux.size()*s;
			
			for(int j=1;j<=s;j++){
				for(int a=0;a<aux.size();a++){
					pt[cont++]=aux[a]-'0';
					
				}
				
			}
			
		}
		init(1,0,n-1);
		
		for(int i=0;i<2048011;i++){
			lz[i]='0';
			
		}
		
		cout<<"Case "<<q<<":"<<'\n';
		
		cin>>m;
		
		cont=1;
		for(int i=1;i<=m;i++){
			cin>>tipo>>aux1>>aux2;
			
			if(tipo!='S'){
				cout<<tipo<<" "<<aux1<<" "<<aux2<<endl;
				lzy(1,0,n-1,aux1,aux2,tipo);
				
			}else{
				query(1,0,n-1,aux1,aux2);
				cout<<"Q"<<cont++<<": "<<'\n';
				
			}
			
		}
		
	}
	
	return 0;
}
 
