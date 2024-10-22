#include<iostream>
#include<string>
using namespace std;
void saydigit(int n ,string arr[]){
    if(n==0)return ;
    int digit=n%10;
    n=n/10;
    saydigit(n,arr);
    cout<<arr[digit]<<" ";
}
int main(){
    int n;
    string arr[10]={"Zero","one","two","three","four","five","six","seven","eight","nine"};
    cout<<"Enter a number"<<endl;
    cin>>n;
    saydigit(n,arr);
}