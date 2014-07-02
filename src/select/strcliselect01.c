/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  strcliselect01.c
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
 * @brief Figure 6.9 Implementation of str_cli function using select (improved in Figure 6.13)
 */

#include "unp.h"

void str_cli4(FILE *fp, int sockfd)
{
  int maxfdp1;
  fd_set rset;
  char sendline[MAXLINE], recvline[MAXLINE];

  FD_ZERO(&rset);
  for ( ; ; ) {
    FD_SET(fileno(fp), &rset);
    FD_SET(sockfd, &rset);
    maxfdp1 = max(fileno(fp), sockfd) + 1;
    Select(maxfdp1, &rset, NULL, NULL, NULL);

    if (FD_ISSET(sockfd, &rset)) {              /* socket is readable */
      if (Readline(sockfd, recvline, MAXLINE) == 0)
        err_quit("str_cli: server terminated prematurely");
      Fputs(recvline, stdout);
    }

    if (FD_ISSET(fileno(fp), &rset)) {          /* input is readable */
      if (Fgets(sendline, MAXLINE, fp) == NULL)
        return;                                 /* all done */
      Writen(sockfd, sendline, strlen(sendline));

    }

  }
}
