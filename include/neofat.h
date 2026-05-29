#ifndef NEOFAT_H
#define NEOFAT_H

#include <stdint.h>

/* NeoFAT: Shadow Directory Entry (Attribute 0x0F)
 * This structure sits in the FAT directory table to store 
 * metadata and security tags for modern file discovery. */

#define ATTR_NEOFAT_SHADOW 0x0F

typedef struct __attribute__((packed)) {
    uint32_t tag_slot_1;       // Primary search tag hash
    uint32_t tag_slot_2;       // Secondary search tag hash
    uint8_t  reserved[3];      
    uint8_t  attribute;        // MUST be 0x0F
    uint8_t  reserved2[10];    
    uint32_t owner_token_hash; // Security: Tied to Process Capability
    uint16_t parent_link;      // Pointer to actual file data
    uint32_t acl_bitmap;       // Access Control List / Permissions
} NeoFatShadowEntry;

#endif
