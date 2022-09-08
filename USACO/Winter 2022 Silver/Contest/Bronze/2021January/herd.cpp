#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string alph,word;
    cin>>alph>>word;
    int res=1;
    for (int i=1;i!=word.size();i++){
        auto a=alph.find(word[i-1]);
        auto b=alph.find(word[i]);
        if(a>=b){
            res++;
        }

    }
    cout<<res<<"\n";
    
}