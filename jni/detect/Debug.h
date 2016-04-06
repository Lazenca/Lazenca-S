#define DbgPrint(...)	__android_log_print(ANDROID_LOG_VERBOSE, "<EDEX>", __VA_ARGS__)

#define	_JAVA(x)		(*env)->x(env,
#define	_ARGS(...)		__VA_ARGS__)
