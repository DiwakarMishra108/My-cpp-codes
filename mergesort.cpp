#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid= (s+e)/2;
    int l1= mid-s+1;
    int l2= e-mid+1;
    int*first=new int(l1);
    int*second= new int(l2);
    // copy values
    int mainArrayindex=s;
    for(int i=0;i<l1;i++){
        first[i]=arr[mainArrayindex++];
    }
    mainArrayindex=mid+1;
    for(int i=0;i<l2;i++){
        second[i]=arr[mainArrayindex++];
    }
    // merge two sorted array
    int index1=0;
    int index2=0;
    mainArrayindex=s;
    while(index1<l1 && index2<l2){
        if(first[index1]<second[index2]){
            arr[mainArrayindex++]= first[index1++];
        }
        else{
            arr[mainArrayindex++]=second[index2++];
        }
    }
    while(index1<l1){
        arr[mainArrayindex++]=first[index1++];
    }
    while(index2<l2){
        arr[mainArrayindex++]=second[index2++];
    }

}
void mergeSort(int *arr,int s,int e){
  if(s>= e){
    return ;
    }
  int mid=(s+e)/2;
//   left part sort karana hai
  mergeSort(arr,s,mid);
//   right part sort karana hai
 mergeSort(arr,mid+1,e);
//  merge karana hai
 merge(arr,s,e);
}
int main(){
    int arr[5]={2,5,1,6,9};
    int n=5;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}