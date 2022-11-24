/*
 * main.cpp
 *
 * COMP 15 Project 2: Six Degrees of Collaboration
 * 
 * by Joel Brandinger, December 2021
 */

#include "SixDegrees.h"

using namespace std;

void openFile(fstream &stream, string filename);
int main(int argc, char *argv[])
{
    SixDegrees program;
    fstream dataFile;
    fstream commandFile;
    fstream outputFile;
    
    if (argc == 2) {
        openFile(dataFile, argv[1]);
        program.start(dataFile, cin, cout);
    } else if (argc == 3) {
        openFile(dataFile, argv[1]);
        openFile(commandFile, argv[2]);
        program.start(dataFile, commandFile, cout);
        commandFile.close();
    } else if (argc == 4) {
        openFile(dataFile, argv[1]);
        openFile(commandFile, argv[2]);
        openFile(outputFile, argv[3]);
        program.start(dataFile, commandFile, outputFile);
        commandFile.close();
        outputFile.close();
    } else {
        cout << "Usage: SixDegrees dataFile [commandFile] [outputFile]"
             << endl;
    }
    dataFile.close();
    
    
    return 0;
}

/* openFile(fstream &stream, string filename)
 *   Purpose: opens a file and makes sure it was properly opened 
 * Paramters:ftsream and string filename 
 *   Returns: none 
 */
void openFile(fstream &stream, string filename)
{
    stream.open(filename);
    if (not stream.is_open()) {
        cerr << filename << " cannot be opened." << endl;
        exit(1);
    }
}
