#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(1);
    cout<<pq.top();
}