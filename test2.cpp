using namespace std;
#include <iostream>

int mysum(int a, int b){return a+b;}

//int mysum(int a, int b, int c){return a+b+c;}

int main(){
    auto p = mysum;
    int ans = p(2,3);
    cout<<ans<<endl;
}