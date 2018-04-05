// FCI – Programming 1 – 2018 - Assignment 3
// Program Name: files.cpp
// Last Modification Date: 28/03/2018
// Author1 and ID and Group: Ahmed Sayed Mansour Sayed  20170022
// Author2 and ID and Group: Abdulrahman Mohamed hassan 20170150
// Author3 and ID and Group: Osama Tareq Mohamed Saad   20170041
// Teaching Assistant: section 1's TA
// Purpose:Text Processing
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

void loadanexistingfile(char name[20], vector<char>& vec){
    char ar;
    fstream lol;
    lol.open(name,ios::in);
    if(lol.fail())
        cout<<"ERROR opening file !!\n"<<endl;
    else{
        cout<<"file opened successfully.\n";
        cout << "Now reading information.\n";
        cout<<"data is loaded\n"<<endl;
        lol>>ar;
        while (lol.good() && !lol.eof()){
            vec.push_back(ar);
            lol.get(ar);
        }
    }
    lol.close();
}

void putvecinfile(char name[20],string name2,vector<char> vec){
    fstream lol;
    loadanexistingfile(name , vec);
    cout <<"enter the name of the file you want save the data to : ";
    cin >>name2;
    lol.open(name2,ios::out);
    for(int i=0 ;i<vec.size();i++)
        lol.put(vec[i]);
    lol.close();
}

void coutvictor(vector<char>& vec,char name[20]){
    loadanexistingfile(name , vec);
    for (int i=0;i<vec.size();i++)
            cout<<vec[i];
}

void putconinfile(string name2 ,string content){
    fstream lol;
    lol.open(name2,ios::out);
    lol<<content;
    lol.close();
    cout<<"File was created successfully\n "<<endl;
}
 void counting (char name[20]){
    char cha,line[20];
    int character=0,word=0;
    fstream lol ;
    lol.open(name,ios::in);
    if (lol.is_open()){
        cout << "file open successfully : \n";
        while(lol>>line){
        for(int i=0;i<20;i++){
                line[i]=tolower(line[i]);
            if (int (line[i]== 0)) break;
            if (line[i]>='a'&&line[i]<='z') character++;
        }
            word++;
        }
    cout << "\nnumber of characters = "<<character << "\nnumber of words is = "<< word<<endl;
    }
    else cout << "file couldn't open ";
    lol.close();
 }
 void searching(char name[20]){
     char line[20],srch1[20];
     bool found =0;
    fstream lol;
    vector <char> srch,srch2;
    cout <<"enter the name to search :";
    cin>>srch1;
    for(int i=0;i<20;i++){
        if (int (srch1[i]== 0)) break;
        srch.push_back(tolower(srch1[i]));
    }
    lol.open(name,ios::in);
    while (lol>> line){
        for(int i=0;i<20;i++){
            if (int (line[i]== 0)) break;
            srch2.push_back(tolower(line[i]));
        }
        if (srch == srch2) {
            found =1;
            break;
        }
        else {
            found=0;
            srch2.clear();
        }
    }
    (found==1)?cout <<"\nWord was found in the file :)\n":cout <<"\nWord is not found in the file:(\n";
    lol.close();
 }

 void clearing(char name[20]){
     fstream lol;
    lol.open(name , ios::out | ios::trunc);
 }
string addword(string x,char name[20])
{
	ofstream lol(name, ios::app);
	lol << " " << x;
	lol.close();
	return x;
}

void replace(string x, string y,char name[20])
{
	string word, allwords;
	ifstream lol(name);
	while (!lol.eof())
	{
		lol >> word;
		if (x == word)
		{
			allwords = allwords + y;
		}
		else
		{
			allwords = allwords + " " + word + " ";
		}
	}
	lol.close();
	ofstream lol1(name);
	lol1 << allwords;

}
char upper(char name[20])
{

	char arr[100];
	ifstream lol(name);
	lol.getline(arr,100,EOF);
	lol.close();
	ofstream lol1(name,ios::out);
	for (int i=0;i<strlen(arr);i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] = (char)(arr[i] - 32);
		}
	}
	for (int i = 0; i < strlen(arr); i++)
	{
		lol1 << arr[i];
	}
	lol1.close();
}
char lower(char name[20])
{
	char arr[100];
	ifstream lol(name);
	lol.getline(arr,100,EOF);
	lol.close();
	ofstream lol1(name,ios::out);
	for (int i=0;i<strlen(arr);i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr[i] = (char)(arr[i] + 32);
		}
	}
	for (int i = 0; i < strlen(arr); i++)
	{
		lol1 << arr[i];
	}
	lol1.close();
}
void cipherrot13(vector<char> &vec ,char name[20]){
    loadanexistingfile(name , vec);
    char test;
    int index;
    fstream lol;
    lol.open(name,ios::out|ios::trunc);
    for(int i=0;i<vec.size();i++){
        test=vec[i];
        if (test >= 'A' && test<='Z'){
            index=test + 13;
            if (index>90)
                index -= 26;
            vec[i] = (char)index;}
        else if (test >= 'a' && test<='z') {
            index=test + 13;
            if (index>122)
                index -= 26;
            vec[i] = (char)index;}}
            coutvictor(vec,name);
        for(int i=0 ;i<vec.size();i++)
            lol.put(vec[i]);
            lol.close();
}
int main()
{
    while (true){
        int character1=0,word1=0,cipherornot;
        bool found1=0;
        char line[20],cha,ar,name[20];
        string content,name2,choice;
        vector<char> vec,vec2;
        cout <<"Ahlan ya user ya hbibi"<< "\nWhat do you like to do today?"<<"\n1- Load an existing file"<<"\n2- Create a new file"<<
        "\n3- Display file content"<<"\n4- Save the loaded text to the same file again or different one"<<
        "\n5- Count the words and the characters in the file "<<"\n6- Search for a word in a file "<<"\n7- Empty file content "<<
        "\n8- Add more content to the end of the file"<<"\n9- Replace a word in the file with another word"<<
        "\n10- Turn all the content file to upper case"<<"\n11- Turn all the content file to lower case"<<
        "\n12- Add another file to the end of the current file"<<"\n13- Encrypt and decrypt the file"<<"\nE- End\n";
        cout <<"enter your choice : ";
        cin >> choice ;
        if(choice=="E" || choice=="e") return 0;
        else if (choice=="1"){
        cout <<"enter the file name: " ;
        cin >>name;
        loadanexistingfile(name,vec);
        }
        else if (choice=="2"){
        cout <<"enter the file name: " ;
        cin.ignore();
        getline(cin,name2);
            cout<<"Put content in created file "<<name<<": ";
            getline(cin,content);
            if(isspace(content.back())) content.erase(content.begin()+(content.length()-1));
            putconinfile(name2,content);}
        else if (choice=="3"){
            cout<<"loading data from loaded file \n"<<endl;
            coutvictor(vec,name);
            cout<<endl<<endl;
        }
        else if(choice=="4"){
            putvecinfile(name,name2,vec);
            cout<<"file saved successfully\n"<<endl;}
        else if (choice == "5") counting(name);
        else if (choice == "6") searching(name);
        else if (choice == "7") clearing(name);
        else if (choice == "8") {
            string word;
            cout << "Enter your word:";
            cin.ignore();
            getline(cin, word);
            addword(word,name);
        }
        else if (choice == "9") {
            string oldword, newword;
            cout << "Enter the word which in the file:";
            cin >> oldword;
            cout << "Enter the new word:";
            cin >> newword;
            replace(oldword,newword,name);
        }
        else if(choice=="10") upper(name);
        else if(choice=="11") lower(name);
        else if(choice=="12"){
            fstream lol;
            loadanexistingfile(name,vec);
            cout<<"enter the name of the file you want to copy data from : ";
            cin.ignore();
            getline(cin,name2);
            lol.open(name2,ios::in);
            if(lol.fail())
                cout<<"ERROR opening file !!\n"<<endl;
            else{
                vec.push_back('\n');
                while(lol.get(ar)){
                    vec.push_back(ar);
                }
                lol.close();
                cout<<"the new file content is :"<<endl;
                lol.open(name,ios::out | ios::trunc);
                for (int i=0;i<vec.size();i++){
                    cout <<vec[i];
                    lol.put(vec[i]);
                }
            }
        }
        else if(choice=="13"){
            cout<<"choose :\n1-Cipher.\n2-Decipher\n";
            cin>>cipherornot;
            if(cipherornot==1){
                cipherrot13(vec,name);}
           else if(cipherornot==2){
                cipherrot13(vec,name);}
            cout <<endl;
        }
        cout <<endl;
        Sleep(600);
    }
}
