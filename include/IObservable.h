#pragma once
#include<map>
#include<set>
#include <functional>
#include <memory>

class IObservable;
class IObserver{
public:
    virtual void Notify(IObservable& o)=0;
};
class LambdaObserver: public IObserver{
    std::function<void(IObservable&)> fun;
public:
    LambdaObserver(std::function<void(IObservable&)>);
    void Notify(IObservable& o ) override;
};
class IObservable{
    std::set<std::shared_ptr<IObserver>> observers;
public:
    void NotifyAll();
    void Register(std::shared_ptr<IObserver>);
    void UnRegister(std::shared_ptr<IObserver>);
    void Register(std::function<void(IObservable&)>);
    virtual ~IObservable()=default;
};