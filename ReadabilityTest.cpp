/*******************************************************************************
 * 
 * Proj.02: A program that submits a user inputed phrase and collects data on it's
 *          readibility according to pre-determined readibility indexs.
 * 
 * File Name: readibilityTest.cpp
 * Name:      Trevor Claridge
 * Course:    CPTR 141
 * Date:      @@date@@
 * 
 */
 
 #include <iostream>
 #include <string>
 #include <ctype.h>
 #include <fstream>
 #include <cassert>
 #include <vector>
 using namespace std;
 
 //debug variable [set to true to see debug outputs]
 bool debug = true;
 
 
 //Prototype for numWords: a function that counts the number of words in a string
 double numWords(string);
 
 //Prototype for numCharacters: a function that counts the number of letters or numbers in a string
 double numCharacters(string);
 
 //Prototype for numSentences: a function that counts the number of number of sentences in a string
 double numSentences(string);
 
 //Prototype for numSyllables: a function that counts the number of syllables in a string
 double numSyllables(string, vector<char>);
 
 //Prototype for longWords: a function that identifies what percent of words a "long" words
 double longWords(string);
 
 //Prototype for AutoReadibility: a function that uses the Automated readiblity index to determine readiblity for a string
 int autoReadibility(int, int, int);
 
 //Prototype for FleschReadiblity: a function that uses the Flesch reading ease readiblity test to deterine readiblity for a string
 double fleschReadibility(double, double, double, double);
 
 //Prototype for AutoLevel: a function that interprets the score of the AutoReadibility function as grade level.
 string gradeLevel(int);
 
 
int main() {
    
    //define main-local variables
    string consoleInput;
    string fileInput;
    string fileOutput;
    ifstream fin;
    ofstream fout;
    char tempInput;
    bool goodFile = false;
    bool goodInputChoice = false;
    bool outputChoice = false;
    bool exitChoice = false;
    bool validExitChoice = false;
    
    string enteredPassage;
    vector<char> vowels = {'a','e','i','o','u','y','A','E','I','O','U','Y'}; 
    
     
     do {
         //show heading
            cout << "===========================================================================================================================" << endl;
            cout << "Thank you for using the TClaridge Readiblity Tester." << endl;
            cout << "Would you like to add a phrase via the console or upload a phrase via a text file?"
                 << endl
                 << "Enter 'c' for console and 't' for text file: ";
        
        //collect input for console or text file
            do {
                cin >> tempInput;
                tempInput = toupper(tempInput);
                
                //output current tempInput value
                if (debug) {
                    cout << endl;
                    cout << "[DEBUG] tempInput: " << tempInput << endl << endl;
                }
            
                //for console input    
                if (tempInput == 'C') {
                    
                    //clear cin in preperation for
                    cin.ignore(1, '\n');
                    cin.clear();
                    
                    cout << "You have chosen console input. Please enter your phrase or passage: ";
                    getline(cin, enteredPassage);
                    
                    //cout << enteredPassage << endl;
                    goodInputChoice = true;
                }
                
                //for file input
                else if (tempInput == 'T') {
                    cout << "You have chosen text file input. Please enter the name of the file you wish to read from: ";
                   
                   do {
                        cin >> fileInput;
                        
                        fin.open(fileInput);
                        if (!fin) {
                            cout << endl;
                            cerr << "Could not open file. Please enter a valid file name: ";
                            fin.clear();
                            goodFile = true;
                        }
                        else {
                            getline(fin, enteredPassage);
                            goodFile = false;
                        }
                    } while (goodFile == true);
                    goodInputChoice = true;
                }
                
                //invalid choice
                else {
                    cerr << "Please only enter 'c' or 't': ";
                    cin.ignore(1, '\n');
                    cin.clear();
                    goodInputChoice = false;
                }
            } while (goodInputChoice == false);
            
        //perform functions on enteredPassage
            cout << endl << "===========================================================================================================================" << endl;
            cout << "Your entered passage has " << numSentences(enteredPassage) << " sentences, " << numWords(enteredPassage) << " words, " << numSyllables(enteredPassage, vowels) << " syllables, and "
                 << numCharacters(enteredPassage) << " characters." << endl;
            cout << "===========================================================================================================================" << endl;
        
        
            cout << "Your entered passage has an average word per sentence count of " << numWords(enteredPassage) / numSentences(enteredPassage) << " and an average syllable per word count of " << numSyllables(enteredPassage, vowels) /numWords(enteredPassage) << "." << endl;
            cout << longWords(enteredPassage) << "% of words in your passage are long words (long words are words of 7 or more characters)." << endl;
            cout << "===========================================================================================================================" << endl;
        
        
            cout << "According to the Automated Readiblity Index, your passage has a readiblity score of " << autoReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage)) << "." << endl;
            cout << "According to the Flesch ease-reading readiblity test, your passasge has a readiblity score of " << fleschReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage), numSyllables(enteredPassage, vowels)) << "." << endl;
            cout << "These scores indicate that your passage has a readibility of about a " << (gradeLevel(fleschReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage), numSyllables(enteredPassage, vowels)))) << " level." << endl;
            
            //DEBUG TABLE
            if (debug) {
                cout << endl;
                cout << "[DEBUG] ===================================================================================================================" << endl;
                cout << "numCharacters: " << numCharacters(enteredPassage) << endl;
                cout << "numSyllables: " << numSyllables(enteredPassage, vowels) << endl;
                cout << "numWords: " << numWords(enteredPassage) << endl;
                cout << "numSentences: " << numSentences(enteredPassage) << endl;
                cout << "longWords: " << longWords(enteredPassage) << endl;
                cout << "autoReadibility: " << autoReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage)) << endl;
                cout << "fleschReadibility: " << fleschReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage), numSyllables(enteredPassage, vowels)) << endl;
                cout << "gradeLevel: " <<  (gradeLevel(fleschReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage), numSyllables(enteredPassage, vowels)))) << endl;
                cout << "[DEBUG] ===================================================================================================================" << endl;
            }
            
         //ask user if they would like to save the statics to a file 
            cout << endl << "Would you like to save these statistics to a file? (y/n) ";
            
            do {    
                cin >> tempInput;
                cout << endl;
                tempInput = toupper(tempInput);
                
                //output current tempInput value
                if (debug) {
                    cout << endl;
                    cout << "[DEBUG] tempInput: " << tempInput << endl << endl;
                }
                
                //sending statistics to Readibility_Statistics.txt
                if (tempInput == 'Y') {
                    
                    cout << "Please enter the name of the file you would like to write to: ";
                    cin >> fileOutput;
                    
                    
                    fout.open(fileOutput);
                    
                    fout << enteredPassage << endl;
                    fout <<"===========================================================================================================================" << endl;
                    fout << "Your entered passage has " << numSentences(enteredPassage) << " sentences, " << numWords(enteredPassage) << " words, " << numSyllables(enteredPassage, vowels) << " syllables, and "
                         << numCharacters(enteredPassage) << " characters." << endl;
                    fout << "===========================================================================================================================" << endl;
                
                
                    fout << "Your entered passage has an average word per sentence count of " << numWords(enteredPassage) / numSentences(enteredPassage) << " and an average syllable per word count of " << numSyllables(enteredPassage, vowels) /numWords(enteredPassage) << "." << endl;
                    fout << longWords(enteredPassage) << "% of the words in your passage are long words (long words are words of 7 or more characters)." << endl;
                    fout << "===========================================================================================================================" << endl;
                
                
                    fout << "According to the Automated Readiblity Index, your passage has a readiblity score of " << autoReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage)) << "." << endl;
                    fout << "According to the Flesch ease-reading readiblity test, your passasge has a readiblity score of " << fleschReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage), numSyllables(enteredPassage, vowels)) << "." << endl;
                    fout << "These scores indicate that your passage has a readibility of about a " << (gradeLevel(fleschReadibility(numCharacters(enteredPassage), numWords(enteredPassage), numSentences(enteredPassage), numSyllables(enteredPassage, vowels)))) << " level." << endl;
                
                    fout.close();
                    
                    cout << "Your readibility statistics have been saved the file " << fileOutput << "." << endl;
                    cout << "===========================================================================================================================" << endl;
                    outputChoice = true;
                    
                }
                
                //moving on if the user chooses not save statistics to a file
                else if (tempInput == 'N') {
                    outputChoice = true;
                    break;
                }
                
                //invalid choice
                else {
                    cerr << "Please choose y for Yes or n for No: ";
                    cin.ignore(1, '\n');
                    cin.clear();
                    goodInputChoice = false;
                }
                
            } while (outputChoice == false);    
     
            cout << "You may now exit the program or enter a new passage." << endl;
            cout << "Enter 'e' to exit the program or 'n' to enter a new passage: ";
            
            do {
                cin >> tempInput;
                cout << endl;
                tempInput = toupper(tempInput);
                
                
                //output current tempInput value
                if (debug) {
                    cout << endl;
                    cout << "[DEBUG] tempInput: " << tempInput << endl << endl;
                }
                
                //Enter a new passage
                if (tempInput == 'N') {
                    exitChoice = false;
                    validExitChoice = true; 
                }
                
                //Exit the program
                else if (tempInput == 'E') {
                    cout << "===========================================================================================================================" << endl;
                    cout << "Goodbye.";
                    
                    exitChoice = true;
                    validExitChoice = true;
                }
            
                //Invalid choice
                else {
                    cerr << "Please only enter 'e' or 'n' ";
                    cin.ignore(1);
                    cin.clear();
                    validExitChoice = false;
                }
            } while (validExitChoice == false);
            
            cout << endl;
     } while (exitChoice == false);
     
     
//END OF MAIN
return 0;
}

//numWords function body
double numWords(string w) {
    int wordCount = 0;
    
    for (int i = 0; i < w.length(); ++i) {
        if ((w.at(i) == ' ') || (w.at(i) == '?') || (w.at(i) == '!')) {
            ++wordCount;
        }
    }
    
    return wordCount + 1;
}

//numCharacters function body
double numCharacters(string c) {
    int characterCount = 0;
    
    for (int i = 0; i < c.length(); ++i) {
        ++characterCount;
    }
    
    for (int i = 0; i < c.length(); ++i) {
        if ((c.at(i) == ' ') || (c.at(i) == '.') || (c.at(i) == ',')) {
            --characterCount;
        }
    }
    
    return characterCount;
}

//numSentences function body
double numSentences(string s) {
    int sentenceCount = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        if (((s.at(i) == '.') || (s.at(i) == '!') || (s.at(i) == '?'))) {
            ++sentenceCount;
        }
    }
    
    return sentenceCount;
}

// //numSyllables function body
double numSyllables(string sl, vector<char> vow) {
    int syllableCount = 0;
    
    for (int i = 0; i < sl.length(); ++i) {
        for (int j = 0; j < vow.size(); ++j) {
            if (sl.at(i) == vow.at(j)) {
                ++syllableCount;
            }    
        }
    }
    
    for (int i = 0; i < sl.length(); ++i) {
        for (int j = 0; j < vow.size(); ++j) {
            if ((sl.at(i) == vow.at(j)) && (sl.at(i + 1) == vow.at(j))) {
                --syllableCount;
            }
        }
    }
    
    for (int i = 0; i < sl.length(); ++i) {
        for (int j = 0; j < vow.size(); ++j) {
            if ((sl.at(i) == vow.at(j)) && (sl.at(i + 1) == ' ')) {
                --syllableCount;
            }
        }
    }
    return syllableCount;
}

//longWords function body
double longWords(string passage) {
    int charCounter = 0;
    int longWordCounter = 0;
    const double LONG_WORD_SIZE = 7.0;
    double ret;

    
    for (int i = 0; i < passage.length(); ++i) {
            if ((passage.at(i) != ' ') && (passage.at(i) != '.') && (passage.at(i) != '?') && (passage.at(i) != '!')) {
                ++charCounter;
            }
            else if ((passage.at(i) == ' ') || (passage.at(i) == '.') || (passage.at(i) == '?') || (passage.at(i) == '!')) {
                if (charCounter >= LONG_WORD_SIZE) {
                    ++longWordCounter;
                    charCounter = 0;
                }
            }
    }
    
    ret = (longWordCounter / (numWords(passage))) * 100.00;
    
    return ret;

}

//autoReadibility function body
 int autoReadibility(int ch, int wo, int se) {
    
    double autoScore = ((4.71 * (ch / wo)) + (0.5 * (wo / se)) - 21.43);
    
    return autoScore;
}

//fleschReadibility function body
double fleschReadibility (double cha, double wor, double sen, double syl) {
    
    double fleschScore = (206.835 - (1.015 * (wor / sen)) - (84.6 * (syl / wor)));

    return fleschScore;
}

//autoLevel function body
string gradeLevel(int score) {
    string grade;
    // switch (score) {
    //     case 1:
    //         grade = "Kindergarten grade";
    //         break;
    //     case 2:
    //         grade = "First/Second grade";
    //         break;
    //     case 3:
    //         grade = "Third grade";
    //         break;
    //     case 4:
    //         grade = "Fourth grade";
    //         break;
    //     case 5:
    //         grade = "Fifth grade";
    //         break;
    //     case 6:
    //         grade = "Sixth grade";
    //         break;
    //     case 7:
    //         grade = "Seventh grade";
    //         break;
    //     case 8:
    //         grade = "Eighth grade";
    //         break;
    //     case 9:
    //         grade = "Ninth grade";
    //         break;
    //     case 10:
    //         grade = "Tenth grade";
    //         break;
    //     case 11:
    //         grade = "Eleventh grade";
    //         break;
    //     case 12:
    //         grade = "Twelfth grade";
    //         break;
    //     case 13:
    //         grade = "College";
    //         break;
    //     case 14:
    //         grade = "Professor";
    //         break;
    //     default:
    //         grade = " [cannot not determine grade] ";
    // }
    
    if (score >= 90.0) {
        grade = "Fifth grade or lower";
    }
    else if (score >= 80.0) {
        grade = "Sixth grade";
    }
    else if (score >= 70.0) {
        grade = "Seventh grade";
    }
    else if (score >= 60.0) {
        grade = "Eighth or Ninth grade";
    }
    else if (score >= 50.0) {
        grade = "Tenth to Twelfth";
    }
    else if (score >= 30.0) {
        grade = "College";
    }
    else if (score <= 29.9) {
        grade = "Graduate, Proffesor, or higher";
    }
    else {
        grade = " [cannot determine grade]";
    }
    
    return grade;
}
