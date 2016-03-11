#include <stdio.h>
#include <stdlib.h>

long long selectSort(long long * array, int length){

	int minIdx;
	int j;
	int temp;

		minIdx = 0;

		for (j = 1; j < length; j++){
			if (array[j]<array[minIdx])
				minIdx = j;
		}
		temp = array[0];
		array[0] = array[minIdx];
		array[minIdx] = temp;
	
	return array[0];
}
int main(){

	int testcase =0;
	int i, j=0, n, m;
	int N, M;
	long long **table;
	long long *resultTable;
	long long result;
	long long *low_point_table;
	long long lowpoint;

	scanf("%d", &testcase);
	scanf("%d %d", &N, &M);

	for (i = 0 ; i < testcase; i++){
		
		resultTable = (long long*)malloc(sizeof(long long)*M);

		for (m = 0; m < M; m++){
			resultTable[m] = 0;
			
		}

		table = (long long**)malloc(sizeof(long long)*N);
		for ( n = 0; n < N; n ++)
			table[n] = (long long*)malloc(sizeof(long long)*(M * 2));

		for (n = 0; n < N; n++){
			for (m = 0; m < M*2; m++)
				scanf("%d", &table[n][m]);
		}

	
	
		for (n = 0; n < N; n++){
			for (m = 0; m < M * 2; m++){
				if (m % 2 != 1){
					resultTable[j] += table[n][m];
					//	printf(" %d += %d ", resultTable[j], table[n][m]);
				}
				else{
					resultTable[j] -= table[n][m];
					j++;
						//printf(" %d -= %d ", resultTable[j], table[n][m]);
				}
			}
			j = 0;
			//printf("\n");
		}

		/// 포인트 가장 작은거 찾아서 더하기만 하면 됨 
		for (m = 1; m < M * 2; m=m+2){
			low_point_table = (long long*)malloc(sizeof(long long)*N);

			for (n = 0; n < N; n++){
				low_point_table[n] = table[n][m];
			}
			lowpoint = selectSort(low_point_table, N);
			//printf("%d  ", lowpoint);
			resultTable[j] += lowpoint;
			
			j++;
			free(low_point_table);
		}

		result = selectSort(resultTable, M);
		
		printf("%d", result);
	}
	return 0;
}