/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  lib.c
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
 * @brief multi version lib function
 */

#include "unp.h"

int inet_pton1(int family, 
    const char *strptr, void *addrptr);         /* Figure 3.12 */
const char * inet_ntop1(int family, const void *addrptr, 
    char *strptr, size_t len);                  /* Figure 3.13 */
ssize_t readline1(int fd, void *vptr, size_t maxlen); /* Figure 3.17 */
ssize_t readline2(int fd, void *vptr, size_t maxlen); /* Figure 3.18 */
void str_echo1(int sockfd);                     /* Figure 5.3 */
void str_echo2(int sockfd);                     /* Figure 5.17 */
void str_echo3(int sockfd);                     /* Figure 5.20 */
void str_cli1(FILE *fp, int sockfd);            /* Figure 5.5 */
void str_cli2(FILE *fp, int sockfd);            /* Figure 5.14 */
void str_cli3(FILE *fp, int sockfd);            /* Figure 5.19 */
void str_cli4(FILE *fp, int sockfd);            /* Figure 6.9 */
void str_cli5(FILE *fp, int sockfd);            /* Figure 6.13 */
Sigfunc * signal1(int signo, Sigfunc *func);    /* Figure 5.6 */
void sig_chld1(int signo);                      /* Figure 5.7 */
void sig_chld2(int signo);                      /* Figure 5.11 */
void dg_echo1(int sockfd, SA *pcliaddr, socklen_t clilen); /* Figure 8.4 */
void dg_echo2(int sockfd, SA *pcliaddr, socklen_t clilen); /* Figure 8.20 */
void dg_echo3(int sockfd, SA *pcliaddr, socklen_t clilen); /* Figure 8.22 */
void dg_cli1(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen); /* Figure 8.8 */
void dg_cli2(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen); /* Figure 8.9 */
void dg_cli3(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen); /* Figure 8.17 */
void dg_cli4(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen); /* Figure 8.19 */


int inet_pton_unp(int family, const char *strptr, void *addrptr)
{
  const char * ver = getenv("inet_pton");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "ansi";

  }
  if (getenv("show")) printf("inet_pton=%s\n", ver);
  if (strcmp(ver, "3.12") == 0) return inet_pton1(family, strptr, addrptr);

  return inet_pton(family, strptr, addrptr);

}


const char * inet_ntop_unp(int family, const void *addrptr, char *strptr, size_t len)
{
  const char * ver = getenv("inet_ntop");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "ansi";

  }
  if (getenv("show")) printf("inet_ntop=%s\n", ver);
  if (strcmp(ver, "3.13") == 0) return inet_ntop1(family, addrptr, strptr, len);

  return inet_ntop(family, addrptr, strptr, len);


}

ssize_t readline_unp(int fd, void *vptr, size_t maxlen)
{

  const char * ver = getenv("readline");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "3.18";

  }
  if (getenv("show")) printf("readline=%s\n", ver);
  if (strcmp(ver, "3.17") == 0) return readline1(fd, vptr, maxlen);
  if (strcmp(ver, "3.18") == 0) return readline2(fd, vptr, maxlen);
  return readline1(fd, vptr, maxlen);
}

void str_echo_unp(int sockfd)
{

  const char * ver = getenv("str_echo");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "5.3";

  }
  if (getenv("show")) printf("str_echo=%s\n", ver);
  if (strcmp(ver, "5.3") == 0) str_echo1(sockfd);
  if (strcmp(ver, "5.17") == 0) str_echo2(sockfd);
  if (strcmp(ver, "5.20") == 0) str_echo3(sockfd);

  str_echo1(sockfd);
}

void str_cli_unp(FILE *fp, int sockfd)
{
  const char * ver = getenv("str_cli");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "5.5";

  }
  if (getenv("show")) printf("str_cli=%s\n", ver);
  if (strcmp(ver, "5.5") == 0) str_cli1(fp, sockfd);
  if (strcmp(ver, "5.14") == 0) str_cli2(fp, sockfd);
  if (strcmp(ver, "5.19") == 0) str_cli3(fp, sockfd);
  if (strcmp(ver, "6.9") == 0) str_cli4(fp, sockfd);
  if (strcmp(ver, "6.13") == 0) str_cli5(fp, sockfd);
  str_cli1(fp, sockfd);
}

Sigfunc * signal_unp(int signo, Sigfunc *func)
{
  const char * ver = getenv("signal");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "ansi";
  }
  if (getenv("show")) printf("signal=%s\n", ver);
  if (strcmp(ver, "5.6") == 0) signal1(signo, func);
  return signal(signo, func);
}

void sig_chld_unp(int signo)
{
  const char * ver = getenv("sig_chld");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "5.7";
  }
  if (getenv("show")) printf("sig_chld=%s\n", ver);
  if (strcmp(ver, "5.7") == 0) sig_chld1(signo);
  if (strcmp(ver, "5.11") == 0) sig_chld2(signo);
  sig_chld1(signo);

}
void dg_echo_unp(int sockfd, SA *pcliaddr, socklen_t clilen)
{
  const char * ver = getenv("dg_echo");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "8.4";
  }
  if (getenv("show")) printf("dg_echo=%s\n", ver);
  if (strcmp(ver, "8.4") == 0) dg_echo1(sockfd, pcliaddr, clilen);
  if (strcmp(ver, "8.20") == 0) dg_echo2(sockfd, pcliaddr, clilen);
  if (strcmp(ver, "8.22") == 0) dg_echo3(sockfd, pcliaddr, clilen);
  dg_echo1(sockfd, pcliaddr, clilen);

}

void dg_cli_unp(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
  const char * ver = getenv("dg_cli");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "8.8";
  }
  if (getenv("show")) printf("dg_cli=%s\n", ver);
  if (strcmp(ver, "8.8") == 0) dg_cli1(fp, sockfd, pservaddr, servlen);
  if (strcmp(ver, "8.9") == 0) dg_cli2(fp, sockfd, pservaddr, servlen);
  if (strcmp(ver, "8.17") == 0) dg_cli3(fp, sockfd, pservaddr, servlen);
  if (strcmp(ver, "8.19") == 0) dg_cli4(fp, sockfd, pservaddr, servlen);

  dg_cli1(fp, sockfd, pservaddr, servlen);
}
