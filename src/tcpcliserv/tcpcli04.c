/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  tcpcli04.c
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
 * @brief Figure 5.9 TCP client that establishes five connections with server.
 */

#include "unp.h"

int tcpcli04_main(int argc, char *argv[])
{
  int i, sockfd[5];
  struct sockaddr_in servaddr;

  if (argc != 2)
    err_quit("usage: tcpcli04 <IPaddress>");

  for (i = 0; i < 5; i++) {
    sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd[i], (SA *) &servaddr, sizeof(servaddr));
  }

  str_cli_unp(stdin, sockfd[0]);                    /* do it all */

  exit(0);
}
