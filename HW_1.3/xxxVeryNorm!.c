////#include <stdio.h>
////#include <stdbool.h>
////
////unsigned int collecton[1000];
////
////bool test();
////unsigned int fibonacci(int number);
////
////int main() {
////    if (!test()) return 1;
////
////    int sumAns = 0;
////
////    for (int i = 0; i < 100; i++) {
////        unsigned int number = fibonacci(i);
////
////        if (number <= 1000000 && number % 2 == 0) {
////            sumAns += number;
////        }
////    }
////    printf("%d", sumAns);
////}
////
////unsigned int fibonacci(int number) {
////    if (number == 0) {
////        collecton[0] = 0;
////        return collecton[0];
////    }
////    if (number == 1) {
////        collecton[1] = 1;
////        return collecton[1];
////    }
////    collecton[number] = collecton[number - 1] + collecton[number - 2];
////
////    return collecton[number];
////}
////
////
////
////bool test() {
////    int testSum = 0;
////    int expectedSum = 1569;
////    for (int i = 0; i <= 15; i++) {
////        testSum += fibonacci(i);
////    }
////    if ((expectedSum - testSum) > 0.0000001) {
////        printf("Test failed");
////        return false;
////    }
////    return true;
////}
////
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//#define testLength 5
//
//void selectionSortEven(int array[], int length);
//bool isSortedInEven(int array[], int length);
//bool tests();
//
//int main() {
//    if (!tests()) return 1;
//
//    int size = 0;
//
//    printf("Enter the size of the array: ");
//    int rez0 = scanf("%d", &size);
//
//    while (size <= 0)
//    {
//        printf("Invalid input (enter a natural number)");
//        printf("Enter the size of the array: ");
//        int rez1 = scanf("%d", &size);
//    }
//
//    int* array = malloc(sizeof(int) * size);
//    if (array == NULL)
//    {
//        printf("Memory is not avaialble!\n");
//        return 1;
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        printf("Enter the element N%d: ", i);
//        int rez2 = scanf("%d", &array[i]);
//    }
//
//    selectionSortEven(array, size);
//
//    printf("Sorted array: ");
//
//    for (int i = 0; i < size; i++) printf("%d ", array[i]);
//
//    free(array);
//    return 0;
//}
//
//void selectionSortEven(int array[], int length) {
//    for (int i = 0; i < length - 1; i += 2) {
//        for (int j = i + 2; j < length; j += 2) {
//            if (array[j] < array[i]) {
//                int temp = array[i];
//                array[i] = array[j];
//                array[j] = temp;
//            }
//        }
//    }
//}
//
//bool isSortedInEven(int array[], int length)
//{
//
//    for (int i = 0; i < length - 2; i += 2)
//    {
//        if (array[i] > array[i + 2])
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//bool tests()
//{
//    int test[testLength] = { 5, 4, 3, 2, 1 };
//    selectionSortEven(test, testLength);
//    if (!isSortedInEven(test, testLength))
//    {
//        printf("Failed on the example array\n");
//        return false;
//    }
//
//    int test1[testLength] = { 1, 2, 3, 4, 5 };
//    selectionSortEven(test1, testLength);
//    if (!isSortedInEven(test1, testLength))
//    {
//        printf("Failed on the sorted array\n");
//        return false;
//    }
//
//    int test2[testLength] = { 9, 9, 9, 9, 9 };
//    selectionSortEven(test2, testLength);
//    if (!isSortedInEven(test2, testLength))
//    {
//        printf("Failed on the array consisisting of the same element\n");
//        return false;
//    }
//    return true;
//}
//
