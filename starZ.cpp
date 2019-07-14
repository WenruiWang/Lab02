#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

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
		result+="\n";

	
	}
	while(s<1){for(int f=0;f<width;f++){
		result+="*";
	}
	s+=1;
	}   result+="\n";
	return result;}

	int main(int argc,char*argv[]){
		if(argc!=2){
			cerr<<"Assertion failed";
			exit(1);
		}
		int m=atoi(argv[1]);
		cout<<starZ(m);
		return 0;
	}
