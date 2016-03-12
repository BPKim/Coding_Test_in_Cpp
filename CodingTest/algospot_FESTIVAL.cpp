#include <stdio.h>
#include <iostream>


int main(int argc, char** argv) {

	freopen("festivalinput.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	int i, j;
	int day;
	int l;
	 double * schedule;
	int min;
	int sum;
	 double min_price;
	 double price;
	

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {

		min_price = 100;

		getchar();
		
		scanf("%d", &day);

		getchar();
		scanf("%d", &l);

		schedule = new  double [day];

		for ( i = 0; i < day; i++) {
			getchar();
			scanf("%lf", &schedule[i]);
		}

		for ( i = 0; i < day; i++){
			sum = 0;
			for ( j = i; j < day; j++) {
				sum += schedule[j];			

				if (j - i + 1 >= l) {
					price = sum / (double)(j - i + 1);
					if (min_price > price)
						min_price = price;
				}
			}
		}

		printf("%.11f\n", min_price);
	}

	return 0;
}