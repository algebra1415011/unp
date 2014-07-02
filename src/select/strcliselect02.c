/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  strcliselect02.c
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
 * @brief Figure 6.13 str_cli function using select that handles EOF correctly.
 */


#include "unp.h"

void str_cli5(FILE *fp, int sockfd)
{
  int maxfdp1, stdineof;
  fd_set rset;
  char buf[MAXLINE];
  int n;

  stdineof = 0;
  FD_ZERO(&rset);
  for ( ; ; ) {
    if (stdineof == 0)
      FD_SET(fileno(fp), &rset);
    FD_SET(sockfd, &rset);
    maxfdp1 = max(fileno(fp), sockfd) + 1;
    Select(maxfdp1, &rset, NULL, NULL, NULL);

    if (FD_ISSET(sockfd, &rset)) {              /* socket is readble */
      if ( (n = Read(sockfd, buf, MAXLINE)) == 0) {
        if (stdineof == 1)
          return;                               /* normal termination */
        else
          err_quit("str_cli: server terminated prematurely");
      }
      Write(fileno(stdout), buf, n);
    }

    if (FD_ISSET(fileno(fp), &rset)) {          /* input is readble */
      if ( (n = Read(fileno(fp), buf, MAXLINE)) == 0) {
        stdineof = 1;
        Shutdown(sockfd, SHUT_WR);              /* send FIN */
        FD_CLR(fileno(fp), &rset);
        continue;
      }
      Writen(sockfd, buf, n);

    }
  }
}

