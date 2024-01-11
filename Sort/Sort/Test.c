#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void Test1(int*  arr,int sz)
{
	//��������
	InsertSort(arr, sz);
	Print(arr,sz);

	////ϣ������
	//ShellSort(arr, sz);
	//Print(arr, sz);

	////ѡ������
	//SelectSort(arr, sz);
	//Print(arr, sz);

	////������
	//HeapSort(arr, sz);
	//Print(arr, sz);

	////ð������
	//BubbleSort(arr, sz);
	//Print(arr, sz);

	//��������
	QuickSort(arr, 0, sz - 1);
	Print(arr, sz);

	////��������-�ǵݹ�
	//QuickSortNonR(arr, 0, sz - 1);
	//Print(arr, sz);

	////�鲢����
	//MergeSort(arr, 0, sz - 1);
	//Print(arr, sz);

	////�鲢����-�ǵݹ�
	//MergeSortNonR(arr, sz);
	//Print(arr, sz);
}

void Test2()
{
	srand((unsigned int)time(0));
	const int N = 10000000;

	//�����ڴ�
	/*int* a1 = malloc(N * sizeof(int));*/
	int* a2 = malloc(N * sizeof(int));
	//int* a3 = malloc(N * sizeof(int));
	//int* a4 = malloc(N * sizeof(int));
	//int* a5 = malloc(N * sizeof(int));
	//int* a6 = malloc(N * sizeof(int));
	//int* a7 = malloc(N * sizeof(int));
	int* a9 = malloc(N * sizeof(int));

	//��N��������ֱ�����ڴ���
	for (int i = 0; i < N; i++)
	{
		/*a1[i] = rand();*/
		a2[i] = rand();
		/*a2[i] = a1[i];
		a3[i]= a1[i];
		a4[i] = a1[i];*/
	/*	a5[i] = a1[i];*/
		/*a6[i] = a2[i];
		a7[i] = a2[i];*/
		a9[i] = a2[i];
	}

	////��������ʱ���
	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	//int begin3 = clock();
	//SelectSort(a3, N);
	//int end3 = clock();

	//int begin4 = clock();
	//HeapSort(a4, N);
	//int end4 = clock();

	/*int begin5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();*/

	int begin6 = clock();
	QuickSort(a2, 0, N - 1);
	int end6 = clock();

	int begin7 = clock();
	QuickSortNonR(a2, 0, N - 1);
	int end7 = clock();

	//int begin6 = clock();
	//MergeSort(a1, N);
	//int end6 = clock();

	int begin9 = clock();
	MergeSortNonR(a9, N);
	int end9 = clock();
	

	/*printf("InsertSort:%d\n", end1 - begin1);*/
	printf("ShellSort:%d\n", end2 - begin2);
	/*printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end5 - begin5);*/
	//printf("QuickSort:%d\n", end6 - begin6);
	//printf("QuickSortNonR:%d\n", end7 - begin7);
	printf("MergeSortNonR:%d\n", end9 - begin9);

	//�ͷ��ڴ�
	/*free(a1);*/
	free(a2);
	//////free(a3);
	//////free(a4);
	////free(a5);
	/*free(a6);
	free(a7);*/
	free(a9);
}

//�������Ӧ�ù鲢����
void Test3()
{
	char origFName[30] = "originalFile.text";//Դ�ļ����ƣ��ļ����޶���30���ַ���
	FILE* pOrigF = fopen(origFName, "w");//��Ҫд�����ݵ�Դ�ļ�������дģʽ�����û�У��Զ��½�
	if (pOrigF == NULL)//�ж��Ƿ�ɹ���
	{
		perror("fopen failed");
		exit(-1);
	}

	//����Դ�ļ��ǿյģ����������Ҫ�Ƚ�����д��Դ�ļ�
	srand((unsigned int)time(0));
	const int N = 100;//Դ�ļ����ܵ�������

	for (int i = 1; i <= N; i++)
	{
		fprintf(pOrigF, "%d\n", rand()%100);//������������[0,99]
	}
	fclose(pOrigF);
	MergeSortFile(origFName);//����
}

int main()
{
	///*int arr[] = { 20 };*/
	///*int arr[] = { 10,20,1,2,5,7,8,66,789,42,21,0,41,45,18,56,46,22 };*/
	///*int arr[] = { 98,72,68,55,53,49,45,41,36,31,25,20,15,12,9,5,3,0 };*/
	///*int arr[] = { 6,1,2,7 };*/
	int arr[] = { 1,2,3,4,5,4,5 };
	//int arr[] = { 19, -10, -2, 40, 3, 36, 57, 25, 66, 51, 5, 40, -8, 43, 9, -5, 0, 4, 55, 28, 63, 67, -2, 35, 57, 0, 0, 30, 17, 55, 22, 34, -4, 42, 57, 52, 4, 65, 6, -2, 8, 12, 31, 43, 26, 34, 31, 19, -3, 36, 34, 11, 58, 23, 13, 7, 17, 10, 33, -5, 10, 53, 14, 56, 18, 8, -6, -2, 37, 7 };
	int sz = sizeof(arr) / sizeof(arr[1]);
	Test1(arr,sz);
	//Test2();//������������
	//Test3();//�鲢����-����н���
}
