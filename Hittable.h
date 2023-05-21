#ifndef HITTABLE_H
#define HITTABLE_H

class Hittable {
public:
    virtual void hit() = 0;
    virtual bool isHit() = 0;
    // Add other functions as needed
};

#endif // HITTABLE_H