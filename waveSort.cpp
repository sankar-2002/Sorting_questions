#include <iostream>
using namespace std;
void swapWv(int arr[], int i, int j) {

    int temp = arr[i];
    arr[i]= arr[j];
    arr[j]= temp;  

}
void waveSort(int arr[], int n) {


    for(int i=1; i<n; i+=2) {  //as we r traversing n/2 elements..we can say the time Comp --> is O(n)

        if(arr[i]>arr[i-1]) {
            swapWv(arr,i,i-1);
        }

        if(arr[i]>arr[i+1] && i<= n-2) { //i should only go till second last element...
            swapWv(arr,i,i+1);  
        }
    }
}
int main() {

    int arr[] = {1,3,4,7,5,6,2};

    waveSort(arr,7);

    for(int i=0; i<7; i++) {
        cout<<arr[i]<<" ";
    }

}