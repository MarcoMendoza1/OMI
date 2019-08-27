#include <bits/stdc++.h>
using namespace std;

int n,cont,mx,ant;
vector<string> rs;

bool vis[10000002];
int arr[10000002];
int res[10000002];
int st[20000002];
long long int org[10000002];
pair<long long int,int> num[10000002];

int query(int nodo,int ini,int fn,int x,int y){
	if(ini>y || fn<x){
		return 0;
		
	}else if(ini>=x && fn<=y){
		return st[nodo];
		
	}
	
	return max(query(nodo*2,ini,(ini+fn)/2,x,y),query(nodo*2+1,(ini+fn)/2+1,fn,x,y));
	
}

void update(int nodo,int ini,int fn,int x,int val){
	if(ini==x && fn==x){
		return st[nodo]=val;
		
	}else if(x>fn || x<ini)
		return st[nodo];
	
	}
	
	st[nodo]=max(update(nodo*2,ini,(ini+fn)/2,x,val),update(nodo*2+1,(ini+fn)/2+1,fn,x,,val));
	
}

int main(){
	rs.clear();
	while(cin>>num[++n].first){
		num[n].second=n;
		org[n]=num[n].first;
		cout<<num[n].first<<" ";
		
	}
	cout<<endl;
	
	n--;
	
	sort(num+1,num+1+n);
	
	for(int i=1;i<=n;i++){
		arr[num[i].second]=++cont;
		
		while(i<n && num[i].first==num[i+1].first){
			i++;
			arr[num[i].second]=cont;
			
		}
		
	}
	
	/*for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
		
	}
	cout<<endl;*/
	
	for(int i=1;i<=n;i++){
		mx=max(mx,(res[i]=query(1,n,1,arr[i]-1)+1));
		
		cout<<res[i]<<" ";
 
		update(arr[i]);
		
	}
	
	cout<<endl;
	
	cout<<mx<<endl<<'-'<<endl;
	
	int i=n;

while(res[i]!=mx){
 i--;
 
}
ant=i--;
rs.push_back(to_string(org[ant]));

for(;i>=1;i--){
 if(res[i]==(res[ant]-1) && arr[i]<arr[ant]){
  rs.push_back(to_string(org[i]));
  ant=i;
 
 }
	
}

for(int i=rs.size()-1;i>=0;i--){
 cout<<rs[i]<<'\n';
 
}

}
