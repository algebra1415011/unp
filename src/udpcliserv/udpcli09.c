/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  udpcli09.c
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
 * @brief Figure 8.23 UDP program that uses connect to determine outgoing interface
 */

#include "unp.h"

int udpcli09_main(int argc, char *argv[])
{
  int sockfd;
  socklen_t len;
  struct sockaddr_in cliaddr, servaddr;

  if (argc != 2)
    err_quit("usage: udpcli09 <IPaddress>");

  sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERV_PORT);
  Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

  len = sizeof(cliaddr);
  Getsockname(sockfd, (SA *) &cliaddr, sizeof(servaddr));
  printf("local address %s\n", Sock_ntop((SA *) &cliaddr, len));

  exit(0);

}


