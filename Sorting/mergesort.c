/*Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then it merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. */

/*Pseudocode :

• Declare left variable to 0 and right variable to n-1 
• Find mid by medium formula. mid = (left+right)/2
• Call merge sort on (left,mid)
• Call merge sort on (mid+1,rear)
• Continue till left is less than right
• Then call merge function to perform merge sort.*/

/*Algorithm:

Step 1: Start
Step 2: Declare an array and left, right, mid variable 
Step 3: Perform merge function.
        mergesort(array,left,right)
        mergesort (array, left, right)
        if left > right
        return
        mid= (left+right)/2
        mergesort(array, left, mid)
        mergesort(array, mid+1, right)
        merge(array, left, mid, right)
Step 4: Stop*/

// C program for Merge Sort
#include <stdio.h>

#define max 10

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
   int i;

   printf("List before sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   sort(0, max);

   printf("\nList after sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}