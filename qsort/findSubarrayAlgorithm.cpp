#include <iostream>
#include "Strategy.h"

using namespace std;

// useless commit 1

namespace find_subarray
{
	struct Result
	{
		int low;
		int high;		
		int sum;
		int *a;
		Result()
		{
			low = high = sum = 0;
			a = nullptr;
		}
	};

	Result FindMaxCrossingSubarray(int **a, int low, int mid, int high)
	{
		Result res;
		int left_sum, right_sum, sum;
		int max_left, max_rigth;
		left_sum = right_sum = sum = max_left = max_rigth = 0;


		for (int i = mid; i >= low; --i)
		{
			sum = sum + *(*a + i);
			if (sum > left_sum)
			{
				left_sum = sum;
				max_left = i;
			}
		}


		sum = 0;
		for (int i = mid + 1; i <= high; ++i)
		{
			sum += *(*a + i);
			if (sum > right_sum)
			{
				right_sum = sum;
				max_rigth = i;
			}
		}


		res.low = max_left;
		res.high = max_rigth;
		res.sum = left_sum + right_sum;


		return res;
	}


	Result FindMaximumSubarray(int **a, int low, int high)
	{
		if (high == low)
		{
			Result res;
			res.low = low;
			res.high = high;
			res.a = *(a)+low;


			return res;
		}
		else
		{
			int mid = (high + low) >> 1;


			Result resLeft;
			Result resRight;
			Result resCross;


			resLeft = FindMaximumSubarray(a, low, mid);
			resRight = FindMaximumSubarray(a, mid + 1, high);
			resCross = FindMaxCrossingSubarray(a, low, mid, high);


			Result res;
			if (resLeft.sum >= resRight.sum && resLeft.sum >= resCross.sum)
			{
				res.low = resLeft.low;
				res.high = resLeft.high;
				res.sum = resLeft.sum;
				return res;
			}
			else if (resRight.sum >= resLeft.sum && resRight.sum >= resCross.sum)
			{
				res.low = resRight.low;
				res.high = resRight.high;
				res.sum = resRight.sum;


				return res;
			}
			else
			{
				res.low = resCross.low;
				res.high = resCross.high;
				res.sum = resCross.sum;


				return res;
			}
		}

	}
} // namespace 





//int main()
//{
//	{
//		User1 *u1 = new User1;
//		User2 u2;
//
//
//		u1->someUse1();
//		u2.someUse2();
//
//		delete u1;
//	}
//
//
//	int const n = 4;
//	int a[n] = { -1, 2, 1, 0};
//	int *pa = a;
//	find_subarray::Result res = find_subarray::FindMaximumSubarray(&pa, 0, n-1);
//
//	return 0;
//}