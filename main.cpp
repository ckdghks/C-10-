#include <iostream>
using namespace std;

class User {
  protected:
    string name;  // 직업의 이름
    int health, mana, power, shield;  // 체력, 마나, 공격력, 방어막
  public:
    User(string n="", int h=100, int m=50) { 
      name = n; health = h; mana = m; 
    }
    void f() { cout << "일반 유저" << endl;}
    virtual void g() { cout << "일반 유저" << endl;}
    virtual double getPower() { return 0; }  // dummy 값 리턴
    //virtual double getShield() { return 0; }  가상함수가 아니라면 주석처리
    string getName() { return name; } // 이름 리 
};

class Knight : public User {
  public:
    Knight(string n="", int h=150, int m=40) { 
      name = n; health = h; mana = m; 
    }
    void f() { cout << "기사 유저" << endl;}
    virtual void g() { cout << "기사 유저" << endl;}
    virtual double getPower() { return power = 0.5 * health; }
    double getShield() { return shield = 0.3 * health; }
};

class Wizard : public User {
  public:
    Wizard(string n="", int h=75, int m=150) { 
      name = n; health = h; mana = m; 
    }
    void f() { cout << "법사 유저" << endl;}
    virtual void g() { cout << "법사 유저" << endl;}
    virtual double getPower() { return power = 0.3 * mana; }
    double getShield() { return shield = 0.5 * mana; }
};

class Archer : public User {
  public:
    Archer(string n="", int h=100, int m=100) { 
      name = n; health = h; mana = m; 
    }
    void f() { cout << "궁수 유저" << endl;}
    void g() { cout << "궁수 유저" << endl;}      // virtual 생략가능
    double getPower() { return 0.4 * health; }
    double getShield() { 
      return shield = 0.2 * (health + mana); 
    }
};

int main() {
  User *p[3];
  Knight *kn = new Knight("기사", 130, 25);
  Wizard *wi = new Wizard("마법사", 65, 145);
  Archer *ar = new Archer("궁수", 85, 45);
  // 업 캐스팅
  p[0] = kn;
  p[1] = wi;
  p[2] = ar;

  for(int i=0; i<3; i++) {
    cout << p[i]->getName() << ": "<< " 파워는 " << p[i]->getPower(); 
    // <<" 쉴드는 " << p[i]->getShield() << endl;
    // 업캐스팅으로 기본클래스 포인터로 파생클래스의 멤버함수에 접근 불가.
    cout << " 쉴드는 "; 
    if(i == 0) cout << kn->getShield() << endl;
    else if(i == 1) cout << wi->getShield() << endl;
    else  cout << ar->getShield() << endl;
  }

  /* 만약 getShield()가 가상함수 라면
  p[0] = new Knight("기사", 130, 25);
  p[1] = new Wizard("마법사", 65, 145);
  p[2] = new Archer("궁수", 85, 45);
  for(int i=0; i<3; i++) {
    cout << p[i]->getName() << ": "<< " 파워는 " << p[i]->getPower()
    <<" 쉴드는 " << p[i]->getShield() << endl;
  }
  */
  
  for( int i=0; i<3; i++){
    p[i]->f();
    cout << "g(): \n";
    p[i]->g();  
    cout << "\n";
  }

  for(int i=0; i<3; i++) delete p[i];
}
