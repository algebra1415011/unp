/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  wrapsock.c
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
 * @brief Figure 1.7 Figure 4.9 sock wrapper function
 */

#include "unp.h"

/*
 * @brief Figure 1.7 Our wrapper function for the socket function
 */
int Socket(int family, int type, int protocol)
{
  int n;
  if ( (n = socket(family, type, protocol)) < 0)
    err_sys("socket error");
  return n;
}
void Socketpair(int family, int type, int protocol, int *fd)
{
  int n;

  if ( (n = socketpair(family, type, protocol, fd)) < 0)
    err_sys("socketpair error");
}
/**
 * @brief Figure 4.9 Wrapper function for listen that allows an environment
 * variable to specify backlog.
 */
void Listen(int fd, int backlog)
{
  char *ptr;
  /* can override 2nd argument with environment variable */
  if ((ptr = getenv("LISTENQ")) != NULL)
    backlog = atoi(ptr);

  if (listen(fd, backlog) < 0)
    err_sys("listen error");
}

/**
 * @brief wrap for accept
 */

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
  int n;
again:
  if ((n = accept(fd, sa, salenptr)) < 0) {
#ifdef EPROTO
    if (errno == EPROTO || errno == ECONNABORTED)
#else
    if (errno == ECONNABORTED)
#endif
      goto again;
    else
      err_sys("accept error");
  }
  return n;
}
/*
 * @brief wrap for bind
 */
void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
  if (bind(fd, sa, salen) < 0)
    err_sys("bind error");
}

/**
 * @brief wrap for connect
 */
void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
  if (connect(fd, sa, salen) < 0)
    err_sys("connect error");
}

void Shutdown(int fd, int how)
{
  if (shutdown(fd, how) < 0)
    err_sys("shutdown error");
}
int Sockatmark(int fd)
{
  int n;

  if ( (n = sockatmark(fd)) < 0)
    err_sys("sockatmark error");
  return n;
}


/**
 * @brief wrap for getpeername
 */

void Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
  if (getpeername(fd, sa, salenptr) < 0)
    err_sys("getpeername error");
}
/**
 * @brief wrap for getsockname
 */

void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
  if (getsockname(fd, sa, salenptr) < 0)
    err_sys("getsockname error");
}

/**
 * @brief wrap for getsockopt
 */

void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr)
{
  if (getsockopt(fd, level, optname, optval, optlenptr) < 0)
    err_sys("getsockopt error");
}

void Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
  if (setsockopt(fd, level, optname, optval, optlen) < 0)
    err_sys("setsockopt error");
}
ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags)
{
  ssize_t n;

  if ( (n = recv(fd, ptr, nbytes, flags)) < 0)
    err_sys("recv error");
  return n;
}
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
    struct sockaddr *sa, socklen_t *salenptr)
{
  ssize_t n;

  if ( (n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr)) < 0)
    err_sys("recvfrom error");
  return n;
}
ssize_t Recvmsg(int fd, struct msghdr *msg, int flags)
{
  ssize_t n;

  if ( (n = recvmsg(fd, msg, flags)) < 0)
    err_sys("recvmsg error");
  return n;
}
void Send(int fd, const void *ptr, size_t nbytes, int flags)
{
  if (send(fd, ptr, nbytes, flags) != (ssize_t) nbytes)
    err_sys("send error");
}

void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
    const struct sockaddr *sa, socklen_t salen)
{
  if (sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t) nbytes)
    err_sys("sendto error");
}
void Sendmsg(int fd, const struct msghdr *msg, int flags)
{
  unsigned int i;
  ssize_t nbytes;

  nbytes = 0;                                   /* must first figure out what return value should be */
  for (i = 0; i < msg->msg_iovlen; i++)
    nbytes += msg->msg_iov[i].iov_len;

  if (sendmsg(fd, msg, flags) != nbytes)
    err_sys("sendmsg error");
}

/**
 * @brief wrap for select
 */
int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval * timeout)
{
  int n;

  if ( (n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
    err_sys("select error");
  return n;                                     /* can return 0 on timeout */

}

/**
 * @brief wrap of poll
 * 
 */
#ifdef HAVE_POLL
int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout)
{
  int n;

  if ( (n = poll(fdarray, nfds, timeout)) < 0)
    err_sys("poll error");

  return n;
}
#endif


