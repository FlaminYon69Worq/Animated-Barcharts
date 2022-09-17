// barchart.h
// David Mendoza, UIC, Project 3: Animated Barchart
// Fall 2021

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in autograder, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Codio (light/dark mode)
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string Frame;
    
 public:
    
    // default constructor:
    BarChart() {
      bars = nullptr;     
      capacity = 0;
      size = 0;
      Frame = "";
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
      bars = new Bar[n];
      capacity = n;
      size = 0;
      Frame = "";
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
      this->bars = new Bar[other.capacity];  // set all other variables = to other
      this->size = other.size;
      this->capacity = other.capacity;
      this->Frame = other.Frame;
      for (int i = 0; i < other.size; ++i) {
        this->bars[i] = other.bars[i];  // copy over data
      }
    }
  
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
      if (this == &other){  // already assigned to itself
        return *this;
      }
      delete[] bars;
      this->bars = new Bar[other.capacity];  // allocate equal to other capacity
      this->size = other.size;
      this->capacity = other.capacity;
      this->Frame = other.Frame;
      for (int i = 0; i < other.size; ++i) {
        this->bars[i] = other.bars[i];  // copy over data
      }
      return *this;
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
      delete[] bars;
      bars = nullptr;     
      capacity = 0;
      size = 0; 
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {
      if (bars != nullptr) {
        delete[] bars;
      }       
    }
    
    // setFrame
    void setFrame(string frame) {
      Frame = frame;
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
      return Frame;
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
      if (size == capacity) {  // if full
        return false;
      }
      Bar b(name, value, category);
      bars[size] = b;
      size++;
      return true;
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
      return size;
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
      if (i < 0 || i >= size) {
        throw out_of_range("BarChart: i out of bounds");
      }
      return bars[i];
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        sort(bars, bars+size, greater<Bar>());  // sort in descending order
        output << "frame: " << Frame << endl;
        for (int i = 0; i < this->size; i++) {
          output << this->bars[i].getName() << " " << this->bars[i].getValue()
            << " " << this->bars[i].getCategory() << endl;
        }
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;
      string barstr = "";
      string color;
      sort(bars, bars+size, greater<Bar>());
      double topValue = bars[0].getValue();
      
      // loop through top
      for (int i = 0; i < top; i++) {
        double barVal = bars[i].getValue();  // value in bar
        // in double so division actually works when calculating
        double barValue = (barVal / topValue) * lenMax;  // calculate length of bar
        int barLength = floor(barValue); // round down
        barstr = "";
        for (int j = 0; j < barLength; j++) {
          barstr += BOX;  // concatenate boxes
        }
        if (colorMap.count(bars[i].getCategory()) > 0) {  // exists
          color = colorMap[bars[i].getCategory()];
        } else {
          color = BLACK;  // reset
        }
        output << color << barstr << " " << bars[i].getName()
        << " " << this->bars[i].getValue() << endl;  // output bar
        }
    }
};

