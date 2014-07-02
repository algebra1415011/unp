/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  wrapunix.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 */
/**
 * @file
 * @brief wrap unix system call and library functions
 */

#include "unp.h"

/**
 * @brief wrap for fork
 * @see tcpserv01.c
 */

pid_t Fork(void)
{
  pid_t pid;
  if ((pid = fork()) == -1)
    err_sys("fork error");
  return pid;
}
/**
 * @brief wrap for open
 * @see
 */

int Open(const char *pathname, int oflag, mode_t mode)
{
  int fd;
  
  if ( (fd = open(pathname, oflag, mode)) == -1)
    err_sys("open error for %s", pathname);
  return fd;
}
/**
 * @brief wrap for write
 * @see
 */
void Close(int fd)
{
  if (close(fd) == -1)
    err_sys("close error");
}

/**
 * @brief wrap for read
 * @see daytimetcpcli.c tcpserv01.c
 */

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
  ssize_t n;
  if ((n = read(fd, ptr, nbytes)) == -1 )
    err_sys("read error");
  return n;
}

/**
 * @brief wrap for write
 * @see daytimetcpsrv.c daytimetcpsrv1.c tcpserv01.c
 * @note in original source file, the second arg type is void *,
 * I change it to const void *
 */

void Write(int fd, const void *ptr, size_t nbytes)
{
  if (write(fd, ptr, nbytes) != nbytes)
    err_sys("write error");
}

void * Malloc(size_t size)
{
  void *ptr;

  if ( (ptr = malloc(size)) == NULL)
    err_sys("malloc error");
  return ptr;
}

void * Calloc(size_t n, size_t size)
{
  void *ptr;
  if ( (ptr = calloc(n, size)) == NULL)
    err_sys("calloc error");
  return ptr;
}

void Dup2(int fd1, int fd2)
{
  if (dup2(fd1, fd2) == -1)
    err_sys("dup2 error");
}
int Fcntl(int fd, int cmd, int arg)
{
  int n;

  if ( (n = fcntl(fd, cmd, arg)) == -1)
    err_sys("fcntl error");
  return n;
}
void Gettimeofday(struct timeval *tv, void *foo)
{
  if (gettimeofday(tv, foo) == -1)
    err_sys("gettimeofday error");
  return;
}
int Ioctl(int fd, int request, void *arg)
{
  int n;

  if ( (n = ioctl(fd, request, arg)) == -1)
    err_sys("ioctl error");
  return n;
}

int Mkstemp(char *template)
{
  int i;

#ifdef HAVE_MKSTEMP
  if ((i = mkstemp(template)) < 0)
    err_quit("mkstemp error");
#else
  if (mktemp(template) == NULL || template[0] == 0)
    err_quit("mktemp error");
  i = Open(template, O_CREAT | O_WRONLY, FILE_MODE);
#endif

  return i;
}

#include <sys/mman.h>

void * Mmap(void * addr, size_t len, int prot, int flags, int fd, off_t offset)
{
  void *ptr;

  if ( (ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void*) -1))
    err_sys("mmap error");
  return ptr;
}

void Pipe(int *fds)
{
  if (pipe(fds) < 0)
    err_sys("pipe error");
}

