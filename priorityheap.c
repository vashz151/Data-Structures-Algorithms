#include <stdio.h>
#include<stdlib.h>
#include<time.h>//for rand() function we need this header file
int *arr,num=0;
int size()//size of array at any given moment
{
  return num;
}
int isEmpty()
{
  if (num=0) return -1;
  else return 1;
}
void swap(int *a,int *b) //swap function, passing address
{
  int t;
  t = *a;
  *a = *b;
  *b = t;
}
int parent(int index) //gives index of parent of given index
{
  return index/2;
}
void heapify(int i)
{
  int largest=i;
  int left=2*i;//since we are starting from index 1
  int right=2*i+1;
  if (left<size() && arr[left]>arr[largest]) largest=left;
  if (right<size() && arr[right]>arr[largest]) largest=right;
  if (largest!=i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(largest);
  }
}
int getMax() //max priority element
{
  return arr[1];
}
int removeMax() //remove maximum priority element
{
  int m=arr[1];
  arr[1]=arr[num];
  num--;
  heapify(1);
  return m;
}
void increase_key(int index, int key) //shift up function, key is the increased value
{
  arr[index]=key;
  while((index>1) && (arr[parent(index)]<arr[index])) 
  {
    swap(&arr[index], &arr[parent(index)]);
    index=parent(index);
  }
}
void decrease_key(int index, int key) //shift down function, key is the decreased value
{
  arr[index]=key;
  heapify(index);
}
void  build_heap()
{
  for(int i=num/2;i>=1;i--)
  {
    heapify(i);
  }
}
void insert(int key)
{
  int i;
  arr[i++]=key;
}
void changeKey(int i, int p) //i is the index for which new value p has to be changed
{
  int old=arr[i];
  arr[i] = p;
  if (p>old) //if new is greater call shift up
  {
    increase_key(i,p);
  }
  else //shift down
  {
    decrease_key(i,p);
  }
}
void display() 
{
  for(int i=1;i<=size();i++) 
  {
    printf("%d ",arr[i]);
  }
}
void removeEle(int i) //removing element at given index
{
  arr[i]=getMax()+1;
  increase_key(i,arr[i]);
  removeMax();
}
int sample()
{
  int r=(rand()) % size(); //generate random number from the range of array elements
  return arr[r];
}
void delRandom()
{
  int r=rand() % size();
  printf("\nRandomly selecting element %d and deleting it from the heap\n",arr[r]);
  removeEle(r); //deleting the element at index r which is random number
}
int main() 
{
  int i,e;
  printf("Enter number of elements:");
  scanf("%d",&num);
  arr=(int *) malloc(sizeof(num*2));
  arr[0]=num;//number of elements is stored in zeroth index
  printf("Enter elements:");
  for(i=1;i<=num;i++)
  {
    scanf("%d",&e);
    insert(e);
  }
  build_heap();
  printf("Priority queue:");
  display();

  printf("\nMaximum priority element: %d",getMax()); 

  printf("\nRemoving element with max priority\n");
  printf("Element %d is removed\n",removeMax());
  printf("Priority queue:");
  display();

  printf("\nEnter the index and new value for increasing key:");
  scanf("%d %d",&i,&e);
  increase_key(i,e);
  printf("Updated priority queue:");
  display();

  printf("\nEnter the index and new value for decreasing key:");
  scanf("%d %d",&i,&e);
  decrease_key(i,e);
  printf("Updated priority queue:");
  display();

  printf("\nEnter the index and new value for changing the key:");
  scanf("%d %d",&i,&e);
  changeKey(i,e);
  printf("Updated priority queue:");
  display();

  printf("\nEnter the index of the element which needs to be removed:");
  scanf("%d",&i);
  removeEle(i);
  printf("Updated priority queue:");
  display();

  printf("\nRandom element from the sample is: %d\n",sample());

  printf("Updated priority queue:");
  delRandom();
  display();
  return 0;
}