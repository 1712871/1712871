#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<wchar.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <io.h> 

struct sinhvien
{
	wchar_t* mssv;
	wchar_t* hovaten;
	wchar_t* khoc;
	wchar_t* khoa;
	wchar_t* ngaysinh;
	wchar_t* hinhcanhan;
	wchar_t* email;
	wchar_t* motabanthan;
	wchar_t* sothichx;
};

int token(FILE* f, wchar_t h)
{
	wchar_t ch;
	int i = 0;
	while (!feof(f)){
		ch = fgetwc(f);
		if (ch != h)
		{
			i++;
		}
		else
			return i + 1;
	}
	return i;
}

void doc(FILE* fIn, sinhvien &x, int &begin)
{
	fseek(fIn, begin, SEEK_SET);
	int a = token(fIn, L',');
	x.mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, begin, SEEK_SET);
	fgetws(x.mssv, a, fIn);
	int b = ftell(fIn);
	
	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.hovaten, a, fIn);
	b = ftell(fIn);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.khoa, a, fIn);
	b = ftell(fIn);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.khoc, a, fIn);
	b = ftell(fIn);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.ngaysinh, a, fIn);
	b = ftell(fIn);
	
	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.hinhcanhan, a, fIn);
	b = ftell(fIn);

	fseek(fIn, b + 1, SEEK_SET);
	a = token(fIn, L',');
	x.email = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.email, a, fIn);
	b = ftell(fIn);
	
	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'"'){
		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x.motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x.motabanthan, a, fIn);
		b = ftell(fIn);
	}
	else{
		fseek(fIn, b + 2, SEEK_SET);
		a = token(fIn, L'"');
		x.motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x.motabanthan, a, fIn);
		b = ftell(fIn) + 1;
	}

	fseek(fIn, b, SEEK_SET);
	if (fgetwc(fIn) == L','){
		if (fgetwc(fIn) != L'"'){
			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, '\n');
			x.sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x.sothichx, a, fIn);
			b = ftell(fIn);
			begin = b;
		}
		else{
			fseek(fIn, b + 2, SEEK_SET);
			a = token(fIn, '"');
			x.sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 2, SEEK_SET);
			fgetws(x.sothichx, a, fIn);

			b = ftell(fIn) + 1;
		}
		begin = b + 2;
	}
	else{
		begin = b;
	}
}

void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT); 
	_setmode(_fileno(stdin), _O_U16TEXT); 
	FILE* fIn;
	_wfopen_s(&fIn, L"ds1.csv", L"r, ccs=UTF-8");
	if (fIn == NULL)
	{
		wprintf(L"Không mở được FILE!!!\n");
	}
	else
	{
		int begin = 3;
		sinhvien* x;
		x = (sinhvien*)malloc(sizeof(sinhvien)* 11);
		for (int i = 0; i <= 10; i++){
			doc(fIn, x[i], begin);
		}
		free(x);
		fclose(fIn);
	}

}