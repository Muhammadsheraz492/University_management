#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

void write_account();
void display_all();
void Student();
void Admin();
void Search();
void loginStudent();
void Search1(int rno);
void delete_account(int n);
void afterlogin(int rno);
void modify_account(int rno);
void CheckAssignment(int rno);

struct Details
{
    char Student_name[50];
    char Student_Assignment[50];
} a;
class account
{
    int Roll;
    char name[50];
    char email[50];
    char Ph_no[50];
    char Assignment[50] = "no_assignment";

public:
    void Add_Record();
    void report() const;

    int retRoll();
    char ReturnName()
    {
        Details d;
        char n[50];
        strcpy(d.Student_name, name);
        strcpy(d.Student_Assignment, Assignment);
        strcpy(n, name);

        return n[50];
    }
    char ReturnEmail()
    {
        return email[50];
    }
    char ReturnPh_no()
    {
        return Ph_no[50];
    }
    char Assi()
    {
        Details d;

        // cout << d.Student_Assignment << endl;
        char n[50];
        strcpy(d.Student_Assignment, Assignment);
        strcpy(n, Assignment);
        return n[50];
    }

    void modify()
    {
        int op;
        cout << "1)Update Email " << endl;

        cout << "2)Update Phone" << endl;
        cout << "3)Update Name" << endl;
        cin >> op;
        cin.ignore();
        switch (op)
        {
        case 1:
            cout << "Enter Email:";
            cin.getline(email, 50);
            break;

        case 2:
            cout << "Enter Phone:";
            cin.getline(Ph_no, 50);
            break;
        case 3:
            cout << "Enter name:";
            cin.getline(name, 50);
            break;
        default:
            cout << "You Entered invalid Please try again" << endl;
            system("pause");
            modify();
        }
    }

}; // class ends here

int account::retRoll()
{
    return Roll;
}
void account::Add_Record()
{
    cout << "\nEnter Roll_No. :";
    cin >> Roll;
    cout << "\n\nEnter The Name of Student : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter Email : ";
    //	cin>>type;
    cin.getline(email, 50);
    //	type=toupper(type);
    cout << "\nEnter Ph Number: ";
    cin.getline(Ph_no, 50);
    strcpy(Assignment, "NO_Assignment");

    cout << "\n\n\nStudent Registered" << endl;
}
void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.Add_Record();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}
void account::report() const
{
    cout << Roll << setw(10) << " " << name << setw(9) << " " << email << setw(15) << Ph_no << endl;
}
void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tAll Student List  \n\n";
    cout << "====================================================\n";
    cout << "Roll.      NAME           Email              PH_No\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}

int main()
{
rep:
    system("cls");
    system("Color 0B");
    int op;
    cout << "1) For Admin" << endl;
    cout << "2)Login As a Student:" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        Admin();
        break;
    case 2:
        loginStudent();
        system("pause");
        break;
    }

    goto rep;
}
void delete_account(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retRoll() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
        else
        {
            flag = true;
        }
    }
    inFile.close();
    outFile.close();
    if (flag)
    {
        cout << "\n\n\tRecord Deleted ..";
    }
    else
    {
        cout << "\n\n\tRecord Not Found ..";
    }
    remove("account.dat");
    rename("Temp.dat", "account.dat");
}
void Admin()
{
    system("cls");
    int op;
    cout << "1)Student Menu" << endl;
    cout << "2)Teacher Menu" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        Student();
        break;
    }
}

void Student()
{
    system("cls");

    int op, roll;
    int admore;
    cout << "1)Add student " << endl;
    cout << "2)Disply All Student " << endl;
    cout << "3)Delete Specific Record Of Student by Roll No" << endl;
    cout << "4)Search Record" << endl;
    cout << "5)For Main Menu" << endl;
    cout << "6)For Update Record of Student" << endl;
    cout << "Enter Your Choice:";

    cin >> op;
    switch (op)
    {
    case 1:
    rep:
        write_account();
        cout << "Enter 1 For add more Data:" << endl;
        cin >> admore;
        if (admore == 1)
        {
            goto rep;
        }
        break;
    case 2:
        display_all();
        system("pause");
        break;
    case 3:
        cout << "Enter Roll For Delete:";
        cin >> roll;
        delete_account(roll);
        system("pause");
        break;
    case 4:
        Search();
        //			Admin();
        system("pause");
        break;
    case 5:
        main();
        break;
    case 6:
        int rno;
        cout << "Enter rno:";
        cin >> rno;
        modify_account(rno);
        //     	modify_account()
        break;
    }

    // Student();
}

void Search()
{
    int rno;
    cout << "Enter rno for search:";
    cin >> rno;
    bool flag = false;
    account ac;
    ifstream inFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tAll Student List  \n\n";
    cout << "====================================================\n";
    cout << "Roll.      NAME           Email              PH_No\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retRoll() == rno)
        {
            flag = true;
            ac.report();
        }
    }
    inFile.close();
    if (!flag)
    {
        cout << "Record Not Found:" << endl;
    }
}
void Search1(int rno)
{

    bool flag = false;
    account ac;
    ifstream inFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    cout << "====================================================\n";
    cout << "Roll.      NAME           Email              PH_No\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retRoll() == rno)
        {

            ac.report();
        }
    }
    inFile.close();
}
void CheckAssignment(int rno)
{

    bool flag = false;
    account ac;
    ifstream inFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retRoll() == rno)
        {
            Details d;
            ac.ReturnName();
            cout << d.Student_Assignment;
        }
    }
    inFile.close();
}
void loginStudent()
{
    int rno;
    cout << "Enter rno:";
    cin >> rno;
    char name[50];
    bool flag = false;
    account ac;
    ifstream inFile;
    string a;

    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retRoll() == rno)
        {
            flag = true;
            //            cout<<;
            ac.ReturnName();
            //             strcpy(name);
            afterlogin(rno);
        }
    }
    inFile.close();
    if (!flag)
    {
        cout << "Record Not Found:" << endl;
    }
}

void afterlogin(int roll)
{
    Details d;
    system("cls");
    system("Color A");
    int op;
    cout << "\t\t\tWelcome to Lms  " << d.Student_name << endl;
    cout << "1)For Check Personal Details:" << endl;
    cout << "2)Check Assignments" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        Search1(roll);
        break;
    case 2:

        cout << d.Student_Assignment << endl;
        break;
    default:
        break;
    }
}

void modify_account(int rno)
{
    system("cls");

    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));

        if (ac.retRoll() == rno)
        {
            ac.report();
            cout << "\n\nEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";

    system("pause");
}
