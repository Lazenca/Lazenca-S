void virtualMachine(char *filePath, char *searchStr,char *findStr){
	FILE *fp;
	char str[81];
	fp = fopen(filePath, "r");

	while(!feof(fp))
	{
		fgets(str, 80, fp);
		if(strstr(str,searchStr) != NULL){
			str[strlen(str)-1] = ',';
			strcat(findStr,str);
		}
	}
	fclose(fp);
}

bool IsBlackDevice(char *deviceName)
{
	if(strstr(deviceName,"BlueStacks") != NULL)
	{
		DbgPrint(" BlueStacks : %s,%p",deviceName,deviceName);
		return false;
	}

	if(strstr(deviceName,"Genymotion") != NULL)
	{
		DbgPrint(" Genymotion : %s,%p",deviceName,deviceName);
		return false;
	}
	return true;
}


void CheckVirtualMachine(){
	char findSearch[300];

	virtualMachine("/system/build.prop","ro.product.manufacturer",&findSearch);
	virtualMachine("/system/build.prop","ro.product.model",&findSearch);
	virtualMachine("/system/build.prop","ro.product.name",&findSearch);
	virtualMachine("/system/build.prop","ro.product.device",&findSearch);

	if(IsBlackDevice(findSearch))	{
		DbgPrint(" BlueStacks : Not Detect");
	}else{
		DbgPrint(" BlueStacks : Detect");
		sleep(10);
		exit(0);
	}
}

