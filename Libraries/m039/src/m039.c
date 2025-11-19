#include <m039.h>

#include <stdio.h>

int logd( const char* format, ... ) {
#if M039_DEBUG
	va_list args;
	va_start( args, format );
	int ret_status = vprintf(format, args);
	va_end( args );
	return ret_status;
#else
    return 0;
#endif
}