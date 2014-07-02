/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  udpcli01.c
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
 * @brief Figure 8.7 UDP echo client
 */

#include "unp.h"

int udpcli01_main(int argc , char *argv[])
{
  int sockfd;
  struct sockaddr_in servaddr;

  if(argc != 2)
    err_quit("usage: udpcli01 <IPaddress>");

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERV_PORT);
  Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

  dg_cli_unp(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));

  exit(0);
}


