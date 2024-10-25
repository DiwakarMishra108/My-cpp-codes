#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void reverse(string &sr,int i,int j){
    if(i>j){
        return;
    }
    swap(sr[i],sr[j]);
    i++;
    j--;
    reverse(sr,i,j);
}
int main(){
    string str="raghav";
    reverse(str,0,str.size()-1);
    cout<<str;
    return 0;
}