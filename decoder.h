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
#ifndef RECDVB_DECODER_H
#define RECDVB_DECODER_H

#include <stdint.h>
#include "config.h"

#ifdef HAVE_LIBARIB25

#include <arib25/arib_std_b25.h>
#include <arib25/b_cas_card.h>

typedef struct decoder {
	ARIB_STD_B25 *b25;
	B_CAS_CARD *bcas;
} decoder;

#else

typedef struct {
	uint8_t *data;
	int32_t  size;
} ARIB_STD_B25_BUFFER;

typedef struct decoder {
	void *dummy;
} decoder;

#endif

typedef struct decoder_options {
	int round;
	int strip;
	int emm;
} decoder_options;

/* prototypes */
decoder *b25_startup(decoder_options *opt);
int b25_shutdown(decoder *dec);
int b25_decode(decoder *dec,
		ARIB_STD_B25_BUFFER *sbuf,
		ARIB_STD_B25_BUFFER *dbuf);
int b25_finish(decoder *dec,
		ARIB_STD_B25_BUFFER *sbuf,
		ARIB_STD_B25_BUFFER *dbuf);


#endif
