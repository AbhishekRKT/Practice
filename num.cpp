#include <iostream> 
using namespace std; 
  

void pushZerosToEnd(int arr[], int n) 
{ 
    int count = 0; 
  
    
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            arr[count++] = arr[i]; 
    while (count < n) 
        arr[count++] = 0; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int n; 
    cout << " enter the size of array "<< endl;
    cin >> n;
    int arr[n] ; 
  for(int i=0; i<n; i++)
  {
      int n1;
      cin>> n1;
      arr[i] = n1;
  } 
    pushZerosToEnd(arr, n);
    cout << "Array after pushing all zeros to end of array :\n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 