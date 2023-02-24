/*The Linear Search algorithm in C sequentially checks each element of the list until the key element is found or the entire list has been traversed. Therefore, it is known as a sequential search. The time complexity of the linear search algorithm in C is O(n), and space complexity is O(1).*/
#include<stdio.h>

int main() {
  // declaration of the array and other variables
  int arr[20], size, key, i, index;
  printf("Number of elements in the list: ");
  scanf("%d", &size);

  printf("Enter elements of the list: ");
  // loop for the input of elements from 0 to number of elements-1
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  printf("Enter the element to search ie. key element: ");
  scanf("%d", &key);

  // loop for traversing the array from 0 to the number of elements-1
  for (index = 0; index < size; index++)
    if (arr[index] == key) // comparing each element with the key element
      break; // cursor out of the loop when a key element found

  if (index < size) // condition to check whether previous loop partially traversed or not
    printf("Key element found at index %d", index); // printing the index if key found
  else
    printf("Key element not found");

  return 0;
}
