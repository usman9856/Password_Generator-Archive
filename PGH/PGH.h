#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>
#include<Windows.h>
#include<time.h>
using namespace std;
string static ID;
void create_Empty();
void GUIDE();
void GoodBye();
void Welcome();
void animation();
void Time();
bool terminate(char user_ch);
string decode(string encoded_pass);
string encode(string generated_pass);
string generate_Password();
char getRandomchar();
void create_Database();
bool log();
string getID();
struct node
{
    string data;
    node* next = NULL;
};
class linklist
{
public:

    //LINK LIST AREA 
    void insert_node(string line);
    void insert_position(int pos, string line);
    void delete_specific(int pos);
    void display_size();
    void get_file_and_insert_to_linklist();
    void save_data_linklist(node* head);


};
class Password :public linklist
{
public:
    string Email, Website, PASSWORD;


    bool creat_Entry();
    void Save_Pass(string str);
    void Get_Pass();
    void Update(int position);
    void display();
    void delete_data(int pos);
    bool get_info();
};