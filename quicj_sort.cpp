//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends


class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            // Find the pivot element such that
            // elements smaller than the pivot are on the left
            // and elements greater than the pivot are on the right.
            int pi = partition(arr, low, high);

            // Recursively call quicksort on the left and right subarrays.
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Function to partition the array and return the pivot index.
    int partition(int arr[], int low, int high)
    {
        // Choose the rightmost element as the pivot.
        int pivot = arr[high];

        // Index of the smaller element.
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            // If the current element is smaller than or equal to the pivot,
            // swap arr[i+1] and arr[j] and increment the smaller element index.
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        // Swap the pivot element with the element at (i+1)th position.
        swap(arr[i + 1], arr[high]);

        // Return the pivot index.
        return (i + 1);
    }
};





//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends