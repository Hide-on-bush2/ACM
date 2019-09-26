#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<string> Books;
vector<string> Authors;
map<string, int> book_ID;
map<string, int> author_ID;


//为每一本书获取ID
int id(string x){
    int i = 1;
    while(x[i] != '\"'){i++;}
    string book, author;
    book.assign(x, 0, i + 1);
    author.assign(x, i + 5, x.size() - i - 5);
    if(book_ID.count(book)){return book_ID[book];}
    Books.push_back(book);
    Authors.push_back(author);
    book_ID[book] = Books.size() - 1;
    return author_ID[author] = Authors.size() - 1;
}

struct cmp{
    bool operator()(int ID1, int ID2){
        return Authors[ID1] == Authors[ID2] ? Books[ID1] < Books[ID2] : Authors[ID1] < Authors[ID2];
    }
}myCmp;

void printBook(vector<int>& books){
    for(int i = 0;i < books.size();i++){
        cout << Books[books[i]] << " ";
    }
    cout << endl;
}

int main(){
    string s;
    vector<int> books;
    while(getline(cin, s) && s != "END"){
        books.push_back(id(s));
    }
    sort(books.begin(), books.end(), myCmp);
    string operation;
    vector<int> wait;
    while(getline(cin, operation) && operation != "END"){
        if(operation[0] == 'B'){
            string name;
            name.assign(operation, 7, operation.size() - 7);
            books.erase(remove(books.begin(), books.end(), book_ID[name]), books.end());
        }
        else if(operation[0] == 'R'){
            string name;
            name.assign(operation, 7, operation.size() - 7);
            wait.push_back(book_ID[name]);
        }
        else{
            sort(wait.begin(), wait.end(), myCmp);
            for(int i = 0;i < wait.size();i++){
                int return_book = wait[i];
                cout << "Put " << Books[return_book] << " ";
                books.push_back(return_book);
                sort(books.begin(), books.end(), myCmp);
                for(int i = 0;i < books.size();i++){
                    if(books[i] == return_book){
                        if(i == 0){cout << "first" << endl;}
                        else{cout << "after " << Books[books[i - 1]] << endl;}
                        break;
                    }
                }
            }
            cout << "END" << endl;
            wait.clear();
        }
    }
}