/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  str_echo09.c
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
 * @brief Figure 5.20 str_echo function that adds two binary integers
 */

#include "unp.h"
#include "sum.h"

void str_echo3(int sockfd)
{
  ssize_t n;
  struct args args;
  struct result result;

  for ( ; ; ) {
    if ( (n = Readn(sockfd, &args, sizeof(args))) == 0)
      return;                                   /* connection closed by other end */

    result.sum = args.arg1 + args.arg2;
    Writen(sockfd, &result, sizeof(result));
  }
}

