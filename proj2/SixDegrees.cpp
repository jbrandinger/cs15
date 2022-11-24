/* SixDegrees.cpp 
 *
 * Purpose: SixDegrees is a program that finds the connection between two
 *          artists through the songs they have collaborated
 *
 * Created By: Joel Brandinger
 * Date: December 2021
 */


#include "SixDegrees.h"
#include <queue>

/* SixDegrees()
 * Purpose: constructor
 */
SixDegrees::SixDegrees()
{    
}

/* SixDegrees()
 * Purpose: destructor
 */
SixDegrees::~SixDegrees()
{    
}

/* start(fstream &dataFile, istream &input, ostream &output)
 * Purpose: start the SixDegrees program
 * Paramters: dataFile to populate graph as well as the adresses of where
 *            to direct input & output
 */
void SixDegrees::start(fstream &dataFile, istream &input, ostream &output)
{
    vector<Artist> artists = get_vector(dataFile);
    graph.populate_graph(artists);
    run_command_loop(input, output);
}

/* get_vector(fstream &dataFile)
 * Purpose: create a vector of Artists and their songs used to populate the
 *          graph
 * Parameters: dataFile containing all the the artist names and songs
 * Returns: the vector of artists
 */
vector<Artist> SixDegrees::get_vector(fstream &dataFile)
{
    vector <Artist> artists;
    string line;
    
    while (not dataFile.eof()) {
        getline(dataFile, line);
        artists.push_back(Artist(line));
        getline(dataFile, line);
        
        while (line != "*") {
            artists[artists.size() - 1].add_song(line);
            getline(dataFile, line);
        }    
    }
    return artists;
}

/* print(ostream &output)
 * Purpose: print the graph
 * Parameters: address of where to dircet output 
 */
void SixDegrees::print(ostream &output)
{
    graph.print_graph(output);
}

/* run_command_loop(istream &input, ostream &output)
 * Purpose: run the command loop of the program that contiually accepts user
 *          input or reads an input file 
 * Parameters: where to direct input & output
 */
void SixDegrees::run_command_loop(istream &input, ostream &output)
{
    string cmd;
    while (not input.eof()) {
        getline(input, cmd);
        if (cmd == "print") {
            print(output);
        } else if (cmd == "bfs") {
            string artist1;
            string artist2;
            getline(input, artist1);
            getline(input, artist2);
            bfs(artist1, artist2, output);
        } else if (cmd == "dfs") {
            string artist1;
            string artist2;
            getline(input, artist1);
            getline(input, artist2);
            dfs(artist1, artist2, output);
        } else if (cmd == "not") {
            string artist1;
            string artist2;
            getline(input, artist1);
            getline(input, artist2);
            vector<Artist> excluded = excluded_artists(input);
            exclusive_search(artist1, artist2, excluded, output);
        } else if (cmd == "quit") {
            return;
        } else {
            output << cmd << " is not a command. Please try again." << endl;
        }
    }
}

/* bfs(string artist1, string artist2, ostream &output)
 * Purpose: perform breadth first search on the graph to update predecessors
 *          of each vertex (artist)
 * Parameters: names of source artist and destination artist as well as
 *             address of where to send output 
 */
void SixDegrees::bfs(string artist1, string artist2, ostream &output)
{
    Artist source(artist1);
    Artist dest(artist2);
    
    if (!doesExist2(source, dest, output)) {
        return;
    }
    
    queue<Artist> q;
    graph.mark_vertex(source);
    q.push(source);
    
    while (not q.empty()) {
        Artist curr = q.front();
        q.pop();
        vector<Artist> neighbors = graph.get_vertex_neighbors(curr);
        
        int size = neighbors.size();
        for (int i = 0; i < size; i++) {
            if (!graph.is_marked(neighbors[i])) {
                graph.mark_vertex(neighbors[i]);
                graph.set_predecessor(neighbors[i], curr);
                q.push(neighbors[i]);
            }
        }
    }
    print_path(source, dest, output);
    graph.clear_metadata();
}

/* dfs(string artist1, string artist2, ostream &output)
 * Purpose: perform depth first search on the graph to update predecessors
 *          of each vertex (artist)
 * Parameters: names of source artist and destination artist as well as
 *             address of where to send output 
 */
void SixDegrees::dfs(string artist1, string artist2, ostream &output)
{
    Artist source(artist1);
    Artist dest(artist2);
    
    if (!doesExist2(source, dest, output)) {
        return;
    }

    dfs_helper(source);
    print_path(source, dest, output);
    graph.clear_metadata();
}

/* dfs_helper(Artist curr)
 * Purpose: recursively search through all neigbors to traverse graph 
 * Parameters: artist/ vertex currently visiting
 */
void SixDegrees::dfs_helper(Artist curr)
{
    graph.mark_vertex(curr);

    vector<Artist> neighbors = graph.get_vertex_neighbors(curr);
    int size = neighbors.size();
    for (int i = 0; i < size; i++) {
        if (!graph.is_marked(neighbors[i])) {
            graph.set_predecessor(neighbors[i], curr);
            dfs_helper(neighbors[i]);
        }
    }
}

/* excluded_artists(istream &input)
 * Purpose: create a vector of artists to exclude in the exclusive search
 * Parameters: address of user input of artists to exclude 
 * Returns: vector of artists 
 */
vector<Artist> SixDegrees::excluded_artists(istream &input)
{
    vector <Artist> artists;
    string line;
    
    getline(input, line);
    while (line != "*") {
        artists.push_back(Artist(line));
        getline(input, line);
    }
    return artists;
}

/* exclusive_search(string artist1, string artist2, vector<Artist> excluded,
 *                  ostream &output)
 * Purpose: perform exclusive bfs traversal
 * Parameters: names of artists to connect, vector of artists to exclude, 
 *             and address of where to send output   
 */
void SixDegrees::exclusive_search(string artist1, string artist2, 
                                  vector<Artist> excluded, ostream &output)
{
    Artist source(artist1);
    Artist dest(artist2);
    
    bool exists = doesExist2(source, dest, output);
    bool correct = check_artists(excluded, output);
    
    if ((!exists) or (!correct)) {
        return;
    }
    
    bfs(artist1, artist2, output);
}
/* print_path(Artist source, Artist dest, ostream &output)
 * Purpose: print the path between two artists if there is one 
 * Parameters: source artist and destination artist and address of where to
 *             print output 
 */
void SixDegrees::print_path(Artist source, Artist dest, ostream &output)
{
    stack<Artist> path = graph.report_path(source, dest);
    if (path.size() == 0) {
        output << "A path does not exist between \"" << source.get_name()
               << "\" and \"" << dest.get_name() << "\"." << endl;
        return;
    } else { 
        while (path.size() >= 2) {
            Artist artist1 = path.top();
            path.pop();
            Artist artist2 = path.top();
            string song = graph.get_edge(artist1, artist2);
            
            output << "\"" << artist1.get_name() << "\" collaborated with \""
                   << artist2.get_name() << "\" in \"" << song << "\"." 
                   << endl;
        }
    }
    output << "***" << endl;
}

/* doesExist1(Artist artist, ostream &output)
 * Purpose: determine if given artist exists in the dataset 
 * Paramters: artist to check and address of output 
 * Returns: true if artist exists, false if it does not exist in the dataset
 */
bool SixDegrees::doesExist1(Artist artist, ostream &output)
{
    bool exists = true;
    
    if (!graph.is_vertex(artist)) {
        output << "\""<< artist.get_name() << "\" was not found in the dataset"
               << " :(" << endl;
        exists = false;
    }
    
    return exists;
}

/* doesExist2(Artist one, Artist two, ostream &output)
 * Purpose: determine if given artists exist in the dataset 
 * Paramters: artists to check and address of output 
 * Returns: true if artists exist, false if one or both do not exist in 
 *          the dataset
 */
bool SixDegrees::doesExist2(Artist one, Artist two, ostream &output)
{
    bool exists = true;
    
    if (!graph.is_vertex(one)) {
        output << "\""<< one.get_name() << "\" was not found in the dataset"
               << " :(" << endl;
        exists = false;
    }
    
    if (!graph.is_vertex(two)) {
        output << "\""<< two.get_name() << "\" was not found in the dataset"
               << " :(" << endl;
        exists = false;
    }
    
    return exists;
}

/* check_artists(vector<Artist> excluded, ostream &output)
 * Purpose: check if all the artists to exclude exist in the graph. If they
 *          do, mark that vertex so it will not be visited in the 
 *          exclusive traversal. If the artist does not exist, mark the 
 *          boolean as false, print the error, and clear the data.
 * Parameters: vector of artists to exclude and address of output 
 * Returns: true if all the artists exist in the graph, false if otherwise
 */
bool SixDegrees::check_artists(vector<Artist> excluded, ostream &output)
{
    bool correct = true;
    
    int size_e = excluded.size();
    for (int i = 0; i < size_e; i++) {
        if (!doesExist1(excluded[i], output)) {
            correct = false;
        } else {
            graph.mark_vertex(excluded[i]);
        }
    }
    if (!correct) {
        graph.clear_metadata();
    }
    
    return correct;
}