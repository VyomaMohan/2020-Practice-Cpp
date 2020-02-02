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
	Book books[20];
	
	//File stream
	fstream filestr("book.dat",ios::binary|ios::app);
	
	//Getting the first set of books
	cout<<"No of records to enter";
	cin>>n;
	for(i=0;i<n;i++){
		books[i].getBook();
		filestr.write((char*)&books[i],sizeof(books[i]));
	}
	
	//While loop stat=rts
	while(flag){
	//Get the option
	cout<<"\n1. Display 2.Add book 3.Exit";
	cin>>op;
	
	//Switchcase of the options
	switch(op){
		
		//Display all the books that exist in the file
		case 1:
		for(i=0;i<n;i++){
		filestr.read((char*)&books[i],sizeof(books[i]));
		books[i].dispbook();
		}
		break;
		
		//Add a book to the file
		case 2:
			//Add the book in the last index
			books[n].getBook();
			filestr.write((char*)&books[n],sizeof(books[n]));
			//Increment the index
			n=n+1;
		break;
		//Exit the program
		case 3:
			flag=0;
		break;
	}
	
	
	}
	
	
}
