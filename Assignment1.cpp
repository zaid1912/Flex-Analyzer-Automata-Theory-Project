#include<iostream>
using namespace std;

struct Book{
int ID = 0;
string BookName = "";
string author;
string ISBN;
int price;
int pages;
    void PrintAllBooks(){
        cout<<"\nBook ID: "<<ID;
        cout<<"\nBook name: "<<BookName;
        cout<<"\nBook author: "<<author;
        cout<<"\nBook ISBN: "<<ISBN;
        cout<<"\nBook price: "<<price;
        cout<<"\nNumber of pages: "<<pages<<endl;
    }
};

struct BookList{
    Book books[5];
    Book booksIdCopy[5];
    
    int currentBooksNum(){
        for(int i = 0; i< 5; i++){
            if(books[i].BookName == ""){
                return i;
            }

        }
        return 5;
    }

    void AddBook(){
        int i = currentBooksNum();
        if(i>=0 && i<=4){
            cout<<"enter the book ID: ";
            cin>>books[i].ID;
            cin.ignore();
            cout<<"\nenter and store the name of book: ";
            getline(cin, books[i].BookName);
            cout<<"\nenter and store the author of book: ";
            getline(cin, books[i].author);
            cout<<"\nenter and store the ISBN of book: ";
            getline(cin, books[i].ISBN);
            cout<<"\nenter and store the price of book: ";
            cin>>books[i].price;
            cout<<"\nenter and store the pages of book: ";
            cin>>books[i].pages;
            booksIdCopy[i].ID = books[i].ID;

            cout<<"\n-----New book details stored successfully-----\n";
        }
        else{
            cout<<"\n---5 books already exist. No more books can be stored---\n";
        }   
    }

    void SortAscending(){
        int i = currentBooksNum();
        

        for(int j = i; j>0; j--){
            for(int k = 0; k<i-1; k++){
                if(booksIdCopy[k].ID > booksIdCopy[k+1].ID){
                    swap(booksIdCopy[k], booksIdCopy[k+1]);
                    
                }
            }
            
        }
        cout<<"\n-----Book ID's In Ascending order-----";
        for(int j = 0; j<currentBooksNum(); j++){
            cout<<endl<<booksIdCopy[j].ID;
        }

    }
    
    void SortDescending(){
        int i = currentBooksNum();

        for(int j = i; j>0; j--){
            for(int k = 0; k<i-1; k++){
                if(booksIdCopy[k].ID < booksIdCopy[k+1].ID){
                    swap(booksIdCopy[k], booksIdCopy[k+1]);
                    
                }
            }
            
        }
        cout<<"\n-----Book ID's In Ascending order-----";
        for(int i = 0; i<currentBooksNum(); i++){
            cout<<endl<<booksIdCopy[i].ID;
        }

    }

    void PrintAll(){
        int i = 0;
        for(i = 0; i< 5; i++){
            if(books[i].BookName == ""){
                break;
            }
        }
        cout << endl << i << endl;
        
        if(i == 0){
            cout<<"\n---No books to show---\n";
        }
        else{
            cout<<"\n----Printing the details of books----\n";
            for(int j = 0; j<i; j++){
                books[j].PrintAllBooks();
        }
        }
    }

    void DeleteBook(){
        int bookID,i, total = 5,j;
        if(books[0].BookName == ""){
            cout<<"\n-----There exist no books currently-----\n";
        }
        else{
        cout<<"\nEnter the ID of the books that is to be deleted: ";
        cin>>bookID;
        for(i = 0; i<total; i++){
            if(bookID == booksIdCopy[i].ID){

                for(j = i; j<(total - 1); j++){
                    books[j].ID = books[j+1].ID;
                    booksIdCopy[j].ID = booksIdCopy[j+1].ID;
                    books[j].BookName = books[j+1].BookName;
                    books[j].author = books[j+1].author;
                    books[j].ISBN = books[j+1].ISBN;
                    books[j].price = books[j+1].price;
                    books[j].pages = books[j+1].pages;
                }
                //i--;
                total--;
            }
        }
        
        cout<<"\n---Book deleted successfully---\n";
        books[currentBooksNum()-1].BookName = "";
    }
    }
    void showParticularBook(){
        int searchID;
        cout<<"\nEnter the ID of the book to see its details: ";
        cin>>searchID;
        for(int i = 0; i<5; i++){
            if(searchID == books[i].ID){
                cout<<"\n-----Showing the details of this book-----\n";
                books[i].PrintAllBooks();
                break;
            }
            else{
                cout<<"\nNo book with this ID exists\n";
            }
        }
    }
};

struct student{
    int ID;
    string StdName = "";
    int RollNo;
    void PrintAll(){
        cout<<"\nStudent ID: "<<ID;
        cout<<"\nStudent Name: "<<StdName;
        cout<<"\nStudent Roll Number: "<<RollNo<<endl;
    }

};

struct StudentList{
    student std[5];
    student stdIdCopy[5];
    int currentStdNum(){
        for(int i = 0; i< 5; i++){
            if(std[i].StdName == ""){
                return i;
            }

        }
        return 5;
    }
    
    void AddUser(){
        int i = currentStdNum();
        if(i>=0 && i<=4){
            cout<<"\nEnter the ID of new student: ";
            cin>>std[i].ID;
            cin.ignore();
            cout<<"\nEnter the name of new student: ";
            getline(cin, std[i].StdName);
            cout<<"\nEnter the roll number of new student: ";
            cin>>std[i].RollNo;
            stdIdCopy[i].ID = std[i].ID; 
            cout<<"\n-----New user added successfully-----\n";


        }
        else{
            cout<<"\n ----5 users already exist. No more users can be entered.----\n";
        }
        

    }


    void DeleteUser(){
        int stdID, i, total = 5,j;
        cout<<"\nEnter the student ID of the student to be deleted: ";
        cin>>stdID;
        for(i = 0; i<5; i++){
            if(stdID == std[i].ID){
                break;
            }
        }
        for(int j = 0; j<total - 1; j++){
            std[i].ID = std[i+1].ID;
            stdIdCopy[i].ID = stdIdCopy[i+1].ID;
            std[i].RollNo = std[i+1].RollNo;
            std[i].StdName = std[i+1].StdName;
        }
        cout<<"\n-----User deleted successfully-----\n";
        std[currentStdNum()-1].StdName = "";
    }
    void PrintAll(){
        int i=0;
        for(i = 0; i<5; i++){
            if(std[i].StdName == ""){
                break;
            }
        }
        if(i == 0){
            cout<<"\n---There are no users to show---\n";
        }
        else{
            cout<<"\n-----Printing the details of all students-----\n";
            for(int j = 0; j<currentStdNum();j++){
                std[j].PrintAll();
            }
        }
    
    }

};

void exit(){
    cout<<"\n-----Exiting from the menu-----\n";
}


void menu(StudentList &s, BookList &b){
    cout<<"\n                **********MAIN MENU**********\n";
    int option;
    cout<<"\nPlease select any option. Enter 10 to exit: ";
    cout<<"\n1. Add new user";
    cout<<"\n2. Delete existing student";
    cout<<"\n3. Show all students";
    cout<<"\n4. Add new book";
    cout<<"\n5. Delete existing book";
    cout<<"\n6. Show particular book";
    cout<<"\n7. Show all books";
    cout<<"\n8. Sort books in ascending order";
    cout<<"\n9. Sort books in descending order";
    cout<<"\n10. Exit";
    cout<<"\nEnter Your Option(between 1-10). Enter 10 to exit ------> ";
    cin>>option;
    while(option != 10){
        switch(option)
        {
        case 1:
            s.AddUser();
            break;
        case 2:
            s.DeleteUser();
            break;
        case 3:
            s.PrintAll();
            break;
        case 4:
            b.AddBook();
            break;
        case 5:
            b.DeleteBook();
            break;
        case 6:
            b.showParticularBook();
            break;
        case 7:
            b.PrintAll();
            break;
        case 8:
            b.SortAscending();
            break;
        case 9:
            b.SortDescending();
            break;

        }
    cout<<"\nEnter Your Option. Enter 10 to exit ------> ";
    cin>>option;

    }
    if(option == 10){
        exit();
    }

}

int main(){
    StudentList s;
    BookList b;
    menu(s, b);
    return 0;
}