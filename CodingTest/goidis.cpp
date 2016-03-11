#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 65~ 90 대문자 
// 97~ 122 소문자

using namespace std;

char* reverse(char *input){

	char * output = (char*)malloc(sizeof(char));
	char a;
	int i = 0, j = 0;
//    int out_length = 0;
	int in_length = strlen(input);
	
	/*
	//printf("%d", in_length);
	// 새롭게 배열 만들 크기 정하기 
	for (i = 0; i < in_length; i++){
		a = input[i];
		printf("%c", a);

		if ((a > 64) && (a < 91))
			out_length++;
		else if ((a > 96) && (a < 123))
			out_length++;
		else{}

	}
	printf("%d \n", out_length);
	*/
	//output = (char*)malloc(sizeof(char)*out_length);

	// 만들어서 거꾸로 넣기 
	for (i = in_length-1; i > -1; i--){
		a = input[i];
		if ((a > 64) && (a < 91))
			output[j++] = a;
		else if ((a > 96) && (a < 123))
			output[j++] = a;
		else{}
			
	}
	
	return output;
}
bool search(char * from, char *to){

	int i = 0; 
	int j = 0; 
	int to_length = strlen(to) - 1;
	int from_length = strlen(from);
	
	for(i = 0 ; i < from_length; i++){

		if (from[i] == to[j]){

			j = to_length;
			i = i + to_length;

			while (from[i] == to[j]){
				i--;
				j--;
				if (j == 0){
					return true;
				}
			}
		}

		j = 0;
	}

	return false;
}

void findIdxValue(int * inarray, int length){
	int * resultarray = (int*)malloc(sizeof(int)*2);
	int value = 0;
	int idx = 0;
	int i = 0;
	
	for (i = 0; i < length; i++){

		if (inarray[0] == inarray[i]){
			value++;
		}
		

	}
	resultarray[0] = idx;


}
int main()
{
	char * input = "asdfqabqqqacd";//"asdf%^$qwer";
	char * search_char = "qqq";
	char * output ;

	int i = 0;

	bool aaa;


	printf("%d", strlen(search_char));
	// 동적할당으로 합시다. 

	// input 값을 이용해서 
	/*
	 aaa= search(input, search_char);
	 if (aaa)
		 printf("true\n");
	 else
		 printf("false\n");
	*/
	/*
	output = reverse(input);
	
	//printf("\n %d\n", strlen(output));
	
	for (i = 0; i < strlen(output); i++){
		printf("%c", output[i]);
	}
	*/
	return 0;
}