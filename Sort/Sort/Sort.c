#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"
#include"Stack.h"

//全部按升序考虑

//插入排序-基本插入排序(O(N2))
void InsertSort(int* arr,int sz)
{
	int i, end, temp;
	for(i=0;i<sz-1;i++)
	{
		temp = arr[i + 1];//从第二个数开始比较
		for (end = i; end >= 0; end--)
		{
			if (arr[end] > temp)
				arr[end + 1] = arr[end];//将大的数放到下一个位置
			else
				break;
		}
		/*将如果循环走完，此时end == -1，那么将temp放到0的位置
		* 如果循环是被break跳出的，那么将temp放到end的下一个位置，因为end此时是小于temp的
		*/
		arr[end + 1] = temp;
	}
}

//插入排序-希尔排序-其实是对基本插入排序的优化，原来的步距为1，现在为gap(时间复杂度不固定)
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
				temp = arr[j + gap];//从第二个数开始比较
				for (end = j; end >= 0; end -= gap)
				{
					if (arr[end] > temp)
						arr[end + gap] = arr[end];//将大的数放到下一个位置
					else
						break;
				}
				/*将如果循环走完，此时end == -1，那么将temp放到0的位置
				* 如果循环是被break跳出的，那么将temp放到end的下一个位置，因为end此时是小于temp的
				*/
				arr[end + gap] = temp;
			}
		}
	}
}

////希尔排序思路二
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

//交换
void Swap(int* a1,int* a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

////选择排序-1
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
//		Swap(&arr[begin], &arr[iMin]);//将找到的最小值与begin位置的值交换，
//		/*假如iMax正好与begin相等，即begin位置的值是最大值，此时max将被换到iMin的位置
//		因此需要将iMin位置的值（此时是最大值）与end位置的值交换
//		*/
//		if (arr[iMin] == max)
//			Swap(&arr[end], &arr[iMin]);
//		else
//			Swap(&arr[end], &arr[iMax]);//将找到的最大值与end位置的值交换
//		begin++;//继续找次小值
//		end--;//继续找次大值
//	}
//}

//选择排序-基本选择排序2(该方法在swap时不需要借助变量max，显然这种方法更优)
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
		Swap(&arr[begin], &arr[iMin]);//将找到的最小值与begin位置的值交换
		/*假如iMax正好与begin相等，即begin位置的值是最大值，此时最大值将被换到iMin的位置
		因此需要将iMin位置的值（此时是最大值）与end位置的值交换
		*/
		if (iMax == begin)
			Swap(&arr[end], &arr[iMin]);
		else
			Swap(&arr[end], &arr[iMax]);//将找到的最大值与end位置的值交换
		begin++;//继续找次小值
		end--;//继续找次大值
	}
}

////判断是否扩容
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

//向下调整
void AdjustDown(int* arr, int parent,int sz)
{
	int maxChild = 2 * parent + 1;//假设左子结点为较大值
	while (maxChild < sz)
	{
		if (maxChild + 1 < sz && arr[maxChild + 1] > arr[maxChild])//如果maxChild+1没有越界，且右子结点大于左子结点
			maxChild++;
		if (arr[maxChild] > arr[parent])//如果较大的子结点大于父结点
			Swap(&arr[maxChild], &arr[parent]);
		parent = maxChild;
		maxChild = 2 * parent + 1;
	}
}

//选择排序-堆排序-升序，建大堆(这里更合适的方法是直接对整体进行构建堆并排序（之前讲的第一种思路），而不是一边push一边构建堆)
void HeapSort(int* arr, int sz)
{
	int i;
	//从后一个父结点开始，自下向上依次执行向下调整算法
	for(i=(sz-1-1)/2; i >=0;i--)//sz-1-1为最后一个有子结点的结点的下标
		AdjustDown(arr,i,sz);
		
	//排序
	int szEnd = sz;
	while(szEnd>1)//当只剩1个元素时，就不需再排序了
	{
		Swap(&arr[0], &arr[szEnd-1]);//交换根结点与尾节点,此时尾节点将是最大值
		szEnd--;
		AdjustDown(arr,0,szEnd);//向下调整，不考虑已经排好序的大值
	}
}

//交换排序-冒泡排序
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

//三个值选中值，将中值与第三个值互换,这种方法只适合选end做key值的情况，如果选begin做key值，又需要再重新修改
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

//三个值选中值-仅返回中值下标，这种方法返回中值的坐标，相比于上面的方法，更加的灵活
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
//	// 三数取中
//	int mid = GetMidIndex(a, left, right);
//	//printf("[%d,%d]-%d\n", left, right, mid);
//
//	Swap(&a[left], &a[mid]);
//
//	int keyi = left;
//	while (left < right)
//	{
//		// 6 6 6 6 6
//		// R找小
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//
//		// L找大
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

//快速排序的递归函数-方法1-Hoare法
int _QuickSort_1(int* arr, int begin, int end)
{
	MidValue(&arr[begin], &arr[(begin + end) / 2], &arr[end]);
	int keyIndex = end;
	//end--;//这一步有没有都可以，基本没意义，而且还会带来其他问题，需要加更多的代码完善
	while (begin < end)
	{
		while (begin < end && arr[begin] <= arr[keyIndex])//直到找到不小于arr[keyIndex]的值，停下
			++begin;
		while (begin < end && arr[end] >= arr[keyIndex])//直到找到不大于arr[keyIndex]的值，停下
			--end;
		if(begin < end)//当相遇时begin == end，就没必要互换了
			Swap(&arr[begin],&arr[end]);//大值与小值交换
	}
	Swap(&arr[begin], &arr[keyIndex]);
	/*Print(arr,7);*/
	return begin;
}

//快速排序的递归函数-方法2-挖坑法
int _QuickSort_2(int* arr, int begin, int end)
{
	MidValue(&arr[begin], &arr[(begin + end) / 2], &arr[end]);
	int key = arr[end];//end为坑
	//end--;//这一步有没有都可以，基本没意义，而且还会带来其他问题，需要加更多的代码完善
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)//直到找到不小于arr[keyIndex]的值，停下
			++begin;
		arr[end] = arr[begin];//begin替代end作为新的坑
		while (begin < end && arr[end] >= key)//直到找到不大于arr[keyIndex]的值，停下
			--end;
		arr[begin] = arr[end];//移动后的end替代之前的begin作为新的坑
	}
	arr[begin]=key;//begin == end，选哪个都一样
	return begin;
}

//快速排序的递归函数-方法3-前后指针法
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

//快速排序（这里有点类似二叉树后序的思路）
void QuickSort(int* arr,int begin,int end)
{
	if (begin == end)//只有一个值，不需要再排序了
		return;
	if (end - begin + 1 > 10)//当超过10个数时（也可以把+1去掉，但是代码可读性稍微受点影响）
	{
		int div = _QuickSort_1(arr, begin, end);
		/*int div = _QuickSort_2(arr, begin, end);*/
		/*int div = _QuickSort_3(arr, begin, end);*/
		if (begin < div)//当begin ==div时，如果再进入递归，div-1将导致end为-1，越界
			QuickSort(arr, begin, div - 1);
		if (end > div)//end ==div时，如果再进入递归，div+1将导致begin越界
			QuickSort(arr, div + 1, end);
	}
	else
		InsertSort(arr + begin,end-begin+1);//begin不一定是数组0下标的位置
}

//快速排序-非递归
void QuickSortNonR(int* arr, int begin, int end)
{
	Stack st;//创建栈结构体变量
	StackInitial(&st);//初始化
	StackPush(&st, end);
	StackPush(&st, begin);

	int left, right, div;

	//开始对左右分别排序，直到完全排序完成后，栈内的段落数据应该被取完，是空的，不需要再进入循环
	while (StackEmpty(&st) == 0)
	{
		//先入left或先入right并不是严格的，但是这里及if结构中的入栈顺序须保持对应
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		div = _QuickSort_3(arr, left, right);//用三种方法中的任何一个都可以
		if(right-left+1 > 10)//当超过10个数时（也可以把+1去掉，但是代码可读性稍微受点影响）
		{
			if (left < div - 1)//等于时就一个数据，不需要再排序
			{
				StackPush(&st, div - 1);//div-1是right
				StackPush(&st, left);//left仍然是left
			}
			if (div + 1 < right)//等于时就一个数据，不需要再排序
			{
				StackPush(&st, right);//right是right
				StackPush(&st, div + 1);//div+1是left
			}
		}
		else
			InsertSort(arr + left, right - left + 1);//left不一定是数组0下标的位置
	}
	StackDestroy(&st);
}

//归并排序的单趟排序-依次对左右部分的数进行比较
void Part_MergeSort(int* arr, int begin_1, int end_1, int begin_2, int end_2, int* arrTemp, int iTemp)
{
	while (begin_1 <= end_1 && begin_2 <= end_2)
	{
		if (arr[begin_1] < arr[begin_2])//哪个小就先把那个放到arrTemp中
		{
			arrTemp[iTemp] = arr[begin_1];
			begin_1++;//继续比较下一个
			iTemp++;//下一个数将要放的位置
		}
		else
		{
			arrTemp[iTemp] = arr[begin_2];
			begin_2++;
			iTemp++;
		}
	}
	/*当左右部分某一个部分被选完后，另一部分可能还有未比较的数据，此时该部分必然是全大于已经比较完测所有数的，
	直接把所有的数都放到arrTemp中*/
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

//归并排序子函数
void _MergeSort(int* arr, int left, int right, int* arrTemp)
{
	int begin_1, end_1, begin_2, end_2, mid,iTemp;
	if (left == right)//当某一部分被分到只剩1个数时，return
		return;
	//将待排序数组分为左右两部分
	mid = (left + right) / 2;
	_MergeSort(arr, left, mid, arrTemp);
	_MergeSort(arr, mid + 1, right, arrTemp);

	begin_1 = left; end_1 = mid;
	begin_2 = mid+1; end_2 = right;
	iTemp = 0;

	//依次对左右部分的数进行比较
	Part_MergeSort(arr,begin_1, end_1, begin_2, end_2, arrTemp,iTemp);
	memmove(arr + left, arrTemp, (right - left + 1) * sizeof(int));//把比较完的数放回数组的原来位置上
}

//归并排序
void  MergeSort(int* arr, int begin, int end)
{
	int* arrTemp = malloc((end - begin)*sizeof(int));
	_MergeSort(arr, begin, end, arrTemp);
	free(arrTemp);
}

//归并排序-非递归
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
			//虽然i不会越界，但是i与gap的和可能会，因此需要对各种情况进行修正
			if (begin_2 > sz - 1)
				break;
			else if (end_2 > sz - 1)
				end_2 = sz - 1;
			Part_MergeSort(arr, begin_1, end_1, begin_2, end_2, arrTemp, iTemp);
			memmove(arr + begin_1, arrTemp, (end_2 - begin_1 + 1) * sizeof(int));//把比较完的数放回数组的原来位置上
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
	char mergeFName[30] ;//归并后创建的文件的名称
	sprintf(mergeFName, "mergeFile\\mergeFile_%d.text", iMerge);//把文件路径及文件名写入文件名字符串
	FILE* pMergeF = fopen(mergeFName,"w");//创建并打开归并文件，进入写模式
	if (pMergeF == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}
	while (ret1 != EOF && ret2 != EOF)//当任一文件中的数据取完时，即停止取数据
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

	//假如有一个文件中的数据被取完，而另一个还有数据时，直接把该文件的数据全部取到合并文件中
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

//归并排序-在外存中对数据进行排序
void MergeSortFile(char* fileName)
{
	//打开源文件
	FILE* pOrigF = fopen(fileName, "r");//打开要写入数据的源文件，进入读模式
	if (pOrigF == NULL)//判断是否成功打开
	{
		perror("fopen failed");
		exit(-1);
	}

	int arr[nSubFile];//存放每份数据的数组，并在内存中进行排序
	int i=0,iFile=0,sz,ret;//iFile用于给存放排序的子文件编号
	char subFName[30];//存放排序之后的数据的子文件的名称
	FILE* pSubF;//指向子文件的文件结构体指针
	int num;//在功能层面，没有num也可以完成排序，但是有了num整个函数将更加流畅
	ret = fscanf(pOrigF, "%d", &num);
	//从源文件取数据到内存-排序-放到子文件
	while(ret != EOF)
	{
		//取nSubFile个数据输入到内存
		//memset(arr,0, nSubFile*sizeof(int));//将arr初始化为0
		if (i < nSubFile)
		{
			arr[i] = num;
			ret = fscanf(pOrigF, "%d", &num);
		}
		/*for (i = 0; i < nSubFile && ret !=EOF; ++i)
		{
			ret=fscanf(pOrigF, "%d", &arr[i]);
		}*/
		//对输入到内存中的数据进行排序
		/*当从文件加载最后一个数据时，文件指针将停留在最后一个数据，并不是文件的结尾
		因此虽然文件中已经没有数据了，ret仍然！=EOF，
		还是会再次进入while，并进入for循环，
		此时再执行一次fscanf才会指向文件末尾，ret才会==EOF，这时就不需要再进行排序等操作了
		这就是加入if判断的原因*/
		//if(ret != EOF)
		else
		{
			++iFile;
			sz = sizeof(arr) / sizeof(arr[1]);
			QuickSort(arr, 0, sz - 1);
			/*Print(arr, sz);*/
			//新建子文件，用于存放排好序的数据
			sprintf(subFName, "subFile\\subFile_%d.text", iFile);//将正确的带编号的文件名写入子文件名字符串
			pSubF = fopen(subFName, "w");//打开要写入数据的子文件，进入写模式，如果没有，自动新建
			if (pSubF == NULL)//判断是否成功打开
			{
				perror("fopen failed");
				exit(-1);
			}
			//将内存中排好序的数据写入子文件中
			for (i = 0; i < nSubFile; ++i)
				fprintf(pSubF, "%d\n", arr[i]);
			fclose(pSubF);
			i = 0;//重置i，才能继续从源文件取数据放入数组中
		}
	}
	fclose(pOrigF);

	//这时每个子文件内部都是有序的，接下来对子文件进行归并排序
	int iMerge;//用于给合并后的文件编号
	FILE* pFile1, * pFile2;
	char mergeFName1[30]= "subFile\\subFile_1.text";
	char mergeFName2[30];//放在循环体中给定名称

	for (iMerge = 1; iMerge < iFile;iMerge++)
	{
		pFile1 = fopen(mergeFName1, "r");//打开目标子文件，进入读模式
		if (pFile1 == NULL)//判断是否成功打开
		{
			perror("fopen failed");
			exit(-1);
		}
		sprintf(mergeFName2, "subFile\\subFile_%d.text", iMerge + 1);//目标子文件2的编号总是当前目标文件的下一个文件
		pFile2 = fopen(mergeFName2, "r");//打开要读取数据的子文件，进入读模式
		if (pFile2 == NULL)//判断是否成功打开
		{
			perror("fopen failed");
			exit(-1);
		}
		pFile1 = _MergeSortFile(pFile1,pFile2,iMerge);//将每次归并后创建的文件的结构体指针赋值给pFile1，继续作为目标文件进行归并
		sprintf(mergeFName1, "mergeFile\\mergeFile_%d.text", iMerge);//将待编号的文件名称写入合并文件的名称字符串中
		fclose(pFile1);
		fclose(pFile2);
	}
}

//打印
void Print(int* arr,int sz)
{
	int i;
	for (i = 0; i < sz; i++)
		printf("%d ",arr[i]);
	printf("\n");
}