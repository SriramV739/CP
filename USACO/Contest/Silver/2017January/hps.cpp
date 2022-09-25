#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ifstream fin ("hps.in");
    ofstream fout ("hps.out");
    int n;
    fin>>n;
    vector<int> p={0},h={0},s={0};
    int ptotal=0,stotal=0,htotal=0;
    for (int i=0;i!=n;i++){
        string a;
        fin>>a;
        if(a=="P"){
            ptotal++;
        }
        else if(a=="S"){
            stotal++;
        }
        else if (a=="H"){
            htotal++;
        }
        p.push_back(ptotal);
        s.push_back(stotal);
        h.push_back(htotal);
    }

    int res=0;
    for (int i=0;i!=p.size();i++){
        res=max(res,max({p[i],s[i],h[i]})+max({ptotal-p[i],stotal-s[i],htotal-h[i]}));
    }
    fout<<res<<"\n";

}