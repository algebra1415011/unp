/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  udpserv01.c
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
 * @brief Figure 8.3 UDP echo server
 */

#include "unp.h"

int udpserv01_main(int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in servaddr, cliaddr;

  sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(SERV_PORT);

  Bind(sockfd, (SA *) &servaddr, sizeof(servaddr));

  dg_echo_unp(sockfd, (SA *) &cliaddr, sizeof(cliaddr));
}

