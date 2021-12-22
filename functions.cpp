// Your name here

// DEFINE YOUR FUNCTIONS HERE
// They have to be declared in the "headers.h" file.
//
// You *have* to use these 2 functions (already declared in records.cpp), 
// but you may add other functions in here as well, if you want.
// See hint in the lab description document.

void InitializeStructures(UndergradStudents us[], int &size) {
    int i(0);
    UndergradStudents temp;
    while(i < 20){
        cout << "Enter first name for student " << i + 1 << " (or X to quit): ";
        getline(cin, temp.firstName);
        if(temp.firstName == "X"){
            break;
        }
        cout << "Enter last name for student " << i + 1 << ": ";
        getline(cin, temp.lastName);
        cout << "Enter major for student " << i + 1 << ": ";
        getline(cin, temp.major);
        cout << "Enter GPA Year 1 for student " << i + 1 << ": ";
        cin >> temp.gpa1;
        cout << "Enter GPA Year 2 for student " << i + 1 << ": ";
        cin >> temp.gpa2;
        cout << "Enter GPA Year 3 for student " << i + 1 << ": ";
        cin >> temp.gpa3;
        cout << "Enter GPA Year 4 for student " << i + 1 << ": ";
        cin >> temp.gpa4;
        cout << endl;
        cin.ignore();
        temp.ID = i + 1;
        us[i] = temp;
        i++;
    }
    size = i;
    bubblesort(us, size);
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
    outf.open("Results.txt");

    outf << "These are the sorted results: " << endl;
    for(int k = 0; k < size; k++){
        double gpa = ((us[k].gpa1 + us[k].gpa2 + us[k].gpa3 + us[k].gpa4) / 4.0);
        outf << "ID# " << us[k].ID << ", " << us[k].lastName << ", " << us[k].firstName << ", " << us[k].major 
             << ", Average GPA: ";
        outf.setf(ios::fixed);
        outf.setf(ios::showpoint);
        outf.precision(2);
        outf << gpa << endl;
    }
    outf.close();
}

void bubblesort(UndergradStudents us[], int size){
    for(int i = size - 1; i > 0; i--){ // bubble sORt
        for (int j = 0; j < i; j++){
            if (us[j].lastName > us[j + 1].lastName){
                UndergradStudents temp = us[j];
                us[j] = us[j + 1];
                us[j + 1] = temp;
            }
        }
    }
}