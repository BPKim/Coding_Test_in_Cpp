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
	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.

		// 방 크기
		scanf("%d", &size);

		for (i = 0; i < 1001; i++){
			for (j = 0; j < 1001; j++){
				room[i][j] = -1;
			}
		}

		 // 거울 저장
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

		// printf("전 (%d, %d), %d, \n", i, j, check);
		 while ((i<size) && (j<size) && (i>-1) && (j>-1)){
			 //printf("   (%d, %d), %d, %d, \n", i, j, room[i][j], check);

			 if (room[i][j]%10 == 2)
			 {

				 //printf("%d, %d", room[i][j], (room[i][j] / 10));
				 // 지나간 방인지 확인 
				 if (room[i][j] / 10 !=1){
					 room[i][j] += 10;
					 check++;
				 }
				 else{

				 }
				 // 방향 변환
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
				 // 지나간 방인지 확인 
				 if (room[i][j] / 10 !=1){
					 room[i][j] += 10;
					 check++;
				 }
				 else{

				 }

				 // 방향 변환
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

			 //printf("후 (%d, %d), %d\n", i, j, check);

		 }
		 
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", check);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}