#define Usuario_h
using namespace std;

class Usuario
{
  private:
    string username;
    string password;
    
    
  public:
    Usuario();
    Usuario(string u, string p);
    ~Usuario();
    string getUsername();
    void setUsername(string u);
    string getPassword();
    void setPassword(string p);
    string toString();
};

