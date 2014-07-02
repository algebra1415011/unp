/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  dg_echo.c
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
 * @brief Figure 8.4 echo lines on a datagram socket
 */

#include "unp.h"

void dg_echo1(int sockfd, SA*pcliaddr, socklen_t clilen)
{
  int n;
  socklen_t len;
  char mesg[MAXLINE];

  for ( ; ; ) {
    len = clilen;
    n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

    Sendto(sockfd, mesg, n, 0, pcliaddr, len);
  }
}


