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
string formatting_screen (string ISBN, string author, string title_book, 
                   string enrolled, string required, string prices_book, string usedornot);
string tolower (string value);


struct Transaction {
    string ISBN, author, title_book, usedornot, enrolled , prices_book , required;

    Transaction() {
        ISBN = "";
        author = "";
        title_book = "";
        usedornot = "";
        enrolled = "";
        prices_book = "";
        required = "";
    }

    Transaction(string ISBN, string author, string title_book, string usedornot, string enrolled, 
                string prices_book, string required) {
        this->ISBN = ISBN;
        this->author = author;
        this->title_book = title_book;
        this->usedornot = usedornot;
        this->enrolled = enrolled;
        this->prices_book = prices_book;
        this->required = required;
    }
    Transaction(string newvalue, string variable){
        if(variable == "ISBN"){
            ISBN = newvalue;
        }
        else if(variable == "author"){
            author = newvalue;
        }
        else if(variable == "title_book"){
            title_book = newvalue;
        }
        else if(variable == "usedornot"){
            usedornot = newvalue;
        }
        else if(variable == "enrolled"){
            enrolled = newvalue;
        }
        else if(variable == "prices_book"){
            prices_book = newvalue;
        }
        else if(variable == "required"){
            required = newvalue;
        }
        else{
        }
    }

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
    
    
    string printObject() {
        // loop through the object array and print each instance within the array
        string printingObject = "";
        printingObject += "ISBN\tAuthor\tTitle\tUsed\tEnrolled\tRequired\tOG_price\t\ttotal price\t\tbooks needed\n";
        for (int i = 0; i < tempNum; i++) {
            printingObject += formatting_screen(object[i].ISBN, object[i].author, object[i].title_book, 
                   object[i].enrolled, object[i].required, object[i].prices_book, object[i].usedornot);
            printingObject += "\n";
        }
        return printingObject;
    }

    void sortByCost(int maxlength) {

    Transaction arr;

    for (int i = 0; i < maxlength-1; i++) {
        for (int j = i+1; j < maxlength; j++) {
            if (atof((object[j].prices_book).c_str()) < atof((object[i].prices_book).c_str())) {
                // swap the object[i] and object[j]
                arr = object[i];
                object[i] = object[j];
                object[j] = arr;
            }

        }
    }
    }

    void sortByFinalCost(int maxlength) {

    Transaction arr;

    for (int i = 0; i < maxlength-1; i++) {
        for (int j = i+1; j < maxlength; j++) {
            if ( calculation(atof((object[j].prices_book).c_str()), atoi(object[j].enrolled.c_str()), object[j].required, object[j].usedornot) < 
                    calculation(atof((object[i].prices_book).c_str()), atoi(object[i].enrolled.c_str()), object[i].required, object[i].usedornot) ) {

                // swap the object[i] and object[j]
                arr = object[i];
                object[i] = object[j];
                object[j] = arr;
            }
            //calculation(newprice, newenroll, required, usedornot)
        }

        }
}

    void alphabetSort(int maxlength) {

        Transaction arr;

        for (int i = 0; i < maxlength-1; i++) {
            for (int j = i+1; j < maxlength; j++) {

                // First compare by cost
                if (atof((object[j].prices_book).c_str()) < atof((object[i].prices_book).c_str())) {
                    arr = object[i];
                    object[i] = object[j];
                    object[j] = arr;
                }

                // If cost is the same, compare by name
                if (atof((object[j].prices_book).c_str()) == atof((object[i].prices_book).c_str())) {
                    if (object[j].title_book < object[i].title_book) {
                        arr = object[i];
                        object[i] = object[j];
                        object[j] = arr;
                    }
                }

            }
        }
    }

    void searchByTitle(int maxlength, string title) {
        bool found = false;
        Transaction temparr[25];
        


        // Search for objects with matching book title
        for (int i = 0; i < maxlength; i++) {
            if (object[i].title_book == title) {
                found = true;
                temparr[i] = object[i];
                // Display object information
                cout << endl;
            }
        }

        if (!found) {
            cout << "No transactions found with book title \"" << title << "\".\n";
        }
        else{
            string printingObject = "";
            printingObject += "ISBN\tAuthor\tTitle\tUsed\tEnrolled\tRequired\tOG_price\t\ttotal price\t\tbooks needed\n";
            for (int i = 0; i < maxlength; i++) {
                printingObject += formatting_screen(temparr[i].ISBN, temparr[i].author, temparr[i].title_book, 
                    temparr[i].enrolled, temparr[i].required, temparr[i].prices_book, temparr[i].usedornot);
                printingObject += "\n";
            }
            cout << printingObject << endl;
        }
    }

    void searchByAuthor(int maxlength, string author) {
            bool found = false;
            Transaction temparr[25];
            


            // Search for objects with matching book title
            for (int i = 0; i < maxlength; i++) {
                if (object[i].author == author) {
                    found = true;
                    temparr[i] = object[i];
                    // Display object information
                    cout << endl;
                }
            }

            if (!found) {
                cout << "No transactions found with book title \"" << title << "\".\n";
            }
            else{
                string printingObject = "";
                printingObject += "ISBN\tAuthor\tTitle\tUsed\tEnrolled\tRequired\tOG_price\t\ttotal price\t\tbooks needed\n";
                for (int i = 0; i < maxlength; i++) {
                    printingObject += formatting_screen(temparr[i].ISBN, temparr[i].author, temparr[i].title_book, 
                        temparr[i].enrolled, temparr[i].required, temparr[i].prices_book, temparr[i].usedornot);
                    printingObject += "\n";
                }
                cout << printingObject << endl;
            }
        }


/*
    string printObject() {
    // Set the column width and alignment
    const int col_width = 15;
    const char separator = ' ';
    cout << left << setw(col_width) << setfill(separator) << "ID";
    cout << left << setw(col_width) << setfill(separator) << "ISBN";
    cout << left << setw(col_width) << setfill(separator) << "Author";
    cout << left << setw(col_width) << setfill(separator) << "Title";
    cout << left << setw(col_width) << setfill(separator) << "Used";
    cout << left << setw(col_width) << setfill(separator) << "Enrolled";
    cout << left << setw(col_width) << setfill(separator) << "Required";
    cout << endl;

    // loop through the object array and print each instance within the array
    string printingObject = "";
    for (int i = 0; i < tempNum; i++) {
        //printingObject += left + setw(col_width) + setfill(separator) + to_string(i+1);
        string line = left + setw(col_width) + setfill(separator) + to_string(i+1);
        printingObject += line;

        printingObject += left + setw(col_width) + setfill(separator) + object[i].ISBN;
        printingObject += left + setw(col_width) + setfill(separator) + object[i].author;
        printingObject += left + setw(col_width) + setfill(separator) + object[i].title_book;
        printingObject += left + setw(col_width) + setfill(separator) + object[i].usedornot;
        printingObject += left + setw(col_width) + setfill(separator) + to_string(object[i].enrolled);
        printingObject += left + setw(col_width) + setfill(separator) + object[i].required;
        printingObject += "\n";
    }
    return printingObject;
}
*/

/*
string printObject() {
    // loop through the object array and print each instance within the array
    const int col_width = 10; // set the column width
    const char separator = ' '; // set the separator character

    string printingObject = "";
    printingObject += "ID\tISBN\tAuthor\tTitle\tUsed\tEnrolled\tRequired\n";
    for (int i = 0; i < tempNum; i++) {
        string left = to_string(i+1);
        printingObject = printingObject + left + " " + setprecision(col_width) + setfill(separator) + object[i].ISBN +
                         setprecision(col_width) + setfill(separator) + object[i].author +
                         setprecision(col_width) + setfill(separator) + object[i].title_book +
                         setprecision(col_width) + setfill(separator) + object[i].usedornot +
                         setprecision(col_width) + setfill(separator) + (object[i].enrolled) +
                         setprecision(col_width) + setfill(separator) + (object[i].required) + "\n";
    }

    return printingObject;
}
*/



    void addTransaction(Transaction transaction) {
        if (tempNum < 25) {
            object[tempNum] = transaction;
            tempNum++;
        }
        else {
            cout << "Error: transaction list is already full." << endl;
        }
    }

    void editItem(int arrnum, string variable, string newvalue) 
    {
        if(variable == "1"){
            object[arrnum].ISBN = newvalue;
        }
        else if(variable == "2"){
            object[arrnum].author = newvalue;
        }
        else if(variable == "3"){
            object[arrnum].title_book = newvalue;
        }
        else if(variable == "4"){
            object[arrnum].usedornot = newvalue;
        }
        else if(variable == "5"){
            object[arrnum].enrolled = newvalue;
        }
        else if(variable == "6"){
            object[arrnum].prices_book = newvalue;
        }
        else if(variable == "7"){
            object[arrnum].required = newvalue;
        }
        else{
        }
    }
    



    vector<Transaction> getTransactions() {
      return transactions;
    }
};


void edit(objectHandler* handler);


int main(){

    //title
    objectHandler handler;
    Transaction tran;
    int maxlength = 0;


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
    do {
    cin >> choice;

    switch (choice) {
    case '1': 
    {
        cout << "would you like to make a new purchase? (yes or no)" << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        string temped = "";
        int whileint = 0;
        getline(cin, temped);
        cout << temped << endl;
        while(whileint == 0){
        if (!temped.empty() && temped.at(0) == 'y'){
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


            tran.ISBN = ISBN;
            tran.author = author;
            tran.title_book = title_book;
            tran.usedornot = usedornot;
            tran.enrolled = enrolled;
            tran.prices_book = prices_book;
            tran.required = required;
            //Transaction transaction = Transaction(ISBN, author, title_book, usedornot, enrolled, prices_book, required);
            Transaction transaction(ISBN, author, title_book, usedornot, enrolled, prices_book, required);


            handler.addTransaction(transaction);
            maxlength++;

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
        //timelock++;
        flush();
        main_menu_screen();
        whileint++;
        //this is the first case, the input / output screen
    }
        continue;
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

   case '3': // search, sort, print, and edit
   {
        flush();
        title();
        cout << "\t<<<edit screen>>>\n" << endl;
        const char* arrangement = "press '1' to edit\n"
        "press '2' to print onto a prn file\n"
        "press '3' to sort your transactions\n";
        cout << arrangement << endl; 

        char temp;
        cin >> temp;
        //creates and set the the temp variable to what ever the user inputs

        switch(temp){
        case '1': // edit
        {
            flush();
            title();
            cout << "\t<<<edit screen>>>\n" << endl;
            edit(&handler);            
            
            cout << "press enter to continue back to the main menu"<< endl;
            cin.get();
            flush();
            main_menu_screen();
            continue;
        }
        case '2': // forward to prn
        {
            string theResults = handler.printObject();;
            //theResults += handler.printObject();
            ofstream outfile("result.prn", ios::trunc); // if there isn't a output.prn file it'll create one, if there is one, it'll clear the entire file
            //const char* theResults = handler.printObject();
            outfile << theResults;
            outfile.close(); // closes the file

            cout << "press enter to continue back to the main menu"<< endl;
            cin.get();
            flush();
            main_menu_screen();
            continue;
            
        }
        case '3': // sorting
        {
            cout << "choose your sorting method" <<endl;
            cout << "1 for sorting your original price from least to greatest" <<endl;
            cout << "2 for sorting your final price from least to greatest" <<endl;

            cin >> temp;
            switch (temp)
            {
            case '1': // sort by the inputed price for least to greatest
            {   
                handler.sortByCost(maxlength);
                cout << "press enter to continue back to the main menu"<< endl;
                cin.get();
                flush();
                main_menu_screen();
                continue;            
            }
                
            case '2':{ // sort by the total price from least to greatest

                handler.sortByFinalCost(maxlength);                
                cout << "press enter to continue back to the main menu"<< endl;
                cin.get();
                flush();
                main_menu_screen();
                continue;
            }
            case '3': // sort by alphebetical order
            {
                handler.alphabetSort(maxlength);
                cout << "press enter to continue back to the main menu"<< endl;
                cin.get();
                flush();
                main_menu_screen();
                continue;
            }   
            default:
            {
                cout << "sorry an error has occured, you will be taken back to the menu screen" << endl;
                
                cout << "press enter to continue back to the main menu"<< endl;
                cin.get();
                flush();
                main_menu_screen();
            }
            }
            
        }
        case '4': // searching
        {
            cin >> temp;
            switch (temp){
                case '1': // search for book title
                {
                    string john = "";
                    cout << "enter the title of the book to return all transactions with that book name: " << endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous inputs that may claug the input status allowing the next input to not be skipped
                    std::getline(std::cin, john);
                    handler.searchByTitle(maxlength, john);


                    cout << "press enter to continue back to the main menu"<< endl;
                    cin.get();
                    flush();
                    main_menu_screen();
                    continue;
                }
                case '2': // search for author of the book
                {
                    string john = "";
                    cout << "enter the author of the book to return all transactions with that author's name: " << endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous inputs that may claug the input status allowing the next input to not be skipped
                    std::getline(std::cin, john);
                    handler.searchByAuthor(maxlength, john);


                    cout << "press enter to continue back to the main menu"<< endl;
                    cin.get();
                    flush();
                    main_menu_screen();
                    continue;

                }
            
            default:
            {

            }
            }

        }
        default:
        {
            cout << "sorry an error has occured, you will be taken back to the menu screen" << endl;
            cout << "press enter to continue back to the main menu"<< endl;
            cin.get();
            flush();
            main_menu_screen();
            continue;
        }       
        
        }
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
    cout << "\tenter '1' for the input screen\n\tenter '2' to update the output.prn file\n\tenter '3' to edit and sort\n\tenter '4' to exit\n" << endl;
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

string formatting_screen (string ISBN, string author, string title_book, 
                   string enrolled, string required, string prices_book, string usedornot){
                    double newprice = atof(prices_book.c_str());
                    int newenroll = atoi(enrolled.c_str());

                   //"ID\tISBN\tAuthor\tTitle\tUsed\tEnrolled\tPrice\tRequired\n"

                   string screen = ISBN + "\t\t" + author + "\t\t" + title_book + "\t\t" + usedornot + "\t\t" + enrolled + "\t\t\t" +
                                    required + "\t\t\t" + prices_book + "\t\t\t" + 
                                    to_string(calculation(newprice, newenroll, required, usedornot)) + "\t\t\t" + to_string(amountofbooks(newenroll, required, usedornot));
                    
                    return screen;

                   }

void edit(objectHandler* handler) {
    int itemIndex;
    string newInput;
    string variable;
    //cout << "Enter the item index you would like to edit: ";

    //int arrnum, string variable, string newValue)
    //     position of the array, variable being changed, new value for that element within the array

    int ting = 0;
    while(ting <= 0) {
        cout << "between 1-25, please select what transaction you want to change" << endl;
        string userChoice;
        cin >> userChoice;
        if(isdigit(userChoice[0]) && (userChoice[0] - '0') < 26 && (userChoice[0] - '0') > 0){
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
            cin >> variable;

            cout << "\nnow type what you want to change the value to" <<endl;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newInput);

            //handler.editItem(atoi(userChoice.c_str())-1, variable, newInput);
            handler->editItem(atoi(userChoice.c_str())-1, variable, newInput);
            ting++;

        }
        else
        {
            cout << "please note that the first character in the word / number will be put" <<endl;
            cout << "the algorithm to check which transaction is being changed" <<endl;
        }

    }

    //cin.ignore();
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




 // future code, incase something goes wrong
/*

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
