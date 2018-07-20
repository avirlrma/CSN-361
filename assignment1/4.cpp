#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
	cout<<"I am the parent --> "<<getpid()<<endl;
	int pid = fork(); 
	if(pid==0){
	//first child
		cout<<"I am the first child --> "<<getpid()<<endl;
		//char* arg[] = {"./a.out",(char*)NULL};
		//execvp(arg[0],arg);
		int pid3 = fork();
		if(pid3==0){
			cout<<"I am the grandchild I suppose -->"<<getpid()<<endl;
		}
		else{
			int pid4 = fork();
			if(pid4==0){
				cout<<"I am the secodn grandchild I supose -->"<<getpid()<<endl;	
			}
		}
	}
	else{
	int pid2 = fork();
		if(pid2==0){
			//second child
			cout<<"I am the second child --> "<<getpid()<<endl;
				int pid3 = fork();
			if(pid3==0){
				cout<<"I am the grandchild I suppose -->"<<getpid()<<endl;
			}
			else{
				int pid4 = fork();
				if(pid4==0){
					cout<<"I am the second grandchild I supose -->"<<getpid()<<endl;	
				}
			}
		}
}
return 0;
}
