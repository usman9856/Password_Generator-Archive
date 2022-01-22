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


void GoodBye();
void Welcome();
void animation();
void Time();
bool terminate(char user_ch);
string decode(string encoded_pass);
string encode(string generated_pass);
string generate_Password();
char getRandomchar();

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


    void get_user_data();
    void Save_Pass(string Website, string Email, string Encoded_pass);
    void Get_Pass();
    void Update(int position);
    void display();
    void delete_data(int pos);

};