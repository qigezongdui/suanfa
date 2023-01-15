//#include<stdio.h>
//int main()
//{
//	float s[9] = {0.0, 0.4, 0.2, 0.5, 0.8, 0.2, 0.2, 0.4, 0.3};
//	int n = sizeof(s) / sizeof(s[0]);
//	int B[9] = { 0 };
//	int x=BinPackingFirstFit(s, n, B);
//	printf("--> 共使用了%d个箱子\n", x);
//}
//int BinPackingFirstFit(float s[], int n, int B[])
//{
//	int i = 1;
//	int j = 1;
//	float b[9] = { 0.0 };
//	for (i = 1; i <= n -1; i++)
//	{
//		B[i] = 0;
//	}
//	for (i = 1; i <= n-1; i++)
//	{
//		for (j = 1; j <= n ; j++)
//		{
//			if ((b[j] + s[i])<=1.0)
//			{
//			B[i] = j;
//			printf("--> %d号物品放入%d号箱子\n", i, j);
//			b[j] = b[j] + s[i];
//			break;
//			}
//		}
//	}
//	for (j = 1; j <= n -1; j++)
//		printf("--> %d号箱子装入物品容量为%.1f\n", j,b[j]);
//	j = 1;
//	while( b[j] != 0 )
//		{
//		j = j+1;
//		}
//	//printf("j-1=%d\n", j - 1);
//	return j - 1;
//}



//#include<stdio.h>
//int main()
//{
//	float s[9] = { 0.0, 0.4, 0.2, 0.5, 0.8, 0.2, 0.2, 0.4, 0.3 };
//	int n = sizeof(s) / sizeof(s[0]);
//	int B[9] = { 0 };
//	int x = BinPackingNextFit(s, n, B);
//	printf("共使用了%d个箱子\n", x);
//}
//int BinPackingNextFit(float s[], int n, int B[])
//{
//	int i = 1;
//	int j = 1;
//	int m = 1;
//	float b[9] = { 0.0 };
//	for (i = 1; i <= n - 1; i++)
//	{
//		B[i] = 0;
//	}
//	for (i = 1; i <= n - 1; i++)
//	{
//			if ((b[m] + s[i]) <= 1.0)
//			{
//				B[i] = m;
//				printf("--> %d号物品放入%d号箱子\n", i, m);
//				b[m] = b[m] + s[i];
//			}
//			else
//			{
//				m = m + 1;
//				B[i] = m;
//				printf("--> %d号物品放入%d号箱子\n", i, m);
//				b[m] = s[i];
//			}
//		
//	}
//	for (j = 1; j <= n - 1; j++)
//		printf("--> %d号箱子装入物品容量为%.1f\n", j, b[j]);
//	return m;
//}


//#include<stdio.h>
//int main()
//{
//	float s[9] = { 0.0, 0.4, 0.2, 0.5, 0.8, 0.2, 0.2, 0.4, 0.3 };
//	int n = sizeof(s) / sizeof(s[0]);
//	int B[9] = { 0 };
//	int x = BinPackingBestFit(s, n, B);
//	printf("共使用了%d个箱子\n", x);
//}
//int BinPackingBestFit(float s[], int n, int B[])
//{
//	int i = 1;
//	int j = 1;
//	int m = 1;
//	float b[9] = { 0.0 };
//	for (i = 1; i <= n - 1; i++)
//	{
//		B[i] = 0;
//	}
//	for (i = 1; i <= n - 1; i++)
//	{
//		float left = 2.0;
//		int a = 1;
//		for (j = 1; j <= m; j++)
//		{
//			if ((b[j] + s[i]) <= 1.0)
//			{
//				if (1 - b[j] <= left)
//				{
//					left = 1 - b[j];
//					a = j;
//				}
//				
//			}
//		}
//		if (left == 2)
//		{
//			m = m + 1;
//			b[m] = s[i];
//			B[i] = m;
//			printf("--> %d号物品放入%d号箱子\n", i, m);
//		}
//		else
//		{
//			b[a] = b[a] + s[i];
//			B[i] = a;
//			printf("--> %d号物品放入%d号箱子\n", i, a);
//			
//		}
//
//	}
//	for (j = 1; j <= n - 1; j++)
//		printf("--> %d号箱子装入物品容量为%.1f\n", j, b[j]);
//	return m;
//}


#include<stdio.h>
int main()
{
	float s[9] = { 0.0, 0.4, 0.2, 0.5, 0.8, 0.2, 0.2, 0.4, 0.3 };
	int n = sizeof(s) / sizeof(s[0]);
	int B[9] = { 0 };
	int x = BinPackingWorseFit(s, n, B);
	printf("共使用了%d个箱子\n", x);
}
int BinPackingWorseFit(float s[], int n, int B[])
{
	int i = 1;
	int j = 1;
	int m = 1;
	float b[9] = { 0.0 };
	for (i = 1; i <= n - 1; i++)
	{
		B[i] = 0;
	}
	for (i = 1; i <= n - 1; i++)
	{
		float left = -1;
		int a = 1;
		for (j = 1; j <= m; j++)
		{
			if ((b[j] + s[i]) <= 1.0)
			{
				if (1 - b[j] >= left)
				{
					left = 1 - b[j];
					a = j;
				}

			}
		}
		if (left == -1)
		{
			m = m + 1;
			b[m] = s[i];
			B[i] = m;
			printf("%d号物品放入%d号箱子\n", i, m);
		}
		else
		{
			b[a] = b[a] + s[i];
			B[i] = a;
			printf("%d号物品放入%d号箱子\n", i, a);

		}

	}
	for (j = 1; j <= n - 1; j++)
		printf("%d号箱子装入物品容量为%.1f\n", j, b[j]);
	return m;
}