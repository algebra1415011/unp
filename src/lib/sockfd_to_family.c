/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  sockfd_to_family.c
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
 * @brief Figure 4.19 Return the address family of a socket
 */

#include "unp.h"

int sockfd_to_family(int sockfd)
{
  struct sockaddr_storage ss;
  socklen_t len;

  len = sizeof(ss);
  if (getsockname(sockfd, (SA *) &ss, &len) < 0)
    return -1;
  return ss.ss_family;
}

