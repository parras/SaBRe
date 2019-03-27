// RUN: %{cc} %s -o %t1
// RUN: touch %t3
// RUN: %{sbr} %t1 %t3 2>&1

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

int main(int argc, char ** argv) {

  int fd = open(argv[1], O_RDONLY);
  if (fd < 0)
    return 1;

  if (fchown(fd, getuid(), getgid()) < 0)
    return 2;

  close(fd);

  return 0;
}
