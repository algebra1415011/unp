/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  inet_pton_ipv4.c
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
 * @brief Figure 3.12 Simple version of inet_pton that supports only IPv4
 */
#include "unp.h"

int inet_pton1(int family, const char *strptr, void *addrptr)
{
  if (family == AF_INET) {
    struct in_addr in_val;
    if (inet_aton(strptr, &in_val)) {
      memcpy(addrptr, &in_val, sizeof(struct in_addr));
      return 1;
    }
    return 0;
  }
  errno = EAFNOSUPPORT;
  return -1;
}
