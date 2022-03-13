#include <iostream>
#include <string>
using namespace std;
struct Node
{
    /* data */
    string name;
    int age;
    string PH_NO;
    int Token;
    Node *next;
};

class List
{

private:
    Node *start, *temp, *cur;
    int TOken;

public:
    List()
    {

        start = NULL;

        TOken = 0;
    }
    void Menu();
    void Input();
    void Disply();
};

int main()
{
    List obj;
    int op;
    obj.Menu();
    // cout << "How Many Test " << endl;

    // cin >> op;
    // for (int i = 0; i < op; i++)
    // {
    //     /* code */
    //     obj.Input();
    // }

    // obj.Disply();
}

void List::Menu()
{

    int op;
    do
    {

        system("cls");

        cout << "1) Check symptoms of covid 19" << endl;
        cout << "2)For Medical Checkup" << endl;
        cout << "3) Deatails Of Every PAtients who visit the hospital" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "\t\tsymptoms of covid 19" << endl;
            cout << "1)fever \n2)cough \n3)tiredness \n4)loss of taste or smell " << endl;

            system("pause");

            break;
        case 2:
            Input();

            break;
        case 3:
            Disply();
            break;

        default:
            cout << "You Entered Invalid Value !" << endl;
            system("pause");
            break;
        }

    } while (op != 3);
}

void List::Input()
{

    cin.ignore();
    if (start == NULL)
    {
        start = new Node;
        cout << "Enter your Name:" << endl;

        getline(cin, start->name);
        cout << "Enter your Phone_Number" << endl;
        getline(cin, start->PH_NO);
        cout << "Enter your age";
        cin >> start->age;
        TOken++;
        start->Token = TOken;

        start->next = NULL;
        cur = start;
        cout << "This is you'r Token Number:" << TOken << endl;
        return;
        //    getline(cin,start->age);
    }
    temp = new Node;
    cout << "Enter your Name:" << endl;
    getline(cin, temp->name);

    cout << "Enter your Phone_Number" << endl;
    getline(cin, temp->PH_NO);
    cout << "Enter age:" << endl;
    cin >> temp->age;
    temp->next = NULL;
    TOken++;
    cout << "This is you'r Token Number:" << TOken << endl;
    temp->Token = TOken;
    cur->next = temp;
    cur = temp;
}

void List::Disply()
{
    cur = start;
    while (cur != NULL)
    {
        /* code */
        cout << cur->Token << "   " << cur->name << "  " << cur->age << "  " << cur->PH_NO << endl;
        cur = cur->next;
    }
}