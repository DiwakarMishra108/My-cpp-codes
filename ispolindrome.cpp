#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool ispolindrome(string sr,int i, int j){
  if(i>j){
    return true;
  }
  if(sr[i]!=sr[j]){
    return false;
  }
  i++;
  j--;
  ispolindrome(sr,i,j);
}
int main(){
    string str="abar";
    if(ispolindrome(str,0,str.size()-1)){
        cout<<"it is a polindrome";
    }
    else
      cout<<"not a polindrome";
}