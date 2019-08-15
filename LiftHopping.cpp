#include <bits/stdc++.h>
using namespace std;

struct estado{
    int piso,elv;
    int tmp;

};

bool operator<(estado a, estado b){
    return a.tmp>b.tmp;

}

int n,k;

int t[7];
int vis[105][7];
int gr[105][7];

priority_queue<estado>mont;

int dijk(){
    estado act;
    while(!mont.empty()){
        act=mont.top();
        mont.pop();

        if(!vis[act.piso][act.elv]){
            vis[act.piso][act.elv]=true;

            if(act.piso==k){
                return act.tmp;

            }

            for(int i=1;i<=n;i++){
                if(gr[act.piso][i] && i!=act.elv){
                    mont.push({act.piso,i,act.piso+60});

                }

            }

            for(int i=0;i<=100;i++){
                if(i!=act.piso && gr[i][act.elv]){
                    mont.push({i,act.elv,abs(i-act.piso)*t[act.elv]});

                }

            }

        }

    }

    return -1;

}

int main(){
    string aux;
    int niv;
    while(cin>>n){
        cin>>k;

        for(int i=1;i<=n;i++){
            cin>>t[i];

        }

        while(!mont.empty()){
            mont.pop();

        }

        for(int i=0;i<=102;i++){
            for(int j=1;j<=n;j++){
                gr[i][j]=0;
                vis[i][j]=0;

            }

        }

        for(int i=1;i<=n;i++){
            getline(cin,aux);
            getline(cin,aux);

            for(int j=0;j<aux.size();j++){
                if(aux[j]>='0' && aux[j]<='9'){
                    int k;
                    k=j;
                    while(aux[k]>='0' && aux[k]<='9' && j<aux.size()){
                        k++;

                    }

                    niv=stoi(aux.substr(j,k-j));
                    j=k;

                    gr[niv][i]=1;

                }

            }

        }

        for(int i=1;i<=n;i++){
            if(gr[0][i]){
                mont.push({0,i,0});

            }

        }

        int res;
        res=dijk();

        if(res!=-1){
            cout<<res<<'\n';

        }else{
            cout<<"IMPOSSIBLE"<<'\n';

        }

    }

    return 0;
}
