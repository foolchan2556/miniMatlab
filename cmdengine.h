#ifndef _H_CMDENGINE_
#define _H_CMDENGINE_

#include <string>
#include <workspace.h>
using namespace std;

extern const int ILLEGAL_EXPR;
extern const int ILLEGAL_NAME;
extern const int ERROR_ADD;
extern const int ERROR_EVAL;
extern Workspace wksp;


int checkValidName(const string & vName);
void uniform(string & expr);
string callItem(string & expr);
string callPlotter(string & expr);
const string process(const string & cmd);

#endif // _H_CMDENGINE_
