#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<long long> a, vector<long long> b){
    return a[1]>b[1];
}

int main(){
    ifstream fin ("rental.in");
    ofstream fout("rental.out");
    long long n,m,r;
    fin>>n>>m>>r;
    vector<long long> cows;
    for (long long i=0;i!=n;i++){
        long long x;
        fin>>x;
        cows.push_back(x);
    }
    sort(cows.begin(),cows.end(),greater<>());
    vector<vector<long long>> milk;
    for (long long i=0;i!=m;i++){
        long long a,b;
        fin>>a>>b;
        milk.push_back({a,b});
    }
    sort(milk.begin(),milk.end(),compare);
    vector<long long> rent;
    for (long long i=0; i!=r;i++){
        long long a;
        fin>>a;
        rent.push_back(a);
    }
    if (rent.size()<cows.size()){
        for (long long i=rent.size();i!=cows.size();i++){
            rent.push_back(0);
        }
    }
    sort(rent.begin(),rent.end());
    rent.resize(n);
    vector<long long> p;
    long long stop;
    long long res=0;
    long long curr=0;
    for (long long i=0;i!=n;i++){
        long long add=0;
        for(long long j=curr;j!=m;j++){
            if (milk[j][0]<cows[i]){
                curr++;
                add+=(milk[j][0]*milk[j][1]);
                cows[i]-=milk[j][0];
            }
            else{
                add+=(cows[i]*milk[j][1]);
                milk[j][0]-=cows[i];
                break;
            }
        }
        if (rent[i]>=add){
            stop=i;
            break;
        }
        else{
            res+=add;
        }
    }
    for(long long i=stop;i!=n;i++) res+=rent[i];
    fout<<res<<"\n";
}