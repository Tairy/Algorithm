#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t fpid;
  
  fpid = fork();
  printf("my pid %d \n", getpid());
  if(fpid < 0) {
    printf("error in fork!\n");
  } else if (fpid == 0) {
    printf("I am child process! My pid is %d \n", getpid());
  } else {
    printf("I am father process! My pid is %d \n", getpid());
  }

  return 0;
}