
#ifndef DSARCHIVE_H
#define DSARCHIVE_H

#include <stdio.h>
#include <time.h>
#include <libslink.h>

#if defined (SLP_WIN)
  #include <io.h>
  #include <direct.h>
  #define mkdir _mkdir
  #define access _access

 #ifndef F_OK
    #define F_OK 0 /* Test for existence. */
  #endif
#endif

/* For the data stream chains */
typedef struct DataStream_s
{
  char   *defkey;
  FILE   *filep;
  time_t  modtime;
  struct DataStream_s *next;
}
DataStream;


extern int ds_streamproc (DataStream **streamroot, char *pathformat,
			  const SLMSrecord *msr, int reclen, int type,
			  int idletimeout);

#endif

