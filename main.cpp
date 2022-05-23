#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;


int main() {

    map <string, int> studentGradeMap;

    //collect numQueries
    int numQueries = 0;
    cin >> numQueries;

    if (numQueries > 0 & numQueries <= 1e5) {
        for (int i = 0; i < numQueries; i++) {

            //Parse each part of string into separate variables
            string input = "";
            //cin.ignore(256, '\n');
            getline(cin >> ws, input);
            stringstream ss (input);
            string stype = "";
            string name = "";
            string sgrade = "";

            ss >> stype >> name >> sgrade;
            if (stype == "") {
                stype = "0";
            }
            if (sgrade == ""){
                sgrade = "0";
            }
            int queryType = stoi(stype);
            int grade = stoi(sgrade);


            if (queryType > 0 && queryType <= 3) {
                map <string, int>::iterator itr;

                // Insert a Student Name AND a Grade
                if (queryType == 1) {

                    //Check to see if the student exists
                    itr = studentGradeMap.find(name);

                    //If the student does not exist, add the name and grade.
                    if (itr == studentGradeMap.end()) {
                        int nameLength = name.length();
                        if (nameLength > 0 && nameLength <= 6 && grade > 0 && grade <= 1e3) {
                            studentGradeMap.insert(make_pair(name, grade));
                        }
                    }
                    //If the student does exist, look for a previous grade, and add the new grade to the total.
                    else if (itr != studentGradeMap.end()) {
                        if (grade > 0 && grade <= 1e3) {
                            int oldGrade = itr->second;
                            int newGrade = oldGrade + grade;
                            itr->second = newGrade;
                        }
                    }
                }
                //Erase the grades of the student
                else if (queryType == 2) {
                    itr = studentGradeMap.find(name);
                    if (itr != studentGradeMap.end()) {
                        itr->second = 0;
                    }
                }
                //Print the grade of the student
                else {
                    itr = studentGradeMap.find(name);
                    if (itr != studentGradeMap.end()) {
                        cout << itr->second << endl;
                    }
                    else {
                        cout << "0" << endl;
                    }
                }
            }
        }
    }
    return 0;
}