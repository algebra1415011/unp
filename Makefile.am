CPPFLAGS = -I $(top_builddir)/src -I $(top_srcdir)/src
lib_LIBRARIES = libunp.a
libunp_a_SOURCES = \
	src/unp.h \
	src/lib.c \
	src/lib/error.c \
	src/lib/wrapsock.c \
	src/lib/sock_ntop.c \
	src/lib/wrapunix.c \
	src/lib/wraplib.c \
	src/lib/wrapstdio.c \
	src/lib/readline.c \
	src/lib/readn.c \
	src/lib/writen.c \
	src/lib/signal.c \
	src/lib/sockfd_to_family.c \
	src/lib/wrappthread.c \
	src/tcpcliserv/sigchldwaitpid.c \
	src/tcpcliserv/sigchldwait.c \
	\
	src/libfree/inet_pton_ipv4.c \
	src/libfree/inet_ntop_ipv4.c \
	\
	src/lib/str_echo.c \
	src/tcpcliserv/str_echo08.c \
	src/tcpcliserv/str_echo09.c \
	\
	src/lib/str_cli.c \
	src/tcpcliserv/str_cli11.c \
	src/tcpcliserv/str_cli09.c \
	src/select/strcliselect01.c \
	src/select/strcliselect02.c  \
	\
	src/test/readline1.c \
	src/lib/readline.c \
	\
	src/lib/dg_echo.c \
	src/udpcliserv/dgecholoop1.c \
	src/udpcliserv/dgecholoop2.c \
	\
	src/lib/dg_cli.c \
	src/udpcliserv/dgcliaddr.c \
	src/udpcliserv/dgcliconnect.c \
	src/udpcliserv/dgcliloop1.c

bin_PROGRAMS = unp

unp_SOURCES = \
	src/unp.h \
	src/main.c \
	src/intro/daytimetcpcli.c \
	src/intro/daytimetcpsrv.c \
	src/intro/byteorder.c \
	src/intro/daytimetcpsrv1.c \
	src/tcpcliserv/tcpserv01.c \
	src/tcpcliserv/tcpcli01.c \
	src/tcpcliserv/tcpcli04.c \
	src/tcpcliserv/tcpserv04.c \
	src/tcpcliserv/tcpservselect01.c \
	src/tcpcliserv/tcpservpoll01.c \
	src/sockopt/checkopts.c \
	src/udpcliserv/udpserv01.c \
	src/udpcliserv/udpcli01.c \
	src/udpcliserv/udpcli09.c \
	src/udpcliserv/udpservselect01.c



unp_LDADD = $(top_builddir)/libunp.a
