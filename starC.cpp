#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starC(int width, int height);
void runTests(void);

// Write starC per specifictions in the lab writeup
// so that internal tests pass, and submit.cs system tests pass

// starC is A C++ function that returns a string that, when printed on cout,
// renders the letter C with stars as ASCII art, 
// at any width or height, provided width is >=2 and height is >=3
// If either is not, the function should return an empty string.

// When width is >=2 and height is >=3, the length of the result string
// should be (width + 1) * height (where the +1 is for the \n).    

// For examples, see the test cases in runTests().

// Note that the trailing spaces on each line are REQUIRED
// for the function to be considered correct.

string starC(int width, int height)
{
  string result="";
  // check if parameters are valid
  if ((width<2) || (height < 3)) {
    return result;  // return without printing anything
  }
  
  // add the first row of width stars  
  for (int col=1; col<=width; col++) {
    result += "*";
  }
  result += "\n";    

  // add the height-2 rows that are a single star
  // followed by width-1 spaces, then a \n
  for (int row=2; row<=height-1; row++) { //similar to starL, but starts at second row and save the last row for full width stars
    result += "*";
    for (int col=2; col<=width; col++) {
      result += " ";
    }
    result += "\n";
  }

  // add the final row of width stars  
  for (int col=1; col<=width; col++) {
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

  string starC34Expected = 
    "***\n"
    "*  \n"
    "*  \n"
    "***\n";
  
  assertEquals(starC34Expected,starC(3,4),"starC(3,4)");

  string starC53Expected =     
    "*****\n"
    "*    \n"
    "*****\n";

  
  assertEquals(starC53Expected,starC(5,3),"starC(5,3)");

  assertEquals("",starC(2,1),"starC(2,1)");
  assertEquals("",starC(2,2),"starC(2,2)");

  string starC23Expected =     
    "**\n"
    "* \n"
    "**\n";
  
  assertEquals(starC23Expected,starC(2,3),"starC(2,3)");
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
  if (argc!=3) {
    cerr << "Usage: " << argv[0] << " width height" << endl;
    exit(1);
  }
  
  // get width and height from command line args
  int width = stoi(argv[1]);
  int height = stoi(argv[2]);

  // If the program is executed with parameters -1 -1 unit test
  // the starC() function using our automated test framework
  if (width==-1 && height==-1) {  //checks if they are both -1; 
    runTests(); // if so, call runTests()
    exit(0);   // then exit.
  }

  cout << starC(width,height); //calls the starC function and prints the result on cout (without an extra newline)
  return 0;

}

