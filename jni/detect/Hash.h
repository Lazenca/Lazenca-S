/*
 * SHA256
 */
#define SHA256_DIGEST_LENGTH	32

/*
 *	sha256(&strSha256,filePath);
 *	DbgPrint("This strSha256 value is %d", strSha256);
 */
void strToSha256(char *strSha256 ,char *string) {
	char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;

	sha256_init(&sha256);
	sha256_update(&sha256, string, strlen((char*) string));
	sha256_final(&sha256, hash);

	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		sprintf(strSha256 + (i * 2), "%02x", hash[i]);
	}
	strSha256[64] = 0;
}

bool fileToSha256(char *strSha256 , char *file_name){
	int len;

	SHA256_CTX sha256;
	char buf[BUFF_MAX] = {0};
	char hash[SHA256_DIGEST_LENGTH];

	FILE *fp = fopen(file_name, "rb");
	if (!fp) {
		perror("fopen : ");
		return false;
	}

	sha256_init (&sha256);

	while ((len = fread(buf, 1, sizeof(buf), fp)) > 0) {
		sha256_update(&sha256, buf, len);
	}
	sha256_final(&sha256, hash);

	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		sprintf(strSha256 + (i * 2), "%02x", hash[i]);
	}
	strSha256[64] = 0;
	return true;
}

/*
 *	unsigned int fileSize = fileToCrc32(&crc,filePath);
 *	DbgPrint("This crc value is %d", crc);
 *	DbgPrint("This filePath value is %s", filePath);
 *	DbgPrint("This fileSize value is %d", fileSize);
 */
unsigned int fileToCrc32(unsigned int *crc32, char *filePath)
{
	int len;
	int i;

	char buf[BUFF_MAX] = {0};

	unsigned int crc = 0;
	unsigned int filesize = 0;

	FILE *fp = fopen(filePath, "rb");
	if(!fp)
	{
		*crc32 = 0;
		return 0;
	}

 	while(1)
	{
		len = fread(buf, 1, sizeof(buf), fp);
		if(len > 0)
		{
			for(i=0; i<len; i++)
			{
				crc = UPDC32(buf[i], crc);
			}
			filesize += len;
		}
		else
		{
			break;
		}
	}
	*crc32 = crc;

	fclose(fp);
    return filesize;
}

/*
 *	file2md5(strMd5,filePath);
 *	DbgPrint("This MD5 value is %s", strMd5);
 */
/*bool fileToMd5(char *strMd5 , char *file_name)
{
    int fd;

    char *data;

    struct stat status;
    unsigned char digest[16];

    MD5_CTX lctx;
    MD5_Init(&lctx);
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        perror("open : ");
        //exit(0);
        return false;
    }
    fstat(fd, &status);

    data = (char *)malloc(status.st_size);
    read (fd, data, status.st_size);

    MD5_Update(&lctx, data, status.st_size);
    MD5_Final(digest, &lctx);

    for (int count = 0; count < sizeof(digest); ++count)
    {
        sprintf(strMd5+(count*2), "%02x", digest[count]);
    }
    free(data);
    close(fd);
    return true;
}*/
