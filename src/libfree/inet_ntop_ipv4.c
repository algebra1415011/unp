/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  inet_ntop_ipv4.c
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
 * @brief Figure 3.13 Simple version of inet_ntop that supports only IPv4
 */

#include "unp.h"

const char * inet_ntop1(int family, const void *addrptr, char *strptr, size_t len)
{
  const u_char *p = (const u_char *) addrptr;
  
  if (family == AF_INET) {
    char temp[INET_ADDRSTRLEN];

    snprintf(temp, sizeof(temp), "%d.%d.%d.%d", p[0], p[1],p[2],p[3]);
    if (strlen(temp) >= len) {
      errno = ENOSPC;
      return NULL;
    }
    strcpy(strptr, temp);
    return strptr;
  }
  errno = EAFNOSUPPORT;
  return NULL;
}
