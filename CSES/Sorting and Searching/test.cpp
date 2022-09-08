#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    multiset<int> ms;
    ms.insert(2);
    ms.insert(1);
    ms.erase(ms.find(*ms.rbegin()));
}
