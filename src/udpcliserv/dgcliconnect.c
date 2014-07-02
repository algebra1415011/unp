/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  dgcliconnect.c
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
 * @brief Figure 8.17 dg_cli function that calls connect
 */


#include "unp.h"

void dg_cli3(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
  int n;
  char sendline[MAXLINE], recvline[MAXLINE + 1];

  Connect(sockfd, (SA *) pservaddr, servlen);

  while (Fgets(sendline, MAXLINE, fp) != NULL) {
    Write(sockfd, sendline, strlen(sendline));
   
    n = Read(sockfd, recvline, MAXLINE);

    recvline[n] = 0;

    Fputs(recvline, stdout);
  }
}


