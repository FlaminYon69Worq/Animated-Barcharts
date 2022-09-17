// barchartanimate.h
// David Mendoza, Project 3: Animated Barchart
// Fall 2021

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string Title;
    string XLabel;
    string Source;
    int colorIndex;

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
      capacity = 4;  // initialize everything else below as empty except array
      barcharts = new BarChart[capacity];  
      size = 0;
      Title = title;
      XLabel = xlabel;
      Source = source;
      colorIndex = 0;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if (barcharts != nullptr) {
          delete[] barcharts;
      }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
      int i, value, N;
      string frame, valStr, name1, name2, trash, category, line, xlabel, title, source;
      // ^^ valSTr to convert, name2 is trash  NStr for graphing the bars
      if (size == capacity) {
        capacity = capacity * 2;  // dynamic allocation
        BarChart* temp = new BarChart[this->capacity];
        for (i = 0; i < this->size; i++) {
          temp[i] = this->barcharts[i];}
        delete[] barcharts;
        barcharts = temp;
      }
      if (size == 0) {
         getline(file, trash);  // consume blank line
       }
       file >> N;  // N is the number of Bars
       BarChart bc(N);  // call parameterized constructor of size N
       i = 0;
       while (i < N) {
         if (i == 0) {
           getline(file, frame);
         }
         getline(file, frame, ',');  // read frame for barchart
         getline(file, name1, ',');  // read name for Bar
         getline(file, name2, ',');  // trash string
         getline(file, valStr, ',');  // read value for Bar, and stoi for comparison
         value = stoi(valStr);
         getline(file, category, '\n');  // read category for BarChart
         if (colorMap.count(category) == 0) {
           colorMap[category] = COLORS[(colorIndex++ % 7)];}
         bc.addBar(name1, value, category);
         i++;
         if (i == N) {  // all bars read, set frame
           bc.setFrame(frame);
           barcharts[size] = bc;}  // set = to barchart at current index
       }
       size++;
       getline(file, trash);  // consume last line
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;  // automatic second count
    if (endIter == -1) {
      endIter = size - 1;
    }
    
    for (int i = 0; i < endIter; i++) {  // loop for however many frames in txt
      usleep(3 * microsecond);
      output << CLEARCONSOLE << BLACK << this->Title << endl;
      output << BLACK << this->Source << endl;
      this->barcharts[i].graph(output, colorMap, top);  // graph
      output << BLACK << XLabel << endl;
      output << "Frame: " << this->barcharts[i].getFrame() << endl;
    }
  }
  
  void animate(ostream &output, int top, int endIter, int ms) {
    if (endIter == -1) {
      endIter = size - 1;
    }
    
    for (int i = 0; i < endIter; i++) {  // loop for however many frames in txt
      usleep(3 * ms);  // controls how fast each frame loads
      output << CLEARCONSOLE << BLACK << this->Title << endl;
      output << BLACK << this->Source << endl;
      this->barcharts[i].graph(output, colorMap, top);  // graph
      output << BLACK << XLabel << endl;
      output << "Frame: " << this->barcharts[i].getFrame() << endl;
    }
  }

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;
        
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
      if (i < 0 || i >= size) {
        throw out_of_range("BarChart: i out of bounds");
      }
      return barcharts[i];
    }
};
