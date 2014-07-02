/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  str_cli.c
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
 * @brief Figure 5.5 str_cli function: client processing loop
 */
#include "unp.h"

/**
 * @brief Figure 5.5 str_cli function: client processing loop
 * @see Fgets, Writen, Readline
 */
void str_cli1(FILE *fp, int sockfd)
{
  char sendline[MAXLINE], recvline[MAXLINE];

  while (Fgets(sendline, MAXLINE, fp) != NULL) {
    Writen(sockfd, sendline, strlen(sendline));

    if (Readline(sockfd, recvline, MAXLINE) == 0)
      err_quit("str_cli: server terminated prematurely");

    Fputs(recvline, stdout);
  }
}
