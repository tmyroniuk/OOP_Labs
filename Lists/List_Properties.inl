//
// Created by tmyro on 15.10.2019.
//

#include "List_Properties.h"

List_Properties::TypeHolder::TypeHolder() : type() {}

List_Properties::Type List_Properties::getType() {
    return type.type;
}

void List_Properties::setType(Type to){
    type.type = to;
}

List_Realisation<int> *List_Properties::create() {
    switch (type.type){
        case Linked:
            return new Linked_List<int>();
        case Array:
            return new Array_List<int>();
    }
}
