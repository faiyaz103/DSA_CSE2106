#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){

    vector<int> L(arr.begin()+left, arr.begin()+mid+1);
    vector<int> R(arr.begin()+mid+1, arr.begin()+right+1);

    int i=0, j=0, k=left;

    while(i<L.size() && j<R.size()){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            k++;
            i++;
        }
        else{
            arr[k]=R[j];
            k++;
            j++;
        }
    }

    while(i<L.size()){
        arr[k]=L[i];
        k++;
        i++;
    }

    while(j<R.size()){
        arr[k]=R[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    // base condition
    if(left>=right) return;

    int mid=left+(right-left)/2; // Avoid integer overflow vs (l+r)/2

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){

    vector<int> arr={3,4,1,6,2,9};

    cout<<"Before Sorting"<<endl;
    for (auto i:arr){
        cout<<i<<' ';
    }
    cout<<endl;

    mergeSort(arr, 0, arr.size()-1);

    cout<<"After Sorting"<<endl;
    for (auto i:arr){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}