/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  readline1.c
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
 * @brief Figure 3.17 readline function: Read a text line from a descriptor, one byte at a time
 *
 * @note This is just an example for slow readline version, not included in the library
 */

#include "unp.h"
/* PAINFULLY SLOW VERSION -- example only */
ssize_t readline1(int fd, void *vptr, size_t maxlen)
{
  ssize_t n, rc;
  char c, *ptr;
  
  ptr = vptr;
  for (n = 1; n < maxlen; n++) {
again:
    if ( (rc = read(fd, &c, 1)) == 1) {
      *ptr++ = c;
      if (c == '\n')
        break;                                  /* newline is stored, like fgets() */
    } else if (rc == 0) {
      *ptr = 0;
      return (n - 1);                           /* EOF, n - 1 bytes were read */
    } else {
      if (errno == EINTR)
        goto again;
      return -1;                                /* error, errno set by read() */
    }
  }

  *ptr = 0;
  return n;                                     /* null terminate like fgets() */
}

