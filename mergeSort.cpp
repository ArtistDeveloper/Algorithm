#include <cstdio>

#define A_SIZE 10

void merge(int a[], int left, int mid, int right)
{
	int temp[10 + 3];
	int i, j, k;
	i = left;
	j = mid + 1;
	k = 0;

	//������ ������ �� ����.
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
	//������ ������� ��
	while (i <= mid) {
		temp[k] = a[i];
		i++;
		k++;
	}
	//�������� ������� ��
	while (j <= right) {
		temp[k] = a[j];
		j++;
		k++;
	}

	k--; //?
	//������ ����
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

		//���� ����
		mergeSort(a, left, mid);
		//���� ����
		mergeSort(a, mid + 1, right);
		// �����ܰ�
		merge(a, left, mid, right);
	}
}

int main()
{
	int a[A_SIZE] = { 15, 2, 24, 18, 7, 13, 12, 4, 21, 9 };
	// ���� �� ���
	for (int i = 0; i < A_SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	mergeSort(a, 0, A_SIZE - 1);

	// ���� �� ���
	for (int i = 0; i < A_SIZE; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}