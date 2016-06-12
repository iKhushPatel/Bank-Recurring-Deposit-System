#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include<algorithm>
#include<math.h>
//#include<stdio.h>
#include<conio.h>
//#include<stdlib.h>
char ESC = 27;
int p = 0;
using namespace std;
void maturity_winthdraw(int,int,double);
int password();
void admin();
void holder();
void ministatement();

/** List of Global Variable */
COORD coord = {0,0}; /// from top-left corner of window

/**
    function : gotoxy
    input: x and y coordinates
    output: moves the cursor in specified position of console
*/
void gotoxy(int x, int y)
{
    coord.X = x ; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/** To delay console window */
int fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

/** Welcome Page */
void welcome()
{
    time_t t = time(0);

        system("color 5E");
        system("cls");

        gotoxy(55,3);
        cout << ctime(&t);
        gotoxy(25,8);
        cout << "*******************************";
        gotoxy(28,10);
        cout << "Banking Management System";
        gotoxy(25,12);
        cout << "*******************************";

        gotoxy(32,16);
        cout << "Presented by";
        gotoxy(40,18);
        cout << " KV IT Solutions";

        gotoxy(25,22);
        cout << "Press any key to continue..";

        getch();
}

/** Loading Page */
void load()
{
    int i;

        system("cls");
        gotoxy(28,10);
        cout << "Loading your Console window";
        gotoxy(35,12);
        cout << "Please Wait";
        for(i=0;i<=6;i++)
        {
                    fordelay(60000000);
                    printf(".");
        }
}

/** Admin Password Page */
void get_Pass()
{
    again_pass:
    int ch;
    system("cls");
    system("color 70");

    gotoxy(28,2);
    cout << "Sign in to your KiVi Account";

    gotoxy(23,3);
    cout << "____________________________________";

    gotoxy(22,4);cout << "|";gotoxy(22,5);cout << "|";gotoxy(22,6);cout << "|";gotoxy(22,7);cout << "|";
    gotoxy(22,8);cout << "|";gotoxy(22,9);cout << "|";gotoxy(22,10);cout << "|";gotoxy(22,11);cout << "|";
    gotoxy(22,12);cout << "|";gotoxy(22,13);cout << "|";gotoxy(22,14);cout << "|";gotoxy(22,15);cout << "|";
    gotoxy(22,16);cout << "|";gotoxy(22,17);cout << "|";gotoxy(22,18);cout << "|";gotoxy(22,19);cout << "|";
    gotoxy(22,20);cout << "|";

    gotoxy(28,8);
    cout << "Password";

    gotoxy(38,7);cout<<"|";gotoxy(38,8);cout<<"|";gotoxy(38,9);cout<<"|";
    gotoxy(39,6);cout<<"_________________";gotoxy(39,9);cout<<"_________________";
    gotoxy(56,7);cout<<"|";gotoxy(56,8);cout<<"|";gotoxy(56,9);cout<<"|";

    gotoxy(31,15);cout << "Press Enter to Sign in";

    gotoxy(59,4);cout << "|";gotoxy(59,5);cout << "|";gotoxy(59,6);cout << "|";gotoxy(59,7);cout << "|";
    gotoxy(59,8);cout << "|";gotoxy(59,9);cout << "|";gotoxy(59,10);cout << "|";gotoxy(59,11);cout << "|";
    gotoxy(59,12);cout << "|";gotoxy(59,13);cout << "|";gotoxy(59,14);cout << "|";gotoxy(59,15);cout << "|";
    gotoxy(59,16);cout << "|";gotoxy(59,17);cout << "|";gotoxy(59,18);cout << "|";gotoxy(59,19);cout << "|";
    gotoxy(59,20);cout << "|";

    gotoxy(23,20);
    cout << "____________________________________";

    gotoxy(40,8);
    //upper(pass);
    if(password() == 1)
    {
        admin();
    }
    else
    {
        //system("cls");
        ++p;
        gotoxy(35,24);
        cout << " Wrong choice.... ";
        gotoxy(39,26);
        cout << "Try " << p;
        if(p == 3)
        {
            cout << "\n\n\n Program Terminated.";
            getch();
            exit(0);
        }
        getch();
        goto again_pass;
    }
}

/** Login Page */
void choose()
{
    again_choose:
    system("cls");
    system("color 70");

    int ac;
    char ch;

    gotoxy(28,2);
    cout << "Sign in to your KiVi Account";

    gotoxy(23,3);
    cout << "____________________________________";

    gotoxy(22,4);cout << "|";gotoxy(22,5);cout << "|";gotoxy(22,6);cout << "|";gotoxy(22,7);cout << "|";
    gotoxy(22,8);cout << "|";gotoxy(22,9);cout << "|";gotoxy(22,10);cout << "|";gotoxy(22,11);cout << "|";
    gotoxy(22,12);cout << "|";gotoxy(22,13);cout << "|";gotoxy(22,14);cout << "|";gotoxy(22,15);cout << "|";
    gotoxy(22,16);cout << "|";gotoxy(22,17);cout << "|";gotoxy(22,18);cout << "|";gotoxy(22,19);cout << "|";
    gotoxy(22,20);cout << "|";

    gotoxy(26,8);
    cout << "Account No.";

    gotoxy(38,7);cout<<"|";gotoxy(38,8);cout<<"|";gotoxy(38,9);cout<<"|";
    gotoxy(39,6);cout<<"_________________";gotoxy(39,9);cout<<"_________________";
    gotoxy(56,7);cout<<"|";gotoxy(56,8);cout<<"|";gotoxy(56,9);cout<<"|";

    gotoxy(31,15);cout << "Press 1 : Administrator";
    gotoxy(31,18);cout << "Press 2 : Customer";

    gotoxy(59,4);cout << "|";gotoxy(59,5);cout << "|";gotoxy(59,6);cout << "|";gotoxy(59,7);cout << "|";
    gotoxy(59,8);cout << "|";gotoxy(59,9);cout << "|";gotoxy(59,10);cout << "|";gotoxy(59,11);cout << "|";
    gotoxy(59,12);cout << "|";gotoxy(59,13);cout << "|";gotoxy(59,14);cout << "|";gotoxy(59,15);cout << "|";
    gotoxy(59,16);cout << "|";gotoxy(59,17);cout << "|";gotoxy(59,18);cout << "|";gotoxy(59,19);cout << "|";
    gotoxy(59,20);cout << "|";

    gotoxy(23,20);
    cout << "____________________________________";

    gotoxy(40,8);cin >> ac;
    gotoxy(50,18);ch = getch();
    if(ch == '1')
        get_Pass();
    else if(ch == '2')
    {
        holder();
    }
    else
    {
        system("cls");
        cout << "\n\n Wrong Choice. Exiting the Program";
        getch();
        //exit(0);
        goto again_choose;
    }

}

/** Converts String to Uppercase */
string upper(char s[])
{
    int i;
    for(i=0;i<s[i]!='\0';i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

/** Exit Page */
void bye()
{
    time_t t = time(0);

        system("color 5E");
        system("cls");

        gotoxy(55,3);
        cout << ctime(&t);

        gotoxy(32,8);
        cout << "Presented by";
        gotoxy(40,10);
        cout << " KV IT Solutions";

        gotoxy(28,14);
        cout << "Thank You for Visiting !!!!!! ";

        gotoxy(35,18);
        cout << "Visit again Soon" << endl << endl;

}



class account
{
    public:
        int accountnumber;
        char name[32];
        int deposit;
        char type;

        virtual void create_account() = 0;
        virtual void show_account() = 0;
        virtual void modify_account() = 0;
        virtual void deposit_funds(int) = 0;
        virtual void find_Maturity() = 0;
        virtual void draw_funds(int) = 0;
        virtual void get_report() = 0;
        virtual int get_accountnumber() = 0;
        virtual int get_funds() = 0;
        virtual char get_accounttype() = 0;
};

class employee : public account
{
private:
    char *pass[38];

public:
    void create_account();
    void show_account();
    void modify_account();
    void deposit_funds(int);
    void find_Maturity();
    void draw_funds(int);
    void get_report();
    int get_accountnumber();
    int get_funds();
    char get_accounttype();
};

void employee :: find_Maturity()
{
    double M,R,n,i;

    cout << "\n Enter monthly Deposits :: ";
    cin>>R;
    cout << "\n Enter No of Quarters (months) :: ";
    cin>>n;
    cout << "\n Enter Rate of Interest :: ";
    cin>>i;
    i=(i/400)+1;

    M=(R*((pow(i,n)-1)))/(1-(pow(i,(double)(-0.333333))));
    cout << "\n\n Maturity Amount :: "<<M;

        cout << "\n\n Would You like to Withdraw in Your Account ? [Y/N] :: ";
        char ch2=getch();
        if(ch2=='Y' | 'y')
        {
            cout <<"\n\n Enter Your Account Number :: ";
            cin>>accountnumber;

            maturity_winthdraw(accountnumber,2,M);
    }
}

void employee::create_account()
{
    create_again:
    system("cls");
        gotoxy(2,1);
        cout<<" Enter the account Number :: ";
        gotoxy(2,3);
        cout<<" Enter the name of the Account holder :: ";
        gotoxy(2,5);
        cout<<" Enter account type (s - saving or c - credit) :: ";
        gotoxy(2,7);
        cout<<" Enter The Initial amount - \n  (Saving - 500 or more and Current - 1000 or more) :: ";
        gotoxy(31,1);
        while(std::cout << "" && !(std::cin >> accountnumber))
        {
            system("cls");
            std::cin.clear(); //clear bad input flag
            std::cin.ignore();
            cout << "\n\n Account Number invalid. Press Enter to try Again...";
            if(getch()==13)
                goto create_again;
            else
                exit(0);
        }

        gotoxy(43,3);
        cin.ignore();
        cin.getline(name,32);
        upper(name);

        gotoxy(53,5);
        cin>>type;
        type=toupper(type);
        if(type != 'S' && type != 'C') /// Validation to ensure S or C is typed in
        {
            MessageBeep(MB_YESNO);
            system("cls");
            cout << "\n Invalid Input. Press Enter to try again...";
            if(getch() == 13)
                goto create_again;
            else
                exit(0);
        }

        gotoxy(55,8);
        cin>>deposit;
        if (type == 'S')
        {
            if(deposit < 500)
            {
                MessageBeep(MB_YESNO);
                system("cls");
                cout << "\n Deposit Amount should be greater than or equal to 500. Press Enter to try again...";
                if(getch() == 13)
                    goto create_again;
                else
                    exit(0);
            }
        }
        else
        {
            if(deposit < 1000)
            {
                MessageBeep(MB_YESNO);
                system("cls");
                cout << "\n Deposit Amount should be greater than or equal to 1000. Press Enter to try again...";
                if(getch() == 13)
                    goto create_again;
                else
                    exit(0);
            }
        }
        cout<<"\n\n  Account Created Successfully...";

        cout << "\n\n\n  Press Enter to go back to Main Menu";
}

void employee::show_account()
{
    system("cls");

    gotoxy(1,1);
    cout << "Account Details --";
    gotoxy(3,3);
    cout<<"Account Number :: " << accountnumber;
    gotoxy(3,4);
    cout<<"Account Holder Name :: "<<name;
    gotoxy(3,5);
    cout<<"Account type :: "<<type;
    gotoxy(3,6);
    cout<<"Account Balance :: "<<deposit;
}

void employee::modify_account()
{
    create_again:

        gotoxy(4,12);
        cout<<" Modified Name of Account Holder :: ";
        gotoxy(4,14);
        cout<<" Modified Account type (s - saving or c - credit) :: ";
        gotoxy(4,16);
        cout<<" Modified the Initial amount - \n     (Saving - 500 or more and Current - 1000 or more) :: ";

        gotoxy(40,12);
        cin.ignore();
        cin.getline(name,32);
        upper(name);

        gotoxy(57,14);
        cin>>type;
        type=toupper(type);
        if(type != 83) /// Validation to ensure S or C is typed in
        {
            MessageBeep(MB_YESNO);
            system("cls");
            cout << "\n Invalid Input. Press Enter to try again...";
            if(getch() == 13)
                goto create_again;
            else
                exit(0);
        }

        gotoxy(57,17);
        cin>>deposit;
        if (type == 'S')
        {
            if(deposit < 500)
            {
                MessageBeep(MB_YESNO);
                system("cls");
                cout << "\n Deposit Amount should be greater than or equal to 500. Press Enter to try again...";
                if(getch() == 13)
                    goto create_again;
                else
                    exit(0);
            }
        }
        else
        {
            if(deposit < 1000)
            {
                MessageBeep(MB_YESNO);
                system("cls");
                cout << "\n Deposit Amount should be greater than or equal to 1000. Press Enter to try again...";
                if(getch() == 13)
                    goto create_again;
                else
                    exit(0);
            }
        }

        cout<<"\n\n  Account Updated Successfully...";
        cout << "\n\n  Press any key to go back to Main Menu";
}

void employee::deposit_funds(int x)
{
        deposit+=x;
        ofstream ministatement ("mini.txt",ios::app);
        if(ministatement.is_open())
        {
           ministatement <<"\n\t      "<<setw(10)<<accountnumber<<"       "<<setw(10)<<name<<setw(10)<<type<<"  "<<setw(10)<<x<<endl;
        }
        else
        {
            cout <<"Enable to Open File !!! \n You have to First DEPOSIT or WITHDRAW amount";
        }

        ministatement.close();
}

void employee::draw_funds(int x)
{
        deposit-=x;
        ofstream ministatement("mini.txt",ios::app);
        if(ministatement.is_open())
        {
            ministatement <<"\n\t      "<<setw(10)<<accountnumber<<"       "<<setw(10)<<name<<setw(10)<<type<<"  "<<setw(10)<<-x<<endl;
        }
        else
        {
            cout <<"Enable to Open File !!! \n You have to First DEPOSIT or WITHDRAW amount";
        }
        ministatement.close();

}

void employee::get_report()
{
        cout<<"\n\t      "<<setw(10)<<accountnumber<<"       "<<setw(10)<<name<<setw(10)<<type<<"  "<<setw(10)<<deposit<<endl;
}

int employee::get_accountnumber()
{

        return accountnumber;
}

int employee::get_funds()
{
        return deposit;
}

char employee::get_accounttype()
{
        return type;
}

class customer : public account
{
public:
    void show_account();
    void deposit_funds(int);
    void find_Maturity();
    void draw_funds(int);
    int get_accountnumber();
    int get_funds();
    char get_accounttype();
};

void customer :: find_Maturity()
{
    double M,R,n,i;

    cout << "\n Enter monthly Deposits :: ";
    cin>>R;
    cout << "\n Enter No of Quarters (months) :: ";
    cin>>n;
    cout << "\n Enter Rate of Interest :: ";
    cin>>i;
    i=(i/400)+1;

    M=(R*((pow(i,n)-1)))/(1-(pow(i,(double)(-0.333333))));
    cout << "\n\n Maturity Amount :: "<<M;

        cout << "\n\n Would You like to Withdraw in Your Account ? [Y/N] :: ";
        char ch2=getch();
        if(ch2=='Y' | 'y')
        {
            cout <<"\n\n Enter Your Account Number :: ";
            cin>>accountnumber;

            maturity_winthdraw(accountnumber,2,M);
        }
}

void customer::show_account()
{
    system("cls");

    gotoxy(1,1);
    cout << "Account Details --";
    gotoxy(3,3);
    cout<<"Account Number :: " << accountnumber;
    gotoxy(3,4);
    cout<<"Account Holder Name :: "<<name;
    gotoxy(3,5);
    cout<<"Account type :: "<<type;
    gotoxy(3,6);
    cout<<"Account Balance :: "<<deposit;
}

void customer::deposit_funds(int x)
{
        deposit+=x;
}

void customer::draw_funds(int x)
{
        deposit-=x;
}

int customer::get_accountnumber()
{
        return accountnumber;
}

int customer::get_funds()
{
        return deposit;
}

char customer::get_accounttype()
{
        return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void terms();

int main()
{
        welcome();

        load();

        choose();

        return 0;
}

/** Admin Menu */
void admin()
{
    char opt;
    int num,i;
    time_t t = time(0);

    for(;;)
        {
            system("cls");
            system("color 70");

            gotoxy(26,2);
            cout<<" Banking Management System";

            gotoxy(55,5);
            cout<<ctime(&t);

            gotoxy(0,6);
            cout<<"________________________________________________________________________________";

            /** For seperate Date and Time */
            /*
            struct tm *now = localtime(&t);
            cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' <<  now->tm_mday << endl;
            */

            gotoxy(6,9);
            cout<<"\t\t~~~~~~~~~~~~~~~~~~~>> Menu <<~~~~~~~~~~~~~~~~~";
                gotoxy(25,11);
                cout<<" Press 1 : Create New Account";
                gotoxy(25,12);
                cout<<" Press 2 : Deposit Funds";
                gotoxy(25,13);
                cout<<" Press 3 : Withdraw Funds";
                gotoxy(25,14);
                cout<<" Press 4 : Check Balance";
                gotoxy(25,15);
                cout<<" Press 5 : View All Account Holder";
                gotoxy(25,16);
                cout<<" Press 6 : Close an Account";
                gotoxy(25,17);
                cout<<" Press 7 : Modify an Account";
                gotoxy(25,18);
                cout<<" Press 8 : Recurring Withdraws";
                gotoxy(25,19);
                cout<<" Press 9 : Exit the Program";
            cout<<"\n\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                gotoxy(25,22);
                cout<<" Choice: ";
                cin>>opt;
                system("cls");
                employee ac;
                switch(opt)
                {
                case '1':
                system("color 02");
                        terms();
                        break;
                case '2':
                system("color 03");
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 1);
                        break;
                case '3':
                system("color 06");
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 2);
                        break;
                case '4':
                system("color 08");
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        display_sp(num);
                        break;
                case '5':
                system("color 9");
                        display_all();
                        break;
                case '6':
                system("color 10");
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        delete_account(num);
                        break;
                 case '7':
                 system("color 11");
                        gotoxy(2,1);
                        cout<<" Enter The account No. :: "; cin>>num;
                        modify_account(num);
                        break;
                 case '8':
                        ac.find_Maturity();
                        break;
                 case '9':
                        //cout<<"\n\n\tThanks for using Bank Managemnt System";
                        bye();
                        getche();
                        exit(0);
                        break;
                 default :cout<<"Invalid Option\n";
                }
                cin.ignore();
                cin.get();

                if(opt=='8')
                break;
        }
}

/** Customer Menu */
void holder()
{
    char opt;
    int num,i;
    time_t t = time(0);

    for(;;)
        {
            system("cls");
            system("color 70");

            gotoxy(26,2);
            cout<<" Banking Management System";

            gotoxy(55,5);
            cout<<ctime(&t);

            gotoxy(0,6);
            cout<<"________________________________________________________________________________";

            /** For seperate Date and Time */
            /*
            struct tm *now = localtime(&t);
            cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' <<  now->tm_mday << endl;
            */

            gotoxy(6,9);
            cout<<"\t\t~~~~~~~~~~~~~~>> Customer Menu <<~~~~~~~~~~~~";
                gotoxy(25,11);
                cout<<" Press 1 : Deposit Funds";
                gotoxy(25,12);
                cout<<" Press 2 : Withdraw Funds";
                gotoxy(25,13);
                cout<<" Press 3 : Check Balance";
                gotoxy(25,14);
                cout<<" Press 4 : Recurring Withdraws";
                gotoxy(25,15);
                cout<<" Press 5 : Mini Statement";
                gotoxy(25,16);
                cout<<" Press 6 : Exit the Program";
            cout<<"\n\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                gotoxy(25,18);
                cout<<" Choice: ";
                cin>>opt;
                system("cls");
                employee ac;
                switch(opt)
                {
                case '1':
                system("color 03");
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 1);
                        break;
                case '2':
                system("color 06");
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        deposit_withdraw(num, 2);
                        break;
                case '3':
                system("color 08");
                        cout<<"\n\n\tEnter The account No. : "; cin>>num;
                        display_sp(num);
                        break;
                 case '4':
                        ac.find_Maturity();
                        break;
                 case '5':
                        ministatement();
                        break;
                 case '6':
                        //cout<<"\n\n\tThanks for using Bank Managemnt System";
                        bye();
                        getche();
                        exit(0);
                        break;
                 default :cout<<"Invalid Option\n";
                }
                cin.ignore();
                cin.get();

                if(opt=='8')
                    break;
        }
}

void terms()
{
    char ch;

    system("color 30");
    //cout <<setw(100)<<setfill('-');
    gotoxy(29,1);
    cout<<"TERMS AND CONDITIONS"<<endl;
    cout <<"\n1) Period of RD - 6 months to 120 months in multiple of 3 months"<<endl;
    cout <<"\n2) Premature withdrawal is allowed."<<endl;
    cout <<"\n3) No TDS is applicable."<<endl;
    cout <<"\n4) Withdrawals on maturity or one month after deposit of last installment, which   ever is later."<<endl;
    cout <<"\n5) No TDS applicable"<<endl;
    cout <<"\n6) Generally loans/overdrafts against deposits are allowed."<<endl;
    cout <<"\n7) Interest on overdue deposit is paid as per prevalent policy of the bank from    time to time."<<endl;
    cout <<"\n8) Interest on bank deposits is exempt from incometax upto a limit specified by.";
    cout <<"\n9) Income Tax authorities from time to time."<<endl;

    cout <<"\n\nDo you Accept our TERMS ans CONDITIONS [Y/N] :: ";
    cin >> ch;

    if(ch=='Y' | ch=='y')
    {
        write_account();
    }
    else
    {
        MessageBeep(MB_YESNO);
        system("cls");
        cout << "\n\n Sorry !!! Your account cannot be created";
        cout << "\n\n Press - \n        Enter to go Back.... \n        ESC to Exit";
        if(getch()==ESC)
        {
            exit(0);
        }
    }
}

void write_account()
{
        employee ac;
        ofstream outFile;
        outFile.open("account.dat",ios::binary|ios::app);
        ac.create_account();
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(employee));
        outFile.close();
}


void display_sp(int n)
{
        employee ac;
        bool flag=false;
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"\n\n File could not be open !! Press any Key...";
                return;
        }

        gotoxy(2,2);
        cout<<"BALANCE DETAILS --";

        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(employee)))
        {
                if(ac.get_accountnumber()==n)
                {
                        ac.show_account();
                        flag=true;
                }
        }
        inFile.close();
        if(flag==false)
                cout<<"\n\n Account number does not exist";
}

void modify_account(int n)
{
        bool found=false;
        employee ac;
        fstream File;
        File.open("account.dat",ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(employee));
                if(ac.get_accountnumber()==n)
                {
                        ac.show_account();
                        gotoxy(1,10);
                        cout<<" Enter The New Details of account -- "<<endl;
                        ac.modify_account();
                        int pos=(-1)*static_cast<int>(sizeof(employee));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(employee));
                        //cout<<"\n\n\n\t Record Updated...";
                        found=true;
                  }
        }
        File.close();
        if(found==false)
                cout<<"\n\n Record Not Found ";
}

void delete_account(int n)
{
        employee ac;
        ifstream inFile;
        ofstream outFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        outFile.open("Temp.dat",ios::binary);
        inFile.seekg(0,ios::beg);
        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(employee)))
        {
                if(ac.get_accountnumber()!=n)
                {
                        outFile.write(reinterpret_cast<char *> (&ac), sizeof(employee));
                }
        }
        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat","account.dat");
        cout<<"\n\n\tRecord Deleted...";
}

void display_all()
{
        employee ac;
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        gotoxy(29,2);
        cout<<"ACCOUNT HOLDER LIST";
        gotoxy(15,4);
        cout<<"====================================================";
        gotoxy(18,5);
        cout<<"Account No.       Name        Type     Balance";
        gotoxy(15,6);
        cout<<"====================================================";
        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(employee)))
        {
                ac.get_report();
        }
        inFile.close();
}

void deposit_withdraw(int n, int option)
{
        int amt;
        bool found=false;
        employee ac;
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(employee));
                if(ac.get_accountnumber()==n)
                {
                        ac.show_account();
                        if(option==1)
                        {
                                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                                cout<<"\n\nEnter The amount to be deposited: ";
                                cin>>amt;
                                ac.deposit_funds(amt);
                        }
                        if(option==2)
                        {
                                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                                cout<<"\n\nEnter The amount to be withdraw: ";
                                cin>>amt;
                                int bal=ac.get_funds()-amt;
                                if((bal<500 && ac.get_accounttype()=='S') || (bal<1000 && ac.get_accounttype()=='C'))
                                        cout<<"Insufficience balance";
                                else
                                        ac.draw_funds(amt);
                        }
                        int pos=(-1)*static_cast<int>(sizeof(ac));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(employee));
                        cout<<"\n\n\t Record Updated";
                        found=true;
               }
         }
        File.close();
        if(found==false)
                cout<<"\n\n Record Not Found ";
}

void maturity_winthdraw(int n, int option, double m)
{
        int amt = m;
        bool found=false;
        employee ac;
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any Key...";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(employee));
                if(ac.get_accountnumber()==n)
                {
                        ac.show_account();
                        if(option==2)
                        {
                            cout << "\n Maturity Amount about to be Withdraw .. Are you Sure ???";

                                int bal=ac.get_funds()-amt;
                                if((bal<500 && ac.get_accounttype()=='S') || (bal<1000 && ac.get_accounttype()=='C'))
                                        cout<<"Insufficience balance";
                                else
                                        ac.draw_funds(amt);
                        int pos=(-1)*static_cast<int>(sizeof(ac));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(employee));
                        cout<<"\n\n\t Record Updated";
                        found=true;
                        }
               }
         }
        File.close();

        cout << "\n\n Would you like to Exit ? [Y/N] :: ";
        if(getch() == 'Y' || getch() == 'y')
        {
            exit(0);
        }
        else
        {
            main();
        }
        if(found==false)
                cout<<"\n\n Record Not Found ";
}
int password()
{
    //system("color 0D");
    string pass ="";
   char ch;
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "brds"){
        gotoxy(34,22);
        cout <<"Password Match ";
      return 1;
   }else{

        gotoxy(18,22);
       cout <<" !!!!!!Sorry you Entered Wrong Password !!!!!!";
       getch();
      return 0;
   }
}

void ministatement()
{
    gotoxy(35,3);
    cout <<"Mini Statement"<<endl<<endl;

    ifstream fi;
    char ch,str;
    static int i=0;
    fi.open("mini.txt");
    if(fi.is_open())
    {
        while(!fi.eof())
        {
            fi.get(ch);
            cout <<ch;
        }
    }
    else
        cout <<"Enable to open file ";

        cout <<"Press any Key ";
}
