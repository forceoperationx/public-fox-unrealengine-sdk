//
//  CYZUEFoxEvent.m
//  EarthWarrior3D
//
//  Created by 呉 維 on 2016/06/13.
//
//
#include "CYZUEFoxEvent.h"


using namespace fox;

CYZUEFoxEvent* CYZUEFoxEvent::makePurchaseEvent(const char* eventName,
                                          uint ltvId,
                                          double price,
                                          const char* currency
                                          ) {
    CYZUEFoxEvent* event =new CYZUEFoxEvent::CYZUEFoxEvent(eventName, ltvId);
    event->price = price;
    event->currency = currency;

    return event;
}

void CYZUEFoxEvent::addParam(const char *k, const char *v) {
    this->extraInfo.insert(std::map<string, string>::value_type(k, v));
}
