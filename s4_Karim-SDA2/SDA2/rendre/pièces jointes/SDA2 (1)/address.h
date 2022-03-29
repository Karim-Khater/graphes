typedef unsigned address;

#define A_WIDTH 32
#define A_TAG_WIDTH 24
#define A_INDEX_WIDTH 4
#define A_OFFSET_WIDTH 4
#define A_BLOCK_WIDTH 4
#define MASK_4 0xF

address a_offset(address pa);
address a_block(address pa);
address a_index(address pa);
address a_tag(address pa);
address a_full_from_bl(address bl,address of);