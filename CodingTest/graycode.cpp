#include <stdio.h>
#include <stdlib.h>

double double selectSort(double double * array, int length){

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
	double double **table;
	double double *resultTable;
	double double result;
	double double *low_point_table;
	double double lowpoint;

	scanf("%d", &testcase);
	scanf("%d %d", &N, &M);

	for (i = 0 ; i < testcase; i++){
		
		resultTable = (double double*)malloc(sizeof(double double)*M);

		for (m = 0; m < M; m++){
			resultTable[m] = 0;
			
		}

		table = (double double**)malloc(sizeof(double double)*N);
		for ( n = 0; n < N; n ++)
			table[n] = (double double*)malloc(sizeof(double double)*(M * 2));

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

		/// ����Ʈ ���� ������ ã�Ƽ� ���ϱ⸸ �ϸ� �� 
		for (m = 1; m < M * 2; m=m+2){
			low_point_table = (double double*)malloc(sizeof(double double)*N);

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