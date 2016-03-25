/*
Roll No: 101453006
Name: Rishabh Kumar Saini
Group: COE9
Question: 11
*/
# include<stdio.h>
#include<iostream>
using namespace std;
struct node {
   int data;
   node *left;
   node *right;
};
void inputData(node *A[10], int *n)
{
   cin >> *n;
   for (int i = 0; i<*n; i++)
   {
      A[i] = new node;
      cin >> A[i]->data;
      A[i]->left = NULL;
      A[i]->right = NULL;
   }
}
void showData(node* A[10], int n)
{
   for (int i = 0; i<n; i++)
      cout << A[i]->data<<" ";
   cout << endl;
}
void input(int* A, int *n)
{
   cin >> *n;
   for (int i = 0; i<*n; i++)
      cin >> A[i];
}
void show(int* A, int n)
{
   //cin>>n;
   for (int i = 0; i<n; i++)
      cout << A[i] << " ";
   cout << endl;
}
int left(int i)
{
   return 2 * i + 1;
}
int right(int i)
{
   return 2 * i + 2;
}
int parent(int i)
{
   return (i - 1) / 2;
}
void minHeapify(node *A[], int n, int i)
{
   int flag = 1;
   while (left(i)<n && flag == 1)
   {
      flag = 0;
      int largest = i;
      if (A[left(i)]->data<A[i]->data)
         largest = left(i);
      if (right(i)<n && A[right(i)]->data<A[largest]->data)
         largest = right(i);
      if (largest != i)
      {
         int temp = A[largest]->data;
         A[largest]->data = A[i]->data;
         A[i]->data = temp;
         flag = 1;
         i = largest;
      }
   }
}
void buildMinHeap(node *A[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
      minHeapify(A, n, i);
}
void insertIntoPriorityQueue(node *A[], int *n, node **a)
{
   A[(*n)] = *a;
   /*A[*n] = new node;
   A[*n]->data = (*a)->data;
   A[*n]->left = (*a)->left;
   A[*n]->right = (*a)->right;
   */int i = (*n);
   while (i >= 0 && A[parent(i)]->data>A[i]->data)
   {
      node *temp = A[parent(i)];
      A[parent(i)] = A[i];
      A[i] = temp;
      i = parent(i);
   }
   showData(A, (*n)+1);
   cout <<A[*n]->data<< A[*n]->left->data << A[*n]->right->data;
   (*n) += 1;
}
node* fetchFromPriorityQueue(node *A[], int *n)
{
   (*n) -= 1;
   node* temp = A[*n];
   A[*n] = A[0];
   A[0] = temp;
   minHeapify(A, *n, 0);
   return A[*n];
}
void createEncodingTree(node *A[], int *n)
{
   int i = *n;
   while (i-- > 1)
   {
      node *a = fetchFromPriorityQueue(A, n);
      node *b = fetchFromPriorityQueue(A,n);
      node *c = new node;
      c->data = a->data + b->data;
      c->left = a;
      c->right = b;
      insertIntoPriorityQueue(A, n, &c);
   }
}
////////knapsack
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

   cout<<"\nThe output matrix is:- ";
   for (i = 0; i < n; i++)
      cout<<x[i];

   cout<<"\nMaximum profit is:- "<<tp;

}

int main()
{
   node *A[10];
   int n;
   ///*
   cin >> n;
   for (int i = 0; i<n; i++)
   {
      A[i] = new node;
      cin >> A[i]->data;
      A[i]->left = A[i]->right = NULL;
   }
   buildMinHeap(A, n);
   showData(A, n);
   createEncodingTree(A,&n);
   showData(A, n);
   //knapsack....................................................
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
   return 0;
}









