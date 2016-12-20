/*
****************************************************************************
Copyright (c) 2015, Integrated Device Technology Inc.
Copyright (c) 2015, RapidIO Trade Association
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
this list of conditions and the following disclaimer in the documentation 
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*************************************************************************
*/

#ifndef __FXFR_MSG_H__
#define __FXFR_MSG_H__

#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <pthread.h>
#include <sys/sem.h>

#include "rapidio_mport_sock.h"
#include "rapidio_mport_dma.h"
#include "libfxfr_private.h"

#define FXFR_MSG_OFFSET 20
#define MAX_MSG_SIZE 0x1000

#ifdef __cplusplus
extern "C" {
#endif

struct fxfr_svr_to_client_msg {
	uint64_t rapidio_addr;
	uint64_t rapidio_size;
	uint64_t tot_bytes_rx;
	uint64_t fail_abort;
	char rx_file_name[MAX_FILE_NAME+1];
};

struct fxfr_client_to_svr_msg {
	uint64_t rapidio_addr;
	uint64_t bytes_tx_now;
	uint64_t tot_bytes_tx;
	uint64_t end_of_file;
	uint64_t fail_abort;
	char rx_file_name[MAX_FILE_NAME+1];
};

#ifdef __cplusplus
}
#endif

#endif /* __FXFR_MSG_H__ */