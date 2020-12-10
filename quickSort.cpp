#include <iostream>  //time comp--> best and avg case --> O(nlogn).....worst case --> O(n^2)..
using namespace std;  //best case-->pivot is the median...worst case mai-->pivot is last element

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j]= temp;
}

int partition(int arr[], int l, int r) {

    int pivot = arr[r]; //declaring last element as pivot...
    int i = l-1;
    for(int j=l; j<r; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);  //as my i will be now at the position which is last element smaller than the pivot after that all the elements are larger than pivot..therefore swap..as pivot's correct position will be i+1..
    return(i+1);
}
void quickSort(int arr[], int l, int r) {

    if(l<r) {

        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
int main() {

    int arr[5]={10,50,45,2,4};

    quickSort(arr,0,4);

    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}