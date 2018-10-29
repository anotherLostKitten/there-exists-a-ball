#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int myfile = open("/dev/random",O_RDONLY);
  if(myfile==-1)
    printf("something is amiss with your random file... errno: %s\n", strerror(errno));
  else {
    unsigned int mine [10], mime [10];
    read(myfile, mine, sizeof(int)*10);
    close(myfile);
    for (char i = 0; i < 10; i++)
      printf("random number %d: %u\n", i, mine[i]);
    int copy = open("filey mcfileface", O_WRONLY | O_CREAT, 0644);
    write(copy, mine, sizeof(int)*10);
    close(copy);
    int boppy = open("filey mcfileface", O_RDONLY);
    read(boppy, mime, sizeof(int)*10);
    for (char i = 0; i < 10; i++)
      printf("this file's random number %d: %u\n", i, mine[i]);
  }
  return 0;
}
