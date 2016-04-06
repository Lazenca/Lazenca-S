int getTime1()
{
	struct timeval tv;
	struct timezone tz;
	gettimeofday (&tv, &tz);
	return (tv.tv_sec*1000 + tv.tv_usec/1000);
}

long getTime2()
{
	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC,&now);
	return now.tv_sec*1000000 + now.tv_nsec/1000;
}

void CheckSpeedHack(){
	int start = 0, end = 0, time_data = 0;
	int start2 = 0, end2 = 0, time_data2 = 0;
	int cmp=1;

	while(cmp){
		start = getTime1();
		start2 = getTime2();

		sleep(100);
		end = getTime1();
		end2 = getTime2();

		time_data = end - start;
		time_data2 = end2 - start2;
		DbgPrint("time_data : %d, end : %d , start : %d",time_data,end,start);
		DbgPrint("time_data2 : %d, end : %d , start : %d",time_data2,end2,start2);
		if(time_data > 101000 || time_data < 10000){
			cmp = 0;
			DbgPrint("SpeedHackDetect");
			sleep(10);
			exit(0);
		}
		if(time_data2 > 100001000 || time_data2 < 100000000){
			cmp = 0;
			DbgPrint("SpeedHackDetect");
			sleep(10);
			exit(0);
		}
	}
}



