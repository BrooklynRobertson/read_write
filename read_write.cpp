// read_write.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void Create() {
    std::fstream fileOut;

    fileOut.open("grades.csv", std::ios::out | std::ios::app);
    if (!fileOut) {
        std::cout << "\n no grades file found......\n";
        return;
    }
    std::cout << "Please enter details of 5 students: " << " roll number(int) name(string) maths(int) phys(int) chem(int) bio(int)";
    int i, rollNum, phys, chem, math, bio;
    std::string name;
    for (int i = 0; i < 5; i++) {
        std::cout << "please enter details of student " << i + 1 << "\n\n";
        std::cin >> rollNum
            >> name
            >> math
            >> phys
            >> chem
            >> bio;

        fileOut << rollNum << ","
            << name << ","
            << math << ","
            << phys << ","
            << chem << ","
            << bio 
            << "\n";
    }
}

std::vector<std::vector<std::string>> Read() {
    //creating the variables for reading
    std::fstream fileIn;
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    int rowNum;
    //assigning file to read and flag to fileIn
    fileIn.open("grades.csv", std::ios::in);

    //determining if file is open
    if (fileIn.is_open()) {
        //while content is in fileIn to line, loop
        while (std::getline(fileIn, line)) {
            row.clear();//deleting current content from string

            //converts file data to string format

            std::stringstream str(line);

            //while content in str, copy to work and stop at each comma
            while (getline(str, word, ',')) {
                row.push_back(word);
            }//appending the content of var word into row

            content.push_back(row);//appending the row content into content variable
        }
         
    }
    else {
        std::cout << "No file found......\n";
    }


    std::cout << "Please input the roll number for the student you wish to view: ";
    std::cin >> rowNum;
    for (int i = 0; i < 5; i++) {
        std::cout << content[rowNum-1][i] << "\t";
    }
    std::cout << "\n\n";
    return content;
}

void Edit(std::vector<std::vector<std::string>> content) {
    //creating the variables for editing
    std::fstream fileEdit;
    
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    int rowNum;
    int input;
    //assigning file to read and flag to fileEdit
    fileEdit.open("grades.csv", std::ios::in | std::ios::out);

    //determining if file is open
    if (fileEdit.is_open()) {

        std::cout << "Which student would you like to edit? (answer with roll number)";
        std::cin >> rowNum;
        std::cout << "Currently viewing... \n\n";
        for (int i = 0; i < content.size(); i++) {
            std::cout << content[rowNum - 1][i] << "\t";
        }
        std::cout << "\n\n"; 
        std::cout << "which cell would you like to edit? \n" <<
                "Options: 1.Name\t2.math\t3.physics\t4.chem\t5.bio (answer with int)\n";
        std::cin >> input;



        ////while content is in fileEdit to line, loop
        //while (std::getline(fileEdit, line)) {


        //    //ask what to edit
        //    
        //    //switchcase
        //    switch (input) {

        //    case 1:
        //        std:: 
        //        break;
        //        /*  case 2:
        //              break;
        //          case 3:
        //              break;
        //          case 4:
        //              break;
        //          case 5:
        //              break;*/



        //    }

        //    //in switch, insert before specified value, delete value after?

        ////ask if anymore to edit


        //}

    }
    else {
        std::cout << "No file found......\n";
    }

}

int main()
{
    int input;
    std::cout << "please select your operation:\n1. \tCreate/Write\n2. \tRead\n3. \tEdit\n";
    std::cin >> input;
    switch (input) {
    case 1:
        Create(); // runs the create function above that produces a new .txt file at root, where the .cpp file is
        break;
    case 2:
        Read();
        break;
    case 3: 
        Edit();
        break;
    }

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
