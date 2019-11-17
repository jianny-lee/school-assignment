#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 31
#define MAX_ELEMENT 200

void min_heap();

typedef struct{
	int key;
}element;

typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;//������ ����

//�� �ʱ�ȭ �Լ�
void init(HeapType *h)
{
	h->heap_size=0;
}

void min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);
// Ʈ���� �Ž��� �ö󰡸鼭 key�� ���ϴ� ����
	while((i != 1) && (item.key < h->heap[i/2].key)) {
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
	
}

element delete_min_heap(HeapType *h) 
{ 
    int parent, child; 
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;	
    child = 2;
    while( child <= h->heap_size ){
	  // ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
	  if( ( child < h->heap_size ) && 
	      (h->heap[child].key) > h->heap[child+1].key)
	      child++;
	  if( temp.key <= h->heap[child].key ) break;
	  // �Ѵܰ� �Ʒ��� �̵�
	  h->heap[parent] = h->heap[child];
	  parent = child;
	  child *= 2;
    }
    h->heap[parent] = temp;
    return item;
} 
void heap_sort(element arr[], int n)
{
  int i;
  HeapType h;
  init(&h);
  for(i=0;i<n;i++){
	  min_heap(&h,arr[i]);
	
  }
  for(i=(n-1);i>=0;i--){
	  arr[i]= delete_min_heap(&h);
  }
  printf("\nresult : ");
  for(i=(n-2);i>=0;i--){
	printf("%d",arr[i]);
	printf("  ");
  }
}
void print_heap(HeapType *h)
{
	int i;
	int level = 1;
	printf("\n==============================");
	for (i = 1; i <= h->heap_size; i++) {
		if (i == level) {
			printf("\n");
			level *= 2;
		}
		printf("%d", h->heap[i].key);
		printf("  ");
	}
	printf("\n=============================");
}
int main(void)
{
	
	int arr[MAX];
	int index=0;
	int i=0;

	HeapType *h;
	h=(HeapType*)malloc(sizeof(HeapType));
	init(h);
	srand(time(NULL));
	printf("input : ");
	for(index=1;index<MAX;index++){
		arr[index]=(rand()%100)+1;
		h->heap[index].key=arr[index];
		printf("%d",h->heap[index]);
		printf("  ");
		(h->heap_size)++;
	}
	printf("\n");
	
	print_heap(h);
	
	heap_sort(h->heap,MAX);
	
	/*printf("\nresult : ");
	for(index=MAX-1;index>0;index--){
		printf("%d",arr[index]);

	printf("  ");
  }*/

	return 0;

}
