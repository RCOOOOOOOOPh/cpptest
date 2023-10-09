#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<int> v)
{
    for(int i: v) cout<<i<<" ";
    cout<<endl;
}

int main(){
    //use push_back
    vector<int> v1;
    v1.push_back(114514);
    //2
    vector<int> v2(3, 10);//[10, 10, 10]
    //3
    vector<int> v3{1, 3, 5};
    //4
    int arr[] = {1,1,4,5,1,4};
    vector<int> v4(arr, arr+4);//[1,1,4,5]
    printvec(v4);
    //5
    vector<int> v5(v4.begin(), v4.end()-1);
    printvec(v5);
}