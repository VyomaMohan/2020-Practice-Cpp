#include<iostream>
#include<fstream>
#include<ctype.h>

using namespace std;

class Book{
	int book_no;
	char bookname[20],bookauthor[20];
	float price;
	public:
		void getBook(){
			cout<<"Enter bookno:";
			cin>>book_no;
			cout<<"Enter bookname:";
			cin>>bookname;
			cout<<"Enter bookauthor:";
			cin>>bookauthor;
			cout<<"Enter price:";
			cin>>price;
		}
		void dispbook(){
			cout<<"\n"<<book_no;
			cout<<"\n"<<bookname;
			cout<<"\n"<<bookauthor;
			cout<<"\n"<<price;
		}
};

int main(){
	int i,n,op;
	int flag=1;
	Book A,books[20];
	fstream filestr("book.dat",ios::binary|ios::app);
	cout<<"No of records to enter";
	cin>>n;
	for(i=0;i<n;i++){
		books[i].getBook();
		filestr.write((char*)&books[i],sizeof(books[i]));
	}
	
	while(flag){
		cout<<"\n1. Display 2.Add book 3.Exit";
	cin>>op;
	
	switch(op){
		case 1:
		for(i=0;i<n;i++){
		filestr.read((char*)&books[i],sizeof(books[i]));
		books[i].dispbook();
		}
		break;
		case 2:
			books[n].getBook();
			filestr.write((char*)&books[n],sizeof(books[n]));
			n=n+1;
		break;
		case 3:
			flag=0;
		break;
	}
	
	
	}
	
	
	
}
