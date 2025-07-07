#include <stdio.h>

#define SEGMENT "pseudo"
#define SEGMENTATION_MASK "pseudo"
#define VA "pseudo"

int main(int argc, char *argv[]){
    printf("Pseudo Segmentation Code based on Segment_bits for adressing .code , heap and stack regions");
    /* 
    Segment = (VA & SEGMENTATION_MASK) >> SEG_SHIFT

    // Get Offset
    Offset = Va & SEGMENTATION_MASK

    //Check if offset is in bounds
    if offset >= Bounds[Segment]{
        RaiseException(PROTECTION_FAULT)

    }else {
        Physical_address = BASE[SEGMENT] + Offset
        Register = AccessMemory(PhysAddr)
    }
    */
   return 0;
}