#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

enum { R, L, U, D};
int room[1001][1001];

int main(int argc, char** argv) {
	
	freopen("mirrorinput.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	int temp, size, direction;
	int i, j;
	int check;
	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.

		// �� ũ��
		scanf("%d", &size);

		for (i = 0; i < 1001; i++){
			for (j = 0; j < 1001; j++){
				room[i][j] = -1;
			}
		}

		 // �ſ� ����
		 for (i = 0; i < size; i++){
			 scanf("%d", &temp);
			 for (j = 0; j < size; j++){
				 room[i][j] = temp / (int)pow(10, (size - j - 1));
				 temp = temp % (int)pow(10, (size - j - 1));
			 }
		 }
		 /*
		 for (int i = 0; i < size; i++){
			 for (int j = 0; j < size; j++){
				 printf("%d ", room[i][j]);
			 }
			 printf("\n"); 
		 }
		 */

		 direction = R;
		 i = 0;
		 j = 0;
		 check = 0;

		// printf("�� (%d, %d), %d, \n", i, j, check);
		 while ((i<size) && (j<size) && (i>-1) && (j>-1)){
			 //printf("   (%d, %d), %d, %d, \n", i, j, room[i][j], check);

			 if (room[i][j]%10 == 2)
			 {

				 //printf("%d, %d", room[i][j], (room[i][j] / 10));
				 // ������ ������ Ȯ�� 
				 if (room[i][j] / 10 !=1){
					 room[i][j] += 10;
					 check++;
				 }
				 else{

				 }
				 // ���� ��ȯ
				 switch (direction)
				 {
					case R:
						direction = D;
						i++;
						break;
					case L:
						direction = U;
						i--;
						break;
					case U:
						direction = L;
						j--;
						break;
					case D:
						direction = R;
						j++;
						break;
				 }

			 }
			 else if (room[i][j] % 10 == 1){

				 //printf("%d, %d", room[i][j], (room[i][j] / 10));
				 // ������ ������ Ȯ�� 
				 if (room[i][j] / 10 !=1){
					 room[i][j] += 10;
					 check++;
				 }
				 else{

				 }

				 // ���� ��ȯ
				 switch (direction)
				 {

					case R:
						direction = U;
						i--;
						 break;
					case L:
						direction = D;
						i++;
						 break;
					case U:
						direction = R;
						j++;
						 break;
					case D:
						direction = L;
						j--;
						 break;
				 }

			 }
			 else
			 {
				 switch (direction)
				 {
				 case R:
					 direction = R;
					 j++;
					 break;
				 case L:
					 direction = L;
					 j--;
					 break;
				 case U:
					 direction = U;
					 i--;
					 break;
				 case D:
					 direction = D;
					 i++;
					 break;
				 }
			 }

			 //printf("�� (%d, %d), %d\n", i, j, check);

		 }
		 
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", check);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}