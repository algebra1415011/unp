/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  dgcliloop1.c
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
 * @brief Figure 8.19 dg_cli function that writes a fixed number of datagrams to the server
 */

#include "unp.h"

#define NDG 2000                                /* datagrams to send */
#define DGLEN 1400                              /* length of each datagram */

void dg_cli4(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
  int i;
  char sendline[DGLEN];

  for (i = 0; i < NDG; i++) {
    Sendto(sockfd, sendline, DGLEN, 0, pservaddr, servlen);
  }
}
