/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  tcpserv01.c
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
 * @brief Figure 5.2 TCP echo server(improved in Figure 5.12)
 */

#include "unp.h"

int tcpserv01_main(int argc, char *argv[])
{
  int listenfd, connfd;
  pid_t childpid;
  socklen_t clilen;
  struct sockaddr_in cliaddr, servaddr;

  listenfd = Socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(SERV_PORT);

  Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

  Listen(listenfd, LISTENQ);

  for( ; ; ) {
    clilen = sizeof(cliaddr);
    connfd = Accept(listenfd, (SA*) &cliaddr, &clilen);

    if ((childpid= Fork() ) == 0) {             /* child process */
      Close(listenfd);
      str_echo_unp(connfd);
      exit(0);
    }
    Close(connfd);

  }
}
