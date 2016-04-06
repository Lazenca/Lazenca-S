#include <jni.h>
#include <android/log.h>
#include <jni.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <android/log.h>
#include <errno.h>
#include <pthread.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include "detect/Debug.h"

typedef enum {false, true} bool;

void *handle = NULL;

/*
 * Load Engine,Unload Engine
 */
bool LoadEngine(){
	handle = dlopen("/data/data/com.greycheatinglab/lib/libLazencaS.so", RTLD_NOW);
	if (!handle)
	{
		DbgPrint("fail to dlopen, %s\n", dlerror());
		return false;
	}
	DbgPrint("True to dlopen\n");
	return true;
}

void UnLoadEngine(){
	if(handle){
		dlclose(handle);
		handle = NULL;
	}
}

/*
 *  CheckSpeedHack
 */
void SpeedHack(){
	if(LoadEngine()){
		void (*pCheckSpeedHack)();
		pCheckSpeedHack = dlsym(handle, "CheckSpeedHack");
		if (pCheckSpeedHack)
		{
			(*pCheckSpeedHack)();
			DbgPrint("Ture to dlsym : CheckSpeedHack");
		}else{
			DbgPrint("CheckSpeedHack : fail to dlsym dlsym=%s\n",strerror(errno));
		}
	}
	UnLoadEngine();
}

void* ThreadCheckSpeedHack(){
	SpeedHack();
}

/*
 *  CheckVirtualMachine
 */
void VirtualMachine(){
	if(LoadEngine()){
		int (*pCheckVirtualMachine)();
		pCheckVirtualMachine = dlsym(handle, "CheckVirtualMachine");
		if (pCheckVirtualMachine)
		{
			(*pCheckVirtualMachine)();
			DbgPrint("Ture to dlsym : CheckVirtualMachine");
		}else{
			DbgPrint("CheckVirtualMachine : fail to dlsym dlsym=%s\n",strerror(errno));
		}
	}
	UnLoadEngine();
}

void* ThreadCheckVirtualMachne(){
	VirtualMachine();
}

/*
 *  CheckDebug
 */
void Debug(){
	if(LoadEngine()){
		int (*pCheckDebug)();
		pCheckDebug = dlsym(handle, "CheckDebug");
		if (pCheckDebug)
		{
			(*pCheckDebug)();
			DbgPrint("Ture to dlsym : CheckDebug");
		}else{
			DbgPrint("CheckDebug : fail to dlsym dlsym=%s\n",strerror(errno));
		}
	}
	UnLoadEngine();
}

void* ThreadCheckDebug(){
	Debug();
}

void RootUser(){
	if(LoadEngine()){
		void (*pCheckRootUser)();
		pCheckRootUser = dlsym(handle, "CheckRootUser");
		if (pCheckRootUser)
		{
			(*pCheckRootUser)();
			DbgPrint("Ture to dlsym : CheckRootUser");
		}else{
			DbgPrint("RootUserCheck : fail to dlsym dlsym=%s\n",strerror(errno));
		}
	}
	UnLoadEngine();
}

void* ThreadRootUserCheck(){
	RootUser();
}

void ModBinary(){
	if(LoadEngine()){
		void (*pCheckRootUser)();
		pCheckRootUser = dlsym(handle, "CheckModBinary");
		if (pCheckRootUser)
		{
			(*pCheckRootUser)();
			DbgPrint("Ture to dlsym : CheckModBinary");
		}else{
			DbgPrint("RootUserCheck : fail to dlsym dlsym=%s\n",strerror(errno));
		}
	}
	UnLoadEngine();
}

void* ThreadModBinary(){
	ModBinary();
}

jint JNI_OnLoad(JavaVM* vm, void* reserved){

	pthread_t thread_id_1;
	pthread_create(&thread_id_1,NULL,&ThreadCheckSpeedHack,NULL);

	pthread_t thread_id_2;
	pthread_create(&thread_id_2,NULL,&ThreadCheckVirtualMachne,NULL);

	pthread_t thread_id_3;
	pthread_create(&thread_id_3,NULL,&ThreadRootUserCheck,NULL);

	pthread_t thread_id_4;
	pthread_create(&thread_id_4,NULL,&ThreadCheckDebug,NULL);

	pthread_t thread_id_5;
	pthread_create(&thread_id_5,NULL,&ThreadModBinary,NULL);
	return JNI_VERSION_1_4;
}

