#include <stdio.h>
#include <string.h>
#include <config.h>
#include <unistd.h>
#include <getopt.h>
#include <wchar.h>
#include <fcntl.h>
#include <sys/stat.h>

#undef vfprintf
int rpl_vfprintf(FILE *stream, const char *format, va_list arg) {
  return vfprintf(stream, format, arg);
}

#undef memchr
void *rpl_memchr(const void *s, int c, size_t n) {
  return memchr(s, c, n);
}

#undef fseeko
int rpl_fseeko(FILE *stream, off_t offset, int whence) {
  return fseeko(stream, offset, whence);
}

#undef stat
int rpl_stat(const char *pathname, struct stat *statbuf) {
  return stat (pathname, statbuf);
}

#undef getcwd
char *rpl_getcwd(char *buf, size_t size) {
  return getcwd(buf, size);
}


# undef optarg
# undef opterr
# undef optind
# undef optopt

# undef getopt
# undef getopt_long

char *rpl_optarg;
int rpl_optind;
int rpl_opterr;
int rpl_optopt;

char *rpl_optarg;
int rpl_optind;


int rpl_getopt_long (int ___argc, char *__getopt_argv_const *___argv,
			const char *__shortopts,
            const struct option *__longopts, int *__longind) {
    int ret = getopt_long(___argc, ___argv, __shortopts, __longopts, __longind);
    rpl_optarg = optarg;
    rpl_optind = optind;
    rpl_opterr = opterr;
    rpl_optopt = optopt;
    return ret;
}

int rpl_getopt (int ___argc, char *const *___argv, const char *__shortopts) {
    int ret = getopt(___argc, ___argv, __shortopts);
    rpl_optarg = optarg;
    rpl_optind = optind;
    rpl_opterr = opterr;
    rpl_optopt = optopt;
    return ret;
}

#undef mbrtowc
size_t rpl_mbrtowc(wchar_t *restrict pwc, const char *restrict s, size_t n,
    mbstate_t *restrict ps) {
        return mbrtowc(pwc, s, n, ps);
    }

#undef fcntl
int rpl_fcntl(int fd, int cmd, ...) {
  unsigned long arg;
	va_list ap;
	va_start(ap, cmd);
	arg = va_arg(ap, unsigned long);
	va_end(ap);
  return fcntl(fd, cmd, arg);
}