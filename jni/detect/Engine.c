#include "detect/hash/md5.h"
#include "detect/hash/crc32.h"
#include "detect/hash/sha256.h"

#include "global.h"
#include "Hash.h"
#include "linux.h"
#include "CheckDebug.h"
#include "CheckRoot.h"
#include "CheckSpeedHack.h"
#include "CheckVirtualMachine.h"
#include "CheckBinaryModification.h"




jint JNI_OnLoad(JavaVM* vm, void* reserved){
	return JNI_VERSION_1_4;
}
