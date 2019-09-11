#include<bits/stdc++.h>
using namespace std;

int n,m,k,ver,hor,aux;

int tab[105][105];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>n>>m>>k;
	
	if(n==0 || m==0){
		cout<<endl;
		return 0;
		
	}

	for(int i=1;i<=k;i++){
		cin>>aux;

		if(aux==1){
			ver++;

		}else if(aux==2){
			ver--;

		}else if(aux==3){
			hor++;

		}else{
			hor--;

		}

	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>tab[j][i];

		}

	}

	ver=ver%m;
	hor=hor%n;

	//cout<<ver<<" "<<hor<<'\n';

	int x=hor;
	int y=ver;

	if(0>x){
		x=n+x;

	}

	if(0>y){
		y=m+y;

	}

	x++;
	y++;
	//cout<<x<<" "<<y<<'\n';

	for(int i=1;i<=m;i++){
		if(y>m){
			y=1;

		}

		for(int j=1;j<=n;j++){
			if(x>n){
				x=1;

			}

			cout<<tab[x][y]<<" ";
			//cout<<x<<" "<<y<<" ";

			x++;

		}
		cout<<'\n';

		y++;

	}

	return 0;

}
