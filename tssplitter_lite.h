/* tssplitter_lite.h  -- split TS stream program's header.

   Copyright 2009 querulous
   Copyright 2010 Naoya OYAMA <naoya.oyama@gmail.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
#pragma once

#include <stdint.h>

#include "decoder.h"

#define LENGTH_PACKET			(188)
#define MAX_PID				(8192)
#define MAX_SERVICES			(50)
#define LENGTH_CRC_DATA			(176)

#define TSS_SUCCESS			(0)
#define TSS_ERROR			(-1)
#define TSS_NULL			(-2)
#define LENGTH_PAT_HEADER		(12)
#define C_CHAR_COMMA			','
#define SECTION_CONTINUE		(1)

typedef struct pmt_version {
	int pid;
	int version;
	int packet;
} pmt_version;

/**
 * splitter構造体
 */
typedef struct splitter {
	unsigned char	pids[MAX_PID];
	unsigned char	pmt_pids[MAX_PID];
	unsigned char*	pat;
	char**		sid_list;
	unsigned char	pat_count;
	int pmt_retain;
	int pmt_counter;
	int avail_pmts[MAX_SERVICES];
	pmt_version pmt_version[MAX_SERVICES];
	int num_pmts;
	uint16_t section_remain[MAX_PID];	// セクション残りバイト数
	uint8_t  packet_seq[MAX_PID];		// 巡回カウンタ
} splitter;

typedef struct _splitbuf_t
{
	uint8_t * buffer;
	int buffer_size;
	int buffer_filled;
} splitbuf_t;

splitter* split_startup(char *sid);
int split_select(splitter *sp, ARIB_STD_B25_BUFFER *sbuf);
void split_shutdown(splitter *sp);
int split_ts(splitter *splitter, ARIB_STD_B25_BUFFER *sbuf, splitbuf_t *dbuf);

