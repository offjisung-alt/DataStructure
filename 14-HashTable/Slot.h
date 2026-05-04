#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus {EMPTY, DELETE, INSUE};

typedef struct __SLOT_H__
{
    Key key;
    Value val;
    enum SlotStatus;    
} Slot;

#endif