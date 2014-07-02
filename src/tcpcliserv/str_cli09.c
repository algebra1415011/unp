/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  str_cli09.c
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
 * @brief Figure 5.19 str_cli that sends two binary integers to server
 */

#include "unp.h"
#include "sum.h"

void str_cli3(FILE *fp, int sockfd)
{
  char sendline[MAXLINE];
  struct args args;
  struct result result;

  while (Fgets(sendline, MAXLINE, fp) != NULL) {

    if (sscanf(sendline, "%ld%ld", &args.arg1, &args.arg2) != 2) {
      printf("invalid input: %s", sendline);
      continue;
    }
    Writen(sockfd, &args, sizeof(args));

    if (Readn(sockfd, &result, sizeof(result)) == 0)
      err_quit("str_cli: server terminated prematurely");
    
    printf("%ld\n", result.sum);

  }
}

