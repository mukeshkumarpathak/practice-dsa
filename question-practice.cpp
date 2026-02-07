#include<bits/stdc++.h>
using namespace std;

class Indicator{
  public:
    virtual void action()=0;
};

class RedIndicator: public Indicator{
  public:
    virtual void action(){
      cout<<"STOP\n";
    }    
};
class GreenIndicator: public Indicator{
  public:
    virtual void action(){
      cout<<"GO\n";
    }    
};
class YellowIndicator: public Indicator{
  public:
    virtual void action(){
      cout<<"SLOW\n";
    }    
};

class TrafficLight{
  protected:    
    Indicator *curIndicator;
  public:
    TrafficLight(Indicator *curIndicator){
      this->curIndicator = curIndicator;
    }
    
    virtual void setIndicator(Indicator *curIndicator)=0;
    virtual void show()=0;
    virtual void next()=0;

};

class TrafficLightService: public TrafficLight{
  public:
    TrafficLightService(Indicator *curIndicator): TrafficLight(curIndicator) {}
    virtual void setIndicator(Indicator *curIndicator){ this->curIndicator=curIndicator; }
    virtual void show() { curIndicator->action(); }
    
    virtual void next(){
      if(dynamic_cast<RedIndicator*> (curIndicator)) { setIndicator(new GreenIndicator()); return; }
      if(dynamic_cast<GreenIndicator*> (curIndicator)) { setIndicator(new YellowIndicator()); return; }
      if(dynamic_cast<YellowIndicator*> (curIndicator)) { setIndicator(new RedIndicator()); return; }
    }


};



int main(){
   TrafficLight *trafficLight = new TrafficLightService(new RedIndicator());
   trafficLight->show();
   trafficLight->next();
   trafficLight->show();
   trafficLight->next();
   trafficLight->show();

  return 0; 
}


