#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int main(void)
{
	int fd;
	if ((fd = creat("file.txt", S_IRUSR)) < 0)
		perror("Create Error");
	if (write(fd, buf1, 10) != 10)
		perror("buf1 write error");
	/* Offset is now = 10 */
	if (lseek(fd, 16384, SEEK_SET) == -1)
		perror("lseek error");
	if (write(fd, buf2, 10) != 10)
		perror("buf2 write error");
	exit(0);
}
