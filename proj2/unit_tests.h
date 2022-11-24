/* unit_tests.h
 *
 * Purpose: test the implemented functions of Collabgraph.cpp as well as
 *          the initial implementation of the SixDegrees class
 *
 * Created By: Joel Brandinger
 * Date: December 2021
 */
 
#include "CollabGraph.h"
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

// create a small vector of artists to populate graph 
vector<Artist> create_vector()
{
    vector<Artist> artists;
    
    artists.push_back(Artist("Adam"));
    artists.push_back(Artist("Brittney"));
    artists.push_back(Artist("Christina"));
    artists.push_back(Artist("Dan"));
    
    artists[0].add_song("Song 1");
    artists[1].add_song("Song 1");
    
    artists[1].add_song("Song 2");
    artists[2].add_song("Song 2");
    
    artists[2].add_song("Song 3");
    artists[3].add_song("Song 3");
    
    return artists;
}

// test the populate_graph() function 
void populate_graph()
{
    vector<Artist> artists = create_vector();
    CollabGraph graph;
    graph.populate_graph(artists);
    graph.print_graph(cout);
}

//test get_vertex_neighbors() function
void get_vertex_neighbors()
{
    vector<Artist> artists = create_vector();
    CollabGraph graph;
    graph.populate_graph(artists);
    
    vector<Artist> neighbors1 = graph.get_vertex_neighbors(artists[1]);
    
    int size1 = neighbors1.size();
    cout << "Neighbors of " << artists[1].get_name() << ":" << endl;
    for (int i = 0; i < size1; i++) {
        cout << neighbors1[i] << endl;
    }
    
    vector<Artist> neighbors2 = graph.get_vertex_neighbors(artists[3]);
    
    int size2 = neighbors2.size();
    cout << "Neighbors of " << artists[3].get_name() << ":" << endl;
    for (int i = 0; i < size2; i++) {
        cout << neighbors2[i] << endl;
    }
}

// test report_path() function
void report_path()
{
    vector<Artist> artists = create_vector();
    CollabGraph graph;
    graph.populate_graph(artists);
    
    graph.set_predecessor(artists[1], artists[0]);
    graph.set_predecessor(artists[2], artists[1]);
    graph.set_predecessor(artists[3], artists[2]);
    
    cout << "Path from Adam to Dan:" << endl;
    stack<Artist> path = graph.report_path(artists[0], artists[3]);
    int size = path.size();
    for (int i = 0; i < size; i++) {
        cout << path.top().get_name() << endl;
        path.pop();
    }
}
