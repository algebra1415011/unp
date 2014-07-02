/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  dgecholoop2.c
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
 * @brief Figure 8.22 dg_echo function that increases the size of the socket receive queue
 */

#include "unp.h"

static void recvfrom_int(int);
static int count;

void dg_echo3(int sockfd, SA *pcliaddr, socklen_t clilen)
{
  int n;
  socklen_t len;
  char mesg[MAXLINE];

  Signal(SIGINT, recvfrom_int);

  n = 220 *1024;
  Setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &n, sizeof(n));

  for ( ; ; ) {
    len = clilen;
    Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

    count++;
  }
}

static void recvfrom_int(int signo)
{
  printf("\nreceived %d datagrams\n", count);
  exit(0);
}
