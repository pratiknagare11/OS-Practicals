#include<iostream>
#include<unistd.h>
#include<fcntl.h>

using namespace std;
int main()
{
  int old_fd,new_fd;
  
  old_fd = open("file1.txt",O_RDWR | O_CREAT);
  
  new_fd = dup(old_fd);
  
  cout<<"old_fd -> "<<old_fd<<endl;
  cout<<"new_fd -> "<<new_fd<<endl;
  //   dup2(old_fd,new_fd);
  
  write(old_fd,"First Message\n",14);
  write(new_fd,"Second Message\n",15);
  return 0;
}