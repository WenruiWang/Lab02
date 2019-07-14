#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);

// Write starZ per specifictions at 
// https://foo.cs.ucsb.edu/16wiki/index.php/F14:Labs:lab04
// and so that internal tests pass, and submit.cs system tests pass

// starZ is A C++ function that returns a string that, when printed on cout,
// renders the letter Z with stars as ASCII art, 
// at any width, provided width >=3
// If less than 3, the function should return an empty string.

// When width is >=3, the length of the result string
// should be (width + 1) * width (where the +1 is for the \n).    

// For examples, see the test cases in runTests().

// Note that the trailing spaces on each line are REQUIRED
// for the function to be considered correct.

string starZ(int width)
{

  string result="";
  // check if parameters are valid
  if ((width<=2)) {
    return result;  // return without printing anything
  }
  
  // add the first row of width stars  
  for (int j=0; j<width; j++) {
    result += "*";
  }
  result += "\n";

  // add the height-2 rows that are a single star
  for (int k=0; k<width-2; k++) { // same as starC, start at second row, save one row for full width stars
    for (int x=0; x<width-k-2; x++) { 
      result += " ";
    }
    result += "*";
    
    for (int x=0; x<=k-1; x++){
      result += " ";
    }

    result += "\n";
  }
  // add the final row of width stars  
  for (int f=0; f<width; f++) {
    result += "*";
  }
  result += "\n";  
  return result;   
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starZ3Expected = 
    "***\n"
    " * \n"
    "***\n";
  
  assertEquals(starZ3Expected,starZ(3),"starZ(3)");

  string starZ4Expected = 
    "****\n"
    "  * \n"
    " *  \n"
    "****\n";
  
  assertEquals(starZ4Expected,starZ(4),"starZ(4)");

  assertEquals("",starZ(0),"starZ(0)");
  assertEquals("",starZ(2),"starZ(2)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[])
{

  // check for parameters
  // and print usage message
  if (argc!=2) {
    cerr << "Usage: " << argv[0] << " width" << endl;
    exit(1);
  }
  
  // get width  from command line args
  int width = stoi(argv[1]);

  // If the program is executed with parameters -1 unit test
  // the starZ() function using our automated test framework
  if (width==-1) {  //checks if it is -1; 
    runTests(); // if so, call runTests()
    exit(0);   // then exit.
  }

  cout << starZ(width); //calls the starZ function and prints the result on cout (without an extra newline)
  return 0;

}


