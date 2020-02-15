/*
 * recdvb - record tool for linux DVB driver.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RECDVB_READER_H
#define RECDVB_READER_H

#include <pthread.h>
#include <stdint.h>

#include "recdvb.h"
#include "queue.h"

/* type definitions */
typedef struct thread_data {
	struct recdvb_options *opts;
	QUEUE_T *queue;
	pthread_mutex_t mutex;
	int alive;
	uint64_t w_byte;
} thread_data;

void *reader_func(void *p);

#endif

