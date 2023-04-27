#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <ostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

void title_screen();
void error_screen();
string whileloop (string value);
void title();
double calculation(double price, int enrollment, string required, string book);
int amountofbooks (int enrolled, string required, string book);
void exit_screen();
bool letterCheck (std::string value);
void main_menu_screen();
void flush();
void userChoice();
string output_screen(string ISBN, string author, string title_book, 
                   string enrolled, string required, string prices_book, string usedornot);
string tolower (string value);


struct Transaction {
    string ISBN, author, title_book, usedornot, enrolled , prices_book , required;
    // declaring variables for future use
};

class objectHandler {
private:
    Transaction object [25];
    int tempNum;
    vector<Transaction> transactions;

public:
    objectHandler() {
        tempNum = 0;
    }
    /*
    void addTransaction(string ISBN, string author, string title_book, string usedornot, string enrolled, string prices_book, string required) {

        if (tempNum < 25) {
            // prompt user to enter transaction data
            // and store it in the next available index of the array
            cout << "Enter ISBN: "<< endl;
            cin >> object[tempNum].ISBN;

            cout << "Enter title_book: "<< endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, object[tempNum].title_book);

            cout << "Enter author: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous inputs that may claug the input status allowing the next input to not be skipped
            std::getline(std::cin, object[tempNum].author);


            cout << "Enter usedornot: "<< endl;
            cin >> object[tempNum].usedornot;

            cout << "Enter enrolled: " << endl;
            cin >> object[tempNum].enrolled;

            cout << "Enter prices_book: "<< endl;
            cin >> object[tempNum].prices_book;

            cout << "Enter required: "<< endl;
            cin >> object[tempNum].required;

            tempNum++;
        } 
        else {
            cout << "the maximum number of transactions has been reached." << endl;
        }
    }
    */

    void printObject() {
        // loop through the object array and print each instance within the array
        cout << "ID\tISBN\tAuthor\tTitle\tUsed\tEnrolled\tPrice\tRequired" << endl;
        for (int i = 0; i < tempNum; i++) {
            cout << output_screen(object[i].ISBN, object[i].author, object[i].title_book, 
                   object[i].enrolled, object[i].required, object[i].prices_book, object[i].usedornot);
        }
    }
    void addTransaction(Transaction transaction) {
      transactions.push_back(transaction);
    }

    vector<Transaction> getTransactions() {
      return transactions;
    }


    //void TransactionList::addTransaction(Transaction transaction) {transactions.push_back(transaction);}

    /*
    void createNewTransaction(int& arrnum) {
    if (tempNum < 25) { // check if array is full
        // prompt user for input of transaction values
            std::string ISBN = "no value";
            std::string author = "no value", title_book = "no value", usedornot = "no value";
            std::string enrolled = "no value", prices_book = "no value", required = "no value";

            flush();                // supposed to help clear the terminal screen 
            title();
            cout <<"\t<<<input screen>>>"<<endl;
            cout << "\n";
            
            userChoice();
            cout << "enter the ISBN (barcode) :   " << endl;
            cin >> ISBN;
            cout << "\n";

            userChoice();
            cout << "enter the title of the book \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous inputs that may claug the input status allowing the next input to not be skipped
            std::getline(std::cin, title_book);
            cout << "\n";

            userChoice();
            cout << "enter the authors name " << endl;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::getline(std::cin, author);
            cout << "\n";
            
            userChoice();
            cout << "enter the number of students in your class " << endl;
            cin >> enrolled;
            enrolled = whileloop(enrolled);                            //these while loop makes sure the input is greater than 0
            cout << "\n";

            userChoice();
            cout << "enter the prices of the book " << endl;
            cin >> prices_book;
            prices_book = whileloop(prices_book);                     //checks if the number is greater than 0
            cout << "\n";

            userChoice();
            cout << "enter 'new' if you want to book to be new, otherwise type something else " << endl;
            cin >> usedornot;
            cout << "\n";

            userChoice();
            cout << "enter 'required' if the book is required, otherwise type something else " << endl;
            cin >> required;
            cout << "\n";
        // call addTransaction function to add new transaction to array
        addTransaction(ISBN, author, title_book, usedornot, enrolled, prices_book, required);
        arrnum++;
        cout << "Transaction added successfully." << endl;
    } 
    else {
        cout << "sorry the storage to store your transaction is currently full." << endl;
    }
}
*/
};



int main(){

    //title
    flush();   //if your not using VS code, pls use this code
    string ISBN = "no value";
    std::string author = "no value", title_book = "no value", usedornot = "no value";
    string enrolled = "no value", prices_book = "no value", required = "no value";
    int timelock = 0;
    title_screen();
    cout << "\n\n\n ";
    cin.get();


//-----------------------------------------------------------------------------------------------------------------
    //input
    flush();   //if your not using VS code, pls use this code
    main_menu_screen();
    char choice;
    int arrnum = 0;
    do {
    cin >> choice;

    switch (choice) {
    case '1': 
    {
        cout << "would you like to make a new purchase? (yes or no)" << endl;
        string temped;
        int whileint =0;
        getline(cin, temped);
        while(whileint == 0){
        if (temped.at(0) == 'y'){
            //handler.addNewTransaction(ISBN, title_book, author, enrolled, prices_book, required, usedornot, arrnum);
            while(timelock <= 0) {
            //cout << "\x1b[2J";
            flush();                // supposed to help clear the terminal screen 
            title();
            cout <<"\t<<<input screen>>>"<<endl;
            cout << "\n";
            
            userChoice();
            cout << "enter the ISBN (barcode) :   " << endl;
            cin >> ISBN;
            if (tolower(ISBN) == "quit"){
                break;
            }       // this if statement, and other like-if statements just help make sure if the input isn't quit
                    // if input is quit, then it terminates the program
            cout << "\n";

            userChoice();
            cout << "enter the title of the book \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous inputs that may claug the input status allowing the next input to not be skipped
            std::getline(std::cin, title_book);
            if (tolower(title_book) == "quit"){
                break;
            }
            cout << "\n";

            userChoice();
            cout << "enter the authors name " << endl;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::getline(std::cin, author);
            if (tolower(author) == "quit"){
                break;
            }
            cout << "\n";
            
            userChoice();
            cout << "enter the number of students in your class " << endl;
            cin >> enrolled;
            enrolled = whileloop(enrolled);                            //these while loop makes sure the input is greater than 0
            if (tolower(enrolled) == "quit"){
                break;
            }
            cout << "\n";

            userChoice();
            cout << "enter the prices of the book " << endl;
            cin >> prices_book;
            prices_book = whileloop(prices_book);                     //checks if the number is greater than 0
            if (tolower(prices_book) == "quit"){
                break;
            }
            cout << "\n";

            userChoice();
            cout << "enter 'new' if you want to book to be new, otherwise type something else " << endl;
            cin >> usedornot;
            if (tolower(usedornot) == "quit"){
                break;
            }
            cout << "\n";

            userChoice();
            cout << "enter 'required' if the book is required, otherwise type something else " << endl;
            cin >> required;
            if (tolower(required) == "quit"){
                break;
            }
            cout << "\n";

            objectHandler handler;

            Transaction tran;
            tran.ISBN = ISBN;
            tran.author = author;
            tran.title_book = title_book;
            tran.usedornot = usedornot;
            tran.enrolled = enrolled;
            tran.prices_book = prices_book;
            tran.required = required;
            //transactions[arrnum] = tran;
            Transaction transaction = Transaction(ISBN, author, title_book, usedornot, enrolled, prices_book, required);
            
            handler.addTransaction(transaction);
            //handler.addObject(transaction);

            vector<Transaction> transactions = handler.getTransactions();
            for (int i = 0; i < transactions.size(); i++) {
                cout << "Transaction " << i + 1 << ":" << endl;
                cout << "ISBN: " << transactions[i].ISBN << endl;
                cout << "Author: " << transactions[i].author << endl;
                cout << "Title: " << transactions[i].title_book << endl;
                cout << "Used: " << transactions[i].usedornot << endl;
                cout << "Enrolled: " << transactions[i].enrolled << endl;
                cout << "Price: " << transactions[i].prices_book << endl;
                cout << "Required: " << transactions[i].required << endl;
    }



            break;
            }
        }
        else if (temped.at(0) == 'n') {
            break;
        }
        else {
            cout << "sorry the input caused an error, please try again" <<endl;
        }
        cout << "please press 'ENTER' to continue";
        cin.get();  
        timelock++;
        flush();
        main_menu_screen();
        continue;
        //this is the first case, the input / output screen
    }
    }

    case '2': //output stuff
    {
    //ofstream outfile("output.prn", ios::app); note this is to add to the file.
    //-----------------------------------------------------------------------------------------------------------------
    flush();  
    title();
    cout << "\t<<<output screen>>>\n" << endl;
    cout << "this is your output currently\n" <<endl;
    cout << output_screen(ISBN, author, title_book, enrolled, required, prices_book, usedornot) <<endl;
    cout << "\n\n would you like to print it out onto a file called output.prn?" << endl;
    cout << "say 'yes' to print,  otherwise you'll be taken back to the main menu" << endl;
    // just shows the user the output and ask if this output is good

    string toprint;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, toprint);  
    //initiates, clears previous inputs, then set the toprint variable to the userinput  

    if (tolower(toprint) == "yes") {
    ofstream outfile("output.prn", ios::trunc); // if there isn't a output.prn file it'll create one, if there is one, it'll clear the entire file
    outfile << output_screen(ISBN, author, title_book, enrolled, required, prices_book, usedornot); //paste this onto the new file
    outfile.close(); // closes the file
    flush();
    cout << "file was successfully updated" << endl;
    }
    // the if statement will check if the user typed yes
    // if true, then the code will clear the prn file for any previous inputs, then prints out the output to the output.prn file
    cout << "press enter to continue back to the main menu"<< endl;
    cin.get();
    flush();
    main_menu_screen();
    continue;
}
    case '3': //edit screen
    {
        flush();
        title();
        cout << "\t<<<edit screen>>>\n" << endl;
        cout << "what would you like to edit:\n" <<endl;
        const char* listofchange = 
        "'1' for chaging ISBN/barcode\n"
        "'2' for changing title of the book\n"
        "'3' for changing the authors name\n"
        "'4' for changing number of students\n"
        "'5' for changing the price of the book\n"
        "'6' is to let us know if you want a new or used book\n"
        "'7' is to let us know if the book is required\n"
        "and 'q' is to exit this screen";
        cout << listofchange <<endl;
        //tells the user the options they have

        char temp;
        cin >> temp;
        //creates and set the the temp variable to what ever the user inputs

        switch(temp){
            case '1':
            {
                cout << "enter the ISBN (barcode) :   " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, ISBN);
                break;
            }
            case '2':
            {
                cout << "enter the title of the book \n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, title_book);
                break;
                
            }
            case '3':
            {
                cout << "enter the authors name " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, author);    
                break;       
            }
            case '4':
            {
                cout << "enter the number of students in your class " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, enrolled);
                break;
                
            }
            case '5':
            {
                cout << "enter the prices of the book " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, prices_book);  
                break;         
                
            }
            case '6':
            {
                cout << "enter 'new' if you want to book to be new, otherwise type something else " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, usedornot);
                break;
                
            }
            case '7':
            {
                cout << "enter 'required' if the book is required, otherwise type something else " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, required);
                break;
            }
            case 'q':
            {
                break;
            }
            default:
            {
                cout << "sorry the input you entered was not recognized, please enter a number 1-6 to edit or 'q' to quit";
                cout << "you will now be taken back to the main menu" <<endl;
            }
        }
        // grabs a specific variable that the user wants to change, then sets that variable to the new input the user typed in

        flush();
        main_menu_screen();
        continue;
    }

    case '4': //exit screen
    {
        exit_screen();
        timelock++;
        break;
        //the 4th case brings the user to the exit screen and terminates the code
    }

    default:
    {
        cout << "sorry the input you entered was invalid please try again\neither '1', '2', '3', or '4' " <<endl;
        //tells the user that the input was invalid then brings them back to the main menu
    }
    }
    }
    while (timelock <= 0);
    // this is the default case, if they dont put in i or e then it go into the default error screen
    // once here the do-while statement will keep asking the user to input a value that matches i or e

    return 0;

}

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
    //output stuff

void title_screen() {
    const char* stuff= "                                            TITLE SCREEN                    \n"
                          "                        ***** < Miramar College Book Ordering System > *****   \n"
                          "                                       3/3/2023 Aaron Goff             \n"
                          "                                please press 'ENTER' to continue";
    cout<<stuff;
}  // just initializing a title and then printing it out

void exit_screen(){
    //cout << "\x1b[2J"; //clearing terminal for VS code
    flush();
    cout<< "\t\t\t";
    title();
    cout << "\t\t\t\t   <<<exit screen>>>"<<endl;
    cout<<"              thank you for your purchase and have a great rest of your day\n\n\n";
} //clears the terminal then prints out a statement

void title(){
    const char* titlescreen = "< Miramar College Book Ordering System >";
    cout << titlescreen <<endl;
}  //initializes a variable to then be printed out

void error_screen(){
    //cout << "\x1b[2J"; //clearing terminal for VS code
    flush();   //if your not using VS code, pls use this code
    title();
    cout << "\nsorry that is an invalid number, please type a number greater than 0\n\n";

} // an error screen that 

void main_menu_screen(){
    cout << "\t\t\t<<<Main Menu>>>" <<endl;
    cout << "\tenter '1' for the input screen\n\tenter '2' to update the output.prn file\n\tenter '3' to change a variable\n\tenter '4' to exit\n" << endl;
}

string output_screen(string ISBN, string author, string title_book, 
                   string enrolled, string required, string prices_book, string usedornot){
    double newprice = atof(prices_book.c_str());
    int newenroll = atoi(enrolled.c_str());

    stringstream outputToFile;
    outputToFile << "\t\t\t" << endl;
    outputToFile << "-----------------YOUR INPUTS-------------" <<endl;
    outputToFile << "barcode : " << ISBN << endl;
    outputToFile << "author : " << author << endl;
    outputToFile << "title : " << title_book << endl;
    outputToFile << "# of students : " << enrolled << endl;
    outputToFile << "is or is not required : " << required << endl;
    outputToFile << "-----------------------------------------" <<endl;

    outputToFile << "the price is $" << fixed << setprecision(2) << calculation(newprice, newenroll, required, usedornot);
    outputToFile << "\nthe number of books needed is : " << amountofbooks(newenroll, required, usedornot);
    
    return outputToFile.str();
}

// takes some of the inputs converts them into ints and doubles, then takes some inputs to the calculation and amountofbooks methods for a number value
// all of this will be added to a stream string variable then once its finished adding to the stream it returns the stream string value

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
    //calculations and conversions stuff


int amountofbooks (int enrolled, string required, string book){
    double numBooks = enrolled;
    double factored = 1;
    if(book == "new"){
        if(required == "required"){
         factored = 1.0;   // Book is new and required
        }
        else{
         factored = 0.35;  // Book is new but not required
        }
    }
    else {
        if(required == "required"){
            factored = 0.6;  // Book is not new but is required
        }
        else  {
            factored = 0.1;  // Book is not new and is not required
        }
    }
    numBooks= enrolled * factored;
    return numBooks;
} //determines the amount of books depending on the inputed values

double calculation(double price, int enrollment, string required, string book) {
    double numBooks;
    double factored = 1;
    if (book == "new") {
        if (required == "required") {
            factored = 1.0;   // Book is new and required
        }
        else {
            factored = 0.35;  // Book is new but not required
        }
    }
    else {
        if (required == "required") {
            factored = 0.6;  // Book is not new but is required
        }
        else {
            factored = 0.1;  // Book is not new and is not required
        }
    }
    numBooks = enrollment * factored;
    double cost = numBooks * price;
    return cost;
}
// determines the price depending on the enrollment number, if its required, and if new or not


string whileloop (string value){
    if (std::atof(value.c_str()) <= 0 || letterCheck(value)){
        while ((std::atof(value.c_str()) <= 0) || tolower(value) == "quit") {
            if (tolower(value) == "quit"){
                break;
            }
        error_screen();
        cin >> value;
        }
    }
    return value;
}
// this while loop will check for the value to be greater than 0, if not shows the error screen and ask for another input value

bool letterCheck (std::string value) {
    if (!value.empty() && std::isalpha(value[0])) {
        return true;
    }
    else {
        return false;
    }
}

// the .empty will check if the first character is empty as in if it contains a space, and the isalpha will check if the 
// first charcter is a letter or not

void userChoice (){
    cout << "enter 'QUIT' in any format to stop the code to take you back to the main menu" << endl;
}
// tells the user if they wanna quit to terminate the code they can

string tolower (string value){
    std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c){ 
        return std::tolower(c); 
        });
    return value;
}
//turns the inputed string into all lowercase

void flush (){
    cout << "\t\t\t\t resetting screen please wait \t\t\t\t\n\n\n\n\n\n\n\n\n" <<endl;
}
// a command that is supposed to help clear the terminal

/*
void arraytime(){
    cout << "enter 25 words or numbers to be arranged"<<endl;
    for (int i = 0; i < universalstring.length(); i++ ){
        cout << "string number " << i+1 << " : "<< endl;
        getline(cin, universalstring[i]);
    }
}

void printarray(string arr[]){
    int size = std::sizeof[arr];
    for (int i=0; i < size; i++){
        cout << arr[i] << " ";
    }
}
*/

/*
string output_screen(string ISBN, string author, string title_book, 
                   string enrolled, string required, string prices_book, string usedornot){
    double newprice = atof(prices_book.c_str());
    int newenroll = atoi(enrolled.c_str());

    string priceSTR = "$" + to_string(calculation(newprice, newenroll, required, usedornot));
    size_t pos = priceSTR.find('.') + 3;
    if (pos > priceSTR.size()) {
        pos = priceSTR.size();
    }
    priceSTR = priceSTR.substr(0, pos);

    string outputToFile = "";
    outputToFile += "\t\t\t\n";
    outputToFile += "-----------------YOUR INPUTS-------------\n";
    outputToFile += "barcode : " + ISBN + "\n";
    outputToFile += "author : " + author + "\n";
    outputToFile += "title : " + title_book + "\n";
    outputToFile += "# of students : " + enrolled + "\n";
    outputToFile += "is or is not required : " + required + "\n";
    outputToFile += "-----------------------------------------\n";

    outputToFile += "the price is " + priceSTR;
    outputToFile += "\nthe number of books needed is : " + to_string(amountofbooks(newenroll, required, usedornot));
    
    return outputToFile;
}
*/
