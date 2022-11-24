/* SixDegrees.h
 *
 * Purpose: the reference file for the SixDegrees class
 *
 * Created By: Joel Brandinger
 * Date: December 2021
 */

#ifndef SIX_DEGREES
#define SIX_DEGREES

#include "CollabGraph.h"
#include <fstream>
#include <iostream>

using namespace std;

class SixDegrees {
    
public:
    
    SixDegrees();
    ~SixDegrees();
    
    void start(fstream &dataFile, istream &input, ostream &output);
    
private:
        
    CollabGraph graph;
    void run_command_loop(istream &input, ostream &output);
    void print(ostream &output);
    vector<Artist> get_vector(fstream &dataFile);
    
    void bfs(string artist1, string artist2, ostream &output);
    
    void dfs(string artist1, string artist2, ostream &output);
    void dfs_helper(Artist curr);
    
    void exclusive_search(string artist1, string artist2,
                          vector<Artist> excluded, ostream &output);
    vector<Artist> excluded_artists(istream &input);
    bool check_artists(vector<Artist> excluded, ostream &output);
    
    void print_path(Artist source, Artist dest, ostream &output);
    bool doesExist1(Artist artist, ostream &output);
    bool doesExist2(Artist one, Artist two, ostream &output);
            
};

#endif