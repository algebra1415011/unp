/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  unp.h
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
 * @brief unp.h
 */

#ifndef __unp_h
#define __unp_h
#include "config.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>

#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif

#ifdef HAVE_SYS_SYSCTL_H
#include <sys/sysctl.h>
#endif

#ifdef HAVE_POLL_H
#define __USE_XOPEN
#include <poll.h>
#endif

#ifdef HAVE_SYS_EVENT_H
#include <sys/event.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

/*
 * Three headers are normally needed for socket/file ioctl's:
 * <sys/ioctl.h>, <sys/filio.h>, and <sys/sockio.h>
 */

#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif

#ifdef HAVE_SYS_FILIO_H
#include <sys/filio.h>
#endif

#ifdef HAVE_SYS_SOCKIO_H
#include <sys/sockio.h>
#endif

#ifdef HAVE_PTHREAD_H
#include <pthread.h>
#endif

#ifdef HAVE_NET_IF_DL_H
#include <net/if_dl.h>
#endif

#ifdef HAVE_NETINET_SCTP_H
#include <netinet/sctp.h>
#endif

/*
 * OSF/1 actually disables recv() and send() in <sys/socket.h>
 */
#ifdef __osf__
#undef recv
#undef send
#define recv(a,b,c,d) recvfrom(a,b,c,d,0,0)
#define send(a,b,c,d) sendto(a,b,c,d,0,0)
#endif

#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif

#ifndef SHUT_RD
#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2
#endif

#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN
#endif

/*
 * Define following even if IPv6 not supported, so we can always allocate
 * an adequately sized buffer without #ifdefs in the code
 */

#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 46
#endif

/*
 * Define bzero() as a macro if it's not in standard C library
 */
#ifndef HAVE_BZERO
#define bzero(ptr, n) memset(ptr, 0, n)
#endif

/*
 * Older resolvers do not have gethostbyname2()
 */
#ifndef HAVE_GETHOSTBYNAME2
#define gethostbyname2(host,family)
#endif

/*
 * The structure returned by recvfrom_flags()
 */
struct unp_in_pktinfo {
  struct in_addr ipi_addr;
  int ipi_ifindex;
};

/*
 * We need the newer CMSG_LEN() and CMSG_SPACE() macros, but few
 * implementations support them today. These two macros readlly need
 * an ALIGN() macro, but each implementation does this differently.
 */
#ifndef CMSG_LEN
#define CMSG_LEN(size)  (sizeof(struct cmsghdr) + (size))
#endif

#ifndef CMSG_SPACE
#define CMSG_SPACE(size)  (sizeof(struct cmsghdr) + (size))
#endif

/*
 * POSIX requires the SUN_LEN() macro, but not all implementations define
 * it (yet). Note that this 4.4BSD macro works regardless whether there is
 * a length field or not.
 */

#ifndef SUN_LEN
#define SUN_LEN(su) \
  (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
#endif


/*
 * POSIX renames "Unix domain" as "local IPC".
 * Not all systems define AF_LOCAL and PF_LOCAL (yet).
 */
#ifndef AF_LOCAL
#define AF_LOCAL AF_UNIX
#endif

#ifndef PF_LOCAL
#define PF_LOCAL PF_UNIX
#endif

/*
 * POSIX requires that an #include of <poll.h> define INFTIM, but many
 * systems still define it in <sys/stropts.h>. We don't want to include
 * all the STREAMS stuff if it's not needed, so we just define INFTIM here.
 * This is the standard value, but there's no guarantee it is -1. 
 */
#ifndef INFTIM
#define INFTIM  (-1)
#ifdef HAVE_POLL_H
#define INFTIM_UNPH
#endif
#endif

/*
 * Following could be derived from SOMAXCONN in <sys/socket.h>, but many
 * kernels still #define it as 5, while actually supporitng many more.
 */
#define LISTENQ 1024
/*
 * Miscellaneous constants
 */
#define MAXLINE 4096
#define BUFFSIZE 8192

/*
 * Define some port number that can be used for our examples
 */
#define SERV_PORT 9877
#define SERV_PORT_STR "9877"
#define UNIXSTR_PATH "/tmp/unix.str"
#define UNIXDG_PATH "/tmp/unix.dg"

/*
 * Following shortens all the typecasts of pointer arguments:
 */
#define SA struct sockaddr

#define HAVE_STRUCT_SOCKADDR_STORAGE
#ifndef HAVE_STRUCT_SOCKADDR_STORAGE
/*
 * RFC 3493: protocol-independent placeholder for socket addresses
 */
#define __SS_MAXSIZE 128
#define __SS_ALIGNSIZE (sizeof(int64_t))
#ifdef HAVE_SOCKADDR_SA_LEN
#define __SS_PAD1SIZE (__SS_ALIGNSIZE -sizeof(u_char) - sizeof(sa_family_t))
#else
#define __SS_PAD1SIZE (__SS_ALIGNSIZE -sizeof(sa_family_t))
#endif
#define __SS_PAD2SIZE (__SS_MAXSIZE - 2*__SS_ALIGNSIZE)
struct sockaddr_storage {
#ifdef HAVE_SOCKADDR_SA_LEN
  u_char ss_len;
#endif
  sa_family_t ss_family;
  char __ss_pad1[__SS_PAD1SIZE];
  int64_t __ss_align;
  char __ss_pad2[__SS_PAD2SIZE];
};
#endif

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define DIR_MODE (FILE_MODE|S_IXUSR|S_IXGRP|S_IXOTH)

typedef void Sigfunc(int);

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/* #ifndef HAVE_ADDRINFO_STRUCT
 * #include "lib/addrinfo.h"
 * #endif
 * 
 * #ifndef HAVE_IF_NAMEINDEX_STRUCT
 * struct if_nameindex {
 *   unsigned int if_index;
 *   char *if_name;
 * 
 * };
 * #endif
 * #ifndef HAVE_TIMESPEC_STRUCT
 * struct timespec {
 *   time_t tv_sec;
 *   long tv_nsec;
 * };
 * #endif
 */

/*
 * error functions
 */
void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);
/*
 * wrapper functions
 */

/*
 * lib/wrapsock.c
 */
int Socket(int family, int type, int protocol); /* Figure 1.7 */
void Socketpair(int family, int type, int protocol, int *fd);
void Listen(int sockfd, int backlog);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Shutdown(int fd, int how);
int Sockatmark(int fd);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr);
void Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen);
ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
    struct sockaddr *sa, socklen_t *salenptr);
ssize_t Recvmsg(int fd, struct msghdr *msg, int flags);
void Send(int fd, const void *ptr, size_t nbytes, int flags);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
    const struct sockaddr *sa, socklen_t salen);
void Sendmsg(int fd, const struct msghdr *msg, int flags);
int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval * timeout);
int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout);

/*
 * lib/wrapunix.c
 */
int Open(const char *pathname, int oflag, mode_t mode);
void Close(int fd);
ssize_t Read(int fd , void *buf, size_t count);
void Write(int fd, const void *ptr, size_t nbytes);
pid_t Fork(void);
void * Malloc(size_t size);
void * Calloc(size_t n, size_t size);
void Dup2(int fd1, int fd2);
int Fcntl(int fd, int cmd, int arg);
void Gettimeofday(struct timeval *tv, void *foo);
int Ioctl(int fd, int request, void *arg);
int Mkstemp(char *template);
void * Mmap(void * addr, size_t len, int prot, int flags, int fd, off_t offset);
void Pipe(int *fds);

/*
 * lib/wrapstdio.c
 */
void Fclose(FILE *fp);
FILE * Fdopen(int fd, const char *type);
char * Fgets(char *ptr, int n, FILE *stream);
FILE * Fopen(const char *filename, const char *mode);
void Fputs(const char *ptr, FILE *stream);

/*
 * lib/readline.c
 */
ssize_t readlinebuf(void **vptrptr);
ssize_t Readline(int fd, void *ptr, size_t maxlen);

/*
 * lib/wraplib.c
 */
const char * Inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
void Inet_pton(int family, const char *strptr, void *addrptr);

/*
 * lib/sockfd_to_family.c
 */
int sockfd_to_family(int sockfd);

/*
 * lib/readn.c
 */
ssize_t readn(int fd, void *vptr, size_t n);
ssize_t Readn(int fd, void *ptr, size_t nbytes);

/*
 * lib/writen.c
 */
ssize_t writen(int fd, const void *vptr, size_t n);
void Writen(int fd, const void *ptr, size_t nbytes);

/*
 * lib/signal.c
 */

Sigfunc * Signal(int signo, Sigfunc *func);

/*
 * lib/wrappthread.c
 */
void Pthread_mutex_lock(pthread_mutex_t *mptr); /* Figure 1.8 */

/*
 * Multi version functions
 */
int inet_pton_unp(int family, const char *strptr, void *addrptr);
const char * inet_ntop_unp(int family, const void *addrptr, char *strptr, size_t len);
ssize_t readline_unp(int fd, void *vptr, size_t maxlen);
void str_echo_unp(int sockfd);
void str_cli_unp(FILE *fp, int sockfd);
Sigfunc * signal_unp(int signo, Sigfunc *func);
void sig_chld_unp(int signo);
void dg_echo_unp(int sockfd, SA *pcliaddr, socklen_t clilen);
void dg_cli_unp(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen);

#endif

