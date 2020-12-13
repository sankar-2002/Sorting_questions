#include <iostream>
using namespace std;
void countSort(int arr[], int n) {

    int k = arr[0];

    for(int i=0; i<n; i++) { //finding the max element in arr
        k=max(k,arr[i]);
    }

    int count[10] = {0}; //as it is not possible to dynamically allocate memory in arr as k...therefore make an arr of n+1 and initialize with zero..

    for(int i=0; i<n; i++) { //storing the count of elements of arr in count arr...
        count[arr[i]]++;
    }

    for(int i=1; i<=  k ; i++) {  //modifying the count arr
        count[i]+=count[i-1];
    }

    int outputArr[n]; // creating an output arr to store the result..

    for(int i=n-1; i>=0; i--) {
        outputArr[--count[arr[i]]] = arr[i];  //now all the elements are sorted in output arr  
    }

    //copying the output arr in main arr...

    for(int i=0; i<n; i++) {
        arr[i]=outputArr[i];
    }


}
int main() {

    int arr[] = {1,3,2,3,4,1,6,4,3};

    countSort(arr,9);

    for(int i=0; i<9; i++) {
        cout<<arr[i]<<" ";
    }
}

/*Counting Sort:-

Pros:
-Time Complexity O(n) or O(max(Ai,n))...whereas Ai is the max element which we r using to create a count arr
- Compareless sorting

Cons:
-Limited Usage i.e for int
-Memory Consuption

Uses:
- Sort numbers
- find counts of letter from string
- remove duplicate from string
- find kth smallest or biggest element from array within O(N) time.*/ 
