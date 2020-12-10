#include <iostream>  //by brute force: O(n^2)..for counting inversion...by this method we count inversion in O(nlogn)..
using namespace std;

long long merge(int arr[], int l, int mid, int r) {

    long long inv =0;

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];  //temp arrays....


    for(int i=0; i<n1; i++) {
        a[i] = arr[l + i];
    }

    for(int i=0; i<n2; i++) {
        b[i] = arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2) {
        if(a[i]<b[j]) {
            arr[k]= a[i];
            k++; i++;
        } else {
            arr[k]= b[j];
            inv += n1-i; //main step for counting inv
            k++; j++;
        }
    }

    while(i<n1) { //corner cases.....
        arr[k]= a[i];
        k++; i++;
    }

    while(j<n2) { //corner cases.....
        arr[k]= b[j];
        k++; j++;
    }

    return inv;
}

long long mergeSort(int arr[],int l, int r) {

    long long inv =0;

    if(l<r) {

        int mid =((l+r)/2);

        inv += mergeSort(arr,l,mid);
        inv += mergeSort(arr,mid+1,r);


        inv += merge(arr,l,mid,r); //merge karne ke liye n time laga...

    }

    return inv;

}


int main() {

    
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<< mergeSort(arr,0,n-1);

}