/* main.cpp 
 * Runs MetroSim simulation
 *
 * Created by: Joel Brandinger 
 * Date: October 2021 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

void openFile(fstream &stream, string filename);
int main(int argc, char *argv[])
{
    MetroSim simulation;
    fstream input_stream;
    fstream output_stream;
    
    if (argc == 3) {
        openFile(input_stream, argv[1]);
        openFile(output_stream, argv[2]);
        simulation.start(input_stream, output_stream, std::cin);
    }
    
    if (argc == 4) {
        fstream commandFile;
        openFile(input_stream, argv[1]);
        openFile(output_stream, argv[2]);
        openFile(commandFile, argv[3]);
        simulation.start(input_stream, output_stream, commandFile);
        commandFile.close();
    }
    
    if (argc < 3 or argc > 4) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" 
             << endl;
        exit(1);
    }
    input_stream.close();
    output_stream.close();
    
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
        cerr << "Error: could not open file " << filename << endl;
        exit(1);
    }
}