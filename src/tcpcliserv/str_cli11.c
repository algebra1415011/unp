/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  str_cli11.c
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
 * @brief Figure 5.14 str_cli that calls writen twice
 *
 */

#include "unp.h"

void str_cli2(FILE *fp, int sockfd)
{
  char sendline[MAXLINE], recvline[MAXLINE];

  while (Fgets(sendline, MAXLINE, fp) != NULL) {
    Writen(sockfd, sendline, 1);
    sleep(1);
    Writen(sockfd, sendline + 1, strlen(sendline) - 1);

    if (Readline(sockfd, recvline, MAXLINE) == 0)
      err_quit("str_cli: server terminated prematurely");
    Fputs(recvline, stdout);
  }
}

