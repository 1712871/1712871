#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

struct Student{
	char *MSSV;
	wchar_t *HoTen;
	wchar_t *Khoa;
	int Khoas;
	char *NgaySinh;
	char *HACN;
	wchar_t *MTBT;
	wchar_t *SoThich;
};

Student* docfileCSV(FILE* f)
{
	
	f = fopen("CSV.text", "rb");
	if (!f)
		printf("Can not open this file");
	else{
		Student* u = (Student*)malloc(sizeof(struct Student));
		fseek(f, 1, 0);
		char s[20];
		int i = 0;
		do{
			s[i] = getc(f);
			i++;
		} while (s[i] != '"');
		
	}
}