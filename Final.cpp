#include <iostream>
using namespace std;
// Roll Number 38
struct Student_Record
{
    string name;
    string email;
    int rno;
    string address;
    string Ph_no;
    struct Student_Record *next;
};
// Huda
struct Teacher_Record
{
    string name;
    string email;
    int T_Id;
    string address;
    string Ph_no;

    struct Teacher_Record *next;
};
struct TimeTable
{
    string Teacher_Name;
    string Subject_Name;
    string Time;
    TimeTable *next;
};
class Student
{
private:
    Student_Record *start, *temp, *cur;
    int rno;
    Teacher_Record *s_T, *temp_T, *cur_T;
    int T_Id;
    TimeTable *start_Time, *Triverse;
    int ToTalTimeTable = 0;

public:
    Student()
    {
        start = NULL;
        rno = 0;
        s_T = NULL;
        T_Id = 0;
        start_Time = NULL;
    }
    //	38 Roll
    void AddStudent();
    void Disply();
    void menu();

    void Student_Menu();
    void Search();
    void Delet_Student();
    void AddTeacher();
    void Disply_Teacher();
    void Teacher_Menu();
    void Search_Teacher();
    void Delet_Teacher();
    void Time_TableMenu();
    void TimeTableAdd();
};

int main()
{
    Student obj;

    int op;

rep:
    system("cls");

    cout << "\t\t\t*************************************************************" << endl;
    cout << "\t\t\t     	  	      CLASS USED IN PROJECT                     " << endl;
    cout << "\t\t\t**********************************************************" << endl;
    string password;
    cout << "1)Admin" << endl;
    cout << "2)Teachar" << endl;
    cout << "3)Exit" << endl;
    cout << "Enter You'r Choice :";
    cin >> op;
    switch (op)
    {
    case 1:

        cout << "Enter Password:";
        cin.ignore();
        getline(cin, password);

        if (password == "password")
        {

            obj.menu();
            system("pause");
        }
        break;
    case 2:
        obj.Disply();
        break;
    case 3:
        cout << "Thanks You Very Much" << endl;

        exit(0);
    }

    goto rep;
}

void Student::Disply()
{
    temp = start;

    system("cls");
    cout << "============================================================\n";
    cout << "Roll.      	 NAME    		       Email              PH_No\n";
    cout << "=============================================================\n";

    while (temp != NULL)
    {

        cout << temp->rno << "  " << temp->name << "   " << temp->email << "   " << temp->Ph_no << "   " << temp->address << endl;
        temp = temp->next;
    }
}

// void Menu(){
//
//
//
//	main();
// }

void Student::Student_Menu()
{
    int op;
    system("cls");
    do
    {

        cout << "1)Add Student " << endl;
        cout << "2)Disply All Student" << endl;
        cout << "3)Search Student" << endl;
        cout << "4)Delet Record" << endl;

        cout << "5)Go TO main Menu" << endl;
        cout << "6)For Close All Program And Exit" << endl;
        cout << "Enter you'r Choice:";
        cin >> op;
        switch (op)
        {

        case 1:
            AddStudent();
            break;
        case 2:
            Disply();
            break;
        case 3:
            Search();
            break;
        case 4:
            Delet_Student();
            break;
        case 5:
            break;
        case 6:
            exit(0);
            break;

        default:
            cout << "You Entered invalid input" << endl;
            system("pause");
            Student_Menu();
        }

    } while (op != 5);
}
void Student::AddStudent()
{
    cin.ignore();
    system("cls");
    if (start == NULL)
    {

        start = new Student_Record;
        cout << "Enter name  :";
        getline(cin, start->name);
        cout << "Enter email  :";
        getline(cin, start->email);
        cout << "Enter Address :";
        getline(cin, start->address);
        cout << "Enter Ph_No  :";
        getline(cin, start->Ph_no);
        rno++;
        start->rno = rno;
        start->next = NULL;
        cur = start;
        cout << " You Can Access Lms Using this as email and password " << rno << endl;
        return;
    }
    temp = new Student_Record;
    cout << "Enter name  :";
    getline(cin, temp->name);
    cout << "Enter email :";
    getline(cin, temp->email);
    //	 cout<<"Enter "
    cout << "Enter Address  :";
    getline(cin, temp->address);
    cout << "Enter Ph_No  :";
    getline(cin, temp->Ph_no);
    rno++;
    temp->rno = rno;
    temp->next = NULL;
    cur->next = temp;
    cur = temp;
    cout << " You Can Access Lms Using this as email and password " << rno << endl;
}

void Student::menu()
{
    system("cls");
    int op;
    cout << "1)Add Student" << endl;
    cout << "2)Add Teacher" << endl;
    cout << "3)For Time Table" << endl;
    cout << "Enter your Choice";
    cin >> op;
    switch (op)
    {
    case 1:
        Student_Menu();
        break;
    case 2:
        Teacher_Menu();

        break;

    case 3:
        Time_TableMenu();
        break;
    default:
        cout << "You Entered Invalid Integer" << endl;
        system("pause");
        menu();
    }
}
void Student::Search()
{
    int rno;
    system("cls");
    cout << "Enter You'r Rno";
    cin >> rno;
    bool flag = false;
    temp = start;
    if (temp == NULL)
    {
        cout << "Reocrd Not Found" << endl;
        return;
    }
    while (temp != NULL)
    {
        if (rno == temp->rno)
        {

            flag = true;
            cout << temp->rno << "  " << temp->name << "   " << temp->email << "   " << temp->Ph_no << "   " << temp->address << endl;
        }
        temp = temp->next;
    }

    if (!flag)
    {
        cout << "Record not Found" << endl;
        system("pause");
    }
}

void Student::Delet_Student()
{
    int rno;
    system("cls");
    cout << "Enter You'r Rno";
    cin >> rno;
    bool flag = false;
    cur = start;
    //		Student_Record *temp1;
    if (cur == NULL)
    {
        cout << "Reocrd Not Found" << endl;
        return;
    }
    if (cur->rno == rno)
    {
        start = cur->next;
        delete cur;
        return;
    }
    while (cur != NULL)
    {
        if (cur->rno == rno)
        {

            temp->next = cur->next;
            delete cur;
            cur = temp;
            flag = true;
        }
        temp = cur;
        cur = cur->next;
    }

    if (flag)
    {
        cout << rno << "  "
             << "Record Deleted Successfully" << endl;
        system("pause");
    }
    else
    {

        cout << "Record Not Founded" << endl;
    }
}
// Huda
void Student::AddTeacher()
{
    cin.ignore();
    system("cls");
    if (s_T == NULL)
    {

        s_T = new Teacher_Record;
        cout << "Enter name  :";
        getline(cin, s_T->name);
        cout << "Enter email  :";
        getline(cin, s_T->email);
        cout << "Enter Address :";
        getline(cin, s_T->address);
        cout << "Enter Ph_No  :";
        getline(cin, s_T->Ph_no);
        T_Id++;
        s_T->T_Id = T_Id;
        s_T->next = NULL;
        cur_T = s_T;
        cout << " You Can Access Lms Using this as email and password " << T_Id << endl;
        return;
    }
    temp_T = new Teacher_Record;
    cout << "Enter name  :";
    getline(cin, temp_T->name);
    cout << "Enter email :";
    getline(cin, temp_T->email);
    //	 cout<<"Enter "
    cout << "Enter Address  :";
    getline(cin, temp_T->address);
    cout << "Enter Ph_No  :";
    getline(cin, temp_T->Ph_no);
    T_Id++;
    temp_T->T_Id = T_Id;
    temp->next = NULL;
    cur_T->next = temp_T;
    cur_T = temp_T;
    cout << " This is You'r Lms Email and Password " << T_Id << endl;
}

void Student::Disply_Teacher()
{
    temp_T = s_T;

    system("cls");
    if (temp_T == NULL)
    {
        cout << "No Record Found" << endl;
        return;
    }

    cout << "====================================================\n";
    cout << "ID.      NAME           Email              PH_No\n";
    cout << "====================================================\n";

    while (temp_T != NULL)
    {
        cout << temp_T->T_Id << "  " << temp_T->name << "   " << temp_T->email << "   " << temp_T->Ph_no << "   " << temp_T->address << endl;
        temp_T = temp_T->next;
    }

    system("pause");
}
// Huda
void Student::Teacher_Menu()
{
    int op;
    //	system("cls");
    do
    {
        system("cls");
        cout << "1)Add Teacher " << endl;
        cout << "2)Disply All Teacher" << endl;
        cout << "3)Search Teacher" << endl;
        cout << "4)Delete Record" << endl;
        cout << "5)Exit" << endl;
        cin >> op;
        switch (op)
        {

        case 1:
            AddTeacher();
            system("pause");
            break;
        case 2:
            Disply_Teacher();
            break;
        case 3:
            Search_Teacher();
            break;
        case 4:
            Delet_Teacher();
            break;
        }
    } while (op != 5);
}
void Student::Search_Teacher()
{
    int T_Id;
    cout << "Enter You'r T_Id";
    cin >> T_Id;
    bool flag = false;
    temp_T = s_T;
    if (temp_T == NULL)
    {
        cout << "Reocrd Not Found" << endl;
        return;
    }
    while (temp != NULL)
    {
        if (T_Id == temp_T->T_Id)
        {
            flag = true;
            cout << temp_T->T_Id << "  " << temp_T->name << "   " << temp_T->email << "   " << temp_T->Ph_no << "   " << temp_T->address << endl;
            break;
        }
        temp_T = temp_T->next;
    }
    if (!flag)
    {
        cout << "Record not Found" << endl;
        system("pause");
    }
}

void Student::Delet_Teacher()
{
    int T_Id;
    cout << "Enter You'r T_Id";
    cin >> T_Id;
    bool flag = false;
    cur_T = s_T;
    //		Teacher_Record *temp1;
    if (cur_T == NULL)
    {
        cout << "Reocrd Not Found" << endl;
        return;
    }
    if (cur_T->T_Id == T_Id)
    {
        s_T = cur_T->next;
        delete cur_T;
        return;
    }
    while (cur_T != NULL)
    {
        if (cur_T->T_Id == T_Id)
        {

            temp_T->next = cur_T->next;
            delete cur_T;
            cur_T = temp_T;
            flag = true;
        }
        temp_T = cur_T;
        cur_T = cur_T->next;
    }

    if (flag)
    {
        cout << T_Id << "  "
             << "Record Deleted Successfully" << endl;
        system("pause");
    }
    else
    {

        cout << "Record Not Founded" << endl;
    }
}

void Student::Time_TableMenu()
{
    int op;
    system("cls");
    cout << "1)For Add Time " << endl;
    cout << "2)Disply Time Table" << endl;
    cout << "3)Update TimeTable" << endl;
    cin >> op;
    switch (op)
    {
    case 1:

        TimeTableAdd();
        break;
    }
}

void Student::TimeTableAdd()
{
    if (ToTalTimeTable == 2)
    {
        cout << "You Add Two Time Table" << endl;
        return;
    }

    if (start_Time == NULL)
    {
        start_Time = new TimeTable;
        cin.ignore();
        cout << "Enter  Teacher Name ";
        getline(cin, start_Time->Teacher_Name);
        cout << "Enter   Subject Name ";
        getline(cin, start_Time->Subject_Name);
        cout << "Enter Time";
        getline(cin, start_Time->Time);
        start_Time->next = NULL;
        Triverse = start_Time;
        ToTalTimeTable++;
        return;
    }
    TimeTable *temp;
    temp = new TimeTable;
    cin.ignore();
    cout << "Enter  Teacher Name ";
    getline(cin, temp->Teacher_Name);
    cout << "Enter   Subject Name ";
    getline(cin, temp->Subject_Name);
    cout << "Enter Time";
    getline(cin, temp->Time);
    temp->next = NULL;
    Triverse->next = temp;
    ToTalTimeTable++;
    Triverse = temp;
}

//*********************
//                   CLASS USED IN PROJECT
//**********************