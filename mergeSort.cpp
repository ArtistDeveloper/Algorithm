#include <cstdio>

#define A_SIZE 10

void merge(int a[], int left, int mid, int right)
{
	int temp[10 + 3];
	int i, j, k;
	i = left;
	j = mid + 1;
	k = 0;

	//한쪽이 전멸할 때 까지.
	while (i <= mid && j <= right) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			i++;
			k++;
		}
		else {
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	//왼쪽이 살아있을 때
	while (i <= mid) {
		temp[k] = a[i];
		i++;
		k++;
	}
	//오른쪽이 살아있을 때
	while (j <= right) {
		temp[k] = a[j];
		j++;
		k++;
	}

	k--; //?
	//마지막 정리
	while (k >= 0) {
		a[left + k] = temp[k]; //low + k??
		k--;
	}

}

void mergeSort(int a[], int left, int right)
{
	if (left < right) {
		int mid;
		mid = (left + right) / 2;

		//왼쪽 분할
		mergeSort(a, left, mid);
		//우측 분할
		mergeSort(a, mid + 1, right);
		// 정복단계
		merge(a, left, mid, right);
	}
}

int main()
{
	int a[A_SIZE] = { 15, 2, 24, 18, 7, 13, 12, 4, 21, 9 };
	// 정렬 전 출력
	for (int i = 0; i < A_SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	mergeSort(a, 0, A_SIZE - 1);

	// 정렬 후 출력
	for (int i = 0; i < A_SIZE; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}