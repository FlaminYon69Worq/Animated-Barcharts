// bar.h
// David Mendoza, Project 3: Animated Barchart
// Fall 2021

#include <iostream>
#include <string>
#include "myrandom.h" // used in autograder, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
  string Name;
  int Value;
  string Category;
    // Private member variables for a Bar object
    // NOTE: You should not be allocating memory on the heap for this class.

 public:

    // default constructor:
    Bar() {
      Name = "";
      Value = 0;
      Category = "";
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
      Name = name;
      Value = value;
      Category = category;
    }

    // destructor:
    virtual ~Bar() {
      Name = "";
      Value = 0;
      Category = "";        
    }

    // getName:
	string getName() {
        
    return Name;
        
	}

    // getValue:
	int getValue() {
    return Value;
	}

    // getCategory:
	string getCategory() {
    return Category;
	}

	// operators
    // objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar &other) const {
    if (this->Value < other.Value) {
      return true;
    }
    return false;
	}

	bool operator<=(const Bar &other) const {
    if (this->Value <= other.Value) {
      return true;
    }
    return false;
	}

	bool operator>(const Bar &other) const {
    if (this->Value > other.Value) {
      return true;
    }
    return false;
	}

	bool operator>=(const Bar &other) const {
    if (this->Value >= other.Value) {
      return true;
    }
    return false;
	}
};

