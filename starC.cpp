#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

string starC(int width,int height){
	if(height<=2){
	return "";}

	int num_spaces=width-1;
	int i=0;
	string result="";
	while(i<1){
		for(int j=0;j<width;j++){
			result+="*";}
		i=i+1;}
		result+="\n";
	
		for(int x=0;x<height-2;x++){
	    			result+="*";
	       		for(int y=0;y<width-1;y++){
			 result+=" ";}
		 result+="\n";
		}
		for(int w=0;w<width;w++){
			result+="*";
		} result+="\n";
		return result;}


		int main(int argc,char*argv[]){
			if(argc!=3){
				cerr<<"Assertion failed.\n";
				exit(1);}
			int m=atoi(argv[1]);
			int n=atoi(argv[2]);
			string result = starC(m,n);
			if(result!="")
			{
				cout<<result;
			}
			return 0;
		}
