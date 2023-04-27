#ifndef IENEMY_H
#define IENEMY_H

#include "Hittable.h"

class IEnemy : public Hittable {
public:
    virtual void move() = 0;
    virtual void shoot() = 0;
    // Add other functions as needed
};

#endif // IENEMY_H