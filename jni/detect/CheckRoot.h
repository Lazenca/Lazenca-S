bool getPpid(int pid)
{
	int ppid = 0;

	char file[PATH_MAX];
	sprintf(file, "/proc/%d/status", pid);

    FILE *fp = fopen(file, "r");
	if(fp)
	{
		while(1)
		{
			char buf[PATH_MAX];
			if(!fgets(buf, sizeof(buf), fp))
			{
				break;
			}
			if(!strncmp("PPid:", buf, 4))
			{
				ppid = atoi(buf+5);
				break;
			}
		}
		fclose(fp);
	}

	return ppid;
}

bool CheckRootUser(){
	struct dirent *entry;
	struct stat fstat;

	DIR *dir = opendir("/proc");

	while(1){
		int pid = 0;
		while((entry = readdir(dir)) != NULL)
		{
			lstat(entry->d_name, &fstat);
			if(!S_ISDIR(fstat.st_mode))
			{
				continue;
			}

			pid = atoi(entry->d_name);
			if(pid <= 0)
			{
				continue;
			}
			int ppid = getPpid(pid);
			if(ppid > 400){
				DbgPrint(">>> Dected Root PPID : %d",ppid);
				return true;
			}
		}
		sleep(1000);
	}
	closedir(dir);
	return false;
}
