#include "functions.h"

void changingFile(string username, string list, string task ,string currentB , string desireB)
{
    ifstream accountsInformation("Accounts.txt");
    vector<string> lines;
    string line;

    if (accountsInformation.is_open()) {
        while (getline(accountsInformation, line)) {
            lines.push_back(line);
        }
        accountsInformation.close();
    }

    else
        cerr <<  "Cannot open the file" << endl;


    for (string & line : lines) {
        istringstream x(line);
        string fKind , fUsernaem , fList , fTask;
        getline(x, fKind , ',');
        if(fKind == "T"){
            getline(x , fUsernaem , ',');
            getline(x , fList , ',');
            getline(x , fTask , ',');
            if (fUsernaem == username && fList == list && fTask == task){
                size_t position = line.find(currentB);
                if (position != string::npos) {
                    line.replace(position , 3 , desireB);
                    break;
                }
            }
        }
    }

    ofstream accountsInformation2("Accounts.txt");
    if (accountsInformation2.is_open()) {
        for (string & line : lines) {
            accountsInformation2 << line << endl;
        }
        accountsInformation2.close();
    }

    else
        cerr << "Cannot open the file" << endl;

}
