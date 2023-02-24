/*Binary Search in C is generally used to solve various issues in computer science and real-world scenarios related to searching.

We have many search algorithms like Linear Search or Sequential Search, Binary Search, Jump Search, Fibonacci Search, etc., and one of the most efficient is the Binary Search algorithm.

In linear search, we compare the element found with each array element from the start to the end of an array (the array elements can be arranged in any order). If the target element is found in the array, we return the index of the element, else, we return -1, indicating that the target element is not found. It takes O(n) time to find an element, while the binary search takes only O(log N) time. */

/*Binary Search in C is a searching algorithm that allows us to find a specific element in a sorted list/array of elements. It uses a variation of the Divide and Conquer approach, in which a large list is gradually broken down into smaller lists over several iterations. Each iteration removes a portion of the list from the search until the last element is reached or the needed element is found, whichever comes first.

In binary search, we reduce the search space at each iteration, find the mid index, and compare the middle element with the target element. If the target element is bigger than the middle element, we reduce the array to the right half, beginning with the mid + 1 (just next to mid) index. If the target element is smaller than the middle element, we reduce the array to the left half only, ending before the mid - 1 index (just before the mid).

Now suppose, we are provided with a sorted array and a target element (let's say k), and we want to search if k exists in the array or not and if k does exist in the array, we return the index/position of k in the array.*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void * m,const void * n) {
  return ( * (int * ) m - * (int * ) n);
}

int main() {

  int arr[6] = {1,5,19,26,31,69};
  int * element;
  int key; // search element

  printf("Enter the target element: ");
  scanf("%d", & key);

  /* bsearch() is being used to find the value 31 in the array. */
  element = (int * ) bsearch( & key, arr, 6, sizeof(int), compare);

  if (element != NULL) 
  {
    printf("\n%d is found in the array", * element);
  } 
  else 
  {
    printf("\n%d could not be found in the array", key);
  }

  return (0);
}
