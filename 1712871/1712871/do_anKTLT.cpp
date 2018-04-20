#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<wchar.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <io.h> 

#define n 10

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

int len(wchar_t s[])
{
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}
	return i + 1;
}

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

int finding(FILE* f, wchar_t s[])
{
	int j, pos = ftell(f), lens = len(s);
	while (!feof(f)){
		j = 0;
		fseek(f, pos, SEEK_SET);
		for (int i = 0; i < lens; i++){
			if (fgetwc(f) != s[i]){
				break;
			}
			else{
				j++;
			}
		}
		if (j == lens - 1){
			return ftell(f) - 1;
		}
		else{
			fseek(f, pos + 1, SEEK_SET);
		}
		pos++;
	}
	return -1;
}

wchar_t* themChuoi(wchar_t* cha, wchar_t* con)
{
	int a = len(cha), b = len(con);
	wchar_t* tm = (wchar_t*)malloc(sizeof(wchar_t)*(a + b));
	for (int i = 0; i < a - 1; i++)
		tm[i] = cha[i];
	for (int i = 0; i <= b; i++)
		tm[i + a - 1] = con[i];
	return tm;
}

void doc(FILE* fIn, sinhvien *x, int N)
{
	int begin = 3;
	for (int i = 0; i < N; i++){
		fseek(fIn, begin, SEEK_SET);
		int a = token(fIn, L',');
		x[i].mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, begin, SEEK_SET);
		fgetws(x[i].mssv, a, fIn);
		int b = ftell(fIn);

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x[i].hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x[i].hovaten, a, fIn);
		b = ftell(fIn);

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x[i].khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x[i].khoa, a, fIn);
		b = ftell(fIn);

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x[i].khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x[i].khoc, a, fIn);
		b = ftell(fIn);

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x[i].ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x[i].ngaysinh, a, fIn);
		b = ftell(fIn);

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x[i].hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x[i].hinhcanhan, a, fIn);
		b = ftell(fIn);

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		x[i].email = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x[i].email, a, fIn);
		b = ftell(fIn);

		fseek(fIn, b + 1, SEEK_SET);
		if (fgetwc(fIn) != L'"'){
			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, L',');
			x[i].motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].motabanthan, a, fIn);
			b = ftell(fIn);
		}
		else{
			fseek(fIn, b + 2, SEEK_SET);
			a = token(fIn, L'"');
			x[i].motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 2, SEEK_SET);
			fgetws(x[i].motabanthan, a, fIn);
			b = ftell(fIn) + 1;
		}

		fseek(fIn, b, SEEK_SET);
		if (fgetwc(fIn) == L','){
			if (fgetwc(fIn) != L'"'){
				fseek(fIn, b + 1, SEEK_SET);
				a = token(fIn, '\n');
				x[i].sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
				fseek(fIn, b + 1, SEEK_SET);
				fgetws(x[i].sothichx, a, fIn);
				b = ftell(fIn);
				begin = b;
			}
			else{
				fseek(fIn, b + 2, SEEK_SET);
				a = token(fIn, '"');
				x[i].sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
				fseek(fIn, b + 2, SEEK_SET);
				fgetws(x[i].sothichx, a, fIn);

				b = ftell(fIn) + 1;
			}
			begin = b + 2;
		}
		else{
			begin = b;
		}
	}
}

void replace(FILE*& f, sinhvien p)
{
	wchar_t* e = themChuoi(p.mssv, L".html");
	FILE* tm;
	wprintf(L"%ls\n", e);
	_wfopen_s(&tm, e, L"w, ccs=UTF-8");
	if (tm == NULL){
		wprintf(L"Không mở được FILE");
	}
	else{
		int i = 0;
		int pos = finding(f, L"<title>HCMUS - ");
		rewind(f);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.hovaten, tm);

		rewind(f);
		pos = finding(f, L"Personal_FullName\">");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.hovaten, tm);

		rewind(f);
		pos = finding(f, L"Email: ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.email, tm);


		rewind(f);
		pos = finding(f, L"Images/ ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f) + 1;
		fputws(p.hinhcanhan, tm);

		rewind(f);
		pos = finding(f, L"<li>Họ và tên: ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.hovaten, tm);

		rewind(f);
		pos = finding(f, L"<li>MSSV: ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.mssv, tm);

		rewind(f);
		pos = finding(f, L"<li>Sinh viên khoa ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.khoa, tm);

		rewind(f);
		pos = finding(f, L"<li>Ngày sinh: ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.ngaysinh, tm);

		rewind(f);
		pos = finding(f, L"<li>Email: ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.email, tm);

		rewind(f);
		pos = finding(f, L"<ul class=\"TextInList\"> ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(L"\t\t\t\t\t\t\t\t<li>", tm);
		fputws(p.sothichx, tm);
		fputws(L"</li>", tm);

		rewind(f);
		pos = finding(f, L"<div class=\"Description\">");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(L"\n\t\t\t\t\t\t\t", tm);
		fputws(p.motabanthan, tm);

		fgetwc(f);
		while (!feof(f)){
			fputwc(fgetwc(f), tm);
		}
		fclose(tm);
	}
	free(e);
}

void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE* fIn;
	_wfopen_s(&fIn, L"ds1.csv", L"r+, ccs=UTF-8");

	if (fIn == NULL)
	{
		wprintf(L"Không mở được FILE!!!\n");
	}
	else
	{
		sinhvien* x;
		x = (sinhvien*)malloc(sizeof(sinhvien)* n);

		doc(fIn, x, n);
		for (int i = 0; i < n; i++)
			wprintf(L"%ls\n", x[i].mssv);


		FILE* f;
		_wfopen_s(&f, L"mauhtml.txt", L"r, ccs=UTF-8");
		if (f == NULL){
			wprintf(L"Không mở được FILE!!!\n");
		}
		else{
			for (int i = 0; i < n; i++){
				replace(f, x[i]);
				wprintf(L"  ");
			}
			fclose(f);
		}
		fclose(fIn);
		free(x);
	}



	_getch();
}