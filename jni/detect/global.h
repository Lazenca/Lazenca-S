#include <jni.h>

#include <android/log.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#include <netdb.h>

#include <dlfcn.h>
#include <time.h>
#include <pthread.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>

#include <stdio.h>
#include <string.h>
#include <asm/io.h>
#include <time.h>
#include <stdlib.h>

#define DbgPrint(...)	__android_log_print(ANDROID_LOG_VERBOSE, "<EDEX>", __VA_ARGS__)

#define	_JAVA(x)		(*env)->x(env,
#define	_ARGS(...)		__VA_ARGS__)

#define	BUFF_MAX		0x2000
#define	MAX_PATH		260

typedef enum {false, true} bool;
