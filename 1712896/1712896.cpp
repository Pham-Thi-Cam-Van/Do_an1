#include <fcntl.h>
#include <io.h>   
#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include<ctype.h>
#include<malloc.h>
#include<wchar.h>
struct SINHVIEN{
	wchar_t *MSSV;
	wchar_t *HoTen;
	wchar_t *Khoa;
	int KHoc;
	wchar_t *NgaySinh;
	wchar_t *HACN;
	wchar_t *MTBT;
	wchar_t *SoThich1;
	wchar_t *SoThich2;
};
struct CHUOI
{
	wchar_t* KHOA;;
	wchar_t* wcs;
};
int StringLength(wchar_t s[])
{
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}return i;
}
wchar_t* Chinh(wchar_t* str)
{
	int k = 0;
	while (k != 2){
		for (int i = 0; i < wcslen(str) - 1; i++)
			str[i] = str[i + 1];
		str[wcslen(str) - 1] = '\0';
		k++;
	}
	for (int i = 0; i < wcslen(str); i++)
	if (str[i] == '"') str[i] = '\0';
	return str;
}
int Chuyenchuoi(wchar_t* str)
{
	int n = 0;
	for (int i = 0; i<wcslen(str); i++){
		n = n * 10 + (str[i] - 48);
	}
	return n;
}
int demdong(FILE* fp)
{
	_wfopen_s(&fp, L"thongtinsv.csv", L"r+, ccs=UTF-8");
	wchar_t ch; int dem = 0;
	do{
		ch = fgetwc(fp);
		if (ch == '\n') dem++;
	} while (ch != WEOF);
	fclose(fp);
	return dem + 1;
}
void docfile(FILE* &fp)
{

	SINHVIEN a[10]; CHUOI h[10];
	wchar_t *c[10];
	c[0] = L"1712450.html";
	c[1] = L"1712451.html";
	c[2] = L"1712452.html";
	c[3] = L"1712453.html";
	c[4] = L"1712454.html";
	c[5] = L"1712455.html";
	c[6] = L"1712456.html";
	c[7] = L"1712457.html";
	c[8] = L"1712458.html";
	c[9] = L"1712459.html";
	wchar_t* e[10];
	wchar_t* str = L",";
	wchar_t** b = (wchar_t**)malloc(255 * sizeof(wchar_t));
	wchar_t* p = (wchar_t*)malloc(255 * sizeof(wchar_t));
	int n = demdong(fp);
	_wfopen_s(&fp, L"thongtinsv.csv", L"r+, ccs=UTF-8");
	if (!fp) wprintf(L"khong mo duoc");
	else{
		for (int i = 0; i < n; i++){
			fseek(fp, 0L, SEEK_CUR);
			fgetws(p, 256, fp);
			h[0].wcs = wcstok_s(p, str, b);
			int k = 0;
			while (h[0].wcs != NULL)
			{
				h[k].KHOA = h[0].wcs;
				h[0].wcs = wcstok_s(NULL, str, b);
				k++;
			}
			e[i] = h[0].KHOA;
			a[i].MSSV = h[0].KHOA;
			Chinh(a[i].MSSV);
			a[i].HoTen = h[1].KHOA; Chinh(a[i].HoTen);
			a[i].Khoa = h[2].KHOA; Chinh(a[i].Khoa);
			a[i].KHoc = Chuyenchuoi(h[3].KHOA);
			a[i].NgaySinh = h[4].KHOA; Chinh(a[i].NgaySinh);
			a[i].HACN = h[5].KHOA; Chinh(a[i].HACN);
			a[i].MTBT = h[6].KHOA; Chinh(a[i].MTBT);
			if (k >= 8){
				a[i].SoThich1 = h[7].KHOA; Chinh(a[i].SoThich1);
				if (k >= 9){
					a[i].SoThich2 = h[8].KHOA; Chinh(a[i].SoThich2);
				}
				else wprintf(L"\n");
			}
			FILE* fp1;
			_wfopen_s(&fp1, c[i], L"w, ccs=UTF-8");
			if (fp1 != NULL)
			{
				fwprintf(fp1, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
				fwprintf(fp1, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
				fwprintf(fp1, L"	<head>\n");
				fwprintf(fp1, L"		<meta http-equiv=\"Content - Type\" content=\"text/html; charset = utf-8\" />\n");
				fwprintf(fp1, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
				fwprintf(fp1, L"		<title>HCMUS - %ls</title>\n", a[i].HoTen);
				fwprintf(fp1, L"	</head>\n");
				fwprintf(fp1, L"	<body>\n");
				fwprintf(fp1, L"		<div class=\"Layout_container\">\n");
				fwprintf(fp1, L"			<!-- Begin Layout Banner Region -->\n");
				fwprintf(fp1, L"			<div class=\"Layout_Banner\" >\n");
				fwprintf(fp1, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
				fwprintf(fp1, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
				fwprintf(fp1, L"			</div>\n");
				fwprintf(fp1, L"			<!-- End Layout Banner Region -->\n");
				fwprintf(fp1, L"			<!-- Begin Layout MainContents Region -->\n");
				fwprintf(fp1, L"			<div class=\"Layout_MainContents\">\n");
				fwprintf(fp1, L"				<!-- Begin Below Banner Region -->\n");
				fwprintf(fp1, L"				<div class=\"Personal_Main_Information\">\n");
				fwprintf(fp1, L"					<!-- Begin Thông tin cá nhân của thầy cô ----------------------------------------------------------------------------------------- -->\n");
				fwprintf(fp1, L"					<div class=\"Personal_Location\">\n");
				fwprintf(fp1, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
				fwprintf(fp1, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", a[i].HoTen, a[i].MSSV);
				fwprintf(fp1, L"						<div class=\"Personal_Department\">Khoa %ls</div>\n", a[i].Khoa);
				fwprintf(fp1, L"						<br />\n");
				fwprintf(fp1, L"						<div class=\"Personal_Phone\">\n");
				fwprintf(fp1, L"							Email: %ls@gmail.com\n", e[i]);
				fwprintf(fp1, L"						</div>\n");
				fwprintf(fp1, L"						<br />\n");
				fwprintf(fp1, L"						<br />\n");
				fwprintf(fp1, L"					</div>\n");
				fwprintf(fp1, L"					<!-- End Thông tin cá nhân của thầy cô ----------------------------------------------------------------------------------------- -->\n");
				fwprintf(fp1, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
				fwprintf(fp1, L"						<img src=\"Images/HinhCaNhan.jpg\" class=\"Personal_Hinhcanhan\" />\n");
				fwprintf(fp1, L"					</div>\n");
				fwprintf(fp1, L"				</div>\n");
				fwprintf(fp1, L"				<!-- End Below Banner Region -->\n");
				fwprintf(fp1, L"				<!-- Begin MainContents Region -->\n");
				fwprintf(fp1, L"				<div class=\"MainContain\">\n\n");
				fwprintf(fp1, L"					<!-- Begin Top Region -->\n");
				fwprintf(fp1, L"					<div class=\"MainContain_Top\">\n\n");
				fwprintf(fp1, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
				fwprintf(fp1, L"                        <div>\n");
				fwprintf(fp1, L"                            <ul class=\"TextInList\">\n");
				fwprintf(fp1, L"                                <li>Họ và tên: %ls</li>\n", a[i].HoTen);
				fwprintf(fp1, L"				<li>MSSV: %ls</li>\n", a[i].MSSV);
				fwprintf(fp1, L"				<li>Sinh viên khoa %ls</li>\n", a[i].Khoa);
				fwprintf(fp1, L"				<li>Ngày sinh: %ls</li>\n", a[i].NgaySinh);
				fwprintf(fp1, L"				<li>Email: %ls@gmail.com</li>\n", e[i]);
				fwprintf(fp1, L"							</ul>\n");
				fwprintf(fp1, L"						</div>\n");
				fwprintf(fp1, L"                        <div class=\"InfoGroup\">Sở thích</div>\n");
				fwprintf(fp1, L"                        <div>\n");
				fwprintf(fp1, L"                            <ul class=\"TextInList\">\n");
				if (k >= 8){
					fwprintf(fp1, L"				<li>%ls</li>\n", a[i].SoThich1);
					if (k >= 9)
						fwprintf(fp1, L"				<li>%ls</li>\n", a[i].SoThich2);
					else fwprintf(fp1, L"\n");
				}
				fwprintf(fp1, L"							</ul>\n");
				fwprintf(fp1, L"						</div>\n");
				fwprintf(fp1, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
				fwprintf(fp1, L"						<div class=\"Description\">\n");
				fwprintf(fp1, L"                            %ls.\n", a[i].MTBT);
				fwprintf(fp1, L"						</div>\n\n");
				fwprintf(fp1, L"					</div>\n");
				fwprintf(fp1, L"				</div>\n");
				fwprintf(fp1, L"			</div>\n\n");
				fwprintf(fp1, L"			<!-- Begin Layout Footer -->\n");
				fwprintf(fp1, L"			<div class=\"Layout_Footer\">\n");
				fwprintf(fp1, L"				<div class=\"divCopyright\">\n");
				fwprintf(fp1, L"					<br />\n");
				fwprintf(fp1, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
				fwprintf(fp1, L"					<br />\n");
				fwprintf(fp1, L"					@2018</br>\n");
				fwprintf(fp1, L"					Đồ án giữ kỳ</br>\n");
				fwprintf(fp1, L"				Kỹ thuật lập trình</br>\n");
				fwprintf(fp1, L"				TH2018/04</br>\n");
				fwprintf(fp1, L"				1712896 - Phạm Thị Cẩm Vân</br>\n");
				fwprintf(fp1, L"				</div>\n");
				fwprintf(fp1, L"			</div>\n");
				fwprintf(fp1, L"			<!-- End Layout Footer -->\n");
				fwprintf(fp1, L"		</div>\n");
				fwprintf(fp1, L"	</body>\n");
				fwprintf(fp1, L"</html>");
			}
			fclose(fp1);
		}
		fclose(fp);
		free(p); free(b);
	}
}
void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	FILE* fp;
	docfile(fp);
}