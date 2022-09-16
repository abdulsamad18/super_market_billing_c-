#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price, dis;
    string pname;

public:
    void menu();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void recipt();
};
void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t*****************************\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t********    SUPER MARKET Main menu        *********\n";
    cout << "\t\t\t\t*****************************\n";
    cout << "\t\t\t\t                              \n";

    cout << "\t\t\t\t    1.Adminstrator    \n";
    cout << "\t\t\t\t                      \n";
    cout << "\t\t\t\t    2.Buyer           \n";
    cout << "\t\t\t\t                      \n";
    cout << "\t\t\t\t    3.exit            \n";
    cout << "\t\t\t\t                      \n";
    cout << "t\t\tEnter your choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t    Please login first    \n";
        cout << "\t\t\t\t    Enter your email    \n";
        cin >> email;
        cout << "\t\t\t\t    Enter your Password    \n";
        cin >> password;

        if (email == "samad@gmail.com" && password == "Samad123")
        {
            admin();
        }
        else
        {
            cout << "\t\t\t  INVALID USERNAME AND PASSWORD\n";
        }
        break;
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "\t\t\t\t\t  PLEASE SELECT FROM THE GIVEN OPTIONS\n";
    }
    }
    goto m;
}
void shopping::admin()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t\t    admin menu              \n";
    cout << "\n\t\t\t\t       1.add the product         \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t    2.Modify the product           \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t    3.delete the product            \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t     4.back to main menu           \n";
    cout << "\t\t\t\t   PLEASE ENTER YOURE CHOICE       \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "INVALID CHOICE/N";
        break;
    }
    goto m;
}
void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t       Buyer                        \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t       1.Buy product                 \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t       2.go back                            \n";
    cout << "\t\t            Enter your choice\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        recipt();
        break;
    case 2:
        menu();
        break;

    default:
        cout << "invalid Choice\n";
        break;
    }
    goto m;
}
void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\t\t\t\t     ADD NEW PRODUCT                              \n";
    cout << "\n\n\t\t\tproduct code of the product                      \n";
    cin >> pcode;
    cout << "\t\t\t\t\n\n Name of the product                             \n";
    cin >> pname;
    cout << "\t\t\nEnter the price of the product                      \n";
    cin >> price;
    cout << "\t\t\nDISCOUNT on the product               \n";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << "  " << pcode << "   " << pname << "  " << price << "   " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << "  " << pcode << "   " << pname << "  " << price << "   " << dis << "\n";
            data.close();
        }
        cout << "\t\t\t\t\nRECORD INSERTED\n";
    }
}
    void shopping::edit()
    {
        fstream data, data1;
        int pkey;
        int token;
        int c;
        float p;
        float d;
        string n;

        cout << "\n\n\t\t\t Modify the record";
        cout << "\n\n\t\t\t PRODUCT CODE";
        cin >> pkey;

        data.open("database.txt", ios::in);
        if (!data)
        {
            cout << "\n\n\tFile doesnot exists\n";
        }
        else
        {
            data1.open("database1.txt", ios::app|ios::out);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pkey == pcode)
                {
                    cout << "\n\n\t\t PRODUCT NEW CODE";
                    cin >> c;
                    cout << "\n\n\tNAME OF THE PRODUCT";
                    cin >> n;
                    cout << "\n\n\t\t price";
                    cin >> p;
                    cout << "\n\n\t\t DISCOUNT";
                    cin >> d;
                    data1 << " " << c << "  " << n << " " << p << "   " << d << "\n";
                    cout << "\t\t\t\n\nRECORD EDITED";
                    token++;
                }
                else
                {
                    data1 << " " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (token == 0)
                cout << "\n\n\t\tRECORD not found\n";
        }
    }
    void shopping::rem()
    {
        fstream data, data1;
        int pkey;
        int token = 0;
        cout << "\n\n\t\tDELETE product";
        cout << "\n\n\t\tEnterv the product code\n";
        cin >> pkey;
        data.open("database.txt", ios::in);
        if (!data)
        {
            cout << "File doesnot exists";
        }
        else
        {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == pkey)
                {
                    cout << "\n\n\t\t  PRODUCT DELETED SUCCESFULLY";
                    token++;
                }
                else
                {
                    data1 << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
                data1.close();
                    remove("database.txt");
                    rename("database1.txt", "database.txt");

                    if (token == 0)
                        cout<< "\n\n\t\tRECORD not found";
        }
    }
    void shopping::list()
    {
        fstream data;
        data.open("database.txt", ios::in);
        cout << "\n\n\n|-------------------------------------\n";
        cout << "product_NO\tName\tPrice\n";
        cout << "\n\n\n|-------------------------------------\n";
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }

    void shopping::recipt()
    {
        fstream data;
        int arrc[100];
        int arrq[100];
        string choice;
        int c = 0;
        float amount = 0;
        float dis = 0;
        float total = 0;

        cout << "\n\n\t\t RECIPT\n";
        data.open("database.txt", ios::in);
        if (!data)
        {
            cout << "\n\n\t\tEmpty database\n";
        }
        else
        {
            data.close();
            list();
            cout << "\n\n\t\t---------------------------------------------\n";
            cout << "\n\n\t\t---------------------------------------------\n";
            cout <<"\n\n\t\t   PLEASE place the order             \n";
            cout << "\n\n\t\t---------------------------------------------\n";
            cout <<"\n\n\t\t---------------------------------------------\n";
            do
            {
                m:
                cout << "\n\n\t\tEnter product code\n";
                cin >> arrc[c];
                cout << "\n\n\t\tenter the product quantity\n";
                cin >> arrq[c];
                for (int i = 0; i < c; i++)
                {
                    if (arrc[c] == arrc[i])
                    {
                        cout << "\n\nDuplicate product code please try again";
                         goto m;
                    }
                }
                c++;
                cout << "\n\nDo you wnat to buy another product? if yes press y and n for no";
                cin>>choice;
            } 
            while (choice=="y");

            cout << "\n\n\n\t\t\t----------------RECIPT--------------------------\n";
            cout << "\n\n\t\tProduct NO\t product name\t product quantity\t price\tAmount\t Amount with discount";

            for (int i = 0; i < c; i++)
            {
                data.open("database.txt", ios::in);
                data >> pcode >> pname >> price >> dis;
                while (!data.eof())
                {
                    if (pcode == arrc[i])
                    {
                        amount = price * arrq[i];
                        dis = amount - (amount * dis / 100);
                        total = total + dis;
                        cout << "\n"<< pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                    }
                    data >> pcode >> pname >> price >> dis;
                }
            }
            data.close();
        }
        cout<<"\n\n\t\t---------------------------------------------------\n";
        cout<<"\nTOTAL AMOUNT=" << total;
    }
    
    

int main()
{
    shopping s;
    s.menu();
}