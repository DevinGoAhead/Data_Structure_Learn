#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"
#include"Stack.h"

//ȫ����������

//��������-������������(O(N2))
void InsertSort(int* arr,int sz)
{
	int i, end, temp;
	for(i=0;i<sz-1;i++)
	{
		temp = arr[i + 1];//�ӵڶ�������ʼ�Ƚ�
		for (end = i; end >= 0; end--)
		{
			if (arr[end] > temp)
				arr[end + 1] = arr[end];//��������ŵ���һ��λ��
			else
				break;
		}
		/*�����ѭ�����꣬��ʱend == -1����ô��temp�ŵ�0��λ��
		* ���ѭ���Ǳ�break�����ģ���ô��temp�ŵ�end����һ��λ�ã���Ϊend��ʱ��С��temp��
		*/
		arr[end + 1] = temp;
	}
}

//��������-ϣ������-��ʵ�ǶԻ�������������Ż���ԭ���Ĳ���Ϊ1������Ϊgap(ʱ�临�ӶȲ��̶�)
void ShellSort(int* arr, int sz)
{
	int i,j, end, temp,gap=sz;
	while(gap>1)
	{
		gap = gap / 3 + 1;
		for (i = 0; i < gap; i++)
		{
			for (j = i; j < sz - gap; j += gap) 
			{
				temp = arr[j + gap];//�ӵڶ�������ʼ�Ƚ�
				for (end = j; end >= 0; end -= gap)
				{
					if (arr[end] > temp)
						arr[end + gap] = arr[end];//��������ŵ���һ��λ��
					else
						break;
				}
				/*�����ѭ�����꣬��ʱend == -1����ô��temp�ŵ�0��λ��
				* ���ѭ���Ǳ�break�����ģ���ô��temp�ŵ�end����һ��λ�ã���Ϊend��ʱ��С��temp��
				*/
				arr[end + gap] = temp;
			}
		}
	}
}

////ϣ������˼·��
//void ShellSort_1(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}

//����
void Swap(int* a1,int* a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

////ѡ������-1
//void SelectSort(int* arr, int sz)
//{
//	int i = 1, begin = 0, end = sz - 1, max = 0;
//	int iMin, iMax ;
//	while(begin <= end)
//	{
//		iMin = iMax = begin;
//		for (i = begin+1; i <= end; i++)
//		{
//			if (arr[i] < arr[iMin])
//				iMin = i;
//			if (arr[i] > arr[iMax])
//				iMax = i;
//		}
//		max = arr[iMax];
//		Swap(&arr[begin], &arr[iMin]);//���ҵ�����Сֵ��beginλ�õ�ֵ������
//		/*����iMax������begin��ȣ���beginλ�õ�ֵ�����ֵ����ʱmax��������iMin��λ��
//		�����Ҫ��iMinλ�õ�ֵ����ʱ�����ֵ����endλ�õ�ֵ����
//		*/
//		if (arr[iMin] == max)
//			Swap(&arr[end], &arr[iMin]);
//		else
//			Swap(&arr[end], &arr[iMax]);//���ҵ������ֵ��endλ�õ�ֵ����
//		begin++;//�����Ҵ�Сֵ
//		end--;//�����Ҵδ�ֵ
//	}
//}

//ѡ������-����ѡ������2(�÷�����swapʱ����Ҫ��������max����Ȼ���ַ�������)
void SelectSort(int* arr, int sz)
{
	int i , begin = 0, end = sz - 1;
	int iMin, iMax;
	while (begin < end)
	{
		iMin = iMax = begin;
		for (i = begin + 1; i <= end; i++)
		{
			if (arr[i] < arr[iMin])
				iMin = i;
			if (arr[i] > arr[iMax])
				iMax = i;
		}
		Swap(&arr[begin], &arr[iMin]);//���ҵ�����Сֵ��beginλ�õ�ֵ����
		/*����iMax������begin��ȣ���beginλ�õ�ֵ�����ֵ����ʱ���ֵ��������iMin��λ��
		�����Ҫ��iMinλ�õ�ֵ����ʱ�����ֵ����endλ�õ�ֵ����
		*/
		if (iMax == begin)
			Swap(&arr[end], &arr[iMin]);
		else
			Swap(&arr[end], &arr[iMax]);//���ҵ������ֵ��endλ�õ�ֵ����
		begin++;//�����Ҵ�Сֵ
		end--;//�����Ҵδ�ֵ
	}
}

////�ж��Ƿ�����
//void HeapCapacity(Heap* pHp)
//{
//	if (pHp->size >= pHp->capacity)
//	{
//		pHp->capacity = pHp->capacity == 0 ? initialCapacity : pHp->capacity * 2;
//		int* pDataTemp = realloc(pHp->pData,pHp->capacity*sizeof(int));
//		if (pDataTemp == NULL)
//			perror("realloc failed");
//		else
//			pHp->pData = pDataTemp;
//	}
//}

//���µ���
void AdjustDown(int* arr, int parent,int sz)
{
	int maxChild = 2 * parent + 1;//�������ӽ��Ϊ�ϴ�ֵ
	while (maxChild < sz)
	{
		if (maxChild + 1 < sz && arr[maxChild + 1] > arr[maxChild])//���maxChild+1û��Խ�磬�����ӽ��������ӽ��
			maxChild++;
		if (arr[maxChild] > arr[parent])//����ϴ���ӽ����ڸ����
			Swap(&arr[maxChild], &arr[parent]);
		parent = maxChild;
		maxChild = 2 * parent + 1;
	}
}

//ѡ������-������-���򣬽����(��������ʵķ�����ֱ�Ӷ�������й����Ѳ�����֮ǰ���ĵ�һ��˼·����������һ��pushһ�߹�����)
void HeapSort(int* arr, int sz)
{
	int i;
	//�Ӻ�һ������㿪ʼ��������������ִ�����µ����㷨
	for(i=(sz-1-1)/2; i >=0;i--)//sz-1-1Ϊ���һ�����ӽ��Ľ����±�
		AdjustDown(arr,i,sz);
		
	//����
	int szEnd = sz;
	while(szEnd>1)//��ֻʣ1��Ԫ��ʱ���Ͳ�����������
	{
		Swap(&arr[0], &arr[szEnd-1]);//�����������β�ڵ�,��ʱβ�ڵ㽫�����ֵ
		szEnd--;
		AdjustDown(arr,0,szEnd);//���µ������������Ѿ��ź���Ĵ�ֵ
	}
}

//��������-ð������
void BubbleSort(int* arr, int sz)
{
	int i, j;
	int k = 0;
	for(i=0;i<sz-1;i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(&arr[j],&arr[j + 1]);
			k = 1;
		}
		if (k == 0)
			break;
	}
}

//����ֵѡ��ֵ������ֵ�������ֵ����,���ַ���ֻ�ʺ�ѡend��keyֵ����������ѡbegin��keyֵ������Ҫ�������޸�
void MidValue(int* a1,int* a2,int* a3)
{
	if (*a1 > *a2)
	{
		if (*a3 > *a1)
			Swap(a3,a1);
		else if(*a2 > *a3)
			Swap(a3,a2);
	}
	else if(*a1 < *a2)
	{
		if (*a3 < *a1)
			Swap(a3, a1);
		else if (*a2 < *a3)
			Swap(a3, a2);
	}
}

//����ֵѡ��ֵ-��������ֵ�±꣬���ַ���������ֵ�����꣬���������ķ��������ӵ����
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] >= a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//int GetMidIndex(int* a, int left, int right)
//{
//	int mid = left + (right - left) / 2;
//	if (a[left] < a[mid])
//	{
//		if (a[mid] < a[right])
//		{
//			return mid;
//		}
//		else if (a[left] > a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//	else // a[left] >= a[mid]
//	{
//		if (a[mid] > a[right])
//		{
//			return mid;
//		}
//		else if (a[left] < a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//}
//
//// [left, right] -- O(N)
//// hoare
//int PartSort1(int* a, int left, int right)
//{
//	// ����ȡ��
//	int mid = GetMidIndex(a, left, right);
//	//printf("[%d,%d]-%d\n", left, right, mid);
//
//	Swap(&a[left], &a[mid]);
//
//	int keyi = left;
//	while (left < right)
//	{
//		// 6 6 6 6 6
//		// R��С
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//
//		// L�Ҵ�
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//
//		if (left < right)
//			Swap(&a[left], &a[right]);
//	}
//
//	int meeti = left;
//
//	Swap(&a[meeti], &a[keyi]);
//
//	return meeti;
//}

//��������ĵݹ麯��-����1-Hoare��
int _QuickSort_1(int* arr, int begin, int end)
{
	MidValue(&arr[begin], &arr[(begin + end) / 2], &arr[end]);
	int keyIndex = end;
	//end--;//��һ����û�ж����ԣ�����û���壬���һ�������������⣬��Ҫ�Ӹ���Ĵ�������
	while (begin < end)
	{
		while (begin < end && arr[begin] <= arr[keyIndex])//ֱ���ҵ���С��arr[keyIndex]��ֵ��ͣ��
			++begin;
		while (begin < end && arr[end] >= arr[keyIndex])//ֱ���ҵ�������arr[keyIndex]��ֵ��ͣ��
			--end;
		if(begin < end)//������ʱbegin == end����û��Ҫ������
			Swap(&arr[begin],&arr[end]);//��ֵ��Сֵ����
	}
	Swap(&arr[begin], &arr[keyIndex]);
	/*Print(arr,7);*/
	return begin;
}

//��������ĵݹ麯��-����2-�ڿӷ�
int _QuickSort_2(int* arr, int begin, int end)
{
	MidValue(&arr[begin], &arr[(begin + end) / 2], &arr[end]);
	int key = arr[end];//endΪ��
	//end--;//��һ����û�ж����ԣ�����û���壬���һ�������������⣬��Ҫ�Ӹ���Ĵ�������
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)//ֱ���ҵ���С��arr[keyIndex]��ֵ��ͣ��
			++begin;
		arr[end] = arr[begin];//begin���end��Ϊ�µĿ�
		while (begin < end && arr[end] >= key)//ֱ���ҵ�������arr[keyIndex]��ֵ��ͣ��
			--end;
		arr[begin] = arr[end];//�ƶ����end���֮ǰ��begin��Ϊ�µĿ�
	}
	arr[begin]=key;//begin == end��ѡ�ĸ���һ��
	return begin;
}

//��������ĵݹ麯��-����3-ǰ��ָ�뷨
int _QuickSort_3(int* arr, int begin, int end)
{
	/*MidValue(&arr[begin], &arr[(begin + end) / 2], &arr[end]);*/
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[begin],&arr[mid]);
	int key = arr[begin];
	int prev = begin;
	int cur = prev+1;
	while(cur<=end)
	{
		if(arr[cur] < key)
		{
			prev++;
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	
	Swap(&arr[prev], &arr[begin]);
	return prev;
}

//�������������е����ƶ����������˼·��
void QuickSort(int* arr,int begin,int end)
{
	if (begin == end)//ֻ��һ��ֵ������Ҫ��������
		return;
	if (end - begin + 1 > 10)//������10����ʱ��Ҳ���԰�+1ȥ�������Ǵ���ɶ�����΢�ܵ�Ӱ�죩
	{
		int div = _QuickSort_1(arr, begin, end);
		/*int div = _QuickSort_2(arr, begin, end);*/
		/*int div = _QuickSort_3(arr, begin, end);*/
		if (begin < div)//��begin ==divʱ������ٽ���ݹ飬div-1������endΪ-1��Խ��
			QuickSort(arr, begin, div - 1);
		if (end > div)//end ==divʱ������ٽ���ݹ飬div+1������beginԽ��
			QuickSort(arr, div + 1, end);
	}
	else
		InsertSort(arr + begin,end-begin+1);//begin��һ��������0�±��λ��
}

//��������-�ǵݹ�
void QuickSortNonR(int* arr, int begin, int end)
{
	Stack st;//����ջ�ṹ�����
	StackInitial(&st);//��ʼ��
	StackPush(&st, end);
	StackPush(&st, begin);

	int left, right, div;

	//��ʼ�����ҷֱ�����ֱ����ȫ������ɺ�ջ�ڵĶ�������Ӧ�ñ�ȡ�꣬�ǿյģ�����Ҫ�ٽ���ѭ��
	while (StackEmpty(&st) == 0)
	{
		//����left������right�������ϸ�ģ��������Ｐif�ṹ�е���ջ˳���뱣�ֶ�Ӧ
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		div = _QuickSort_3(arr, left, right);//�����ַ����е��κ�һ��������
		if(right-left+1 > 10)//������10����ʱ��Ҳ���԰�+1ȥ�������Ǵ���ɶ�����΢�ܵ�Ӱ�죩
		{
			if (left < div - 1)//����ʱ��һ�����ݣ�����Ҫ������
			{
				StackPush(&st, div - 1);//div-1��right
				StackPush(&st, left);//left��Ȼ��left
			}
			if (div + 1 < right)//����ʱ��һ�����ݣ�����Ҫ������
			{
				StackPush(&st, right);//right��right
				StackPush(&st, div + 1);//div+1��left
			}
		}
		else
			InsertSort(arr + left, right - left + 1);//left��һ��������0�±��λ��
	}
	StackDestroy(&st);
}

//�鲢����ĵ�������-���ζ����Ҳ��ֵ������бȽ�
void Part_MergeSort(int* arr, int begin_1, int end_1, int begin_2, int end_2, int* arrTemp, int iTemp)
{
	while (begin_1 <= end_1 && begin_2 <= end_2)
	{
		if (arr[begin_1] < arr[begin_2])//�ĸ�С���Ȱ��Ǹ��ŵ�arrTemp��
		{
			arrTemp[iTemp] = arr[begin_1];
			begin_1++;//�����Ƚ���һ��
			iTemp++;//��һ������Ҫ�ŵ�λ��
		}
		else
		{
			arrTemp[iTemp] = arr[begin_2];
			begin_2++;
			iTemp++;
		}
	}
	/*�����Ҳ���ĳһ�����ֱ�ѡ�����һ���ֿ��ܻ���δ�Ƚϵ����ݣ���ʱ�ò��ֱ�Ȼ��ȫ�����Ѿ��Ƚ�����������ģ�
	ֱ�Ӱ����е������ŵ�arrTemp��*/
	while (begin_1 <= end_1)
	{
		arrTemp[iTemp] = arr[begin_1];
		begin_1++;
		iTemp++;
	}

	while (begin_2 <= end_2)
	{
		arrTemp[iTemp] = arr[begin_2];
		begin_2++;
		iTemp++;
	}
}

//�鲢�����Ӻ���
void _MergeSort(int* arr, int left, int right, int* arrTemp)
{
	int begin_1, end_1, begin_2, end_2, mid,iTemp;
	if (left == right)//��ĳһ���ֱ��ֵ�ֻʣ1����ʱ��return
		return;
	//�������������Ϊ����������
	mid = (left + right) / 2;
	_MergeSort(arr, left, mid, arrTemp);
	_MergeSort(arr, mid + 1, right, arrTemp);

	begin_1 = left; end_1 = mid;
	begin_2 = mid+1; end_2 = right;
	iTemp = 0;

	//���ζ����Ҳ��ֵ������бȽ�
	Part_MergeSort(arr,begin_1, end_1, begin_2, end_2, arrTemp,iTemp);
	memmove(arr + left, arrTemp, (right - left + 1) * sizeof(int));//�ѱȽ�������Ż������ԭ��λ����
}

//�鲢����
void  MergeSort(int* arr, int begin, int end)
{
	int* arrTemp = malloc((end - begin)*sizeof(int));
	_MergeSort(arr, begin, end, arrTemp);
	free(arrTemp);
}

//�鲢����-�ǵݹ�
void MergeSortNonR(int* arr, int sz)
{
	int i,begin_1, end_1, begin_2, end_2, iTemp;
	int gap = 1;
	int* arrTemp = malloc(sz * sizeof(int));
	while(gap<=sz)
	{
		for (i = 0; i < sz; i += 2 * gap)
		{
			begin_1 = i; end_1 = i + gap - 1;
			begin_2 = i + gap; end_2 = i + 2 * gap - 1;
			iTemp = 0;
			//��Ȼi����Խ�磬����i��gap�ĺͿ��ܻᣬ�����Ҫ�Ը��������������
			if (begin_2 > sz - 1)
				break;
			else if (end_2 > sz - 1)
				end_2 = sz - 1;
			Part_MergeSort(arr, begin_1, end_1, begin_2, end_2, arrTemp, iTemp);
			memmove(arr + begin_1, arrTemp, (end_2 - begin_1 + 1) * sizeof(int));//�ѱȽ�������Ż������ԭ��λ����
		}
		
		gap *= 2;
	} 
	free(arrTemp);
}

FILE* _MergeSortFile(FILE* pFile1, FILE* pFile2,int iMerge)
{
	int num1, num2;
	int ret1 = fscanf(pFile1, "%d", &num1);
	int ret2 = fscanf(pFile2, "%d", &num2);
	char mergeFName[30] ;//�鲢�󴴽����ļ�������
	sprintf(mergeFName, "mergeFile\\mergeFile_%d.text", iMerge);//���ļ�·�����ļ���д���ļ����ַ���
	FILE* pMergeF = fopen(mergeFName,"w");//�������򿪹鲢�ļ�������дģʽ
	if (pMergeF == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}
	while (ret1 != EOF && ret2 != EOF)//����һ�ļ��е�����ȡ��ʱ����ֹͣȡ����
	{
		if (num1 < num2)
		{
			fprintf(pMergeF, "%d\n", num1);
			ret1 = fscanf(pFile1, "%d", &num1);
		}
		else
		{
			fprintf(pMergeF, "%d\n", num2);
			ret2 = fscanf(pFile2, "%d", &num2);
		}
	}

	//������һ���ļ��е����ݱ�ȡ�꣬����һ����������ʱ��ֱ�ӰѸ��ļ�������ȫ��ȡ���ϲ��ļ���
	while (ret1 != EOF)
	{
		fprintf(pMergeF, "%d\n", num1);
		ret1 = fscanf(pFile1, "%d", &num1);
		
	}
	while (ret2 != EOF)
	{
		fprintf(pMergeF, "%d\n", num2);
		ret2 = fscanf(pFile2, "%d", &num2);	
	}
	fclose(pMergeF);
	return pMergeF;
}

//�鲢����-������ж����ݽ�������
void MergeSortFile(char* fileName)
{
	//��Դ�ļ�
	FILE* pOrigF = fopen(fileName, "r");//��Ҫд�����ݵ�Դ�ļ��������ģʽ
	if (pOrigF == NULL)//�ж��Ƿ�ɹ���
	{
		perror("fopen failed");
		exit(-1);
	}

	int arr[nSubFile];//���ÿ�����ݵ����飬�����ڴ��н�������
	int i=0,iFile=0,sz,ret;//iFile���ڸ������������ļ����
	char subFName[30];//�������֮������ݵ����ļ�������
	FILE* pSubF;//ָ�����ļ����ļ��ṹ��ָ��
	int num;//�ڹ��ܲ��棬û��numҲ����������򣬵�������num������������������
	ret = fscanf(pOrigF, "%d", &num);
	//��Դ�ļ�ȡ���ݵ��ڴ�-����-�ŵ����ļ�
	while(ret != EOF)
	{
		//ȡnSubFile���������뵽�ڴ�
		//memset(arr,0, nSubFile*sizeof(int));//��arr��ʼ��Ϊ0
		if (i < nSubFile)
		{
			arr[i] = num;
			ret = fscanf(pOrigF, "%d", &num);
		}
		/*for (i = 0; i < nSubFile && ret !=EOF; ++i)
		{
			ret=fscanf(pOrigF, "%d", &arr[i]);
		}*/
		//�����뵽�ڴ��е����ݽ�������
		/*�����ļ��������һ������ʱ���ļ�ָ�뽫ͣ�������һ�����ݣ��������ļ��Ľ�β
		�����Ȼ�ļ����Ѿ�û�������ˣ�ret��Ȼ��=EOF��
		���ǻ��ٴν���while��������forѭ����
		��ʱ��ִ��һ��fscanf�Ż�ָ���ļ�ĩβ��ret�Ż�==EOF����ʱ�Ͳ���Ҫ�ٽ�������Ȳ�����
		����Ǽ���if�жϵ�ԭ��*/
		//if(ret != EOF)
		else
		{
			++iFile;
			sz = sizeof(arr) / sizeof(arr[1]);
			QuickSort(arr, 0, sz - 1);
			/*Print(arr, sz);*/
			//�½����ļ������ڴ���ź��������
			sprintf(subFName, "subFile\\subFile_%d.text", iFile);//����ȷ�Ĵ���ŵ��ļ���д�����ļ����ַ���
			pSubF = fopen(subFName, "w");//��Ҫд�����ݵ����ļ�������дģʽ�����û�У��Զ��½�
			if (pSubF == NULL)//�ж��Ƿ�ɹ���
			{
				perror("fopen failed");
				exit(-1);
			}
			//���ڴ����ź��������д�����ļ���
			for (i = 0; i < nSubFile; ++i)
				fprintf(pSubF, "%d\n", arr[i]);
			fclose(pSubF);
			i = 0;//����i�����ܼ�����Դ�ļ�ȡ���ݷ���������
		}
	}
	fclose(pOrigF);

	//��ʱÿ�����ļ��ڲ���������ģ������������ļ����й鲢����
	int iMerge;//���ڸ��ϲ�����ļ����
	FILE* pFile1, * pFile2;
	char mergeFName1[30]= "subFile\\subFile_1.text";
	char mergeFName2[30];//����ѭ�����и�������

	for (iMerge = 1; iMerge < iFile;iMerge++)
	{
		pFile1 = fopen(mergeFName1, "r");//��Ŀ�����ļ��������ģʽ
		if (pFile1 == NULL)//�ж��Ƿ�ɹ���
		{
			perror("fopen failed");
			exit(-1);
		}
		sprintf(mergeFName2, "subFile\\subFile_%d.text", iMerge + 1);//Ŀ�����ļ�2�ı�����ǵ�ǰĿ���ļ�����һ���ļ�
		pFile2 = fopen(mergeFName2, "r");//��Ҫ��ȡ���ݵ����ļ��������ģʽ
		if (pFile2 == NULL)//�ж��Ƿ�ɹ���
		{
			perror("fopen failed");
			exit(-1);
		}
		pFile1 = _MergeSortFile(pFile1,pFile2,iMerge);//��ÿ�ι鲢�󴴽����ļ��Ľṹ��ָ�븳ֵ��pFile1��������ΪĿ���ļ����й鲢
		sprintf(mergeFName1, "mergeFile\\mergeFile_%d.text", iMerge);//������ŵ��ļ�����д��ϲ��ļ��������ַ�����
		fclose(pFile1);
		fclose(pFile2);
	}
}

//��ӡ
void Print(int* arr,int sz)
{
	int i;
	for (i = 0; i < sz; i++)
		printf("%d ",arr[i]);
	printf("\n");
}