#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool authenticate(int& x)
{
	bool registered = false;
	// File pointer
    fstream fin;
  
    // Open an existing file
    fin.open("voters.csv", ios::in);
  
    // Get the roll number
    // of which the data is required
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word;
    int id, count = 0;
  
    while (!fin.eof()) {
  
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
  
        // used for breaking words
        stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
  
        // convert string to integer for comparision
        while (!fin.eof()) {
            id = stoi(row[0]);
        // Compare the roll number
		    if (id == x) {
		    	count == 1;
		    	registered = true;
                cout << "Error: This CNIC is already registered" << endl;
                cout << "Please enter your CNIC again:\n";
                cin >> x;
            }
            if (id != x){
            	registered = false;
            	break;
			}
		}
        
    }
    //cout << count;

    fin.close();
    return registered;
}

void voter(int idm, string name)
{
	fstream fout;
	fout.open("voters.csv", ios::out|ios::app);
	fout << idm << "," << name << endl;
	fout.close();
}

int main()
{
    // file pointer
    fstream fout;
    char op;
  
    string name;
    int i = 0, idm;
    bool registered = false;
    
	// exception handling to check if voters.csv file exists or not
	try{
		if(!fout){
			throw "404! File voters.csv not found";
		}
	}
	catch(const char* er){
		cerr << er << endl;
	}
    
    while(true){
    	cout << "\t ****************************** \t\n" 
		<< "\t   Voter Registration System \t\n"  
		<< "\t ****************************** \t\n";
    	cout << "Please enter your details"
         << " (CNIC Name):" << endl;
  
        cin >> idm >> name;
        
        registered = authenticate(idm); //returns boolean value on registration status
        
        // Insert the data to file and add newly registered id to voters list 
        if (registered == false){
            voter(idm, name); 
        }    

        cout << "Register another person(y/n)\n";
        cin >> op;
        if (op == 'n' || op == 'N'){
        	break;
		}
    }
}

