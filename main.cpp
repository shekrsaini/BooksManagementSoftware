#include <iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<conio.h>

using namespace std;

class Book {
    private:
        int book_id;
        char book_title [20];
        double book_price;
    public:
         Book(){
            book_id=0;
            strcpy(book_title, "no title" );
            book_price=0.0;
          };
        void get_bookdata();
        int store_bookdata(); 
        void show_bookdata();
        void view_allbooks();
        int search_allbooks(int searching_id);
        int update_bookdata(int searching_id);
}; 
int Book::update_bookdata(int searching_id){
    if(search_allbooks(searching_id)){
                        show_bookdata();
                        cout<<"enter new price: ";
                        cin>>book_price;
                        cout<<"\nnow update record for "<<searching_id<<" is: "<<endl;
                        show_bookdata();
                        return 1;
    }else{
        cout<<"there is not any book record for "<<searching_id<<" id"<<endl; 
       return 0;
       };
   
};


int Book::search_allbooks(int searching_id){
    ifstream fin;
    fin.open("file_handling.txt",ios::in|ios::binary);
    if(!fin){
        cout<<"record file not found in harddisk "<<endl;
        return 0;
    };
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
        if( book_id==searching_id){
            show_bookdata();
        return 1;
        };
        fin.read((char*)this,sizeof(*this));
    };
    return 0;
};
void Book::view_allbooks(){
    ifstream fin;
    fin.open("file_handling.txt",ios::in|ios::binary);
    if(!fin){
        cout<<"\nfile not found"<<endl;
    };
    fin.read((char*)this, sizeof(*this));
    cout<<"book_id "<<"book_title "<<"book_price"<<endl;
    while(!fin.eof()){
    show_bookdata();
    fin.read((char*)this, sizeof(*this));
    };
    
    
};

void Book::get_bookdata(){
    cout<<"enter bookid , title, and price "<<endl;
    cin>>book_id;
    cin.ignore();
    cin.getline(book_title,19);
    cin>>book_price;
};
void Book::show_bookdata(){
    cout<<"\n"<<book_id<<"       "<<book_title<<"     "<<book_price<<endl;
}
int Book::store_bookdata(){
    if(book_id==0 && book_price==0){
        cout<<"book data is not initalized"<<endl;
        return 0;
    }
    else{
     ofstream fout;
     fout.open("file_handling.txt", ios::app | ios::binary);
     fout.write((char*)this, sizeof(*this));
     fout.close();
     return 1;
     };
}


int main()
{   
    string username="shekr";
    string password="12345";
    string iuser;
    char ipass[10];
    cout<<"---------------------------------login please-------------------------------------"<<endl;
    login:
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"enter your username: ";
    getline(cin,iuser);
    cout<<"\nenter your password: ";
   	{
 		char a;
 		for(int i = 0;;)
 		{
 			a = getch();
 			if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
 			{
 				ipass[i] = a;
 				i++;
 				cout<<"*";
			}
			if(a == '\b' && i >= 1)
			{
				cout<<"\b \b";
				i--;
			}
			if(a == '\r')
			{
				ipass[i] = '\0';
				break;
			}
	    }
    }
    if(iuser==username && password == ipass){
        cout<<"\n\nlogin successful!!"<<endl;
        cout<<"press enter to continue.... ";
        getche();
        system("cls");
    Book b1;
    int key,flag=1,searching_id;
     int num{0};
     while(flag){
    cout<<endl;
    cout<<"||  press 1  to store book data        ||"<<endl;
    cout<<"||  press 2  to view all books data    ||"<<endl;
    cout<<"||  press 3  to exit!!                 ||"<<endl;
    cout<<"||  press 4  to clear the screen       ||"<<endl;
    cout<<"||  press 5  to search book data by id ||"<<endl;
    cout<<"||  press 6  to update book record     ||"<<endl;
    cin>>key;
    switch(key){
        case 1: 
                   cout<<"how many book do you want to add?  ";
                   cin>>num;
                    while(num--){
                        b1.get_bookdata();
                        b1.show_bookdata();
                        b1.store_bookdata();
                    };
                    break;
        case 2: b1.view_allbooks(); break;
        case 3: cout<<"exiting ................."; flag=0; break;
        case 4: system("cls"); break;
        case 5: cout<<"enter book id: ";
                    cin>>searching_id;
                    b1.search_allbooks(searching_id); break;
        case 6: cout<<" enter the book id you want to update : ";
                    cin>>searching_id;
                    b1.update_bookdata( searching_id);break;
                    
    };
    
    };
    }else{system("cls");cout<<"try again   "<<endl; goto login;};
    return 0;
}
