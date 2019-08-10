#include<bits/stdc++.h>
using namespace std;

int n,m,cont;
int rn[100002];
int fn[100002];
int rg[100002];

int st[200009];

int ini(int nodo,int ii,int f){
if(ii==f){
 return st[nodo]=rg[ii];
 
}

return st[nodo]=max(ini(nodo*2,ii,(ii+f)/2),ini(nodo*2+1,(f+ii)/2+1,f));

}

int query(int nodo,int ii,int f,int x,int y){
if(f<x || ii>y){
 return -1;
 
}else if(ii>=x && f<=y){
 return st[nodo];
 
}

return max(query(nodo*2,ii,(ii+f)/2,x,y),query(nodo*2+1,(ii+f)/2+1,f,x,y));

}

int main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool ii,fi;
int ant,aux1,aux2;
int ri,rf,mx;
while(true){
 cin>>n;
 
 if(n==0){
  return 0;
  
 }
 
 cin>>m;
 
 for(int i=1;i<=n;i++){
  fn[i]=0;
  rn[i]=0;
  rg[i]=0;
  
 }
 
 cont=0;
 ant=100000000;
 for(int i=1;i<=n;i++){
  cin>>aux1;
  
  if(aux1==ant){
   rn[i]=cont;
   rg[cont]++;
   
  }else{
   if(cont!=0){
    fn[cont]=(i-1);
    
   }
   cont++;
   
   rn[i]=cont;
   rg[cont]++;
   
   ant=aux1;
   
  }
  
 }
 
 fn[cont]=(n);
 
 ini(1,1,cont);

 for(int i=1;i<=m;i++){
  cin>>aux1>>aux2;
  
  /*if(i==21){
   cout<<aux1<<" "<<aux2<<endl;
    for(int j=1;j<=n;j++){
   	 cout<<rn[j]<<" ";
  		
  	}
  	
  	cout<<endl<<endl<<cont<<endl;
  	
  	for(int j=1;j<=cont;j++){
  		cout<<fn[j]<<" ";
  		
  	}
  	
  	cout<<endl;
  	
  }*/
  
  if(rn[aux1]==rn[aux2]){
   cout<<(aux2-aux1+1)<<endl;
   
  }else{
   ii=false;
   fi=false;
   ri=aux1;
   rf=aux2;
   if(aux1!=1 && (rn[aux1]==1 || (fn[rn[aux1]-1]+1)!=aux1)){
    ii=true;
    ri=fn[rn[aux1]]+1;
    
   }
   
   if(aux2!=n && (fn[rn[aux2]])!=aux2){
    fi=true;
    rf=fn[rn[aux2]-1];
    
   }
   
   mx=0;
   
   if(rf>=ri){
    mx=query(1,1,cont,rn[ri],rn[rf]);
    
   }
   
   if(ii){
    mx=max(mx,(fn[rn[aux1]]-aux1+1));
    
   }
   
   if(fi){
    mx=max(mx,(aux2-(fn[rn[aux2]-1]+1)+1));
    
   }
   
   cout<<mx<<endl;
   
  }
  
 }
 
}

}
