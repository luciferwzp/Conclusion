1.冒泡排序
//一次比较两个元素，如果前面的元素比后面的元素大，则将他们交换过来；
//反之继续往下走，从第一对开始到结尾的最后一对，这样一次的比较就将最大的数放在了最后；
//然后重复之前的步骤，直到排序完成。

//基础版本
void BubbleSort(int* arr, int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

			}
		}
	}
}

//进阶版
int* BubbleSort(int* arr, int length)                            
{                            
	int len = length - 1;
	while(len)
	{
		int flag;//记录最后一次交换的位置，以后循环比较只用到最后一次的位置即可
		//因为，最后一次交换位置之后的地方都是顺序排放的                                                          

		for(int j = 0; j < len; j++)                  
		{                                                        
			if(arr[j] > arr[j+1])                                
			{               
				flag = j;
				int tmp = arr[j];                                
				arr[j] = arr[j+1];                           
				arr[j+1] = tmp;
			}    
		}        
		len = flag;
	}
	return arr;
}


2.插入排序
//从第一个元素开始，该元素可以认为是已经排序好的；
//取出下一个元素，与之前的元素对比
//如果前一个元素大于后面的元素，则交换，再与前面的元素比较

int* insertSort(int* arr, int length)
{
	for(int i = 1; i < length; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(arr[j] < arr[j-1])
			{
				int tmp = arr[j];
				arr[j+1] = arr[j];
				arr[j] = arr[j+1];
			}
		}
	}

	return arr;
}


3.选择排序
//

int* SelectSort(int* arr , int len)
{

	int min_index;
	//i是此时走到的位置，j是找后面最小元素的下标
	for(int i = 0; i < len - 1; i++)
	{
		min_index = i;
		for(int j = i + 1; j< len ; j++)  
		{
			if(arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}

		//判断此时所在的位置是不是最小的元素的下标，不是则交换
		if(i != min_idex)
		{
			int tmp = arr[i];
			arr[i]  = arr[min_index];
			arr[min_index] = tmp;
		}
	}

	return arr;
}


4.快排排序
//挑选基准值
//重新排序，小于基准值的排在前面，大于的排在后面，分成两个子串
//递归将每个子串排序

void quickSort(vertor<int>& nums, int left, int right)
{
	if(left > right)
		return ;
	//取中位数
	int mid = midValue(nums, left, right);
	swap(nums[left], nums[mid]);
	int begin = left;
	int end = right;
	int key = left;
	while(left < right)
	{
		//从右往左找，找到一个比key小的值
		while(left < right && nums[right] >= nums[key])
		{
			--right;
		}
		//从左往右找，找到一个比key大的值
		while(left < right && nums[left] <= nums[key])
		{
			++left;
		}
		//这里说明我们已经找到了两个需要交换的数字
		swap(nums[left], nums[right]);
	}
	//这里说明交换完毕，这里我们需要将key值与right值进行交换
	//为什么是right？ 因为每次right先开始找，所以我们能保证right一定是较小值
	swap(nums[key], nums[right]);
	//这里进入递归过程
	quickSort(nums, begin, right-1);
	quickSort(nums, right+1, end);
}



5.希尔排序
//插入排序的改进

void Sort(int A[], int len) {
	int count = 0;
	int gap = len / 2;
	while (gap >= 1) {
		for (int i = gap; i < len; i++) {
			int max = A[i];
			int j = i - gap;
			while ((j >= 0) && (A[j] > max)) {
				count++;
				A[j + gap] = A[j];
				j = j - gap;
			}
			A[j + gap] = max;
		}
		gap /= 2;
	}
	cout << "loop count = " << count << endl;
}


6.堆排序

#define left(x) 2*x+1;//获得左节点在数组中的下标
#define right(x) 2 * (x + 1);//获得右节点在数组中的下标

//假定对某一个节点i其左，右子树都是都是最大堆，但是对于节点i和它的左右子节点则可能破坏最大堆的性质，我们来写一个函数对这
//情况下的堆来进行维护使整体的堆满足最大堆性质
void MaxHeapify(int* a, int i, int low, int high)//输入为要被排序的数组和根节点，数组a当中被维护的那一部分的下标low，high
{
	int l = left(i);//计算下标为i的节点的左子节点
	int r = right(i);//计算下标为i的节点的右子节点
	int largest;//保存i,l,r(即i和它的左右子节点)之间的最大数的下标
	int temp;//交互数组中的数所使用的临时变量
	//找到三个数当中最大的那个数，将最大的那个数和i进行互换
	if (l <= high && a[l] > a[i])
	{
		largest = l;
	}
	else {
		largest = i;
	}

	if (r <= high && a[r] > a[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		MaxHeapify(a, largest, low, high);//交换有可能破坏子树的最大堆性质，所以对所交换的那个子节点进行一次维护，而未交换的那个子节点，根据我们的假设，是保持着最大堆性质的。
	}
}


//将数组建立为一个最大堆
//调整数组当中数的位置将其处理为一个最大堆
void BuildMaxHeap(int* a, int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(a, i, 0, length - 1);
	}
}

//堆排序函数
void HeapSort(int a[], int length)
{
	int temp;
	BuildMaxHeap(a, length);
	for (int i = length - 1; i >= 1; i--)
	{
		//交换根节点和数组的最后一个节点
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		MaxHeapify(a, 0, 0, i - 1);//维护从下标为i-1到0的子数组
	}
}


7.归并排序

using namespace std;

void Merge(int[], int, int[], int, int, int)  //归并函数的声明【把归并函数提到该函数前面，则不用声明】
	//归并排序
	////参数：
	////        numbers[]：原数组
	////        length：数组元素的个数（数组长度）
	////        temp[]：辅助数组
	////        begin：数组开头的下标
	////        end：数组结尾的下标
void MergeSort(int numbers[], int length, int temp[], int begin, int end)
{
	//1. 同样判断传入的参数是否有效
	if (numbers == nullptr || length <= 0 || begin < 0 || end >= length)
		throw new exception("Invalid input.");

	//2. 作为递归的结束条件，开始下标和结束下标相等时，说明子序列中只有一个元素，看作有序的
	if (end - begin == 0)
		return;

	//3. 定义中间变量，将数组分半【如果有7个元素，下标0-6，则middle=3，数组分为长度为4和3的两段】
	int middle = ((end - begin) / 2 ) + begin;
	//4. 递归，先递归左半边，再递归右半边，将左右子序列不断分为长度为1的子序列才停止递归
	MergeSort(numbers, length, temp, begin, middle);
	MergeSort(numbers, length, temp, middle + 1, end);
	//5. 再慢慢归并
	Merge(numbers, length, temp, begin, end, middle);
}
//归并函数
//参数：
//      numbers[]：原数组
//      length：数组元素的个数（数组长度）
//      temp[]：辅助数组
//      begin：数组开头的下标
//      end：数组结尾的下标
//      middle：数组中间的下标
void Merge(int numbers[], int length, int temp[], int begin, int end, int middle)
{
	//1. 判断是否有不符合要求的参数传入，有则抛出错误
	if (numbers == nullptr || length <= 0 || begin < 0 || end >= length)
		throw new exception("Invalid input.");

	//2. 将原序列从中分开
	int leftIndex = begin;      //左边序列的开始（左边序列的结尾是middle）
	int rightIndex = middle + 1;//右边序列的开始（右边序列的结尾是end）
	int tempIndex = begin;      //辅助数组的下标
	//3. 当左右子序列尚未到头时，循环
	while (leftIndex <= middle && rightIndex <= end)
	{
		//4. 两两对比判断，谁大谁就放入辅助数组，同时指针后移
		if (numbers[leftIndex] < numbers[rightIndex])
			temp[tempIndex] = numbers[leftIndex++];
		else
			temp[tempIndex] = numbers[rightIndex++];
		//5. 辅助数组下标++
		++tempIndex;
	}

	//6. 当左边或右边子序列尚未到头时，直接放入辅助数组
	while (leftIndex <= middle)
		temp[tempIndex++] = numbers[leftIndex++];

	while (rightIndex <= end)
		temp[tempIndex++] = numbers[rightIndex++];

	//7. 再将辅助数组中已经有序的元素覆盖掉原数组中无序的元素，使原数组变成部分有序
	for (int i = begin; i <= end; ++i)
		numbers[i] = temp[i];
}
//简单测试
int main(int arvc, char* argv[])
{
	const int length = 9;
	int nums[length] = { 18, 7, 23, 3, 9, 32, 10 , 99, 0 };
	int *temp = new int[length];

	MergeSort(nums, length, temp, 0, 8);

	for (int i = 0; i < length; i++)
		cout << nums[i] << "  ";

	delete[] temp;
	temp = nullptr;
	cout << endl;
	return 0;
}
