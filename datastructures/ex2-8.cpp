#include <stdio.h>

void main() {
	int i = 10, j = 20;
	printf("\n i의 값 = %d \n j의 값 = %d", i, j);
	printf("\n i의 메모리 주소(&i) = %u", &i);
	printf("\n j의 메모리 주소(&j) = %u", &j);

	int *ptr;
	ptr = &i;
	printf("\n\n << ptr=&i 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 창조 값(*ptr) = %d", *ptr);

	ptr = &j;
	printf("\n\n << ptr = &j실행 >>");
	printf("\n ptr의 메모리 주소(&prt) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 창조값(*ptr) =%d", *ptr);

	i = *ptr;
	printf("\n\n << i=*ptr 실행 >>");
	printf("\n i의 값 = %d", i);

	getchar();
}