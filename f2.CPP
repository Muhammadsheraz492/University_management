#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <windows.h>
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

using namespace std;
// Function to creating loading bar
void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0A");

    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;

    cout << "\n\n\n\n";
    printf("\n\n\n\n\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);

    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);

        // Sleep for 1 second
        Sleep(1000);
    }
}

void Time()
{

    system("cls");
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // stores the local time of the computer.

    int seconds = (timePtr->tm_sec);
    int minutes = (timePtr->tm_min);
    int hrs = (timePtr->tm_hour);
    if (hrs > 12)
    {
        hrs = hrs - 12;
    }

    cout << "\t\t\t"
         << "Today Time is :" << hrs << ":" << minutes << ":" << seconds << endl;
    cout << endl
         << endl
         << endl;
}

struct TimeTable
{
    int id;
    string Teacher_Name;
    string Subject_Name;
    string Time;
    string Seaction;
    TimeTable *next;
};

struct StudentData
{
    /* data */

    string name;
    string email;

    string address;
    string Ph_no;
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
    int Time_TableId;

public:
    Student()
    {
        start = NULL;
        rno = 0;
        s_T = NULL;
        T_Id = 0;
        start_Time = NULL;
        Time_TableId = 0;
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
    void TimeTableAdd(string Section);
    void DisplyTimeTable();
    void UpdateTimeTable();
    void Student_Access();
    void WelCome_Student_Lms(int rno, string name, string phone, string Section, string address);
    void TeacherAccess();
    void SectionA();
    void SectionB();
    void AccessLms_Teacher(int id, string name, string phone, string email, string address);
};

int main()
{
    //	loadingBar();

    Time();
    system("pause");
    Student obj;

    int op;

rep:
    system("cls");

    cout << "\t\t\t*************************************************************" << endl;
    cout << "\t\t\t     	   WELCOME TO UNIVERSITY MANAGEMENT                     " << endl;
    cout << "\t\t\t **********************************************************" << endl;
    string password;
    cout << "1)Admin" << endl;
    cout << "2)Teachar" << endl;
    cout << "3)For Student" << endl;
    cout << "4)Exit" << endl;
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
        // obj.Disply();
        break;

    case 3:
        obj.Student_Access();
        break;

    case 4:
        cout << "Thanks You Very Much" << endl;

        exit(0);
        break;
    default:
        cout << " You entered  Invalid  choice " << endl;
        system("pause");
    }

    goto rep;
}

void Student::Disply()
{
    temp = start;
    if (start == NULL)
    {
        cout << "Record Not Found" << endl;
        return;
    }

    system("cls");
    cout << "=================================================================\n";
    cout << "Roll.      	 NAME    		       Email                PH_No\n";
    cout << "==================================================================\n";

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
            system("cls");
            break;
        case 2:
            Disply();
            system("cls");

            break;
        case 3:
            Search();
            system("cls");
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
    system("pause");
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
        cout << "5)Go to main Menu" << endl;
        cout << "6)Shutdow System" << endl;
        cout << "Enter you'r choice:";
        cin >> op;
        switch (op)
        {

        case 1:
            AddTeacher();
            system("pause");
            Teacher_Menu();
            break;
        case 2:
            Disply_Teacher();
            Teacher_Menu();
            break;
        case 3:
            Search_Teacher();
            Teacher_Menu();
            break;
        case 4:
            Delet_Teacher();
            Teacher_Menu();
            break;
        case 5:

            break;

        case 6:
            exit(0);
            break;
        default:
            cout << "You Entered Invalid Value!" << endl;
            system("pause");
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
    int val;
    string Section;
    system("cls");
    cout << "1)For Add Time " << endl;
    cout << "2)Disply Time Table" << endl;
    cout << "3)Update TimeTable" << endl;
    cout << "4)Go to Back Menu" << endl;
    cout << "Enter your choice:" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "How Many Subkect You want TO added";
        cin >> val;
        cout << "Enter Section Name without Space: ";
        //  getline(cin,Section);
        cin >> Section;

        //  cin.ignore();
        for (int i = 0; i < val; i++)
        {
            /* code */

            TimeTableAdd(Section);
        }

        system("pause");
        Time_TableMenu();

        break;

    case 2:
        DisplyTimeTable();
        system("pause");
        Time_TableMenu();
        break;
    case 3:
        UpdateTimeTable();
        system("pause");
        Time_TableMenu();
        break;
    case 4:
        break;
    default:
        cout << "You Entered Invaliid Value" << endl;

        system("pause");
        Time_TableMenu();
        break;
    }
}

void Student::TimeTableAdd(string Section)
{
    // if (ToTalTimeTable == )
    // {
    //     cout << "You Add Two Time Table" << endl;
    //     return;
    // }

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
        start_Time->Seaction = Section;
        start_Time->next = NULL;
        ToTalTimeTable++;
        start_Time->id = ToTalTimeTable;
        Triverse = start_Time;
        return;
    }
    TimeTable *temp;
    temp = new TimeTable;
    // cin.ignore();
    cout << "Enter  Teacher Name ";
    getline(cin, temp->Teacher_Name);
    cout << "Enter   Subject Name ";
    getline(cin, temp->Subject_Name);
    cout << "Enter Time";
    getline(cin, temp->Time);
    temp->Seaction = Section;
    ToTalTimeTable++;
    temp->id = ToTalTimeTable;
    temp->next = NULL;
    Triverse->next = temp;
    Triverse = temp;
}

void Student::DisplyTimeTable()
{

    TimeTable *temp;
    temp = start_Time;

    if (temp == NULL)
    {
        cout << "You Have No Time Table Please First Add Time Table" << endl;
        system("pause");
        Time_TableMenu();
        return;
    }

    while (temp != NULL)
    {
        /* code */

        cout << temp->id << "  " << temp->Subject_Name << "      " << temp->Teacher_Name << "    " << temp->Time << "   " << temp->Seaction << endl;
        cout << endl;

        temp = temp->next;
    }
}

void Student::UpdateTimeTable()
{

    TimeTable *temp;
    temp = start_Time;
    int id;
    cout << "Enter Time  Table Id  For Update ";
    cin >> id;

    while (temp != NULL)
    {
        /* co
        de */
        if (temp->id == id)
        {
        rep:
            int op;
            cout << "1)For Update Teacher Name" << endl;
            cout << "2)For Update Subject Name" << endl;
            cout << "3)For Update Section Name" << endl;
            cout << "4)For Update Time" << endl;
            cout << "5)Update All Things" << endl;
            cout << "6)For Back Menu" << endl;
            cout << "Enter You'r Choice" << endl;
            cin >> op;
            cin.ignore();
            switch (op)
            {
            case 1:
                /* code */
                cout << "Enter Teacher Name";
                getline(cin, temp->Teacher_Name);

                break;
            case 2:
                cout << "Enter Stubject Name";
                getline(cin, temp->Subject_Name);
            case 3:
                cout << "Enter Section";
                getline(cin, temp->Seaction);
            case 4:
                cout << "Enter Time";
                getline(cin, temp->Time);

                break;
            case 5:
                cout << "Enter Teacher Name";
                getline(cin, temp->Teacher_Name);
                cout << "Enter Stubject Name";
                getline(cin, temp->Subject_Name);
                cout << "Enter Section";
                getline(cin, temp->Seaction);
                cout << "Enter Time";
                getline(cin, temp->Time);
                break;
            case 6:
                Time_TableMenu();

                break;
            default:
                cout << "You Enter Invalid choice Please Enter Correct" << endl;
                system("pause");
                goto rep;

                break;
            }

            cout << temp->id << "  " << temp->Subject_Name << "      " << temp->Teacher_Name << "    " << temp->Time << "   " << temp->Seaction << endl;
            cout << endl;
        }

        temp = temp->next;
    }
}
void Student::Student_Access()
{
    temp = start;
    StudentData d;
    int rno;
    cout << "Enter You'r Roll NUmber" << endl;
    cin >> rno;

    if (temp == NULL)
    {
        cout << "Please Contact Your Admin" << endl;
        return;
    }
    while (temp != NULL)
    {
        if (temp->rno == rno)
        {
            d.name = temp->name;
            d.email = temp->email;
            d.address = d.address;
            WelCome_Student_Lms(temp->rno, temp->name, temp->Ph_no, temp->email, temp->address);
        }
        temp = temp->next;
    }

    system("pause");
}

void Student::WelCome_Student_Lms(int rno, string name, string phone, string Section, string address)
{
    StudentData D;

    cout << "\t\t\t*************************************************************" << endl;
    cout << "\t\t\t     	   WELCOME TO UOG LMS " << name << "                     " << endl;
    cout << "\t\t\t **********************************************************" << endl;
    cout << endl;
    cout << endl;
    int op;
rep:
    system("cls");
    cout << "1)Check Personal Details" << endl;
    cout << "2)Check Time Table" << endl;
    // cout << "3)Check Present" << endl;
    cout << "3)For  main Menu:" << endl;
    cout << "Enter you'r Choice :";
    cin >> op;

    switch (op)
    {
    case 1:
        cout << "Roll Number :" << rno << endl;
        cout << "Name is :" << name << endl;
        cout << "Phone Number :" << phone << endl;
        cout << "Email For Addmission :" << Section;
        cout << "Section :";
        if (rno % 2 == 0)
        {
            cout << "A" << endl;
        }
        else
        {
            cout << "B" << endl;
        }
        system("pause");
        goto rep;
        break;

    case 2:
        DisplyTimeTable();
        system("pause");
        goto rep;
        break;
    case 3:
        break;

    default:
        cout << "You Entered Invalid Value" << endl;
        system("pause");

        goto rep;
        break;
    }
}

void Student::TeacherAccess()
{

    temp_T = s_T;

    system("cls");
    int id;
    bool flag = false;
    cout << "ENter Id:";
    cin >> id;

    if (temp_T == NULL)
    {
        cout << "No Record Found   please cntact your Admin" << endl;
        return;
    }

    while (temp_T != NULL)
    {
        if (temp_T->T_Id == id)
        {

            AccessLms_Teacher(temp_T->T_Id, temp_T->name, temp_T->Ph_no, temp_T->email, temp_T->address);
            // cout << temp_T->T_Id << "  " << temp_T->name << "   " << temp_T->email << "   " << temp_T->Ph_no << "   " << temp_T->address << endl;
        }

        temp_T = temp_T->next;
    }

    if (!flag)
    {

        cout << "Record Not Found  !" << endl;
    }
    system("pause");
}

void Student::AccessLms_Teacher(int rno, string name, string phone, string email, string address)
{
    int op;

    cout << "\t\t\t*************************************************************" << endl;
    cout << "\t\t\t     	   WELCOME TO UOG LMS " << name << "                     " << endl;
    cout << "\t\t\t **********************************************************" << endl;

rep:
    system("cls");
    cout << "1)Check Personal Details" << endl;
    cout << "2)Check Time Table" << endl;
    // cout << "3)Check Present" << endl;
    cout << "3)Check Students" << endl;
    cout << "4)Section A  student" << endl;
    cout << "5)Section B  student" << endl;
    cout << "6)For  main Menu:" << endl;
    cout << "Enter you'r Choice :";

    cin >> op;

    switch (op)
    {
    case 1:
        cout << "Id Number :" << rno << endl;
        cout << "Name is :" << name << endl;
        cout << "Phone Number" << phone << endl;
        cout << "Email For Addmission :" << email;
        cout << "Address :" << address;
        system("pause");
        goto rep;

        break;

    case 2:
        DisplyTimeTable();
        system("pause");
        goto rep;
        break;
    case 3:
        Disply();

        break;
    case 4:
        SectionA();
        system("pause");
        goto rep;
        break;

    case 6:
        SectionB();
        system("pause");
        goto rep;
        break;

    default:
        cout << "You Entered Invalid Value" << endl;
        system("pause");

        goto rep;
        break;
    }
}

void Student::SectionA()
{

    temp = start;
    if (start == NULL)
    {
        cout << "Record Not Found" << endl;
        return;
    }

    system("cls");
    // cout << "=================================================================\n";
    // cout << "Roll.      	 NAME    		       Email                PH_No\n";
    // cout << "==================================================================\n";

    while (temp != NULL)
    {

        if (temp->rno % 2 == 0)
        {

            cout << temp->rno << "  " << temp->name << "   " << temp->email << "   " << temp->Ph_no << "   " << temp->address << endl;
        }
        temp = temp->next;
    }
}
void Student::SectionB()
{

    temp = start;
    if (start == NULL)
    {
        cout << "Record Not Found" << endl;
        return;
    }

    system("cls");
    // cout << "=================================================================\n";
    // cout << "Roll.      	 NAME    		       Email                PH_No\n";
    // cout << "==================================================================\n";

    while (temp != NULL)
    {

        if (temp->rno % 2 != 0)
        {

            cout << temp->rno << "  " << temp->name << "   " << temp->email << "   " << temp->Ph_no << "   " << temp->address << endl;
        }
        temp = temp->next;
    }
}