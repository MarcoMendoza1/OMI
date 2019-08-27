#include <bits/stdc++.h>
using namespace std;

int n,cont,mx,ant;

bool vis[10000002];
int arr[10000002];
int res[10000002];
int st[20000002];
long long int org[10000002];
pair<long long int,int> num[10000002];

vector<string> rs;

int query(int nodo,int ini,int fn,int x,int y){
	if(ini>y || fn<x){
		return 0;
		
	}else if(ini>=x && fn<=y){
		return st[nodo];
		
	}
	
	return max(query(nodo*2,ini,(ini+fn)/2,x,y),query(nodo*2+1,(ini+fn)/2+1,fn,x,y));
	
}

int update(int nodo,int ini,int fn,int x,int val){
	if(ini==x && fn==x){
		return st[nodo]=val;
		
	}else if(fn<x || ini>x){
		return st[nodo];
	
	}
	
	return st[nodo]=max(update(nodo*2,ini,(ini+fn)/2,x,val),update(nodo*2+1,(ini+fn)/2+1,fn,x,val));
	
}

int main(){
	rs.clear();
	while(cin>>num[++n].first){
		num[n].second=n;
		org[n]=num[n].first;
		//cout<<num[n].first<<" ";
		
	}
	//cout<<endl;
	
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
	
	int val;
	
	for(int i=1;i<=n;i++){
		val=query(1,1,n,1,max(arr[i]-1,1))+1;
		
		mx=max(mx,val);
		res[i]=val;
		
		update(1,1,n,arr[i],val);
		
	}
	
	int i=n;
	
	while(res[i]!=mx){
		i--;
		
	}
	ant=i;
	rs.push_back(to_string(org[i]));
	
	for(;i>=1;i--){
		//cout<<ant<<" "<<i<<" "<<res[i]<<" "<<arr[i]<<" "<<res[ant];
		if(res[i]==(res[ant]-1) && arr[i]<arr[ant]){
			//cout<<"-----";
			rs.push_back(to_string(org[i]));
			ant=i;

		}
		//cout<<endl;
		
	}
	
	cout<<mx<<endl<<'-'<<endl;
	
	for(int i=rs.size()-1;i>=0;i--){
		cout<<rs[i]<<endl;
		
	}
	
	return 0;

}
