#ifndef OBJECT_H
#define OBJECT_H

struct Object {
    Object();
    virtual ~Object();

    virtual void init() = 0;
    virtual void render() = 0;
    virtual void update() = 0;

    bool active;
};

#endif
