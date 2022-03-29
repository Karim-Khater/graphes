#include "address.h"

address a_offset(address pa)
{return pa & MASK_4;}
address a_block(address pa)
{return pa >> A_BLOCK_WIDTH ;}
address a_index(address pa)
{return pa>>A_BLOCK_WIDTH & MASK_4 ;}
address a_tag(address pa)
{return pa>>A_INDEX_WIDTH>>A_BLOCK_WIDTH ;}
address a_full_from_bl(address bl,address of)
{return bl<<A_OFFSET_WIDTH | of ;}