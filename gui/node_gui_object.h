#ifndef NODE_GUI_OBJECT_H
#define NODE_GUI_OBJECT_H

#include <node.h>
#include "node_gui.h"

namespace clip {
using namespace node;
using namespace v8;

class Object: public ObjectWrap {
public:
    Object ();
    Object (void *external);
    virtual ~Object ();

    static void Init (Handle<v8::Object> target);
    static Handle<Value> NewInstance (void *);

protected:
    DEFINE_CPP_METHOD (New);
    DEFINE_CPP_METHOD (GetProperty);
    DEFINE_CPP_METHOD (SetProperty);
    DEFINE_CPP_METHOD (On);

protected:
    void *obj_; // Raw GTK+ object pointer
    bool host_; // Whether we should manage its life

public:
    static Persistent<FunctionTemplate> constructor_template;

/* Not to be implemented */
private:
    Object (const Object&);
    Object& operator= (const Object&);

};
} /* clip */

#endif /* end of NODE_GUI_OBJECT_H */
