/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  str_echo08.c
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
 * @brief Figure 5.17 str_echo function that adds two numbers
 */

#include "unp.h"

void str_echo2(int sockfd)
{
  long arg1, arg2;
  ssize_t n;
  char line[MAXLINE];

  for ( ; ; ) {
    if ( (n = Readline(sockfd, line, MAXLINE)) == 0)
      return;                                   /* connection closed by other end */
    
    if (sscanf(line, "%ld%ld", &arg1, &arg2) == 2)
      snprintf(line, sizeof(line), "%ld\n", arg1 + arg2 );
    else
      snprintf(line, sizeof(line), "input error\n");

    n = strlen(line);
    Writen(sockfd, line, n);
  }
}

