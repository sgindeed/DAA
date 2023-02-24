/*In this method, the Knapsack's filling is done so that the maximum capacity of the knapsack is utilized so that maximum profit can be earned from it. The knapsack problem using the Greedy Method is referred to as:
Given a list of n objects, say {I1, I2,……, In) and a knapsack (or bag).
The capacity of the knapsack is M.
Each object Ij has a weight wj and a profit of pj
If a fraction xj (where x ∈ {0...., 1)) of an object Ij is placed into a knapsack, then a profit of pjxj is earned.
The problem (or Objective) is to fill the knapsack (up to its maximum capacity M), maximizing the total profit earned.*/

/*Knapsack Problem Using Greedy Method Pseudocode
A pseudo-code for solving knapsack problems using the greedy method is;
greedy fractional-knapsack (P[1...n], W[1...n], X[1..n]. M)
/*P[1...n] and W[1...n] contain the profit and weight of the n-objects ordered such that X[1...n] is a solution set and M is the capacity of knapsack*/
//{

//For j ← 1 to n do
//X[j]← 0
//profit ← 0 // Total profit of item filled in the knapsack
//weight ← 0 // Total weight of items packed in knapsacks
//j ← 1
//While (Weight < M) // M is the knapsack capacity*/

# include<stdio.h>
 
void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   tp = tp + (x[i] * profit[i]);
 
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nMaximum profit is:- %f", tp);
 
}
 
int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;
 
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);
 
   printf("\nEnter the wts and profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }
 
   printf("\nEnter the capacityacity of knapsack:- ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
 
   knapsack(num, weight, profit, capacity);
   return(0);
}