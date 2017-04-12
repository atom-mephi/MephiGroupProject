#include <stdio.h>
#include <stdlib.h>

#define CLASS Object

struct CLASS;

#define method0(ret, name) ret (* name )( struct CLASS * );
#define method1(ret, name, param1) ret (* name )( struct CLASS *, param1);
#define method2(ret, name, param1, param2) ret (* name )( struct CLASS *, param1, param2);
#define method3(ret, name, param1, param2, param3) ret (* name )( struct CLASS *, param1, param2, param3);

#define INIT(class, name1, value1, name2, value2, name3, value3) \
    struct class * class () \
{ \
    struct class * obj = malloc(sizeof( class )); \
    obj->name1 = value1; \
    obj->name2 = value2; \
    obj->name3 = value3; \
    return obj; \
};

struct CLASS
{
    int id;
    method1(void, setId, int)
        method0(int, getId)
};

void __setObjectId__(struct CLASS* obj, int id)
{
    obj->id = id;
}

int __getObjectId__(struct CLASS* obj)
{
    return obj->id;
}

INIT( CLASS , id, 0, setId, __setObjectId__, getId, __getObjectId__)

    int main(void) {

        struct Object* obj = Object();
        int id;

        scanf("%d", &id);
        obj->setId(obj, id);
        printf("%d", obj->getId(obj));
        return 0;
    }
