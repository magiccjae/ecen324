#include "csapp.h"
#include <unistd.h>
#include <sys/mman.h>

void mmapcopy(int fd, int size)
{
	char *bufp;
	bufp = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	bufp[0] = 'J';
	write(1, bufp, size);
	return;
}

int main(int argc, char**argv)
{
	struct stat stat;
	int fd;
	
	if(argc != 2) {
		printf("usage: %s <filename>\n", argv[0]);
		exit(0);
	}
	
	fd = open(argv[1], O_RDWR, 0);
	fstat(fd, &stat);
	mmapcopy(fd, stat.st_size);
	exit(0);

}
