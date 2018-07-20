#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
	int pid;
/*	if(pid==0){
		cout<<"I am child and my pid is "<<getpid()<<endl ;
	}
	else{
		cout<<"I am parent and my pid is "<<getpid()<<endl;
	}*/
	for(int i=0;i<5;i++){
		pid = fork();
	  if(pid==0){
          cout<<"I am child and my pid is "<<getpid()<<endl ;
     	 }
      else{
          cout<<"I am parent and my pid is "<<getpid()<<endl; 
		}
	
	}
	return 0;
}
