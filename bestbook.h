#ifndef BESTBOOK_H
#define BESTBOOK_H
#include <Wt/Dbo/Dbo>
#include <string>

namespace dbo = Wt::Dbo;

class BestBook {
public:
  enum Role {
    Visitor = 0,
    Admin = 1,
    Alien = 42
  };

  std::string name;
  std::string password;
  Role        role;
  int         karma;

  template<class Action>
  void persist(Action& a)
  {
    dbo::field(a, name,     "name");
    dbo::field(a, password, "password");
    dbo::field(a, role,     "role");
    dbo::field(a, karma,    "karma");
  }
};

#endif // BESTBOOK_H
