#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;


bool voter(int& x)
{
    // File pointer
    fstream fin;
    
    bool registered = true;
  
    // Open an existing file
    fin.open("voters.csv", ios::in);
  
    // Get the id of which the data is required
    int id, count = 0;

    // Read the Data from the file as String Vector
    vector<string> row;
    string line, word;
  
    while (!fin.eof()) {
  
        row.clear();
        // read an entire row and store it in a string variable 'line'
        getline(fin, line);
  
        // used for breaking words
        stringstream s(line);
  
        // read every column data of a row and store it in a string variable, 'word'
        while (getline(s, word, ',')) {
            // add all the column data of a row to a vector
            row.push_back(word);
        }
  
        // convert string to integer for comparision
        id = stoi(row[0]);
        // Compare the roll number
        if (id == x) {
  
            // Print the found data
            count = 1;
            cout << "Welcome: " << row[1] << endl;
            cout << endl;
            registered = true;
            
            break;
        }
    }
    if (count == 0){
    	registered = false;
        cout << "Error: CNIC is not registered.\n";
        
    }
        
    fin.close();
    return registered;
}

bool vote_status(int& x){
	bool voted = false;
	fstream fin;
	int count = 0, id;
	vector<string> row;
	string line, word;
	fin.open("voted.csv", ios::in);
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
        //while (!fin.eof()) {
            id = stoi(row[0]);
        // Compare the roll number
		    if (id == x) {
		    	voted = true;
		    	count = 1;
		    	//count = 1;
                cout << "You have already casted a vote" << endl;
                break;
            }
        if (count == 0){
    	    voted = false;
        
        }
    }
    fin.close();
    return voted;
}

void record_vote_n(string selectparty, int tvotes)
{
	// File pointer
    fstream fin, fout;
  
    // Open an existing record
    fin.open("na_results.csv", ios::in);
  
    // Create a new file to store updated data
    fout.open("na_resultsnew.csv", ios::out);
  
    int found = 0, i, votes=0;
    char sub;
    int index, new_marks;
    string line, word, party;
    vector<string> row;
  
    // Traverse the file
    while (!fin.eof()) {
  
        row.clear();
  
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        party = row[0];
        int row_size = row.size();

        if (party == selectparty) {
            found = 1;
            stringstream convert;
  
            // sending a number as a stream into output string and adding new votes
            votes += tvotes + stoi(row[1]);
            convert << votes;
  
            // the str() converts number into string
            row[1] = convert.str();
  
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'resultsnew.csv'
                    // using fout
                    fout << row[i] << ",";
                }
  
                fout << row[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ",";
                }
  
                // the last column data ends with a '\n'
                fout << row[row_size - 1] << endl;
            }
        }
        if (fin.eof())
            break;
    }
    if (found == 0)
        cout << "error" << endl;
  
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("na_results.csv");
    // renaming the updated file with the existing file name
    rename("na_resultsnew.csv", "na_results.csv");
}

void record_vote_p(string selectparty, int tvotes)
{
	    // File pointer
    fstream fin, fout;
  
    // Open an existing record
    fin.open("pa_results.csv", ios::in);
  
    // Create a new file to store updated data
    fout.open("pa_resultsnew.csv", ios::out);
  
    int found = 0, i, votes=0;
    char sub;
    int index, new_marks;
    string line, word, party;
    vector<string> row;
  
    // Traverse the file
    while (!fin.eof()) {
  
        row.clear();
  
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
  
        party = row[0];
        int row_size = row.size();

        if (party == selectparty) {
            found = 1;
            stringstream convert;
  
            // sending a number as a stream into output string and adding new votes
            votes += tvotes + stoi(row[1]);
            convert << votes;
  
            // the str() converts number into string
            row[1] = convert.str();
  
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // write the updated data
                    // into a new file 'resultsnew.csv'
                    // using fout
                    fout << row[i] << ",";
                }
  
                fout << row[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
  
                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ",";
                }
  
                // the last column data ends with a '\n'
                fout << row[row_size - 1] << endl;
            }
        }
        if (fin.eof())
            break;
    }
    if (found == 0)
        cout << "error" << endl;
  
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("pa_results.csv");
    // renaming the updated file with the existing file name
    rename("pa_resultsnew.csv", "pa_results.csv");
}

void na_displayresults()
{
	// File pointer
    fstream fin;
  
    // Open an existing file
    fin.open("na_results.csv", ios::in);
  
    int count = 0;
 
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word;
    
    cout << "\t ****************************** \t\n" 
	<< "\t   NA Election Results \t\n"  
	<< "\t ****************************** \t\n";
  
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
        cout << row[0] << ": ";
        cout << row[1] << endl;
    }
    fin.close();
}

void pa_displayresults()
{
	    // File pointer
    fstream fin;
  
    // Open an existing file
    fin.open("pa_results.csv", ios::in);
  
    // Get the roll number
    // of which the data is required
    int count = 0;
 
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word;
    
    cout << "\t ****************************** \t\n" 
	<< "\t   PA Election Results \t\n"  
	<< "\t ****************************** \t\n";
    
    //Nauman Method
    /*while(fin){
    	//getline(fin, line);
    	size++;
	}
	fin.close();
	
	fin.open("presults.csv", ios::in);*/

	while(!fin.eof()) {
        row.clear();
        getline(fin, line);
  
        // read an entire row and
        // store it in a string variable 'line'
        //getline(fin, line);
  
        // used for breaking words
        stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
        cout << row[0] << ": ";
        cout << row[1] << endl;
    }
    fin.close();
}

int main()
{
    int id;
    bool voted, registered;
    char op, partyselect, admin;
    string party, adminpw;
    int partyvote[4] = {0};
    int pvote[4] = {0};
    
    // file pointer
    fstream foutn;
    fstream foutp;
  
    // opens an existing csv file or creates a new file.
    foutn.open("voted.csv", ios::out|ios::app);
    
    cout << "\t ****************************** \t\n" 
	<< "\t   E-Voting System \t\n"  
	<< "\t ****************************** \t\n";

    while(true){
    	cout << "Enter your CNIC: ";
    	cin >> id;
        cout << endl;
        
        registered = voter(id);
        voted = vote_status(id);
        
        if(voted == false && registered == true){
        	cout << "\t ****************************** \t\n" 
		    << "\t   Please cast your vote for NA \t\n"  
		    << "\t ****************************** \t\n";
            cout << "\na.PTI\n" << "b.PML(N)\n" << "c.PPP\n" << "d.MMA\n" << "e.TLP\n" << "f.Independent" << endl;  
            cin >> partyselect;
            if(partyselect == 'a'){
        	    party = "PTI";
        	    partyvote[0]++;
        	    record_vote_n(party, partyvote[0]);
		    }
		    else if (partyselect == 'b')
		    {
		        party = "PMLN";
		        partyvote[1]++;
		        record_vote_n(party, partyvote[1]);
			}
		    else if (partyselect == 'c')
		    {
		    	party = "PPP";
		    	partyvote[2]++;
		    	record_vote_n(party, partyvote[2]);
			}
			else if (partyselect == 'd'){
				party = "MMA";
				partyvote[3]++;
				record_vote_n(party, partyvote[3]);
			}
			else if (partyselect == 'e')
			{
				party = "TLP";
				partyvote[4]++;
				record_vote_n(party, partyvote[4]);
			}
			else if (partyselect == 'f'){
				party = "Indie";
				partyvote[5]++;
				record_vote_n(party, partyvote[5]);
			}
			else{
				cout << "invalid input\n";
			}
			foutn << id << endl;
			cout << "Voted successfully.\n";
			    
	        cout << "\t ****************************** \t\n" 
		    << "\t   Please cast your vote for PA \t\n"  
		    << "\t ****************************** \t\n";
            cout << "\na.PTI\n" << "b.PML(N)\n" << "c.PPP\n" << "d.MMA\n" << "e.TLP\n" << "f.Independent" << endl;  
            cin >> partyselect;
            if(partyselect == 'a'){
        	    party = "PTI";
        	    pvote[0]++;
        	    record_vote_p(party, pvote[0]);
		    }
		    else if (partyselect == 'b')
		    {
		        party = "PMLN";
		        pvote[1]++;
		        record_vote_p(party, pvote[1]);
			
		    }
		    else if (partyselect == 'c')
		    {
		    	party = "PPP";
		    	pvote[2]++;
		    	record_vote_p(party, pvote[2]);
			}
			else if (partyselect == 'd'){
				party = "MMA";
				pvote[3]++;
				record_vote_p(party, pvote[3]);
			}
			else if (partyselect == 'e')
			{
				party = "TLP";
				pvote[4]++;
				record_vote_p(party, pvote[4]);
			}
			else if (partyselect == 'f'){
			    party = "Indie";
				pvote[5]++;
				record_vote_p(party, pvote[5]);
			}
			else{
				cout << "invalid input\n";
			}
			foutp << id << endl;
			cout << "Voted successfully.\n";
	    }
	    
        cout << "\nProceed to other voter.(Y/N)\n";
        cin >> op;
        if(op == 'n' || op == 'N'){
        	cout << "Do you want to end the election and display election results.(Y/N)\n";
	        cin >> admin;
	        if(admin == 'Y' || admin == 'y'){
		    cout << "Please enter the admin. password to gain administrative access.\n";
		    cin >> adminpw;
		        if(adminpw == "1234e")
		        {
			        na_displayresults();
			        pa_displayresults();
		        }
		        else{
		            cout << "Wrong Password\n";
	            }
	        }
        	break;
		}
	}


	foutn.close();
	foutp.close();

	return 0;
}
