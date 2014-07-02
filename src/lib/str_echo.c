/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  str_echo.c
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
 * @brief Figure 5.3 str_echo function: echoes data on a socket.
 * @see writen.c
 */

#include "unp.h"

void str_echo1(int sockfd)
{
  ssize_t n;
  char buf[MAXLINE];
again:
  while ((n = read(sockfd, buf, MAXLINE)) > 0)
    Writen(sockfd, buf, n);

  if (n < 0 && errno == EINTR)
    goto again;
  else if (n < 0)
    err_sys("str_echo: read error");
}
