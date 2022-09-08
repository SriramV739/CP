#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
long long n;
bool check(long long val){
    long long lower=0;
    long long higher=0;
    for (long long i=1;i!=n+1;i++){
        if ((long long) ceil((float) val/(float) i)-1>n) lower+=n;
        else lower+=(long long) ceil((float) val/(float) i)-1;
        higher+=n-(long long) floor((float) val/(float) i);
    }
    if (lower<(long long) (pow(n,2)/2+1)) return true;
    else return false;
}

int main(){
    cin>>n;
    long long lo=0;
    long long hi=pow(n,2);
    while (lo<hi){
        long long middle=(lo+hi+1)/2;
        if (check(middle)) lo=middle;
        else hi=middle-1;
    }
    cout<<lo<<"\n";
}
