#include"PGH.h"
using namespace std;
#pragma warning(disable : 4996)


void animation()
{
    cout << "Processing ..";
    Sleep(75);
    cout << ".";
    Sleep(75);
    cout << ".";
    Sleep(75);
    cout << ".";
    Sleep(75);
    cout << ".";
    Sleep(75);
    cout << ".";
    Sleep(75);
    cout << ".";
    Sleep(75);
    cout << ".";
    Sleep(75);
    cout << "." << endl;
    cout << "...Process Completed..." << endl;

}
void Welcome()
{
    cout << "Booting ..";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << "." << endl;
    system("cls");
    cout << "***         ***  *********  ***        **********  ************  ****       *****  *********  " << endl;
    cout << "***   ***   ***  ***        ***        **********  ************  ******    ******  ***        " << endl;
    cout << "***   ***   ***  ***        ***        ***         ***      ***  *** ***  *** ***  ***        " << endl;
    cout << "***   ***   ***  *********  ***        ***         ***      ***  ***  ******  ***  *********  " << endl;
    cout << "***   ***   ***  *********  ***        ***         ***      ***  ***   ****   ***  *********  " << endl;
    cout << "***   ***   ***  ***        ***        ***         ***      ***  ***          ***  ***        " << endl;
    cout << "***   ***   ***  ***        *********  **********  ************  ***          ***  ***        " << endl;
    cout << "***************  *********  *********  **********  ************  ***          ***  *********  " << endl;
}
void GoodBye()
{
    cout << "Saving Progress ..";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << ".";
    Sleep(150);
    cout << "." << endl;
    system("cls");
    cout << "************   ***     ***  ************  ***       ***  ***    ***    ***     ***  ************  ***   ***  " << endl;
    cout << "************   ***     ***  ***      ***  ******    ***  ***  ***       ***   ***   ***      ***  ***   ***  " << endl;
    cout << "    ****       ***********  ************  *** ***   ***  ******          *** ***    ***      ***  ***   ***  " << endl;
    cout << "    ****       ***********  ************  ***  ***  ***  *** ***           ***      ***      ***  ***   ***  " << endl;
    cout << "    ****       ***     ***  ***      ***  ***   *** ***  ***  ***          ***      ***      ***  ***   ***  " << endl;
    cout << "    ****       ***     ***  ***      ***  ***    ******  ***   ***         ***      ************  *********  " << endl;
}
///////////////////////////////////////////////////////////////////
void Time()
{
    string dt;
    //current date and time on the current system
    time_t now = time(0);

    //convert now to string form
    char* date_time = ctime(&now);
    dt = date_time;

    cout << dt << endl;
}
bool terminate(char user_ch)
{
    if (user_ch == '0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string decode(string encoded_pass)
{
    string decoded_pass;
    for (int i = 0; i < encoded_pass.length() && encoded_pass != "\0"; i++)
    {
        decoded_pass += (encoded_pass[i] - 2);
    }
    return decoded_pass;
}
string encode(string generated_pass)
{
    string encoded_pass;
    for (int i = 0; i < generated_pass.length() && generated_pass != "\0"; i++)
    {
        encoded_pass += (generated_pass[i] + 2);
    }
    return encoded_pass;
}
///////////////////////////////////////////////////////////////////
struct node* head = NULL;
struct node* tail = NULL;
void linklist::insert_node(string line)
{
    node* temp = new node;
    temp->data = line;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }


}
void linklist::insert_position(int pos, string line)
{
    node* previous = new node;
    node* current = new node;
    node* temp = new node;
    current = head;
    for (int i = 0; i <= pos; i++)
    {
        if (pos == 0)
        {
            temp->data = line;
            temp->next = head;
            head = temp;
            break;
        }
        if (current == NULL)
        {
            insert_node(line);
            break;
        }
        if (i == pos)
        {
            temp->data = line;
            previous->next = temp;
            temp->next = current;
            temp = NULL;
            break;
        }
        previous = current;
        current = current->next;
    }

}
void linklist::delete_specific(int pos)
{
    node* previous = new node;
    node* current = new node;
    node* temp = new node;
    current = head;
    for (int i = 0; i <= pos; i++)
    {
        if (pos == 0)
        {
            head = head->next;
            break;
        }
        else if (current->next == NULL)
        {
            tail = previous;
            previous->next = NULL;
            break;
        }
        if (i == pos)
        {
            previous->next = current->next;
            current = NULL;
            break;
        }
        previous = current;
        current = current->next;
    }
}
void linklist::display_size()
{
    int iterator = 0;
    node* temp = new node;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        iterator++;
    }
    cout << "Size of Link List : " << iterator << endl;
}
void linklist::get_file_and_insert_to_linklist()
{
    head = NULL;
    string line;
    fstream data;
    data.open("Passwords.text", ios::in | ios::out);

    if (data.is_open())
    {

        while (getline(data, line))
        {
            insert_node(decode(line));
        }
        data.close();
    }
}
void linklist::save_data_linklist(node* head)
{
    node* temp = new node;
    temp = head;
    fstream data;
    data.open("Passwords.text", ios::out);
    if (data.is_open())
    {
        while (temp != NULL)
        {
            data << encode(temp->data) << endl;
            temp = temp->next;
        }
    }
    data.close();
}
///////////////////////////////////////////////////////////////////
void Password::get_user_data()
{
    int user_choice;
    cout << "Enter 0 to terminate Process.." << endl;
    cout << "Please enter the email and the website name. \n Website: \n";
    cin >> Website;
    if (terminate(Website[0]))
    {
        exit;
    }
    cout << "Email: \n";
    cin >> Email;
    if (terminate(Email[0]))
    {
        exit;
    }
    cout << "1.Enter Own Password \n2.Generate Password \n";
    cin >> user_choice;
    if (user_choice == 1)
    {
        cout << "Enter Password: ";
        cin >> PASSWORD;
    }
    else if (user_choice == 2)
    {
        PASSWORD = generate_Password();
    }
    Save_Pass(Website, Email, PASSWORD);
}
void Password::Save_Pass(string Website, string Email, string Encoded_pass)
{
    string str = "\t" + Website + "\t\t" + Email + "\t\t\t" + Encoded_pass;

    fstream dataout;
    dataout.open("Passwords.text", ios::out | ios::app);
    {
        dataout << encode(str) << endl;
    }
    dataout.close();
}
void Password::Get_Pass()
{
    string line;
    int count = 1;
    fstream datain;
    datain.open("Passwords.text", ios::in);
    if (!datain)
    {
        cout << "File either does not exit or it was moved!! " << endl;
    }
    cout << "\tSr." << "\t\tWEBSITE \tEMAIL \t\t\t\tPassword\t\t\n";

    while (getline(datain, line))
    {
        cout << "\t" << count << "\t" << decode(line) << endl;
        count++;
    }
    datain.close();
}
void Password::Update(int position)
{
    int user_choice;
    string str;
    delete_specific(position);
    {
        int user_choice = 0;
        cout << "Enter 0 to terminate Process.." << endl;
        cout << "Please enter the email and the website name. \n Website: \n";
        cin >> Website;
        if (terminate(Website[0]))
        {
            exit;
        }
        cout << "Email: \n";
        cin >> Email;
        if (terminate(Email[0]))
        {
            exit;
        }
        if (user_choice == 1)
        {
            cout << "Enter Password: ";
            cin >> PASSWORD;
        }
        else if (user_choice == 2)
        {
            PASSWORD = generate_Password();
        }
    }
    str = "\t" + Website + "\t\t" + Email + "\t\t\t" + PASSWORD;

    cout << endl;
    insert_position(position - 1, str);
    save_data_linklist(head);


}
void Password::display()
{
    node* temp = new node;
    temp = head;
    int count = 1;
    while (temp != NULL)
    {
        cout << count << "\t" << temp->data << endl;
        temp = temp->next;
        count++;
    }

}
void Password::delete_data(int pos)
{
    delete_specific(pos);
    save_data_linklist(head);
    animation();
    cout << "Entry Deleted " << endl;
    system("pause");
}