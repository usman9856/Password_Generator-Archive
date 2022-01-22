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
    /* system("cls");
     Time();
     Welcome();
     system("pause");*/
start:
    Password user;
    int user_choice;
    system("cls");
    Time();
    cout << "Select what you want to do: \n1.Show Existing Entry \n2.New Entry \n3.Update Entry \n4.Delete a Entry \n5.Exit" << endl;
    cin >> user_choice;
    enum { DISPLAY = 1, NEW, UPDATE, _DELETE, EXIT };
    switch (user_choice)

    {
    case DISPLAY:
    {
        system("cls");
        Time();
        animation();
        user.Get_Pass();
        system("pause");
        goto start;

    }
    case NEW:
    { //ERROR :system not terminating on 0 as input investigate further .
        system("cls");
        Time();
        user.get_user_data();
        animation();
        cout << "Data Saved..." << endl;
        system("pause");
        goto start;

    }
    case UPDATE:
    {
        //ERROR :file when told to update first enrty add an entry prior positision to the first entry
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
    case _DELETE:
    {
        user.get_file_and_insert_to_linklist();
        user.Get_Pass();
        cout << "Enter the line number you want to delete." << endl;
        cin >> user_choice;
        user.delete_data(user_choice);
        goto start;
    }
    case EXIT:
    {
        GoodBye();
        system("pause");
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