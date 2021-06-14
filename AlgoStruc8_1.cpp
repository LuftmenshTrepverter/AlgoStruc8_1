#include <stdio.h>
#include <iostream>

const int maxn = 30;
int n, V, maxValue = 0;//物品件数 背包容量 最大价值
int w[maxn], v[maxn]; //每件物品的重量 每件物品的价值

void DFS(int index, int sumW, int sumV) //index：当前物品的编号
{
	if (index == n) //递归边界
	{
		return;
	}

	DFS(index + 1, sumW, sumV); //不选第index件物品

	if (sumW + w[index] <= V) //不超过背包容量
	{
		if (sumV + v[index] > maxValue)
		{
			maxValue = sumV + v[index]; //更新最大价值
		}

		DFS(index + 1, sumW + w[index], sumV + v[index]); //选第index件物品
	}
}

//const int maxn = 30;
//int n, V, maxValue = 0;
//int w[maxn], v[maxn];
//
////DFS
//void DFS(int index, int sumW, int sumV)
//{
//	printf("第11行：(%d %d %d)\n", index, sumW, sumV);
//	if (index == n)
//	{
//		printf("第14行：进入if(index == n), (%d %d %d %d)\n", n, sumW, sumV, maxValue);
//		return;
//	}
//
//	//不选第index物品
//	printf("第19行：(%d %d %d)\n", index, sumW, sumV);
//	DFS(index + 1, sumW, sumV);
//	printf("第21行：(%d %d %d)\n", index, sumW, sumV);
//
//	//选第index物品，先判断sumW会不会超过背包重量V
//	if (sumW + w[index] <= V)
//	{
//		printf("第26行：进入if (sumW + w[index] <= V)\n");
//		if (sumV + v[index] > maxValue)
//		{
//			maxValue = sumV + v[index];
//			printf("第29行：进入if (sumV + v[index] > maxValue),更新max = %d\n", maxValue);
//			
//		}
//		printf("第33行：(%d %d %d)\n", index, sumW, sumV);
//		DFS(index + 1, sumW + w[index], sumV + v[index]);
//		printf("第35行：(%d %d %d)\n", index, sumW, sumV);
//	}
//}



int main()
{
	scanf_s("%d%d", & n, &V);
	
	//获取每件物品的重量
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &w[i]);
	}

	//获取每件物品的价值
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &v[i]);
	}

	DFS(0, 0, 0);
	printf("%d", maxValue);
	
	return 0;
}
