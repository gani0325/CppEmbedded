#include <stdio.h>

void main() {
	char aszData[3][16] = {
		"Test string",
		"Sample data",
		"Array of array"
	};

	printf("%c\n", aszData[1][3]);
	printf("%c\n", *(*(aszData + 1) + 3));

	printf("%s\n", aszData[0]);
	printf("%s\n", aszData + 1);
	printf("%s\n", *(aszData + 2));
	//printf("%p\n", aszData);
	//printf("%p\n", aszData[0]);
	//printf("%p\n", aszData + 1);
	//printf("%p\n", aszData + 2);
	
	printf("%p\n", *aszData);
	printf("%p\n", *aszData + 1);
	printf("%s\n", *(aszData + 1) + 1);

	char aszData2[16] = "hello";
	printf("%s\n", aszData2);
}
/*
p
p
Test string
Sample data
Array of array
est string
ample data
*/