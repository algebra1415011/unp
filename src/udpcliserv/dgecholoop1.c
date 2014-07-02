/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  dgecholoop1.c
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
 * @brief Figure 8.20 dg_echo function that counts received datagrams
 */


#include "unp.h"

static void recvfrom_int(int);
static int count;

void dg_echo2(int sockfd, SA *pcliaddr, socklen_t clilen)
{
  socklen_t len;
  char mesg[MAXLINE];

  Signal(SIGINT, recvfrom_int);

  for ( ; ; ) {
    len = clilen;
    Recvfrom(sockfd, mesg, MAXLINE, 0 , pcliaddr, &len);

    count++;
  }
}

static void recvfrom_int(int signo)
{
  printf("\nreceived %d datagrams\n", count);
  exit(0);
}

