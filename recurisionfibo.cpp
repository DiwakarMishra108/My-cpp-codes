#include<iostream>
using namespace std;
int fibo(int a){
    if(a==0)return 0;
    if(a==1)return 1;
    int ans = fibo(a-1)+fibo(a-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number to print fibonachi"<<endl;
    cin>>n;
   cout<<fibo(n)<<endl;
    return 0;
}