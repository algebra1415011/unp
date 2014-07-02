/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  readn.c
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
 * @brief Figure 3.15 readn function: Read n bytes from a descriptor.
 */
#include "unp.h"

ssize_t readn(int fd, void *vptr, size_t n)
{
  size_t nleft;
  ssize_t nread;
  char *ptr;

  ptr = vptr;
  nleft = n;
  while (nleft > 0) {
    if ((nread = read(fd, ptr, nleft)) < 0) {
      if (errno == EINTR)
        nread = 0;                              /* and call read() again */
      else
        return -1;
    } else if (nread == 0)
      break;                                    /* EOF */
    
    nleft -= nread;
    ptr += nread;
  }

  return (n - nleft);                           /* return >= 0 */
}
ssize_t Readn(int fd, void *ptr, size_t nbytes)
{
  ssize_t n;

  if ((n = readn(fd, ptr, nbytes)) < 0)
    err_sys("readn error");
  return n;
}
