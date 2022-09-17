#include <iostream>
#include <gtest/gtest.h>
#include "barchartanimate.h"
using namespace std;

// tests default constructor
bool testBarDefaultConstructor() {
    Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

// tests default constructor
bool testBarDefaultConstructor2() {
	Bar b2;
    if (b2.getName() != "") {
    	cout << "testBarDefaultConstructor2: getName failed" << endl;
    	return false;
    } else if (b2.getValue() != 0) {
    	cout << "testBarDefaultConstructor2: getValue failed" << endl;
    	return false;
    } else if (b2.getCategory() != "") {
    	cout << "testBarDefaultConstructor2: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor2: all passed!" << endl;
    return true;
}

// tests param constructor
bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

// tests param constructor
bool testBarParamConstructor2() {
	Bar b("You kno", 69420, "meme");
    if (b.getName() != "You kno") {
    	cout << "testBarParamConstructor2: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 69420) {
    	cout << "testBarParamConstructor2: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "meme") {
    	cout << "testBarParamConstructor2: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor2: all passed!" << endl;
    return true;
}

// test destructor
bool testBarDestructor() {
	Bar b;
  b.~Bar();
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

// test destructor
bool testBarDestructor2() {
	Bar b("Chicago", 9234324, "US");
  b.~Bar();
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor2: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor2: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor2: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor2: all passed!" << endl;
    return true;
}

// test less than operator
bool testLess1() {
  Bar b("Chicago", 9234324, "US");
  Bar b1("California", 90210, "Southwest");
  if (b1 < b) {
    cout << "testLess1: passed!" << endl;
    return true;
  }
  return false;
}

// test less than operator
bool testLess2() {
  Bar b("Chicago", 3, "US");
  Bar b1("California", 43, "Southwest");
  if (b < b1) {
    cout << "testLess2: passed!" << endl;
    return true;
  }
  return false;
}

// test less than equal operator
bool testLessEQ1() {
  Bar b("Chicago", 9234324, "US");
  Bar b1("California", 90210, "Southwest");
  if (b1 < b) {
    cout << "testLessEQ1: passed!" << endl;
    return true;
  }
  return false;
}

// test less than equal operator
bool testLessEQ2() {
  Bar b("Chicago", 43, "US");
  Bar b1("California", 43, "Southwest");
  if (b <= b1) {
    cout << "testLessEQ2: passed!" << endl;
    return true;
  }
  return false;
}

// test greater than operator
bool testGreat1() {
  Bar b("Chicago", 9234324, "US");
  Bar b1("California", 902101232, "Southwest");
  if (b1 > b) {
    cout << "testGreat1: passed!" << endl;
    return true;
  }
  return false;
}

// test greater than operator
bool testGreat2() {
  Bar b("Chicago", 432, "US");
  Bar b1("California", 43, "Southwest");
  if (b > b1) {
    cout << "testGreat2: passed!" << endl;
    return true;
  }
  return false;
}

// test greater than equal operator
bool testGreatEQ1() {
  Bar b("Chicago", 9234324, "US");
  Bar b1("California", 90210, "Southwest");
  if (b >= b1) {
    cout << "testGreatEQ1: passed!" << endl;
    return true;
  }
  return false;
}

// test greater than equal operator
bool testGreatEQ2() {
  Bar b("Chicago", 43, "US");
  Bar b1("California", 43, "Southwest");
  if (b >= b1) {
    cout << "testGreatEQ2: passed!" << endl;
    return true;
  }
  return false;
}

// test default constructor
bool testBCDefaultConstructor() {
	BarChart bc;
    if (bc.getSize() != 0) {
    	cout << "testBCDefaultConstructor: getSize failed" << endl;
    	return false;
    } else if (bc.getFrame() != "") {
    	cout << "testBCDefaultConstructor: getFrame failed" << endl;
    	return false;
    }
    cout << "testBCDefaultConstructor: all passed!" << endl;
    return true;
}

// test default constructor
bool testBCParamConstructor2() {
	BarChart bc(5);
    if (bc.getSize() != 5) {
    	cout << "testBCParamConstructor2: getSize failed" << endl;
    	return false;
    } else if (bc.getFrame() != "") {
    	cout << "testBCParamConstructor2: getFrame failed" << endl;
    	return false;
    }
    cout << "testBCParamConstructor2: all passed!" << endl;
    return true;
}

// test get size
bool testBCGetSize() {
  BarChart bc(3);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  if (bc.getSize() != 3) {
    cout << "getSize failed" << endl;
    return false;
  }
  cout << "getSize passed" << endl;
  return true;
}

bool testBCGetSize2() {
  BarChart bc(1);
  bc.addBar("Chicago", 1020, "US");
  if (bc.getSize() != 1) {
    cout << "getSize failed" << endl;
    return false;
  }
  cout << "getSize passed" << endl;
  return true;
}

// test clear function
bool testClear() {
  BarChart bc(3);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  bc.clear();
  if (bc.getSize() != 0) {
    	cout << "testBCDefaultConstructor: getSize failed" << endl;
    	return false;
    } else if (bc.getFrame() != "") {
    	cout << "testBCDefaultConstructor: getFrame failed" << endl;
    	return false;
    }
  cout << "clear passed" << endl;
  return true;
}



int main() {
  
// 	BarChart bc(3);
//   bc.setFrame("1950");
//   bc.addBar("Chicago", 1020, "US");
//   bc.addBar("NYC", 1300, "US");
//   bc.addBar("Paris", 1200, "France");
//   bc.dump(cout);
//   string red("\033[1;31m");
//   string blue("\033[1;34m");
//   map<string, string> colorMap;
//   colorMap["US"] = red;
//   colorMap["France"] = blue;
//   bc.graph(cout, colorMap, 3);
//   string red("\033[1;36m");
//   string blue("\033[1;33m");
//   map<string, string> colorMap;
//   colorMap["US"] = red;
//   colorMap["France"] = blue;
//   bc.graph(cout, colorMap, 3);
  string filename = "endgame.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, 12, 69, 2);
  // testBCParamConstructor2();
  
}