#include <stdio.h>
void bubblesort1A(int A[], int n);
//void swap(int *x, int *y);

int main()
{
	int A[] = {1, -1, 2, 3, 1, 9, 100, 21, -2};
	int n = sizeof(A)/sizeof(A[0]);
	
	bubblesort1A(A, n);
	printf("sorted: A = {");
	for(int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("}\n");
	
	return 0;
}



void bubblesort1A(int A[], int n) //气泡排序算法（版本1A）: 0 <= n
{
	typedef enum{false, true} bool;
	bool sorted = false; //整体排序标志，首先假定尚为排序
	
	while (!sorted) {	//在尚未确认全局排序之前，逐趟进行扫描交换
		sorted = true;	//假定已经排序
		for(int i = 1; i < n; i++) { //自左向右逐对检查当前范围A[0, n)内的各相邻元素 
			if(A[i-1] > A[i]) {	//一旦发现A[i-1]与A[i]逆序，则
				swap(&A[i-1], &A[i]);	//交换之，并
				sorted = false;	//因为整体排序不能保证，需要清除排序标志
			}
		}

		n--;	//至此，末元素必然就位，故可缩短待排序序列的有效长度
	}
}	//借助布尔型标志位sorted, 可及时提前退出，而不总是蛮力地做n - 1趟扫描交换

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

