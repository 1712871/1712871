#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <wchar.h>
#include <stdlib.h>
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

int timN(FILE* f)
{
	int i = 0;
	while (!feof(f)){
		if (fgetwc(f) == L'\n')
			i++;
	}
	return i;
}

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

bool ktEmail(FILE* f, int pos, int a)
{
	wchar_t* s;
	s = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(f, pos, SEEK_SET);
	fgetws(s, a, f);
	int i = 0;
	while (s[i] != L'\0'){
		if (s[i] == L'@'){
			free(s);
			return true;
		}
		i++;
	}
	free(s);
	return false;
}

void doc(FILE* fIn, sinhvien *x, int N)
{
	int a, b = 3;
	for (int i = 0; i < N; i++){
		fseek(fIn, b, SEEK_SET);
		a = token(fIn, L',');
		fseek(fIn, b, SEEK_SET);
		if (ktEmail(fIn, b, a) == false){
			x[i].mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b, SEEK_SET);
			fgetws(x[i].mssv, a, fIn);
			b = ftell(fIn);
		}
		else{
			x[i].email = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].email, a, fIn);
			b = ftell(fIn);

			fseek(fIn, b, SEEK_SET);
			a = token(fIn, L',');
			x[i].mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b, SEEK_SET);
			fgetws(x[i].mssv, a, fIn);
			b = ftell(fIn);

		}


		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		fseek(fIn, b + 1, SEEK_SET);
		if (ktEmail(fIn, b + 1, a) == false){
			x[i].hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].hovaten, a, fIn);
			b = ftell(fIn);
		}
		else{
			x[i].email = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].email, a, fIn);
			b = ftell(fIn);

			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, L',');
			x[i].hovaten = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].hovaten, a, fIn);
			b = ftell(fIn);


		}

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		fseek(fIn, b + 1, SEEK_SET);
		if (ktEmail(fIn, b + 1, a) == false){
			x[i].khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].khoa, a, fIn);
			b = ftell(fIn);
		}
		else{
			x[i].email = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].email, a, fIn);
			b = ftell(fIn);

			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, L',');
			x[i].khoa = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].khoa, a, fIn);
			b = ftell(fIn);


		}

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		fseek(fIn, b + 1, SEEK_SET);
		if (ktEmail(fIn, b + 1, a) == false){
			x[i].khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].khoc, a, fIn);
			b = ftell(fIn);
		}
		else{
			x[i].email = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].email, a, fIn);
			b = ftell(fIn);

			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, L',');
			x[i].khoc = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].khoc, a, fIn);
			b = ftell(fIn);


		}

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		fseek(fIn, b + 1, SEEK_SET);
		if (ktEmail(fIn, b + 1, a) == false){
			x[i].ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].ngaysinh, a, fIn);
			b = ftell(fIn);
		}
		else{
			x[i].email = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].email, a, fIn);
			b = ftell(fIn);

			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, L',');
			x[i].ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].ngaysinh, a, fIn);
			b = ftell(fIn);


		}

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		fseek(fIn, b + 1, SEEK_SET);
		if (ktEmail(fIn, b + 1, a) == false){
			x[i].hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].hinhcanhan, a, fIn);
			b = ftell(fIn);
		}
		else{
			x[i].email = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].email, a, fIn);
			b = ftell(fIn);

			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, L',');
			x[i].hinhcanhan = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].hinhcanhan, a, fIn);
			b = ftell(fIn);
		}

		fseek(fIn, b + 1, SEEK_SET);
		a = token(fIn, L',');
		fseek(fIn, b + 1, SEEK_SET);
		if (ktEmail(fIn, b + 1, a) == false){
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
		}
		else{
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
		}

		

		fseek(fIn, b, SEEK_SET);
		if (fgetwc(fIn) == L','){

			fseek(fIn, b + 1, SEEK_SET);
			a = token(fIn, '\n');
			x[i].sothichx = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x[i].sothichx, a, fIn);
			b = ftell(fIn) + 2;
		}
		else{
			x[i].sothichx = L"Không có sở thích";
		}
	}
}

void ghiSoThich(FILE* f, wchar_t* s)
{
	bool kt = false;

	int N = len(s);

	for (int e = 0; e < N; e++){
		if (s[e] == L'"' || s[e] == L','){
			kt = true;
			break;
		}
	}

	if (kt == true){
		int i = 0;
		while (i < N){
			if (s[i] == L'"'){
				for (int j = i + 1; j < N; j++){
					if (s[j] == L'"'){
						fputws(L"\t\t\t\t\t\t\t\t<li>", f);
						for (int t = i + 1; t < j; t++)
							fputwc(s[t], f);
						fputws(L"</li>", f);
						i = j + 1;
						break;
					}
				}
			}
			else{
				for (int j = i; j < N; j++){
					if (s[j] == L','){
						fputws(L"\t\t\t\t\t\t\t\t<li>", f);
						for (int t = i; t < j; t++)
							fputwc(s[t], f);
						fputws(L"</li>", f);
						i = j;
						break;
					}
				}
			}
			i++;
		}
		if (s[N - 2] != L'"'){
			for (int j = N - 2; j >= 0; j--){
				if (s[j] == L','){
					fputws(L"\t\t\t\t\t\t\t\t<li>", f);
					for (int t = j + 1; t <= N - 2; t++){
						fputwc(s[t], f);
					}
					fputws(L"</li>", f);
					break;
				}
			}
		}
	}
	else{
		fputws(L"\t\t\t\t\t\t\t\t<li>", f);
		fputws(s, f);
		fputws(L"</li>", f);
	}
}

void replace(FILE* f, sinhvien p)
{
	wchar_t* e = themChuoi(p.mssv, L".html");
	FILE* tm;
	_wfopen_s(&tm, e, L"w, ccs=UTF-8");
	if (tm == NULL){
		wprintf(L"Không mở được FILE");
	}
	else{
		int i = 0;
		rewind(f);
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
		fputws(L" - ", tm);
		fputws(p.mssv, tm);

		rewind(f);
		pos = finding(f, L"Personal_Department\">Khoa ");
		fseek(f, i, SEEK_SET);
		while (ftell(f) < pos){
			fputwc(fgetwc(f), tm);
		}
		i = ftell(f);
		fputws(p.khoa, tm);

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
		while (ftell(f) < pos - 1){
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
		ghiSoThich(tm, p.sothichx);


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
		int n = 0;
		n = timN(fIn);
		sinhvien* x;
		x = (sinhvien*)malloc(sizeof(sinhvien)* n);
		doc(fIn, x, n);


		FILE* f;
		_wfopen_s(&f, L"mauhtml.txt", L"r, ccs=UTF-8");
		if (f == NULL){
			wprintf(L"Không mở được FILE!!!\n");
		}
		else{

			for (int i = 0; i < n; i++){
				replace(f, x[i]);
			}
			fclose(f);
		}
		fclose(fIn);
		free(x);
	}
}