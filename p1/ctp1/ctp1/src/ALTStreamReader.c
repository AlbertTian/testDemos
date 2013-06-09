//
//  ALTStreamReader.c
//  kqueueBasic
//
//  Created by Albert Tian on 13-3-26.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#include <stdio.h>
#include "ALTStreamReader.h"

#include <unistd.h>
#include <sys/event.h>
#include <errno.h>

#define MAX_REG_COUNT 5

int registerWithKqueue();

int registerWithKqueue(int newfd) {
    static int kQueueFileDescriptor = -1;
    if (kQueueFileDescriptor < 0) {
        kQueueFileDescriptor = kqueue();
    }
    
    /*
     struct kevent {
     uintptr_t	ident;		// identifier for this event 
     int16_t    filter;		// filter for event 
     uint16_t	flags;		// general flags 
     uint32_t	fflags;		// filter-specific flags 
     intptr_t	data;		// filter-specific data 
     void		*udata;		// opaque user data identifier 
     };
     */
    
    struct kevent event[MAX_REG_COUNT];
    EV_SET(&event[0], newfd, EVFILT_READ, EV_ADD, EV_ENABLE, 0, 0);
    struct timespec nowait = {0, 0};
    kevent(kQueueFileDescriptor, &event[0], 1, NULL, 0, &nowait);
    
    
}



