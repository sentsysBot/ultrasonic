#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int fd1;
char* buff[1000];
int rd, nbytes, tries;

int main()
{
	fd1 = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd1 == -1)
		printf("Could not open port.\n");

	fcntl(fd1, F_SETFL, 0);
	rd = read(fd1, buff, 100);
	printf("Bytes sent are %s\n", buff);
	close(fd1);
	return 0;
}