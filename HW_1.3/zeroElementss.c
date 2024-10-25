//#include <stdio.h>
//
//int main(void) {
//	int lenArr = 0;
//	printf("enter the length of the array (max 1000): ");
//	int result = scanf("%d", &lenArr);
//	printf("enter elements via ENTER\n");
//
//	char seq[1000];
//
//	for (int i = 0; i < lenArr; i++) {
//		int perem = 0;
//		int rez = scanf("%d", &perem);
//		seq[i] = perem;
//	}
//
//	int countZero = 0;
//
//	for (int i = 0; i < lenArr; i++) {
//		if (seq[i] == 0) countZero++;
//	}
//
//	printf("number of zeros in your string: %d\n", countZero);
//}