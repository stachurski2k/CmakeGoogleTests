#include "IObservable.h"

LambdaObserver::LambdaObserver(std::function<void(IObservable&)>o){
    this->fun=o;
}
void LambdaObserver::Notify(IObservable& o){
    if(fun){
        fun(o);
    }
}
void IObservable::NotifyAll(){
    for(auto o: observers){
        o->Notify(*this);
    }
}

void IObservable::Register(std::shared_ptr<IObserver> o){
    observers.insert(o);
}
void IObservable::UnRegister(std::shared_ptr<IObserver> o){
    observers.erase(o);
}
void IObservable::Register(std::function<void(IObservable&)> fun){
    auto o = std::make_shared<LambdaObserver>(fun);
    observers.insert(o);
}