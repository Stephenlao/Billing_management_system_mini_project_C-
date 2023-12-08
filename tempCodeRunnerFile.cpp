#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
using std::fstream;


class Shopping {
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    
    public:
        Shopping(){};

        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

// declare scope resolution if using function outside class
void Shopping :: menu() {
    // define in goto
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t        Supermarket Main Menu       \n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t|  1) Administrator                 |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  2) Buyer                         |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  3) Exit                          |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  Please select: ";
    cin >> choice;



    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login\n";
        cout << "\t\t\t Enter Email: ";
        cin >> email;
        cout << "\t\t\t Enter password: ";
        cin >> password;

        if (email == "abc" && password == "1234") {
            // call function administrator in class Shopping
            administrator();
        } else {
            cout << "Wrong email or password. Please try again!" << '\n';
        } 
        break;
    case 2:
        buyer();
        break;
    case 3:
        cout << "Quit system!" << "\n";
        exit(0);
    default:
        cout << "Invalid choice!" << "\n";
        break;
    }

// define m location to go back at the beginning of program
// implement like while loop to ask user several times
goto m;
}


void Shopping::administrator() {
    m:
    int choice;
    cout << "\n\n\n";
    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t        Administrator               \n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t|  1) Add the product               |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  2) Modify the product            |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  3) Delete the product            |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  4) Back to main menu             |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  4) Please select: ";
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
        cout << "Please choice the correct choice in board!" << "\n";
        break;
    }
goto m;
};


void Shopping::buyer() {
    m:
    int choice;
    cout << "\n\n\n";
    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t        Buyer                       \n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t|  1) Buy product                   |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  2) Back to main menu             |\n";
    cout << "\t\t\t\t|                                   |\n";
    cout << "\t\t\t\t|  Please select:";
    cin >> choice;

    switch (choice) {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Please choice the correct choice in board!" << "\n";
        break;
}
goto m;
};


void Shopping::add() {
    m:
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    fstream myFile;


    cout << "\t\t\t\t  Add new product                  \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t  1.Product code: ";
    cin >> pcode;
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t  2.Product name: ";
    cin >> pname;              
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t  3.Product price: ";
    cin >> price;
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t  4.Product discount: ";
    cin >> dis;
    cout << "\t\t\t\t                                   \n";

    // open file in read mode
    myFile.open("database.txt", std::ios::in);

    // if file did not created before

    if (!myFile.is_open()) {
        // open file in append mode to write product info
        myFile.open("database.txt", std::ios::app | std::ios::out);
        myFile << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        cout << "Recorded successfull for first time!" << "\n";
        myFile.close();
        return;

    // if file is created
    } else {

        // read each line in file then store in  c,n,p,d

        myFile >> c >> n >> p >> d;
        // read all the content
        while(!myFile.eof()) {
            if (c == pcode) { // check whether pcode in file equal pcode enter from user
                token ++; // if yes increase token to 1
            }
            // read next line in file and return while loop if has content
            myFile >> c >> n >> p >> d;
    }
    }
    myFile.close();

    // token = 1 => duplicate pcode return menu to add product info again
    if (token == 1) {
        cout << "Product code has already exists, please added again!" << "\n";
        goto m;
        // valid pcode write to file
    } else {
        myFile.open("database.txt", std::ios::app | std::ios::out);
        myFile << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        cout << "Recorded successfull!" << "\n";
        myFile.close();
    }
}

void Shopping::edit() {
    fstream myFile, myFile1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code: ";
    cin >> pkey;

    myFile.open("database.txt", std::ios::in);
    
    if (!myFile.is_open()) {
        std::cerr << "File is not exist!" << "\n";
        return;
    } else {
        myFile1.open("database1.txt", std::ios::app | std::ios::out);
        
        myFile >> pcode >> pname >> price >> dis;
        while(!myFile.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\t Product new code: ";
                cin >> c;
                cout << "\n\t\t Name of the product: ";
                cin >> n;
                cout << "\n\t\t New price: ";
                cin >> p;
                cout << "\n\t\t Discount: ";
                cin >> d;
                myFile1 << " " << c << " " << n << " " << p << " " << d << "\n";
                token ++;
                cout << "Edited record successfull" << "\n";
            } else {
                myFile1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            myFile >> pcode >> pname >> price >> dis;
        }
        myFile.close();
        myFile1.close();
    }
    // delete database.txt
    remove("database.txt");

    // change name database1.txt to database.txt
    rename("database1.txt", "database.txt");

    if (token == 0) {
        cout << "\n\n Record not found sorry!" << "\n";
    }
}


void Shopping ::rem() {
    fstream myFile, myFile1;
    int pkey;
    int token = 0;


    cout << "\n\t\t Remove product \n";
    cout << "\n\t\t Product code: ";
    cin >> pkey;

    myFile.open("database.txt", std::ios::in);
    if (!myFile.is_open()) {
        std::cerr << "File is not exist!" << "\n";
        return;
    } else {
        myFile1.open("database1.txt", std::ios::app | std::ios::out);

        // read each line and store value in each variables
        myFile >> pcode >> pname >> price >> dis;
        while(!myFile.eof()) {
            if (pkey == pcode) {
                cout << "Remove product successfull" << "\n";
                token ++;
            } else {
                myFile1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            // continue next loop
            myFile >> pcode >> pname >> price >> dis;
        }
        myFile.close();
        myFile1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0) {
            cout << "Record not found" << "\n";
        }
    }
}

void Shopping ::list() {
    fstream myFile;
    myFile.open("database.txt", std::ios::in);

    cout << "\n\n|_______________________________|\n";
    cout << "\n\nProNo\t\tName\t\tPrice";
    cout << "\n\n|_______________________________|\n";


    if (!myFile.is_open()) {
        std::cerr << "File path is not exist!" << "\n";
        return;
    } else {
        myFile >> pcode >> pname >> price >> dis;

        while (!myFile.eof()) {
            cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
            myFile >> pcode >> pname >> price >> dis;
        }
        myFile.close();
    }
}


void Shopping :: receipt() {
    m:
    fstream myFile;
    // array of code to store code and quantity enter by user
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT ";
    myFile.open("database.txt", std::ios::in);

    if (!myFile.is_open()) {
        std::cerr << "Empty database!" << "\n";
    
    } else {
        myFile.close();
        list();
        cout <<"\n______________________________\n";
        cout <<"\n                              \n";
        cout <<"\n    Please place the order    \n";
        cout <<"\n                              \n";
        cout <<"\n______________________________\n";

        do
        {
            cout << "Please enter the product code: ";
            cin >> arrc[c];
            cout << "Please enter the product quantity: ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "Duplicated product code. Please re-enter again!" << "\n";
                    goto m;
                }
            }
            c++;
            cout << "Do you want to buy another product or not. Please press y to continue otherwise press n: ";
            cin >> choice;
        } while (choice == 'y');
        
        cout <<"\n\n\t\t\t__________________RECEIPT__________________\n";
        cout <<"\nProduct No\tProduct name\tproduct quantity\tprice\t\tAmount\t\tAmount with discount\n";

      
        for (int i = 0; i < c; i++) {
            myFile.open("database.txt", std::ios::in);
            myFile >> pcode >> pname >> price >> dis;
            while (!myFile.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    dis = amount - (amount/100);
                    total = total + dis;
                    cout << "\n\t" << pcode << "\t" << pname << "\t\t" <<  arrq[i] << "\t\t\t" << price << "\t\t\t" << amount << "\t\t\t" << dis << "\n";
            }
                myFile >> pcode >> pname >> price >> dis;
            }
            myFile.close();
        }
        }

        cout << "\n\n____________________________________";
        cout << "\n Total Amount: " << total;
    }

int main() {
    Shopping shopping;
    shopping.menu();
}

