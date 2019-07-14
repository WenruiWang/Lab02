#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
	

string starT(int width,int height){
string result="";
int num_of_stars_on_each_line=1;
int num_spaces=width-num_of_stars_on_each_line;
int num_spaces_each_side=num_spaces/2;
int i=0;
	        if(width%2==0||width<3||height<2){
		         exit(1);
		}

		while(i<1){
			for(int j=0;j<width;j++){
				result+="*";}
			i=i+1;}
		result+="\n";
		for(int w=0;w<height-1;w++){
			for(int j=0;j<num_spaces_each_side;j++){
				result+=" ";
			}
			result+="*";
			for(int j=0;j<num_spaces_each_side;j++){
				result+=" ";
			}
			result+="\n";
		} 
		return result;}


int main(int argc, char*argv[]){
	if(argc!=3){
		cerr<<"Assertion Failed\n";
		exit(1);
	}


	int m=atoi(argv[1]);
	int n=atoi(argv[2]);
	cout<<starT(m,n);
	return 0;
}
