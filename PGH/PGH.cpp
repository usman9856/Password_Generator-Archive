#include"PGH.h"

static const char pool[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
   'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
   ,'0','1','2','3','4','5','6','7','8','9','!','@', '#','$','5','&','.','-' };
int poolSize = sizeof(pool) - 1;
string generate_Password()
{
    int passlength;
    string pass;
    pass.clear();
    srand(time(0));
    cout << "Enter the length of the Password: \n";
    cin >> passlength;
    for (int i = 0; i < passlength; i++)
    {
        pass += getRandomchar();
    }
    cout << "Generated Password: " << pass << endl;
    return pass;
}
char getRandomchar()
{
    return pool[rand() % poolSize];
}

int main()
{
    create_Empty();
beg:
    system("cls");
    Time();
    Welcome();
    cout << "First time Entry please enter 'Admin' as your ID.\n";
    if (log())
    {
        goto beg;
       
    }
     string id = getID();
start:
    Password user;
    int user_choice;
    system("cls");
    Time();
    GUIDE();    
    cout << "ID :" << id << endl;
    cout << "Select what you want to do: \n1.Show Existing Entry \n2.New Entry \n3.Update Entry \n4.Delete a Entry \n5.Switch Database \n6.Create Database \n7.Exit" << endl;
    cin >> user_choice;
    enum { DISPLAY = 1, NEW, UPDATE, _DELETE,SWITCH,CREAT, EXIT };
    switch (user_choice)

    {
    case DISPLAY:
    {
        system("cls");
        Time();
        animation();
        system("cls");
        user.Get_Pass();
        system("pause");
        goto start;

    }
    case NEW:
    { 
        system("cls");
        animation();
        system("cls");
        Time();
        if (user.creat_Entry())
        {
            goto start;
        }
        else
        {
            animation();
            cout << "Data Saved..." << endl;
        }
        system("pause");
        goto start;

    }
    case UPDATE:
    {
        system("cls");
        animation();
        system("cls");
        Time();
        user.get_file_and_insert_to_linklist();
        user.display();
        cout << "Enter the line data you want to update: ";
        cin >> user_choice;
        user.Update(user_choice);
        animation();
        goto start;
    }
     case _DELETE:  //option to abruptly ending the delete program
    {
         system("cls");
         animation();
         system("cls");
        user.get_file_and_insert_to_linklist();
        user.display(); // Fix Display
        cout << "Enter the line number you want to delete. \n Enter 0 to delete all Entries." << endl;
        cin >> user_choice;
        user.delete_data(user_choice);
        goto start;
    }
    case SWITCH:
    {
        system("cls");
        if (log())
        {
            cout << "ID :Invalid ID Try Again." << endl;
            Sleep(2000);
            goto start;
        }
        else
        {
            id = getID();
            animation();
            system("cls");
            cout << "Database Switched." << endl;
            goto start;
        }
    }
    case CREAT:
    {
        system("cls");
        animation();
        system("cls");
        create_Database();
        cout << "Database Created Sucessfully." << endl;
        goto start;
    }
    case EXIT:
    {
        GoodBye();
        exit(0);
        break;
    }
    default:
    {
        cout << "!!!INVALID ENTRY!!!" << endl;
        system("pause");
        goto start;
    }
    }

}