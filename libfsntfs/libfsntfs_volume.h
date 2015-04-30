/*
 * Volume functions
 *
 * Copyright (C) 2010-2015, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFSNTFS_INTERNAL_VOLUME_H )
#define _LIBFSNTFS_INTERNAL_VOLUME_H

#include <common.h>
#include <types.h>

#include "libfsntfs_extern.h"
#include "libfsntfs_io_handle.h"
#include "libfsntfs_libbfio.h"
#include "libfsntfs_libcerror.h"
#include "libfsntfs_mft.h"
#include "libfsntfs_mft_entry.h"
#include "libfsntfs_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfsntfs_internal_volume libfsntfs_internal_volume_t;

struct libfsntfs_internal_volume
{
	/* The IO handle
	 */
	libfsntfs_io_handle_t *io_handle;

	/* The file IO handle
	 */
	libbfio_handle_t *file_io_handle;

	/* Value to indicate if the file IO handle was created inside the library
	 */
	uint8_t file_io_handle_created_in_library;

	/* Value to indicate if the file IO handle was opened inside the library
	 */
	uint8_t file_io_handle_opened_in_library;

	/* The MFT
	 */
	libfsntfs_mft_t *mft;
};

LIBFSNTFS_EXTERN \
int libfsntfs_volume_initialize(
     libfsntfs_volume_t **volume,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_free(
     libfsntfs_volume_t **volume,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_signal_abort(
     libfsntfs_volume_t *volume,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_open(
     libfsntfs_volume_t *volume,
     const char *filename,
     int access_flags,
     libcerror_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
LIBFSNTFS_EXTERN \
int libfsntfs_volume_open_wide(
     libfsntfs_volume_t *volume,
     const wchar_t *filename,
     int access_flags,
     libcerror_error_t **error );
#endif

LIBFSNTFS_EXTERN \
int libfsntfs_volume_open_file_io_handle(
     libfsntfs_volume_t *volume,
     libbfio_handle_t *file_io_handle,
     int access_flags,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_close(
     libfsntfs_volume_t *volume,
     libcerror_error_t **error );

int libfsntfs_volume_open_read(
     libfsntfs_internal_volume_t *internal_volume,
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_has_bitlocker_drive_encryption(
     libfsntfs_volume_t *volume,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_has_volume_shadow_snapshots(
     libfsntfs_volume_t *volume,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_cluster_block_size(
     libfsntfs_volume_t *volume,
     size_t *cluster_block_size,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_utf8_name_size(
     libfsntfs_volume_t *volume,
     size_t *utf8_name_size,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_utf8_name(
     libfsntfs_volume_t *volume,
     uint8_t *utf8_name,
     size_t utf8_name_size,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_utf16_name_size(
     libfsntfs_volume_t *volume,
     size_t *utf16_name_size,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_utf16_name(
     libfsntfs_volume_t *volume,
     uint16_t *utf16_name,
     size_t utf16_name_size,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_version(
     libfsntfs_volume_t *volume,
     uint8_t *major_version,
     uint8_t *minor_version,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_number_of_file_entries(
     libfsntfs_volume_t *volume,
     uint64_t *number_of_file_entries,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_file_entry_by_index(
     libfsntfs_volume_t *volume,
     uint64_t mft_entry_index,
     libfsntfs_file_entry_t **file_entry,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_root_directory(
     libfsntfs_volume_t *volume,
     libfsntfs_file_entry_t **root_directory_file_entry,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_file_entry_by_utf8_path(
     libfsntfs_volume_t *volume,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libfsntfs_file_entry_t **sub_file_entry,
     libcerror_error_t **error );

LIBFSNTFS_EXTERN \
int libfsntfs_volume_get_file_entry_by_utf16_path(
     libfsntfs_volume_t *volume,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libfsntfs_file_entry_t **sub_file_entry,
     libcerror_error_t **error );

int libfsntfs_volume_read_bitmap(
     libfsntfs_internal_volume_t *internal_volume,
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

