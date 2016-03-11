// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	int stoneNum;
	int k; 
	
	int temp;
	int front;
	int jump;
	int * stone;
	int now;
	int i=0;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		
		jump = 0;
		front = 0;

		scanf("%d", &stoneNum);	
		stone = new int[stoneNum+1];
		// �� ��ġ �Է� 
		stone[0] = 0;
		for (int i = 1; i < stoneNum+1 ; i++){
			scanf("%d", &temp);
			stone[i] = temp;
		}


		scanf("%d", &k);	// cin ��� ����

		i = 0;

		now = stone[i];
		front += k;

		jump++;
		while (front < temp){

			printf("0     ���� i : %d / now : %d / front : %d / stone[i] : %d  \n", i, now, front, stone[i]);

			if (front < stone[i]){
				i--;
				now = stone[i--];
				front = now +k;
				i++;
				jump++;
				printf("2 i-- ���� i : %d / now : %d / front : %d / stone[i] : %d  \n", i, now, front, stone[i]);

				if (front < stone[i + 1]){
					jump = -1;
					break;
				}

			}
			else if (front > stone[i]){
				i++;
				printf("1 i++ ���� i : %d / now : %d / front : %d / stone[i] : %d  \n", i, now, front, stone[i]);


			}
			else{

				now = stone[i];
				front = now + k;
				jump++;

				printf("3     ���� i : %d / now : %d / front : %d / stone[i] : %d  \n", i, now, front, stone[i]);
				if (front < stone[i + 1]){
					jump = -1;
					break;
				}
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", jump);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}

/*
// �� ��ġ �Է�
for (int i = 0; i < stoneNum - 1; i++){
scanf("%d", &temp);
stone += 1 << temp;
printf("%d - ", 1 << temp);
printf("%d\n", stone);
}
// ������ ��ġ���� �Է� �׷��� ���� �迭 ���� ����
scanf("%d", &size);
stone += 1 << size;

plane = new int[size];
plane[0] = 1;
for (int i = 0; i < size+1; i++){

((1 << i) & stone) ? plane[i] = 1 : plane[i] = 0;
((1 << i) & stone) ? temp= 1 : temp = 0;
printf("%d ", temp);
//printf("%d ", plane[i]);
}
*/