#include <iostream> 
#include <ctime>
using namespace std;

int max3(int a, int b, int c);
int maxSubSum1(const int * a, int size);
int maxSubSum2(const int * a, int size);
int maxSumRec(const int * a, int left, int right);
//void showarray(const int * a, int size);
int maxSum3(const int * a, int size);

/*
Algorithm 1 O(n^3)
*/
int maxSubSum1(const int * a, int size)
{
	int maxSum = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			int thisSum = 0;

			for (int k = i; k <= j; k++)
				thisSum += a[k];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

/*
Algorithm 2 O(n^2)
*/
int maxSubSum2(const int * a, int size)
{
	int maxSum = 0;

	for (int i = 0; i < size; i++)
	{
		int thisSum = 0;

		for (int j = i; j < size; j++)
		{

			thisSum += a[j];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

/*
Algorithm 3 O(nlog(n))
*/
int maxSumRec(const int * a, int left, int right)
{
	if (left == right) //base case
		if (a[left] > 0)
			return a[left];
		else
			return 0;

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}
	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center + 1; j <= right; j++)
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum )
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum,
		maxLeftBorderSum + maxRightBorderSum);
}

/*
maxSumRec driver
*/
int maxSum3(const int * a, int size)
{
	return maxSumRec(a, 0, size - 1);
}

/*
Algorithm 4 O(n)
*/
int maxSubSum4(const int * a, int size)
{
	int maxSum = 0, thisSum = 0;

	for (int j = 0; j < size; j++)
	{
		thisSum += a[j];

			if( thisSum > maxSum )
				maxSum = thisSum;
			else if( thisSum < 0 )
				thisSum = 0;
	}

	return maxSum;
}

int max3(int a, int b, int c)
{
	if (a >= b)
		if (b >= c)
			return a;
		else
			if (a >= c)
				return a;
			else
				return c;
	else
	{
		if (b >= c)
			return b;
		else
			return c;
	}
}

//void showarray(const int * a, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << a[i] << ", ";
//	}
//	cout << endl;
//}

int main()
{
	int * r = new int [10000000];
	for (int i = 0; i < 10000000; ++i) {
		r[i] = rand() % 8;
	}

	//measuring time
	double duration;
	clock_t startTime;

	int n = 2;
	while (n <= 10000000)
	{
		startTime = clock();
		maxSubSum4(r, n);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout << "Execution took " << duration << " milliseconds in Algorithm 4 for n = " << n << endl;
		n *= 2;
	}	
	n = 2;
	while (n <= 10000000)
	{
		startTime = clock();
		maxSum3(r, n);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout << "Execution took " << duration << " milliseconds in Algorithm 3 for n = " << n << endl;
		n *= 2;
	}
	n = 2;
	while (n <= 100000)
	{
		startTime = clock();
		maxSubSum2(r, n);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout << "Execution took " << duration << " milliseconds in Algorithm 2 for n = " << n << endl;
		n *= 2;
	}
	n = 2;
	while (n <= 30000)
	{
		startTime = clock();
		maxSubSum1(r, n);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout << "Execution took " << duration << " milliseconds in Algorithm 1 for n = " << n << endl;
		n *= 2;
	}
	delete[] r;
	//system("pause");
};