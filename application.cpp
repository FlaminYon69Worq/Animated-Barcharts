// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// Creative Component: Asks a filename to load and analyze, also controls how many frames and bars to graph
// And how fast to load them
// While loop until user does not want to analyze anymore
//
// David Mendoza
// U. of Illinois, Chicago
// CS 251: Fall 2021
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
  string filename;
  cout << "Animated BarChart" << endl;
	cout << "Enter a filename to analyze" << endl;
  cin >> filename;  // enter filename, assuming it exists
	while (filename != "q") {
    ifstream infile(filename);  // file check, edge case, filename does not exist
    if (!infile.is_open()) {
      cout << "error, invalid filename. " << endl;
    } else {
    string title;  // read in file
    getline(infile, title);
    string xlabel;
    getline(infile, xlabel);
    string source;
    getline(infile, source);
    BarChartAnimate bca(title, xlabel, source);
    while (!infile.eof()) {
      bca.addFrame(infile);
    }
    int ms, frames, bars;
    cout << "How many bars, how many frames, how fast???" << endl;
    cin >> bars >> frames >> ms;  // input numbers, all separated by space
    // ^^  ^top    ^endIter  ^ms
    bca.animate(cout, bars, frames, ms);
    }
    cout << "Enter a filename to analyze" << endl;
    cin >> filename;  // enter filename, assuming it exists
  }
    cout << "GOODBYE!!! " << endl;
    return 0;
}
