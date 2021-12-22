// Your name here

// DEFINE STRUCTURE HERE -- MISSING!
struct UndergradStudents{
    string firstName;
    string lastName;
    string major;
    double gpa1;
    double gpa2;
    double gpa3;
    double gpa4;
    int ID;
};

// DECLARE FUNCTIONS HERE.
// I've already declared 2 functions for you (DO NOT CHANGE THESE!)
void InitializeStructures(UndergradStudents us[], int &size);
void WriteResults(ofstream &outf, UndergradStudents us[], int size);
void bubblesort(UndergradStudents us[], int size);
// You may add other function declarations in here as well, if you want to.
// See hint in the lab description document.
