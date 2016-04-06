bool isCheckCmdline() {
   char filePath[32], fileRead[128];
   FILE* file;

   snprintf(filePath, 24, "/proc/%d/cmdline", getppid());
   file = fopen(filePath, "r");

   fgets(fileRead, 128, file);
   fclose(file);

   if(!strcmp(fileRead, "gdb")) {
	   DbgPrint("Debugger(gdb) detected\n");
       return true;
   }
   DbgPrint("Clear(Debug)\n");
   return false;
}

bool isCheckTracerPid() {
	int TPid;
	char buf[512];

	const char *str = "TracerPid:";
	size_t strSize = strlen(str);

	FILE* file = fopen("/proc/self/status", "r");

	while (fgets(buf, 512, file)) {
		if (!strncmp(buf, str, strSize)) {
			sscanf(buf, "TracerPid: %d", &TPid);
			if (TPid != 0) {
				DbgPrint("Debugger detected\n");
				return true;
			}
		}
	}
	fclose(file);
	DbgPrint("Clear(Debug)\n");
	return false;
}

void CheckDebug(){
	if(isCheckCmdline()){
		exit(0);
	}
	if(isCheckTracerPid()){
		exit(0);
	}
}
