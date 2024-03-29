/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  writen.c
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
 * @brief Figure 3.16 writen function: Write n Bytes to a descriptor.
 */

#include "unp.h"

ssize_t writen(int fd, const void *vptr, size_t n)
{
  size_t nleft;
  ssize_t nwritten;
  const char *ptr;
  
  ptr = vptr;
  nleft = n;
  while (nleft > 0) {
    if ((nwritten = write(fd, ptr, nleft)) <= 0) {
      if (nwritten < 0 && errno == EINTR)
        nwritten = 0;                           /* and call write() again */
      else
        return -1;                              /* error */
    }

    nleft -= nwritten;
    ptr += nwritten;
  }

  return n;
}

void Writen(int fd, const void *ptr, size_t nbytes)
{
  if (writen(fd, ptr, nbytes) != nbytes)
    err_sys("writen error");
}
