#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<iomanip>

using namespace std;

fstream list;
bool close = false;

void textColor(int x){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,x);
}

class Menu{
	public:
		void importStu();
		void showList();
};

void menu();
void saveFile();
void openFile();
void exit();

void Menu::importStu(){
	int index;
	cout<<"Nhap so luong sinh vien : ";	cin>>index;
	for(int i = 1; i <= index; i++){
		int MSSV,birth;
		string name0,name1,address,class_,major,cohort,gender;
		int point1,point2,point3;
				
			
		cout<<"Nhap thong tin sinh vien:\n";
		cout<<"Nhap MSSV: ";			cin>>MSSV;					list<<MSSV<<"|";	fflush(stdin);
		cout<<"Nhap ho va ten lot: ";	getline(std::cin,name0);	list<<name0<<" ";	fflush(stdin);
		cout<<"Nhap ten sinh vien: ";	getline(std::cin,name1);	list<<name1<<"|";	fflush(stdin);
		cout<<"Nhap nam sinh: ";		cin>>birth;					list<<birth<<"|";	fflush(stdin);
		cout<<"Nhap gioi tinh <nam/nu> : ";	cin>>gender;			list<<gender<<"|";	fflush(stdin);
		cout<<"Nhap dia chi: ";			getline(std::cin,address);	list<<address<<"|";	fflush(stdin);
		cout<<"Nhap ma lop: ";			cin>>class_;				list<<class_<<"|";	fflush(stdin);
		cout<<"Nhap nganh hoc: ";		getline(std::cin,major);	list<<major<<"|";	fflush(stdin);
		cout<<"Nhap khoa hoc: ";		cin>>cohort;				list<<cohort<<"|";	fflush(stdin);
		
		cout<<"Nhap thong tin 3 mon: \n";
		cout<<"Nhap diem mon \"Lap trinh tren Window\" : ";		cin>>point1;	list<<point1<<" ";
		cout<<"Nhap diem mon \"Lap trinh huong doi tuong\" : ";	cin>>point2;	list<<point2<<" ";
		cout<<"Nhap diem mon \"Ky thuat lap trinh\" : ";			cin>>point3;	list<<point3<<" ";		
		
		list<<endl;
	}
	menu();
}

void Menu::showList(){
	int w = 10;
	cout<<setw(w*5)<<"DANH SACH SINH VIEN"<<endl;
	cout<<"   MSSV"<<setw(w*2)<<"Ho va ten"<<setw(w+w/2)<<"NSinh"<<
	setw(w)<<"Phai"<<setw(w)<<"Dia chi"<<setw(w)<<"Ma lop"<<setw(w)<<"Nganh hoc"<<
	setw(w)<<"Khoa"<<setw(w)<<"M1"<<setw(w)<<"M2"<<setw(w)<<"M3"<<setw(w)<<"DTB"<<
	setw(w)<<"Kqua"<<setw(w)<<"X.Loai"<<endl;
	
	string MSSV,birth;
	string name,address,class_,major,cohort,gender;
	string point1,point2,point3;
	string line;
	while(getline(list,line)){
		int i = 0;
		while(i < line.length()){
			if(line[i] != '|'){
				MSSV += line[i];	i++;
			}
			else{
				i++;
				if(line[i] != '|'){
					name += line[i];	i++;
				}
			}
		}
	}
	
	int c;
	cin>>c;
	
	menu();
}

void menu(){
	system("cls");
	int check;
	cout<<"BAN DANG O MENU THUC HIEN\n";
	cout<<"1. Nhap sinh vien\n";
	cout<<"2. Xem danh sach sinh vien\n";
	cout<<"3. Sap xep danh sach sinh vien\n";
	cout<<"4. Thay doi thong tin sinh vien\n";
	cout<<"5. Xoa danh sach\n";
	cout<<"6. Tim kiem sinh vien trong danh sach\n";
	cout<<"7. Thong ke\n";
	cout<<"0. Thoat\n";
	
    cout<<"Lua chon cua ban :";		cin>>check;
    Menu myOpj;
	switch(check){
		case 1:	myOpj.importStu();
				break;
		case 2: myOpj.showList();
				break;
	}
}

void saveFile(){
	
}

void openFile(){
	string name;
	cout<<"Nhap duong dan cua File can Open : ";
	cin>>name;
	list.open(name.c_str(), ios::in | ios::app);
	if(list.is_open())	cout<<"Open File Susessfull";
}

void exit(){
	
}

void start(){
	int check;
    cout<<"CHAO MUNG DEN VOI CHUONG TRINH QUAN LY SINH VIEN\n";
    cout<<"1. Menu\n";
    cout<<"2. Save File\n";
    cout<<"3. Open File\n";
    cout<<"4. Exit\n";
    
    cout<<"Lua chon cua ban :";
    cin>>check;
    if(check == 1)	menu();
    if(check == 2)	saveFile();
    if(check == 3)	openFile();
    if(check == 4)	exit();
}

int main(){
	textColor(11);
    while(!close){
    	system("cls");
    	start();
	}
    
    return 0; 
}
