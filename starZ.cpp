#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);
string starZ(int width){
	if(width<3){
		exit(1);
	}


	string result="";
	int i=0;
	int s=0;
	while(i<1){for(int j=0;j<width;j++){
		result+="*";
	}i=i+1;}
	result+="\n";
	for(int k=0;k<width-2;k++){
		for(int x=0;x<width-k-2;x++){
			result+=" ";}
		result+="*";
	for(int x=0; x<k-1;x++){
		result+=" ";}

		
		
			result+="\n";
	
	
	
	} 

	while(s<1){for(int f=0;f<width;f++){
		result+="*";
	}
	s+=1;
	}   result+="\n";
	return result;}


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


























	int main(int argc,char*argv[]){
		if(argc!=2){
			cerr<<"Assertion failed";
			exit(1);
		}
		int m=atoi(argv[1]);
		cout<<starZ(m);
		return 0;
	}
