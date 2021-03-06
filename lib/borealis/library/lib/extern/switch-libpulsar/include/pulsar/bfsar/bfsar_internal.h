#pragma once

#include <pulsar/types.h>
#include <pulsar/archive/archive_internal.h>

// @see https://github.com/Kinnay/Nintendo-File-Formats/wiki/BFSAR-File-Format
// @see http://mk8.tockdom.com/wiki/BFSAR_(File_Format)

#define _PLSR_BFSAR_MAGIC "FSAR"
#define _PLSR_BFSAR_STRG_MAGIC "STRG"
#define _PLSR_BFSAR_INFO_MAGIC "INFO"
#define _PLSR_BFSAR_FILE_MAGIC "FILE"

#define _PLSR_BFSAR_SECTION_IDENTIFIER_STRG 0x2000
#define _PLSR_BFSAR_SECTION_IDENTIFIER_INFO 0x2001
#define _PLSR_BFSAR_SECTION_IDENTIFIER_FILE 0x2002

#define _PLSR_BFSAR_SECTION_ID_LIST 0x0100

#define _PLSR_BFSAR_STRG_IDENTIFIER_STRING_TABLE 0x2400
#define _PLSR_BFSAR_STRG_IDENTIFIER_STRING_TABLE_ENTRY 0x1f01
#define _PLSR_BFSAR_STRG_IDENTIFIER_STRING_TREE 0x2401

#define _PLSR_BFSAR_INFO_IDENTIFIER_SOUND_TABLE 0x2100
#define _PLSR_BFSAR_INFO_IDENTIFIER_BANK_TABLE 0x2101
#define _PLSR_BFSAR_INFO_IDENTIFIER_PLAYER_TABLE 0x2102
#define _PLSR_BFSAR_INFO_IDENTIFIER_WAVE_ARCHIVE_TABLE 0x2103
#define _PLSR_BFSAR_INFO_IDENTIFIER_SOUND_SET_TABLE 0x2104
#define _PLSR_BFSAR_INFO_IDENTIFIER_GROUP_TABLE 0x2105
#define _PLSR_BFSAR_INFO_IDENTIFIER_FILE_TABLE 0x2106
#define _PLSR_BFSAR_INFO_IDENTIFIER_SOUND_ARCHIVE_INFO 0x220B

#define _PLSR_BFSAR_INFO_IDENTIFIER_SOUND_ENTRY 0x2200
#define _PLSR_BFSAR_INFO_IDENTIFIER_STREAM_ENTRY 0x2201
#define _PLSR_BFSAR_INFO_IDENTIFIER_WAVE_ENTRY 0x2202
#define _PLSR_BFSAR_INFO_IDENTIFIER_SEQUENCE_ENTRY 0x2203
#define _PLSR_BFSAR_INFO_IDENTIFIER_SOUND_SET_ENTRY 0x2204
#define _PLSR_BFSAR_INFO_IDENTIFIER_WAVE_ARCHIVE_TABLE_ENTRY 0x2205
#define _PLSR_BFSAR_INFO_IDENTIFIER_BANK_ENTRY 0x2206
#define _PLSR_BFSAR_INFO_IDENTIFIER_WAVE_ARCHIVE_ENTRY 0x2207
#define _PLSR_BFSAR_INFO_IDENTIFIER_GROUP_ENTRY 0x2208
#define _PLSR_BFSAR_INFO_IDENTIFIER_PLAYER_INFO_ENTRY 0x2209
#define _PLSR_BFSAR_INFO_IDENTIFIER_FILE_ENTRY 0x220A

#define _PLSR_BFSAR_FILE_IDENTIFIER_INTERNAL 0x220c
#define _PLSR_BFSAR_FILE_IDENTIFIER_EXTERNAL 0x220d

#define _PLSR_BFSAR_FILE_TYPE_SOUND 1
#define _PLSR_BFSAR_FILE_TYPE_SOUND_SET 2
#define _PLSR_BFSAR_FILE_TYPE_BANK 3
#define _PLSR_BFSAR_FILE_TYPE_PLAYER 4
#define _PLSR_BFSAR_FILE_TYPE_WAVE_ARCHIVE 5
#define _PLSR_BFSAR_FILE_TYPE_GROUP 6

#define _PLSR_BFSAR_ITEM_ID_INDEX_BITS 24
#define _PLSR_BFSAR_ITEM_ID_TYPE_BITS 8

#define _PLSR_BFSAR_FLAG_STRING_INDEX BIT(0)
#define _PLSR_BFSAR_FLAG_WAVE_ARCHIVE_COUNT BIT(1)

typedef struct {
	u32 count;
} _PLSR_BFSARIdListHeader;

typedef struct {
	u32 rootNodeIndex;
	u32 nodeCount;
} _PLSR_BFSARStringTreeHeader;

typedef struct {
	u16 endpointFlag;
	u16 stringBit;
	u32 leftIndex;
	u32 rightIndex;
	u32 stringTableIndex;

	u32 itemId;
} _PLSR_BFSARStringTreeNode;

typedef struct {
	u32 fileIndex;
	u32 flags;
} _PLSR_BFSARGroupEntry;

typedef struct {
	u32 fileIndex;
	u32 playerItemId;
	u8 initialVolume;
	u8 remoteFilter;
	char _padX0A[2];
	_PLSR_ArchiveRef ref;
	u32 flags;
} _PLSR_BFSARSoundEntry;

typedef struct {
	u32 index;
	u32 trackCount;
	u32 flags;
} _PLSR_BFSARSoundWaveEntry;

typedef struct {
	u32 firstItemId;
	u32 lastItemId;
	_PLSR_ArchiveRef fileTableRef;
	_PLSR_ArchiveRef waveArchiveTableRef;
	u32 flags;
} _PLSR_BFSARSoundSetEntry;

typedef struct {
	u32 fileIndex;
	char _unkX04[1];
	char _padX05[3];
	u32 flags;
} _PLSR_BFSARWaveArchiveEntry;
